
import sqlite3

con = sqlite3.connect("LibraryManagement.db")
cur = con.cursor()

# Create tables
def create_tables():
    cur.execute("""
        CREATE TABLE IF NOT EXISTS Member (
            MemberId INTEGER PRIMARY KEY,
            MName TEXT NOT NULL,
            Email TEXT,
            Address TEXT,
            PhoneNo TEXT,
            MembershipDate TEXT,
            ExpiryDate TEXT
        )
    """)

    cur.execute("""
        CREATE TABLE IF NOT EXISTS Book (
            BookId INTEGER PRIMARY KEY,
            BookName TEXT NOT NULL,
            AuthorName TEXT,
            PublicationYear INTEGER,
            Price REAL
        )
    """)

    cur.execute("""
        CREATE TABLE IF NOT EXISTS Transactions (
            TransactionId INTEGER PRIMARY KEY,
            BookId INTEGER,
            MemberID INTEGER,
            IssueDate TEXT,
            DueDate TEXT,
            ReturnDate TEXT,
            FinalAmount REAL,
            Status TEXT CHECK (
                Status IN ('Issued', 'Returned', 'Overdue', 'Reserved')
            ),
            FOREIGN KEY (BookId) REFERENCES Book(BookId),
            FOREIGN KEY (MemberID) REFERENCES Member(MemberId)
        )
    """)

    con.commit()
    print("Tables created successfully.")


# MEMBER CRUD OPERATIONS

def add_member():
    mid = int(input("Enter Member ID: "))
    name = input("Enter member name: ")
    email = input("Enter email: ")
    address = input("Enter address: ")
    phone = input("Enter phone number: ")
    mdate = input("Enter membership date (YYYY-MM-DD): ")
    edate = input("Enter expiry date (YYYY-MM-DD): ")

    cur.execute("""
        INSERT INTO Member
        VALUES (?, ?, ?, ?, ?, ?, ?)
    """, (mid, name, email, address, phone, mdate, edate))

    con.commit()
    print("Member added successfully.")


def view_members():
    cur.execute("SELECT * FROM Member")
    for row in cur.fetchall():
        print(row)


def update_member():
    mid = int(input("Enter Member ID to update: "))
    name = input("Enter new name: ")
    email = input("Enter new email: ")
    address = input("Enter new address: ")
    phone = input("Enter new phone: ")
    mdate = input("Enter membership date (YYYY-MM-DD): ")
    edate = input("Enter expiry date (YYYY-MM-DD): ")

    cur.execute("""
        UPDATE Member
        SET MName=?, Email=?, Address=?, PhoneNo=?,
            MembershipDate=?, ExpiryDate=?
        WHERE MemberId=?
    """, (name, email, address, phone, mdate, edate, mid))

    con.commit()
    print("Member updated." if cur.rowcount else "Member not found.")


def delete_member():
    mid = int(input("Enter Member ID to delete: "))

    cur.execute("DELETE FROM Member WHERE MemberId=?", (mid,))
    con.commit()

    print("Member deleted." if cur.rowcount else "Member not found.")


# BOOK CRUD OPERATIONS

def add_book():
    bid = int(input("Enter Book ID: "))
    name = input("Enter book name: ")
    author = input("Enter author name: ")
    year = int(input("Enter publication year: "))
    price = float(input("Enter price: "))

    cur.execute("""
        INSERT INTO Book VALUES (?, ?, ?, ?, ?)
    """, (bid, name, author, year, price))

    con.commit()
    print("Book added successfully.")


def view_books():
    cur.execute("SELECT * FROM Book")
    for row in cur.fetchall():
        print(row)


def update_book():
    bid = int(input("Enter Book ID to update: "))
    name = input("Enter new book name: ")
    author = input("Enter new author name: ")
    year = int(input("Enter new publication year: "))
    price = float(input("Enter new price: "))

    cur.execute("""
        UPDATE Book
        SET BookName=?, AuthorName=?, PublicationYear=?, Price=?
        WHERE BookId=?
    """, (name, author, year, price, bid))

    con.commit()
    print("Book updated." if cur.rowcount else "Book not found.")


