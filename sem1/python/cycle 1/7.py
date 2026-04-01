"""
Aim: Write a Python program to find the factorial of a number.
Course: Python Programming Lab (CET MCA)
"""

import math

def get_factorial(num):
    """Computes factorial using the math library."""
    if num < 0:
        return "Not defined for negative numbers."
    return math.factorial(num)

if __name__ == "__main__":
    print("--- Factorial Calculator ---")
    try:
        user_input = int(input("Enter a number: "))
        result = get_factorial(user_input)
        print(f"Factorial of {user_input} is: {result}")
    except ValueError:
        print("Invalid input! Please enter an integer.")