
from abc import ABC, abstractmethod
import math

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass


class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius * self.radius


class Triangle(Shape):
    def __init__(self, base, height):
        self.base = base
        self.height = height

    def area(self):
        return 0.5 * self.base * self.height


# Main program
radius = float(input("Enter radius of circle: "))
c = Circle(radius)
print("Area of Circle:", round(c.area(), 2))

base = float(input("\nEnter base of triangle: "))
height = float(input("Enter height of triangle: "))
t = Triangle(base, height)
print("Area of Triangle:", t.area())
