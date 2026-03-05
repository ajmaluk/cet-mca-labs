"""
Aim: Write a Python program to find the Greatest Common Divisor (GCD) of two numbers.
Course: Python Programming Lab (CET MCA)
"""

import math

def calculate_gcd(a, b):
    """Calculates GCD using the Euclidean algorithm via math.gcd."""
    return math.gcd(a, b)

if __name__ == "__main__":
    print("--- GCD Calculator ---")
    try:
        n1 = int(input("Enter first number: "))
        n2 = int(input("Enter second number: "))
        print(f"Greatest Common Divisor of {n1} and {n2} is: {calculate_gcd(n1, n2)}")
    except ValueError:
        print("Please enter valid integers.")
