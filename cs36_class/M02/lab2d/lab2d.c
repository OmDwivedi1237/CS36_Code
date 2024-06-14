#include <stdio.h>

void printSquare(int size);
void printSquare_char(char ch, int size);

int main() {
    int size;
    char userChar;

    printf("Enter the size of the square of asterisks: ");
    scanf("%d", &size);
    printSquare(size);

    printf("Enter a character: ");
    scanf(" %c", &userChar);
    printf("Enter the size of the square: ");
    scanf("%d", &size);
    printSquare_char(userChar, size);

    return 0;
}

void printSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printSquare_char(char ch, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }
}
