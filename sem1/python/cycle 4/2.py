"""
Aim: Create a class Time with private attributes (hour, minute, second). 
     Overload the '+' operator to add two Time objects.
Course: Python Programming Lab (CET MCA)
"""

class Time:
    """Represents time and provides operator overloading for addition."""
    
    def __init__(self, hour=0, minute=0, second=0):
        self.__hour = hour
        self.__minute = minute
        self.__second = second

    def __add__(self, other):
        """Overloads the '+' operator to add two Time objects."""
        total_seconds = (self.__hour * 3600 + self.__minute * 60 + self.__second) + \
                        (other.__hour * 3600 + other.__minute * 60 + other.__second)

        # Normalize the time
        hours = (total_seconds // 3600) % 24
        minutes = (total_seconds % 3600) // 60
        seconds = total_seconds % 60

        return Time(hours, minutes, seconds)

    def __gt__(self, other):
        """Overloads the '>' operator for Time comparison."""
        return (self.__hour, self.__minute, self.__second) > \
               (other.__hour, other.__minute, other.__second)

    def __str__(self):
        """String representation of Time."""
        return f"{self.__hour:02d}:{self.__minute:02d}:{self.__second:02d}"

if __name__ == "__main__":
    print("--- Time Addition & Comparison ---")
    
    t1 = Time(10, 45, 30)
    t2 = Time(5, 20, 45)
    
    print(f"Time 1: {t1}")
    print(f"Time 2: {t2}")
    
    t3 = t1 + t2
    print(f"\nSum (t1 + t2)   : {t3}")
    
    print(f"Is t1 > t2?     : {'Yes' if t1 > t2 else 'No'}")
