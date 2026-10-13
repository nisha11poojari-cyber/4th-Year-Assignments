
import math

class Shape:
    def __init__(self, length):
        self.length = length

    def area(self):
        pass


class Square(Shape):
    def __init__(self, length):
        self.length = length

    def area(self):
        return self.length * self.length


class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius * self.radius


# Main program
length = float(input("Enter the side of square: "))
radius = float(input("Enter the radius of circle: "))

s = Square(length)
c = Circle(radius)

print("Area of Square:", s.area())
print("Area of Circle:", round(c.area(), 2))
