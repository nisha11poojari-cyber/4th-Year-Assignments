
class Student:
    def __init__(self, roll_no, name):
        self.roll_no = roll_no
        self.name = name

    def student_details(self):
        print("Roll Number:", self.roll_no)
        print("Student Name:", self.name)


class Test(Student):
    def get_marks(self):
        self.m1 = float(input("Enter marks for Subject 1: "))
        self.m2 = float(input("Enter marks for Subject 2: "))
        self.m3 = float(input("Enter marks for Subject 3: "))

    def set_marks(self):
        print("Marks saved successfully.")


class Marks(Test):
    def calculate_average(self):
        total = self.m1 + self.m2 + self.m3
        average = total / 3

        print("Subject 1 Marks:", self.m1)
        print("Subject 2 Marks:", self.m2)
        print("Subject 3 Marks:", self.m3)
        print("Total Marks:", total)
        print("Average Marks:", average)

        if average >= 75:
            print("Class: Distinction")
        elif average >= 60:
            print("Class: First Class")
        elif average >= 50:
            print("Class: Second Class")
        elif average >= 35:
            print("Class: Pass Class")
        else:
            print("Class: Fail")


# Main program
roll_no = int(input("Enter roll number: "))
name = input("Enter student name: ")

s = Marks(roll_no, name)

s.get_marks()
s.set_marks()

print("\n--- Student Details ---")
s.student_details()
s.calculate_average()
