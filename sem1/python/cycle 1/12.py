"""
Aim: Create a list of colors from comma-separated color names entered by user. Display the first and last colors.
Course: Python Programming Lab (CET MCA)
"""

def process_colors(color_string):
    """Splits color string and prints first/last elements."""
    # Split and strip whitespace from each color
    color_list = [c.strip() for c in color_string.split(',') if c.strip()]
    
    if not color_list:
        print("No valid colors were entered.")
        return

    print(f"\nTotal colors identified: {len(color_list)}")
    print(f"First color: {color_list[0]}")
    print(f"Last color : {color_list[-1]}")

if __name__ == "__main__":
    print("--- Color List Processor ---")
    raw_input = input("Enter color names (comma-separated): ")
    process_colors(raw_input)
