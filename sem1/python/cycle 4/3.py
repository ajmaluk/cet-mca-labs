"""
Aim: Create a hierarchy of classes: Publisher -> Book -> Python. 
     Demonstrate constructor invocation and method overriding.
Course: Python Programming Lab (CET MCA)
"""

class Publisher:
    """Base class for publishers."""
    def __init__(self, name):
        self.name = name

    def display(self):
        print(f"Publisher Name: {self.name}")

class Book(Publisher):
    """Derived class for general books."""
    def __init__(self, name, title, author):
        super().__init__(name)
        self.title = title
        self.author = author

    def display(self):
        super().display()
        print(f"Book Title    : {self.title}")
        print(f"Author        : {self.author}")

class Python(Book):
    """Multi-level derived class for Python books."""
    def __init__(self, name, title, author, price, pages):
        super().__init__(name, title, author)
        self.price = price
        self.pages = pages

    def display(self):
        """Overrides display to show all details."""
        print("\n--- Book Details ---")
        super().display()
        print(f"Price         : ₹{self.price}")
        print(f"Pages         : {self.pages}")
        print("--------------------")

if __name__ == "__main__":
    print("--- Library Management Hierarchy ---")
    
    my_book = Python(
        name="O'Reilly",
        title="Fluent Python",
        author="Luciano Ramalho",
        price=3500,
        pages=700
    )
    
    my_book.display()