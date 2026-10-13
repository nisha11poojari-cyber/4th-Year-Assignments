
import sqlite3

# Connect to the database
con = sqlite3.connect("HospitalManagement.db")
cur = con.cursor()


# 1. Create database tables
def create_tables():
    cur.execute("""
        CREATE TABLE IF NOT EXISTS hospital (
            hospital_id INTEGER PRIMARY KEY,
            hospital_name VARCHAR(255) NOT NULL,
            address VARCHAR(255) NOT NULL,
            city VARCHAR(100),
            established_year INTEGER
        )
    """)

    cur.execute("""
        CREATE TABLE IF NOT EXISTS doctor (
            doctor_id INTEGER PRIMARY KEY,
            name VARCHAR(255) NOT NULL,
            specialization VARCHAR(100),
            phone VARCHAR(15),
            email VARCHAR(100),
            experience INTEGER,
            hospital_id INTEGER,
            salary REAL,
            FOREIGN KEY (hospital_id)
                REFERENCES hospital(hospital_id)
        )
    """)

    con.commit()
    print("Tables created successfully.")


# Insert sample data
def insert_sample_data():
    cur.execute("SELECT COUNT(*) FROM hospital")
    if cur.fetchone()[0] == 0:
        cur.executemany("""
            INSERT INTO hospital VALUES (?, ?, ?, ?, ?)
        """, [
            (1, "City Hospital", "FC Road", "Pune", 1995),
            (2, "LifeCare Hospital", "Baner Road", "Pune", 2005),
            (3, "Sunrise Hospital", "MG Road", "Mumbai", 2010)
        ])

    cur.execute("SELECT COUNT(*) FROM doctor")
    if cur.fetchone()[0] == 0:
        cur.executemany("""
            INSERT INTO doctor VALUES (?, ?, ?, ?, ?, ?, ?, ?)
        """, [
            (101, "Amit Sharma", "Cardiology",
             "9876543210", "amit@gmail.com", 10, 1, 120000),
            (102, "Priya Patil", "Neurology",
             "9876543211", "priya@gmail.com", 7, 1, 90000),
            (103, "Rahul Desai", "Cardiology",
             "9876543212", "rahul@gmail.com", 5, 2, 80000),
            (104, "Sneha Kulkarni", "Pediatrics",
             "9876543213", "sneha@gmail.com", 8, 3, 95000)
        ])

    con.commit()


# 2. Read a hospital by hospital name
def get_hospital(hospital_name):
    cur.execute("""
        SELECT * FROM hospital
        WHERE hospital_name = ?
    """, (hospital_name,))

    records = cur.fetchall()
    if records:
        for row in records:
            print(row)
    else:
        print("Hospital not found.")


# 2. Read a doctor by doctor name
def get_doctor(doctor_name):
    cur.execute("""
        SELECT * FROM doctor
        WHERE name = ?
    """, (doctor_name,))

    records = cur.fetchall()
    if records:
        for row in records:
            print(row)
    else:
        print("Doctor not found.")


# 3. Doctors with matching specialization and salary
def get_specialist_doctors_list(specialization, salary):
    cur.execute("""
        SELECT * FROM doctor
        WHERE specialization = ? AND salary > ?
    """, (specialization, salary))

    records = cur.fetchall()
    if records:
        for row in records:
            print(row)
    else:
        print("No matching doctors found.")


# 4. Get doctors working at a given hospital
def get_doctors_by_hospital(hospital_name):
    cur.execute("""
        SELECT d.*
        FROM doctor d
        JOIN hospital h
        ON d.hospital_id = h.hospital_id
        WHERE h.hospital_name = ?
    """, (hospital_name,))

    records = cur.fetchall()
    if records:
        for row in records:
            print(row)
    else:
        print("No doctors found for this hospital.")


# 5. Update doctor experience using doctor ID
def update_doctor_experience(doctor_id, experience):
    cur.execute("""
        UPDATE doctor
        SET experience = ?
        WHERE doctor_id = ?
    """, (experience, doctor_id))

    con.commit()

    if cur.rowcount > 0:
        print("Doctor experience updated successfully.")
    else:
        print("Doctor ID not found.")


# Main program
create_tables()
insert_sample_data()

while True:
    print("\n===== HOSPITAL MANAGEMENT =====")
    print("1. Read hospital details")
    print("2. Read doctor details")
    print("3. Find specialist doctors by salary")
    print("4. List doctors by hospital")
    print("5. Update doctor experience")
    print("6. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        name = input("Enter hospital name: ")
        get_hospital(name)

    elif choice == "2":
        name = input("Enter doctor name: ")
        get_doctor(name)

    elif choice == "3":
        specialization = input("Enter specialization: ")
        salary = float(input("Enter minimum salary: "))
        get_specialist_doctors_list(specialization, salary)

    elif choice == "4":
        name = input("Enter hospital name: ")
        get_doctors_by_hospital(name)

    elif choice == "5":
        doctor_id = int(input("Enter doctor ID: "))
        experience = int(input("Enter updated experience: "))
        update_doctor_experience(doctor_id, experience)

    elif choice == "6":
        print("Exiting Hospital Management.")
        break

    else:
        print("Invalid choice. Try again.")

con.close()
