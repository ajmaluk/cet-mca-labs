"""
Aim: Create a BankAccount class with attributes like owner and balance, 
     and methods for deposit, withdrawal, and balance display.
Course: Python Programming Lab (CET MCA)
"""

class BankAccount:
    """Represents a simple bank account with basic transactions."""
    
    def __init__(self, owner, balance=0.0):
        self.owner = owner
        self.balance = float(balance)

    def deposit(self, amount):
        """Adds funds to the account."""
        if amount > 0:
            self.balance += amount
            print(f"Deposited: ₹{amount:.2f}. New Balance: ₹{self.balance:.2f}")
        else:
            print("Deposit amount must be positive.")
    
    def withdraw(self, amount):
        """Subtracts funds if balance is sufficient."""
        if amount > self.balance:
            print(f"Withdrawal of ₹{amount:.2f} failed: Insufficient Balance (Available: ₹{self.balance:.2f})")
        elif amount <= 0:
            print("Withdrawal amount must be positive.")
        else:
            self.balance -= amount
            print(f"Withdrew: ₹{amount:.2f}. New Balance: ₹{self.balance:.2f}")

    def display(self):
        """Prints account status."""
        print(f"Account Home: {self.owner:10} | Current Balance: ₹{self.balance:,.2f}")

if __name__ == "__main__":
    print("--- Bank Account Management System ---")
    
    # Initialize some accounts
    acc1 = BankAccount("Ajmal", 1000)
    acc2 = BankAccount("Amar", 200)
    
    print("\nInitial State:")
    acc1.display()
    acc2.display()
    
    print("\nTransactions:")
    acc1.deposit(5000)
    acc2.withdraw(500)  # Should fail
    acc2.withdraw(50)   # Should succeed
    
    print("\nFinal State:")
    acc1.display()
    acc2.display()
