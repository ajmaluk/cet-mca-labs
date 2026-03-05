"""
Aim: Write a Python program to display leap years from the current year to a future year.
Course: Python Programming Lab (CET MCA)
"""

import datetime

def list_leap_years(start_year, end_year):
    """Prints all leap years between start_year and end_year inclusive."""
    leap_years = [y for y in range(start_year, end_year + 1) 
                  if (y % 400 == 0) or (y % 4 == 0 and y % 100 != 0)]
    
    if not leap_years:
        print(f"No leap years found between {start_year} and {end_year}.")
    else:
        print(f"Leap years in range: {leap_years}")

if __name__ == "__main__":
    print("--- Leap Year Range Finder ---")
    current_year = datetime.date.today().year
    try:
        future_year = int(input(f"Enter a future year (current is {current_year}): "))
        if future_year < current_year:
            print("Please enter a year in the future.")
        else:
            list_leap_years(current_year, future_year)
    except ValueError:
        print("Invalid input! Please enter a year.")
