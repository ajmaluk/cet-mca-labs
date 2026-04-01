"""
Sphere surface area and volume functions.
"""
import math

def area(radius):
    return 4 * math.pi * radius * radius

def volume(radius):
    return (4/3) * math.pi * (radius ** 3)
