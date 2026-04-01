"""
Aim: Demonstrate data visualization using Matplotlib.
Course: Python Programming Lab (CET MCA)
"""

try:
    import matplotlib.pyplot as plt
    import numpy as np
except ImportError:
    plt = None

def plot_trig_functions():
    print("--- Matplotlib Visualization ---")
    
    # Generate data
    x = np.linspace(0, 10, 100)
    y_sin = np.sin(x)
    y_cos = np.cos(x)

    # Create the plot
    plt.figure(figsize=(10, 6))
    plt.plot(x, y_sin, label='Sine Wave', color='blue', linestyle='--')
    plt.plot(x, y_cos, label='Cosine Wave', color='red', linewidth=2)

    # Add labels and styling
    plt.title('Sine and Cosine Functions')
    plt.xlabel('Time (s)')
    plt.ylabel('Amplitude')
    plt.legend()
    plt.grid(True)

    # Save the plot
    plt.savefig('trig_plot.png')
    print("Plot generated and saved as 'trig_plot.png'.")
    
    # plt.show() # Uncomment to see the window locally

if __name__ == "__main__":
    if plt:
        plot_trig_functions()
    else:
        print("Matplotlib/NumPy not installed. Try 'pip install matplotlib numpy'.")
