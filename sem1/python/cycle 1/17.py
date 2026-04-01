"""
Aim: From a list of integers, create a new list after removing even numbers.
Course: Python Programming Lab (CET MCA)
"""

def remove_even_numbers(input_list):
    """Returns a new list containing only odd numbers (fixed removal-while-iterating bug)."""
    return [x for x in input_list if x % 2 != 0]

if __name__ == "__main__":
    print("--- Even Number Remover ---")
    original_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print(f"Original List: {original_list}")
    
    filtered_list = remove_even_numbers(original_list)
    print(f"Filtered List (Odd Only): {filtered_list}")