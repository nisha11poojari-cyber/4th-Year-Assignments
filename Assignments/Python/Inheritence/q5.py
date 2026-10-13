
class Employee:
    def employee_details(self, emp_id, name):
        self.emp_id = emp_id
        self.name = name


class Designer(Employee):
    def designer_details(self, tool):
        self.tool = tool

    def display(self):
        print("\n--- Designer Details ---")
        print("Employee ID:", self.emp_id)
        print("Employee Name:", self.name)
        print("Design Tool:", self.tool)


class Developer(Employee):
    def developer_details(self, tool):
        self.tool = tool

    def display(self):
        print("\n--- Developer Details ---")
        print("Employee ID:", self.emp_id)
        print("Employee Name:", self.name)
        print("Development Tool:", self.tool)


# Main program
print("1. Designer")
print("2. Developer")

choice = int(input("Enter your choice: "))

emp_id = int(input("Enter Employee ID: "))
name = input("Enter Employee Name: ")

if choice == 1:
    tool = input("Enter Design Tool: ")
    d = Designer()
    d.employee_details(emp_id, name)
    d.designer_details(tool)
    d.display()

elif choice == 2:
    tool = input("Enter Development Tool: ")
    d = Developer()
    d.employee_details(emp_id, name)
    d.developer_details(tool)
    d.display()

else:
    print("Invalid choice!")
