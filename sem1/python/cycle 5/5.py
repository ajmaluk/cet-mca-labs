"""
Aim: Demonstrate basic NumPy operations (Array creation, indexing, and math).
Course: Python Programming Lab (CET MCA)
"""

import numpy as np

def numpy_demo():
    print("--- NumPy Basic Operations ---")
    
    # 1. Create a 1D Array
    arr1 = np.array([1, 2, 3, 4, 5])
    print(f"1D Array: {arr1}")
    
    # 2. Create a 2D Array
    matrix = np.array([[1, 2], [3, 4]])
    print(f"2D Matrix:\n{matrix}")
    
    # 3. Basic Arithmetic
    print(f"\nArray + 10: {arr1 + 10}")
    print(f"Matrix Square:\n{np.square(matrix)}")
    
    # 4. Statistical Operations
    print(f"\nMean of arr1: {np.mean(arr1)}")
    print(f"Sum of matrix elements: {np.sum(matrix)}")

if __name__ == "__main__":
    try:
        numpy_demo()
    except ImportError:
        print("NumPy is not installed. Use 'pip install numpy' to run this experiment.")
