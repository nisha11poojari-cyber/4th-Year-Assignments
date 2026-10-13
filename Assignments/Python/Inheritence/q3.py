
class Student:
    def __init__(self, name):
        self.name = name


class Course:
    def __init__(self, course):
        self.course = course


class CourseStudent(Student, Course):
    def __init__(self, name, course):
        Student.__init__(self, name)
        Course.__init__(self, course)

    def enroll(self):
        print("\n--- Student Enrollment Details ---")
        print("Student Name:", self.name)
        print("Course Name:", self.course)
        print("Enrollment Successful!")


# Main program
name = input("Enter student name: ")
course = input("Enter course name: ")

s = CourseStudent(name, course)
s.enroll()
