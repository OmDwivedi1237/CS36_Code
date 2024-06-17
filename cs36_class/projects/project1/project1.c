// Om Dwivedi - Project 1

#include <stdio.h>

// prototypes
void printSquaresAndCubes();
void printNameASCII();
void calculateAndPrintFloatStats();

int main() {
    printSquaresAndCubes();
    printNameASCII();
    calculateAndPrintFloatStats();
}

//----Part 1----
void printSquaresAndCubes() {
    int num;
    printf("Number\tSquare\tCube\n");
    for (num = 1; num <= 10; num++) {
        printf("%d\t%d\t%d\n", num, num * num, num * num * num);
    }

    printf("\n\n");
}

//----Part 2----
void printNameASCII() {
    char name[] = "Om Dwivedi";
    for (int i = 0; name[i] != '\0'; i++) {
        printf("\n%c - %d\n", name[i], name[i]);
    }

    printf("\n\n");
}

//----Part 3----
void calculateAndPrintFloatStats() {
    float num1, num2, num3;
    printf("Pick the first floating-point number: ");
    scanf("%f", &num1);
    printf("Pick the second floating-point number: ");
    scanf("%f", &num2);
    printf("Pick the third floating-point number: ");
    scanf("%f", &num3);

    float sum = num1 + num2 + num3;
    float average = sum / 3;
    float product = num1 * num2 * num3;

    float smallest = num1;
    if (num2 < smallest) smallest = num2;
    if (num3 < smallest) smallest = num3;

    float largest = num1;
    if (num2 > largest) largest = num2;
    if (num3 > largest) largest = num3;

    printf("Sum: %.2f\n", sum);
    printf("Average: %.2f\n", average);
    printf("Product: %.2f\n", product);
    printf("Smallest: %.2f\n", smallest);
    printf("Largest: %.2f\n", largest);}
