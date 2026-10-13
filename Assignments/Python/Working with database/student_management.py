
import sqlite3

# Connect to database
con = sqlite3.connect("StudentManagement.db")
cur = con.cursor()


# 1. Create student table
def create_table():
    cur.execute("""
        CREATE TABLE IF NOT EXISTS Student (
            StudentID INTEGER PRIMARY KEY,
            name TEXT NOT NULL,
            dob TEXT,
            contact_details TEXT,
            status TEXT CHECK (
                status IN ('admitted', 'cancelled', 'InProgress')
            )
        )
    """)
    con.commit()
    print("Student table created successfully.")


# Function to select student status
def get_status():
    print("1. admitted")
    print("2. cancelled")
    print("3. InProgress")

    choice = input("Select status: ")

    statuses = {
        "1": "admitted",
        "2": "cancelled",
        "3": "InProgress"
    }

    return statuses.get(choice)


# 2. Add student record
def add_student():
    sid = int(input("Enter Student ID: "))
    name = input("Enter student name: ")
    dob = input("Enter date of birth (YYYY-MM-DD): ")
    contact = input("Enter contact details: ")
    status = get_status()

    if status is None:
        print("Invalid status.")
        return

    cur.execute("""
        INSERT INTO Student
        VALUES (?, ?, ?, ?, ?)
    """, (sid, name, dob, contact, status))

    con.commit()
    print("Student added successfully.")


# 3. Update student record
def update_student():
    sid = int(input("Enter Student ID to update: "))

    name = input("Enter new student name: ")
    dob = input("Enter new date of birth (YYYY-MM-DD): ")
    contact = input("Enter new contact details: ")
    status = get_status()

    if status is None:
        print("Invalid status.")
        return

    cur.execute("""
        UPDATE Student
        SET name = ?, dob = ?, contact_details = ?, status = ?
        WHERE StudentID = ?
    """, (name, dob, contact, status, sid))

    con.commit()

    if cur.rowcount > 0:
        print("Student updated successfully.")
    else:
        print("Student ID not found.")


# 4. Search student by name
def search_student():
    name = input("Enter student name to search: ")

    cur.execute("""
        SELECT * FROM Student
        WHERE name LIKE ?
    """, ('%' + name + '%',))

    records = cur.fetchall()

    if records:
        print("\nStudent Records:")
        for row in records:
            print(row)
    else:
        print("No student found.")


# Display all students
def display_students():
    cur.execute("SELECT * FROM Student")
    records = cur.fetchall()

    if records:
        for row in records:
            print(row)
    else:
        print("No student records available.")


# Main menu
create_table()

while True:
    print("\n===== STUDENT MANAGEMENT SYSTEM =====")
    print("1. Add Student")
    print("2. Update Student")
    print("3. Search Student by Name")
    print("4. Display All Students")
    print("5. Exit")

    choice = input("Enter your choice: ")

    try:
        if choice == "1":
            add_student()
        elif choice == "2":
            update_student()
        elif choice == "3":
            search_student()
        elif choice == "4":
            display_students()
        elif choice == "5":
            print("Exiting Student Management System.")
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
