"""
Aim: Write a Python program to read specific columns of a given CSV file 
     and print their content.
Course: Python Programming Lab (CET MCA)
"""

import csv
import os

def read_specific_columns(filename, columns):
    """Reads specific columns from a CSV using DictReader."""
    if not os.path.exists(filename):
        print(f"Source file {filename} missing.")
        return

    print(f"\nReading columns {columns} from {filename}:")
    try:
        with open(filename, mode='r') as f:
            reader = csv.DictReader(f)
            for row in reader:
                # Extract requested columns
                filtered_row = {col: row[col] for col in columns if col in row}
                print(filtered_row)
    except Exception as e:
        print(f"Error reading CSV: {e}")

if __name__ == "__main__":
    print("--- CSV Specific Column Reader ---")
    # Ensure data.csv exists with headers
    target_file = "data.csv"
    requested_cols = ["Name", "Department"]
    
    read_specific_columns(target_file, requested_cols)
