"""
Aim: Write a Python program to swap two numbers without using a third variable.
Course: Python Programming Lab (CET MCA)
"""

def swap_numbers(a, b):
    """Swaps two integers using arithmetic operations."""
    print(f"\nBefore Swapping: a = {a}, b = {b}")
    
    # Arithmetic swap logic
    a = a + b
    b = a - b
    a = a - b
    
    print(f"After Swapping : a = {a}, b = {b}")
    return a, b

if __name__ == "__main__":
    print("--- Variable Swapping (Without Temp) ---")
    try:
        val1 = int(input("Enter first integer (a): "))
        val2 = int(input("Enter second integer (b): "))
        swap_numbers(val1, val2)
    except ValueError:
        print("Please enter valid integers.")