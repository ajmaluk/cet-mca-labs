"""
Aim: Write a Python program to perform basic arithmetic operations.
Course: Python Programming Lab (CET MCA)
"""

def perform_operations(x, y):
    """Performs addition, subtraction, multiplication, and division."""
    print(f"\n--- Results for {x} and {y} ---")
    print(f"Addition       : {x + y}")
    print(f"Subtraction    : {x - y}")
    print(f"Multiplication : {x * y}")
    
    if y != 0:
        print(f"Division       : {x / y:.2f}")
        print(f"Modulus        : {x % y}")
    else:
        print("Division       : Error (Division by Zero)")

if __name__ == "__main__":
    print("--- Arithmetic Operator Tool ---")
    try:
        a = float(input("Enter first value: "))
        b = float(input("Enter second value: "))
        perform_operations(a, b)
    except ValueError:
        print("Numeric inputs required.")
