"""
Aim: Merge two Python dictionaries.
Course: Python Programming Lab (CET MCA)
"""

def merge_dictionaries(d1, d2):
    """Merges two dictionaries using the unpack operator (Python 3.5+)."""
    merged = {**d1, **d2}
    return merged

if __name__ == "__main__":
    print("--- Dictionary Merger ---")
    dict_a = {"id": 101, "name": "Ajmal", "course": "MCA"}
    dict_b = {"sem": 1, "mca_lab": "Python"}
    
    print(f"Dict 1: {dict_a}")
    print(f"Dict 2: {dict_b}")
    
    result = merge_dictionaries(dict_a, dict_b)
    print(f"Merged Result: {result}")