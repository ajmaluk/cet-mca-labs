"""
Aim: Write a Python dictionary to a CSV file. After writing, read the CSV 
     and display its content.
Course: Python Programming Lab (CET MCA)
"""

import csv

def save_dict_to_csv(filename, data_list):
    """Writes a list of dictionaries to a CSV file."""
    if not data_list:
        return

    # Extract headers from keys of the first dictionary
    headers = data_list[0].keys()

    with open(filename, mode='w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=headers)
        writer.writeheader()
        writer.writerows(data_list)
    print(f"Data successfully written to {filename}")

def read_and_display_csv(filename):
    """Reads CSV and displays content."""
    print(f"\nVerifying content of {filename}:")
    with open(filename, mode='r') as f:
        reader = csv.DictReader(f)
        for row in reader:
            print(dict(row))

if __name__ == "__main__":
    print("--- Dictionary to CSV Tool ---")
    
    students = [
        {"ID": "S01", "Name": "Ajmal", "Grade": "A"},
        {"ID": "S02", "Name": "Alok", "Grade": "B"},
        {"ID": "S03", "Name": "Sreya", "Grade": "A+"}
    ]
    
    file_name = "students.csv"
    save_dict_to_csv(file_name, students)
    read_and_display_csv(file_name)
