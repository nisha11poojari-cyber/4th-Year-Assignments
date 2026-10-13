
class Academic:
    def academic_details(self, roll_no, marks):
        self.roll_no = roll_no
        self.marks = marks


class Sports:
    def sports_details(self, roll_no, marks):
        self.sports_roll_no = roll_no
        self.sports_marks = marks


class Student(Academic, Sports):
    def student_details(self, roll_no, name):
        self.roll_no = roll_no
        self.name = name

    def display(self):
        print("\n--- Student Details ---")
        print("Roll Number:", self.roll_no)
        print("Student Name:", self.name)
        print("Academic Marks:", self.marks)
        print("Sports Roll Number:", self.sports_roll_no)
        print("Sports Marks:", self.sports_marks)


# Main program
roll_no = int(input("Enter roll number: "))
name = input("Enter student name: ")
marks = float(input("Enter academic marks: "))
sports_roll_no = int(input("Enter sports roll number: "))
sports_marks = float(input("Enter sports marks: "))

s = Student()

s.academic_details(roll_no, marks)
s.sports_details(sports_roll_no, sports_marks)
s.student_details(roll_no, name)

s.display()
