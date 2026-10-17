
#include <stdio.h>

// Structure declaration
struct Student {
    int rollNo;
    float marks;
    char grade;
};

// Union declaration
union StudentData {
    int rollNo;
    float marks;
    char grade;
};

int main() {
    // Structure variable
    struct Student s;

    s.rollNo = 101;
    s.marks = 89.5;
    s.grade = 'A';

    printf("STRUCTURE:\n");
    printf("Roll Number = %d\n", s.rollNo);
    printf("Marks = %.2f\n", s.marks);
    printf("Grade = %c\n", s.grade);

    // Union variable
    union StudentData u;

    printf("\nUNION:\n");

    u.rollNo = 101;
    printf("Roll Number = %d\n", u.rollNo);

    u.marks = 89.5;
    printf("Marks = %.2f\n", u.marks);

    u.grade = 'A';
    printf("Grade = %c\n", u.grade);

    printf("\nSize of structure = %zu bytes\n", sizeof(s));
    printf("Size of union = %zu bytes\n", sizeof(u));

    return 0;
}
