#include <stdio.h>

int main() {
    // Part 1
    printf("\n\n\n---Part1---------------\n\n\n\n");
    printf("  *\n ***\n*****\n");

    // Part 2
    printf("\n\n\n---Part 2 --------------------\n\n\n\n");
    int divid = 17;
    int divis = 5;
    int q = divid / divis;
    int r = divid % divis;
    printf("17 / 5 = %i remainder %i\n", q, r);

    // Part 3
    printf("\n\n\n---Part 3 --------------\n\n\n\n");
    float pi = 3.14;
    float radius;
    printf("Enter the radius of the circle: ");
    scanf_s("%f", &radius);
    float diameter = 2 * radius;
    float circumference = 2 * pi * radius;
    float area = pi * radius * radius;
    printf("\nDiameter: %f\n", diameter);
    printf("Circumference: %f\n", circumference);
    printf("Area: %f\n", area);
    
    return 0;
}
