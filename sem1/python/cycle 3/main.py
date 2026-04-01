"""
Aim: Demonstrate Python packages and sub-packages.
Course: Python Programming Lab (CET MCA)
"""

from graphics import circle, rectangle, square
from graphics.graphics3d import cuboid, sphere

if __name__ == "__main__":
    print("--- Geometric Calculation Package Demo ---")
    
    # 2D Shapes
    print("\n[ 2D Shapes ]")
    print(f"Rectangle (10, 5)  : Area = {rectangle.area(10, 5)}, Perimeter = {rectangle.perimeter(10, 5)}")
    print(f"Circle (7)         : Area = {circle.area(7):.2f}, Perimeter = {circle.perimeter(7):.2f}")
    print(f"Square (4)         : Area = {square.area(4)}, Perimeter = {square.perimeter(4)}")
    
    # 3D Shapes (Subpackage)
    print("\n[ 3D Shapes (Subpackage) ]")
    print(f"Cuboid (10, 5, 2)  : Surface Area = {cuboid.area(10, 5, 2)}, Volume = {cuboid.volume(10, 5, 2)}")
    print(f"Sphere (7)         : Surface Area = {sphere.area(7):.2f}, Volume = {sphere.volume(7):.2f}")
