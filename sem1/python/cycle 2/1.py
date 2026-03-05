"""
Aim: Write a Python program to find the factorial of a number using recursion.
Course: Python Programming Lab (CET MCA)
"""

def factorial_recursive(n):
    """Computes factorial using recursion."""
    if n == 0 or n == 1:
        return 1
    return n * factorial_recursive(n - 1)

if __name__ == "__main__":
    print("--- Recursive Factorial ---")
    try:
        num = int(input("Enter a non-negative integer: "))
        if num < 0:
            print("Factorial is not defined for negative numbers.")
        else:
            print(f"Factorial of {num} is: {factorial_recursive(num)}")
    except ValueError:
        print("Invalid input! Please enter an integer.")