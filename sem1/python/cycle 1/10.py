"""
Aim: Write a Python program to find the roots of a quadratic equation.
Course: Python Programming Lab (CET MCA)
"""

import cmath # Using cmath to handle complex roots automatically

def solve_quadratic(a, b, c):
    """Solves ax^2 + bx + c = 0 and prints the roots."""
    if a == 0:
        print("Coefficient 'a' cannot be zero for a quadratic equation.")
        return

    # Calculate the discriminant
    d = (b**2) - (4*a*c)

    # find two solutions
    sol1 = (-b - cmath.sqrt(d)) / (2*a)
    sol2 = (-b + cmath.sqrt(d)) / (2*a)

    print(f"\nResults for: {a}x^2 + {b}x + {c} = 0")
    if d > 0:
        print(f"The roots are real and distinct: {sol1.real:.2f} and {sol2.real:.2f}")
    elif d == 0:
        print(f"The roots are real and equal: {sol1.real:.2f}")
    else:
        print(f"The roots are complex: {sol1:.2f} and {sol2:.2f}")

if __name__ == "__main__":
    print("--- Quadratic Equation Solver ---")
    try:
        coeff_a = float(input("Enter coefficient a (x^2): "))
        coeff_b = float(input("Enter coefficient b (x): "))
        coeff_c = float(input("Enter constant c: "))
        solve_quadratic(coeff_a, coeff_b, coeff_c)
    except ValueError:
        print("Inputs must be numbers.")
