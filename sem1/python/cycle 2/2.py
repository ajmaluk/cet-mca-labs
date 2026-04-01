"""
Aim: Write a Python program to generate Fibonacci series of N terms.
Course: Python Programming Lab (CET MCA)
"""

def generate_fibonacci(n):
    """Generates and prints the Fibonacci series up to n terms."""
    if n <= 0:
        print("Please enter a positive integer.")
        return
    
    series = []
    a, b = 0, 1
    for _ in range(n):
        series.append(str(a))
        a, b = b, a + b
    
    print(f"Fibonacci series ({n} terms):")
    print(", ".join(series))

if __name__ == "__main__":
    print("--- Fibonacci Series Generator ---")
    try:
        count = int(input("Enter the number of terms: "))
        generate_fibonacci(count)
    except ValueError:
        print("Invalid input! Please enter an integer.")
