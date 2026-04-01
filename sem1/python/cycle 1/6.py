"""
Aim: Write a Python program to find the sum of first n even numbers.
Course: Python Programming Lab (CET MCA)
"""

def sum_of_even_numbers(n):
    """Calculates the sum of the first n even numbers (starting from 0 or 2)."""
    # Assuming first n even numbers are 2, 4, ..., 2n
    total = sum(i for i in range(2, (2 * n) + 1, 2))
    return total

if __name__ == "__main__":
    print("--- Sum of First N Even Numbers ---")
    try:
        n = int(input("Enter the value of n: "))
        if n < 0:
            print("Please enter a non-negative integer.")
        else:
            result = sum_of_even_numbers(n)
            print(f"The sum of the first {n} even numbers is: {result}")
    except ValueError:
        print("Invalid input! Please enter an integer.")
