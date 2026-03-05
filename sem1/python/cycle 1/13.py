"""
Aim: Create a single string from two given strings, separated by a space and swapping the first characters of each string.
Course: Python Programming Lab (CET MCA)
"""

def swap_first_chars(s1, s2):
    """Swaps the first characters of two strings and joins them."""
    if len(s1) < 1 or len(s2) < 1:
        return s1 + " " + s2

    new_s1 = s2[0] + s1[1:]
    new_s2 = s1[0] + s2[1:]
    
    return f"{new_s1} {new_s2}"

if __name__ == "__main__":
    print("--- String First Char Swapper ---")
    str1 = input("Enter first string: ")
    str2 = input("Enter second string: ")
    
    result = swap_first_chars(str1, str2)
    print(f"Result: {result}")