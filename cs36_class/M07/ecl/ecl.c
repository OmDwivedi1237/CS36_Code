#include <stdio.h>

struct Student {
    int studentID;
    char name[50];
    int age;
    double GPA;
};

void inputStudent(struct Student* s);
void displayStudent(const struct Student* s);
double averageGPA(const struct Student students[], int size);
const struct Student* oldestStudent(const struct Student students[], int size);

int main() {
    struct Student classOfStudents[4];

    for (int i = 0; i < 4; ++i) {
        printf("\nEnter data for Student %d:\n", i + 1);
        inputStudent(&classOfStudents[i]);
    }

    printf("\nStudent Information:\n");
    for (int i = 0; i < 4; ++i) {
        displayStudent(&classOfStudents[i]);
    }

    double avg = averageGPA(classOfStudents, 4);
    printf("Average GPA for the class: %.2f\n", avg);

    const struct Student* oldest = oldestStudent(classOfStudents, 4);
    printf("Oldest Student:\n");
    displayStudent(oldest);

    return 0;
}

void inputStudent(struct Student* s) {
    printf("Enter Student ID: ");
    scanf("%d", &s->studentID);
    printf("Enter Name: ");
    scanf("%s", s->name);
    printf("Enter Age: ");
    scanf("%d", &s->age);
    printf("Enter GPA: ");
    scanf("%lf", &s->GPA);
}

void displayStudent(const struct Student* s) {
    printf("Student ID: %d\n", s->studentID);
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("GPA: %.2f\n", s->GPA);
}

double averageGPA(const struct Student students[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += students[i].GPA;
    }
    return sum / size;
}

const struct Student* oldestStudent(const struct Student students[], int size) {
    const struct Student* oldest = &students[0];
    for (int i = 1; i < size; ++i) {
        if (students[i].age > oldest->age) {
            oldest = &students[i];
        }
    }
    return oldest;
}
