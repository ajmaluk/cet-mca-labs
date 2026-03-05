"""
Aim: Write a Python program to construct star patterns using nested loops.
Course: Python Programming Lab (CET MCA)
"""

def right_triangle(n):
    print("\n1. Right Angled Triangle:")
    for i in range(1, n + 1):
        print("* " * i)

def pyramid(n):
    print("\n2. Pyramid Pattern:")
    for i in range(1, n + 1):
        print(" " * (n - i) + "* " * i)

def inverted_pyramid(n):
    print("\n3. Inverted Pyramid:")
    for i in range(n, 0, -1):
        print(" " * (n - i) + "* " * i)

if __name__ == "__main__":
    print("--- Star Pattern Generator ---")
    try:
        rows = int(input("Enter number of rows: "))
        if rows > 0:
            right_triangle(rows)
            pyramid(rows)
            inverted_pyramid(rows)
        else:
            print("Please enter a positive integer.")
    except ValueError:
        print("Invalid input! Please enter an integer.")
