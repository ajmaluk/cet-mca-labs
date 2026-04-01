"""
Aim: Write a Python program to find the area and perimeter of a circle.
Course: Python Programming Lab (CET MCA)
"""

import math

def calculate_circle_metrics(radius):
    """Calculates and prints area and perimeter given a radius."""
    area = math.pi * math.pow(radius, 2)
    perimeter = 2 * math.pi * radius
    
    print(f"\nResults for Circle with Radius {radius}:")
    print(f"Area      : {area:.2f} sq. units")
    print(f"Perimeter : {perimeter:.2f} units")

if __name__ == "__main__":
    print("--- Circle Geometry Calculator ---")
    try:
        r = float(input("Enter the radius of the circle: "))
        if r < 0:
            print("Radius cannot be negative.")
        else:
            calculate_circle_metrics(r)
    except ValueError:
        print("Invalid input! Please enter a numerical value.")
