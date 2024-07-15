#include <stdio.h>

int main() {
    int number;
    int d1, d2, d3, d4;
    int encryptedNumber;

    printf("Enter a 4-digit number (first digit cannot be 0 and third digit cannot be 2): ");
    scanf("%d", &number);

    // extract given digits
    d1 = number / 1000;
    d2 = (number / 100) % 10;
    d3 = (number / 10) % 10;
    d4 = number % 10;

    // checking if people can follow instructions or not
    if (d1 == 0 || d3 == 2) {
        printf("Invalid input. First digit cannot be 0 and third digit cannot be 2.\n");
        return 1;
    }

    // encypting
    d1 = (d1 + 8) % 10;
    d2 = (d2 + 8) % 10;
    d3 = (d3 + 8) % 10;
    d4 = (d4 + 8) % 10;

    // swapping digits 1 and 3 & 2 and 4
    encryptedNumber = d3 * 1000 + d4 * 100 + d1 * 10 + d2;

    printf("\n%d is now encrypted to %d\n", number, encryptedNumber);

    return 0;
}
