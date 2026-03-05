"""
Aim: Write a Python program to copy all odd lines of one file to another.
Course: Python Programming Lab (CET MCA)
"""

def copy_odd_lines(source, destination):
    """Reads source file and writes odd-numbered lines to destination."""
    try:
        with open(source, 'r') as f_src:
            lines = f_src.readlines()
        
        # In programming, lines are usually treated as 0-indexed.
        # Human-readable "odd lines" (1, 3, 5) correspond to indices 0, 2, 4.
        odd_lines = [line for idx, line in enumerate(lines) if idx % 2 == 0]
        
        with open(destination, 'w') as f_dest:
            f_dest.writelines(odd_lines)
            
        print(f"Successfully copied {len(odd_lines)} lines to {destination}.")
        
    except FileNotFoundError:
        print(f"Error: Source file '{source}' not found.")

if __name__ == "__main__":
    print("--- Odd Line File Copier ---")
    
    # Create a sample file for demonstration
    sample_content = (
        "Line 1: This is an odd line.\n"
        "Line 2: This is an even line.\n"
        "Line 3: Another odd line.\n"
        "Line 4: Another even line.\n"
    )
    
    with open("input.txt", "w") as f:
        f.write(sample_content)
    
    copy_odd_lines("input.txt", "output.txt")
    
    # Verify the output
    print("\nContent of output.txt:")
    with open("output.txt", "r") as f:
        print(f.read())
