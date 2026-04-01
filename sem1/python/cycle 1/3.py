"""
Aim: Write a Python program to find the largest among three numbers.
Course: Python Programming Lab (CET MCA)
"""

def find_largest(a, b, c):
    """Returns the largest among three values using nested conditionals."""
    if a >= b and a >= c:
        return a
    elif b >= c:
        return b
    else:
        return c

if __name__ == "__main__":
    print("--- Maximum Finding Utility ---")
    try:
        n1 = float(input("Enter first number: "))
        n2 = float(input("Enter second number: "))
        n3 = float(input("Enter third number: "))
        
        largest = find_largest(n1, n2, n3)
        print(f"\nThe largest number is: {largest}")
        
    except ValueError:
        print("Invalid input format.")
