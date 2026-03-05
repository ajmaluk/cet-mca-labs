"""
Aim: Write a Python program to display first n multiples of a given number.
Course: Python Programming Lab (CET MCA)
"""

def display_multiples(base, count):
    """Displays the multiplication table for base up to count."""
    print(f"\n--- Multiplication Table for {base} ---")
    for i in range(1, count + 1):
        print(f"{i:2} x {base} = {i * base}")

if __name__ == "__main__":
    print("--- Multiple Generator ---")
    try:
        num = int(input("Enter the base number: "))
        n = int(input("How many multiples to display? "))
        
        if n > 0:
            display_multiples(num, n)
        else:
            print("Range must be greater than zero.")
            
    except ValueError:
        print("Please enter valid integers.")