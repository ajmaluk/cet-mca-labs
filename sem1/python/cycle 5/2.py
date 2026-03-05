"""
Aim: Read each row from a given CSV file and print it as a list of strings.
Course: Python Programming Lab (CET MCA)
"""

import csv
import os

def read_csv_as_list(filename):
    """Reads a CSV file and prints each row as a list."""
    if not os.path.exists(filename):
        print(f"File {filename} not found. Creating a sample...")
        with open(filename, 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(["ID", "Name", "Department"])
            writer.writerow(["101", "Ajmal", "MCA"])
            writer.writerow(["102", "Alok", "MBA"])

    print(f"\nReading {filename}:")
    with open(filename, mode='r') as f:
        reader = csv.reader(f)
        for row in reader:
            print(row)

if __name__ == "__main__":
    print("--- CSV Row Reader ---")
    read_csv_as_list("data.csv")
