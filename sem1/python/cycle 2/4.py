"""
Aim: Write a Python program to add 'ing' at the end of a given string. 
     If it already ends with 'ing', add 'ly' instead.
Course: Python Programming Lab (CET MCA)
"""

def modify_string(s):
    """Appends 'ly' if ends with 'ing', otherwise appends 'ing'."""
    if len(s) < 3:
        return s + "ing"
    
    if s.endswith("ing"):
        return s + "ly"
    else:
        return s + "ing"

if __name__ == "__main__":
    print("--- String Suffix Modifier ---")
    user_input = input("Enter a word: ")
    print(f"Modified string: {modify_string(user_input)}")