def delete_book():
    bid = int(input("Enter Book ID to delete: "))

    cur.execute("DELETE FROM Book WHERE BookId=?", (bid,))
    con.commit()

    print("Book deleted." if cur.rowcount else "Book not found.")


# TRANSACTION CRUD OPERATIONS

def add_transaction():
    tid = int(input("Enter Transaction ID: "))
    bid = int(input("Enter Book ID: "))
    mid = int(input("Enter Member ID: "))
    issue = input("Enter issue date (YYYY-MM-DD): ")
    due = input("Enter due date (YYYY-MM-DD): ")
    returned = input("Enter return date (YYYY-MM-DD or blank): ")
    amount = float(input("Enter final amount: "))

    print("1. Issued  2. Returned  3. Overdue  4. Reserved")
    choice = input("Choose status: ")

    statuses = {
        "1": "Issued",
        "2": "Returned",
        "3": "Overdue",
        "4": "Reserved"
    }

    if choice not in statuses:
        print("Invalid status.")
        return

    returned = returned if returned else None

    cur.execute("""
        INSERT INTO Transactions
        VALUES (?, ?, ?, ?, ?, ?, ?, ?)
    """, (tid, bid, mid, issue, due, returned, amount,
          statuses[choice]))

    con.commit()
    print("Transaction added successfully.")


def view_transactions():
    cur.execute("SELECT * FROM Transactions")
    for row in cur.fetchall():
        print(row)


def update_transaction():
    tid = int(input("Enter Transaction ID to update: "))
    returned = input("Enter return date (YYYY-MM-DD or blank): ")
    amount = float(input("Enter final amount: "))

    print("1. Issued  2. Returned  3. Overdue  4. Reserved")
    choice = input("Choose status: ")

    statuses = {
        "1": "Issued",
        "2": "Returned",
        "3": "Overdue",
        "4": "Reserved"
    }

    if choice not in statuses:
        print("Invalid status.")
        return

    returned = returned if returned else None

    cur.execute("""
        UPDATE Transactions
        SET ReturnDate=?, FinalAmount=?, Status=?
        WHERE TransactionId=?
    """, (returned, amount, statuses[choice], tid))

    con.commit()
    print("Transaction updated." if cur.rowcount else
          "Transaction not found.")


def delete_transaction():
    tid = int(input("Enter Transaction ID to delete: "))

    cur.execute("""
        DELETE FROM Transactions WHERE TransactionId=?
    """, (tid,))

    con.commit()
    print("Transaction deleted." if cur.rowcount else
          "Transaction not found.")


# MAIN MENU

create_tables()

while True:
    print("\n===== LIBRARY MANAGEMENT SYSTEM =====")
    print("1. Add Member")
    print("2. View Members")
    print("3. Update Member")
    print("4. Delete Member")
    print("5. Add Book")
    print("6. View Books")
    print("7. Update Book")
    print("8. Delete Book")
    print("9. Add Transaction")
    print("10. View Transactions")
    print("11. Update Transaction")
    print("12. Delete Transaction")
    print("13. Exit")

    choice = input("Enter your choice: ")

    try:
        if choice == "1":
            add_member()
        elif choice == "2":
            view_members()
        elif choice == "3":
            update_member()
        elif choice == "4":
            delete_member()
        elif choice == "5":
            add_book()
        elif choice == "6":
            view_books()
        elif choice == "7":
            update_book()
        elif choice == "8":
            delete_book()
        elif choice == "9":
            add_transaction()
        elif choice == "10":
            view_transactions()
        elif choice == "11":
            update_transaction()
        elif choice == "12":
            delete_transaction()
        elif choice == "13":
            print("Thank you for using Library Management.")
            break
        else:
            print("Invalid choice. Try again.")

    except sqlite3.IntegrityError as e:
        con.rollback()
        print("Database error:", e)
    except (ValueError, sqlite3.Error) as e:
        con.rollback()
        print("Error:", e)

con.close()
