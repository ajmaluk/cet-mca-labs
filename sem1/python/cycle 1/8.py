"""
Aim: Write a Python program to find the number of digits in an integer.
Course: Python Programming Lab (CET MCA)
"""

def count_digits(number):
    """Counts digits by converting to string or using mathematical approach."""
    # handles absolute value to ignore sign
    return len(str(abs(number)))

if __name__ == "__main__":
    print("--- Digit Counter ---")
    try:
        num = int(input("Enter an integer: "))
        print(f"Number of digits in {num} is: {count_digits(num)}")
    except ValueError:
        print("Please enter a valid integer.")
