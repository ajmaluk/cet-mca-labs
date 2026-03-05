"""
Aim: Simple Turtle graphics demonstration.
Course: Python Programming Lab (CET MCA)
"""

import turtle

def draw_filled_square(size, color):
    """Draws a filled square using turtle."""
    turtle.fillcolor(color)
    turtle.begin_fill()
    for _ in range(4):
        turtle.forward(size)
        turtle.left(90)
    turtle.end_fill()

if __name__ == "__main__":
    print("Opening Turtle Graphics...")
    turtle.speed(2)
    draw_filled_square(100, "red")
    print("Done. Close the window to continue.")
    turtle.done()
