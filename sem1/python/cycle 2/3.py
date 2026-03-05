"""
Aim: Write a Python program to count the frequency of each character in a given string.
Course: Python Programming Lab (CET MCA)
"""

def count_char_frequency(s):
    """Counts character frequency using a dictionary."""
    freq = {}
    for char in s:
        freq[char] = freq.get(char, 0) + 1
    return freq

if __name__ == "__main__":
    print("--- Character Frequency Counter ---")
    user_str = input("Enter a string: ")
    
    frequencies = count_char_frequency(user_str)
    print("\nCharacter Frequencies:")
    for char, count in sorted(frequencies.items()):
        # Escape spaces and tabs for better visibility
        display_char = f"'{char}'" if char != ' ' else "'Space'"
        print(f"{display_char} : {count}")
