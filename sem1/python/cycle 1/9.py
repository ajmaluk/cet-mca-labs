"""
Aim: Write a Python program to check whether a given year is a leap year.
Course: Python Programming Lab (CET MCA)
"""

def is_leap(year):
    """Determines if a year is a leap year based on Gregorian calendar rules."""
    if (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0):
        return True
    return False

if __name__ == "__main__":
    print("--- Leap Year Checker ---")
    try:
        yr = int(input("Enter the year to check: "))
        if is_leap(yr):
            print(f"YES, {yr} is a leap year.")
        else:
            print(f"NO, {yr} is not a leap year.")
    except ValueError:
        print("Invalid year format.")
