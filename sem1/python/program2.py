# program2.py
import datetime

print("<==== Leap Year Checker With In Range From Current Year2 ====>")

def printLeapYears(cYear, fYear):
    for year in range(cYear, fYear+1):
        if year % 400 == 0:
            print(year)
        elif year % 100 == 0:
            pass        
        elif year % 4 == 0:
            print(year)
        else:
            pass

cYear = datetime.date.today().year
fYear = int(input("Enter the Ending Year : "))
print(f"Range from {cYear} to {fYear}\n\n\n")
printLeapYears(cYear, fYear)