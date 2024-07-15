#include <stdio.h>

int main() {
    int encryptedNumber;
    int d1, d2, d3, d4;
    int originalNumber;

    printf("Enter the 4-digit encrypted number: ");
    scanf("%d", &encryptedNumber);

    // extract digits
    d3 = encryptedNumber / 1000;
    d4 = (encryptedNumber / 100) % 10;
    d1 = (encryptedNumber / 10) % 10;
    d2 = encryptedNumber % 10;

    // decrypt digits
    d1 = (d1 + 2) % 10;
    d2 = (d2 + 2) % 10;
    d3 = (d3 + 2) % 10;
    d4 = (d4 + 2) % 10;

    // calculate and print original number
    originalNumber = d1 * 1000 + d2 * 100 + d3 * 10 + d4;

    printf("\n%d decrypts to %d\n", encryptedNumber, originalNumber);

    return 0;
}
