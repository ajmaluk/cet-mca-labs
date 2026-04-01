"""
Aim: Sort a dictionary in ascending and descending order based on values.
Course: Python Programming Lab (CET MCA)
"""

def sort_dict_by_value(d):
    """Sorts and displays dictionary by values in both orders."""
    print(f"Original Dictionary: {d}")
    
    # Sort Ascending
    asc = dict(sorted(d.items(), key=lambda item: item[1]))
    print(f"Ascending Order   : {asc}")
    
    # Sort Descending
    desc = dict(sorted(d.items(), key=lambda item: item[1], reverse=True))
    print(f"Descending Order  : {desc}")

if __name__ == "__main__":
    print("--- Dictionary Value Sorter ---")
    # Sample data
    sample_dict = {
        "Apple": 50,
        "Banana": 20,
        "Cherry": 80,
        "Date": 10
    }
    sort_dict_by_value(sample_dict)