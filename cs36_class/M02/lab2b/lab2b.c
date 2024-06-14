#include <stdio.h>

int main() {
    int sum = 0;
    int count = 0;
    int num;

    // Part1
    printf("Enter integers one by one (enter -1 to stop):\n");

    while (1) {
        printf("Enter an integer: ");
        scanf("%d", &num);
        
        if (num == -1) {
            break;
        }

        sum += num;
        count++;
    }

    if (count > 0) {
        double average = (double)sum / count;
        printf("The average of the entered integers is: %.2f\n", average);
    } else {
        printf("No integers were entered.\n");
    }

    // Part2
    int product_number;
    printf("%s %s", "Product #", "Price\n");
    printf("%d<-------->$%.2f\n", 1, 2.98);
    printf("%d<-------->$%.2f\n", 2, 4.50);
    printf("%d<-------->$%.2f\n", 3, 9.98);
    printf("%d<-------->$%.2f\n", 4, 4.49);
    printf("%d<-------->$%.2f\n", 5, 6.87);   
    printf("\nEnter a product number (1-5): ");
    scanf("%d", &product_number);

    switch (product_number) {
        case 1:
            printf("You have chosen product %d, the price is $2.98\n", product_number);
            break;
        case 2:
            printf("You have chosen product %d, the price is $4.50\n", product_number);
            break;
        case 3:
            printf("You have chosen product %d, the price is $9.98\n", product_number);
            break;
        case 4:
            printf("You have chosen product %d, the price is $4.49\n", product_number);
            break;
        case 5:
            printf("You have chosen product %d, the price is $6.87\n", product_number);
            break;
        default:
            printf("No\n");
            break;
    }

    return 0;
}
