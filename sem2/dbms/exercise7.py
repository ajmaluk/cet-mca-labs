"""Converted from exercise7.ipynb: PyMongo examples.

Usage:
    python exercise7.py

This script runs a set of queries and demos against a MongoDB collection
named `studlist` in database `college`. Adjust `url` or collection name as
needed before running.
"""

import pymongo


def print_details(student):
    """Print all details of a student document in a readable format."""
    if not student:
        print("<no student>")
        return

    name = student.get('name', {})
    fname = name.get('fname', '')
    lname = name.get('lname', '')

    address = student.get('address', {})
    house = address.get('house_name', '')
    city = address.get('city', '')

    phone = student.get('phone', {})
    phone_no = phone.get('no', '')
    phone_type = phone.get('type', '')

    print(f"Name: {fname} {lname}")
    print(f"Address: {house}, {city}, Gender: {student.get('gender', '')}")
    print(f"Course: {student.get('course', '')}, Mark: {student.get('mark', '')}, Grade: {student.get('grade', '')}")
    print(f"Phone: {phone_no} ({phone_type})")
    print('-' * 40)


def main():
    url = "mongodb://localhost:27017"
    client = pymongo.MongoClient(url)
    db = client["college"]
    collection = db["studlist"]

    # 1. Name and Mark of all Female students in MCA
    print('\n### 1. Female students in MCA (Name and Mark)')
    for student in collection.find({"gender": "female", "course": "MCA"}):
        fname = student.get('name', {}).get('fname', '')
        lname = student.get('name', {}).get('lname', '')
        print(f"Name: {fname} {lname}, Marks: {student.get('mark', '')}")

    # 2. Student who scored the highest mark in MCA
    print('\n### 2. Topper in MCA')
    topper_cursor = collection.find({"course": "MCA"}).sort("mark", -1).limit(1)
    topper = next(topper_cursor, None)
    print_details(topper)

    # 3. All male students who secured A+
    print('\n### 3. Male students with grade A+')
    for student in collection.find({"gender": "male", "grade": "A+"}):
        print_details(student)

    # 4. Top 3 Students in Mechanical Department
    print('\n### 4. Top 3 Mechanical students')
    mech_toppers = collection.find({"course": "Mechanical"}).sort("mark", -1).limit(3)
    for student in mech_toppers:
        print_details(student)

    # 5. Female Students who have secured more than 90
    print('\n### 5. Female students with marks > 90')
    for student in collection.find({"gender": "female", "mark": {"$gt": 90}}):
        fname = student.get('name', {}).get('fname', '')
        lname = student.get('name', {}).get('lname', '')
        print(f"Name: {fname} {lname}")
        print(f"Grade: {student.get('grade', '')}, Mark: {student.get('mark', '')}")
        phone = student.get('phone', {})
        print(f"Contact: {phone.get('no', '')} ({phone.get('type', '')})")
        print('-' * 40)

    # 6. Students who scored marks in between 80 and 90
    print('\n### 6. Students with marks between 80 and 90')
    for student in collection.find({"mark": {"$gt": 80, "$lt": 90}}):
        print_details(student)

    # 7. Students whose name starts with 'V'
    print("\n### 7. Students whose first name starts with 'V'")
    for student in collection.find({"name.fname": {"$regex": "^V"}}):
        print_details(student)

    # 8. All students from Kollam
    print('\n### 8. Students from Kollam')
    for student in collection.find({"address.city": "Kollam"}):
        print_details(student)

    # 9. Students who do not belong to Kollam nor Thiruvananthapuram
    print('\n### 9. Students not from Kollam or Thiruvananthapuram')
    not_kollam_nor_tvm = collection.find({"address.city":  {"$nin": ["Thiruvananthapuram", "Kollam"]}})
    for student in not_kollam_nor_tvm:
        print_details(student)

    # 10. Female students who belong to either Kollam or Thiruvananthapuram
    print('\n### 10. Female students from Kollam or Thiruvananthapuram')
    kollam_or_tvm = collection.find({"gender": "female", "$or": [{"address.city": "Thiruvananthapuram"}, {"address.city": "Kollam"}]})
    for student in kollam_or_tvm:
        print_details(student)

    # Insertion: add a sample student with _id 26
    print('\n### Insertion: adding sample student with _id 26')
    student_doc = {'_id': 26, 'name': {'fname': 'John', 'lname': 'Doe'}, 'address': {'house_name': 'BS34X', 'city': 'Atlantis'}, 'gender': 'male', 'course': 'MCA', 'mark': 80, 'grade': 'A', 'phone': {'type': 'mobile', 'no': 8888888888}}
    try:
        collection.insert_one(student_doc)
        print('Inserted student with _id 26')
    except Exception as e:
        print(f'Insertion skipped/failure: {e}')

    print('\nInserted document:')
    print_details(collection.find_one({"_id": 26}))

    # Updation: update the inserted student's name
    print('\n### Updation: updating name for _id 26')
    query = {"_id": 26}
    newval = {"$set": {"name.fname": "Don", "name.lname": "Joe"}}
    collection.update_one(query, newval)
    print_details(collection.find_one({"_id": 26}))

    # Deletion: remove the sample student
    print('\n### Deletion: removing _id 26')
    collection.delete_one({"_id": 26})
    print('Deleted _id 26 (if existed)')


if __name__ == '__main__':
    main()
