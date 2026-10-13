
import sqlite3

# Connect to database
con = sqlite3.connect("CustomerManagement.db")
cur = con.cursor()


# 1. Create customer table
def create_table():
    cur.execute("""
        CREATE TABLE IF NOT EXISTS Customer (
            CustomerId INTEGER PRIMARY KEY,
            Name TEXT NOT NULL,
            Address TEXT,
            contact TEXT,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL
        )
    """)
    con.commit()
    print("Customer table created successfully.")


# 2. Add customer details
def add_customer():
    cid = int(input("Enter Customer ID: "))
    name = input("Enter customer name: ")
    address = input("Enter address: ")
    contact = input("Enter contact number: ")
    username = input("Enter username: ")
    password = input("Enter password: ")

    cur.execute("""
        INSERT INTO Customer
        VALUES (?, ?, ?, ?, ?, ?)
    """, (cid, name, address, contact, username, password))

    con.commit()
    print("Customer added successfully.")


# 3. Update customer details
def update_customer():
    cid = int(input("Enter Customer ID to update: "))

    name = input("Enter new name: ")
    address = input("Enter new address: ")
    contact = input("Enter new contact number: ")
    username = input("Enter new username: ")
    password = input("Enter new password: ")

    cur.execute("""
        UPDATE Customer
        SET Name = ?, Address = ?, contact = ?,
            username = ?, password = ?
        WHERE CustomerId = ?
    """, (name, address, contact, username, password, cid))

    con.commit()

    if cur.rowcount > 0:
        print("Customer details updated successfully.")
    else:
        print("Customer ID not found.")


# 4. Display all customers
def display_customers():
    cur.execute("""
        SELECT CustomerId, Name, Address, contact, username
        FROM Customer
    """)

    records = cur.fetchall()

    if records:
        for row in records:
            print(row)
    else:
        print("No customer records found.")


# 5. Search customer by ID
def search_customer():
    cid = int(input("Enter Customer ID to search: "))

    cur.execute("""
        SELECT CustomerId, Name, Address, contact, username
        FROM Customer
        WHERE CustomerId = ?
    """, (cid,))

    record = cur.fetchone()

    if record:
        print("Customer details:", record)
    else:
        print("Customer not found.")


# Main menu
create_table()

while True:
    print("\n===== CUSTOMER MANAGEMENT SYSTEM =====")
    print("1. Add Customer")
    print("2. Update Customer")
    print("3. Display All Customers")
    print("4. Search Customer")
    print("5. Exit")

    choice = input("Enter your choice: ")

    try:
        if choice == "1":
            add_customer()
        elif choice == "2":
            update_customer()
        elif choice == "3":
            display_customers()
        elif choice == "4":
            search_customer()
        elif choice == "5":
            print("Exiting Customer Management System.")
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
