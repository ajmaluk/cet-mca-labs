"""
Aim: Create a string from a given string where the first and last characters have been exchanged.
Course: Python Programming Lab (CET MCA)
"""

def exchange_first_last(s):
    """Exchanges the first and last characters of a string."""
    if len(s) <= 1:
        return s
    
    first = s[0]
    last = s[-1]
    middle = s[1:-1]
    
    return last + middle + first

if __name__ == "__main__":
    print("--- String Character Exchange ---")
    user_str = input("Enter a string: ")
    result = exchange_first_last(user_str)
    print(f"Original: {user_str}")
    print(f"Modified: {result}")