#include <stdio.h>

int main() {
    int sum = 0;
    int count = 0;
    int num;

    // Part1
    printf_s("Enter integers one by one (enter -1 to stop):\n");

    while (1) {
        printf_s("Enter an integer: ");
        scanf_s("%d", &num);
        
        if (num == -1) {
            break;
        }

        sum += num;
        count++;
    }

    if (count > 0) {
        double average = (double)sum / count;
        printf_s("The average of the entered integers is: %.2f\n", average);
    } else {
        printf_s("No integers were entered.\n");
    }

    // Part2
    int product_number;
    printf_s("%s %s", "Product #", "Price\n");
    printf_s("%d<-------->$%.2f\n", 1, 2.98);
    printf_s("%d<-------->$%.2f\n", 2, 4.50);
    printf_s("%d<-------->$%.2f\n", 3, 9.98);
    printf_s("%d<-------->$%.2f\n", 4, 4.49);
    printf_s("%d<-------->$%.2f\n", 5, 6.87);   
    printf_s("\nEnter a product number (1-5): ");
    scanf_s("%d", &product_number);

    switch (product_number) {
        case 1:
            printf_s("You have chosen product %d, the price is $2.98\n", product_number);
            break;
        case 2:
            printf_s("You have chosen product %d, the price is $4.50\n", product_number);
            break;
        case 3:
            printf_s("You have chosen product %d, the price is $9.98\n", product_number);
            break;
        case 4:
            printf_s("You have chosen product %d, the price is $4.49\n", product_number);
            break;
        case 5:
            printf_s("You have chosen product %d, the price is $6.87\n", product_number);
            break;
        default:
            printf_s("No\n");
            break;
    }

    return 0;
}
