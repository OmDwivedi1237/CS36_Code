
#include <stdio.h>

int main(void) {
    printf("\nEnter two integers for me to evaluate: ");

    int num1 = 0, num2 = 0;
    scanf_s("%i %i", &num1, &num2);

    if (num1 == num2) {
        printf("%i is equal to %i\n", num1, num2);
    } else {
        printf("%i is not equal to %i\n", num1, num2);
    }

    if (num1 < num2) {
        printf("%i is less than %i\n", num1, num2);
    }

    if (num1 > num2) {
        printf("%i is greater than %i\n", num1, num2);
    }

    if (num1 <= num2) {
        printf("%i is less than or equal to %i\n", num1, num2);
    }

    if (num1 >= num2) {
        printf("%i is greater than or equal to %i\n", num1, num2);
    }

    return 0;
}
