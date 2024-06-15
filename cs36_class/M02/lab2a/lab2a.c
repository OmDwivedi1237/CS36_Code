#include <stdio.h>
#include <limits.h>

int main() {

    // Part1
    int user_input;
    int counter;
    int largest = INT_MIN;
    int largest_2nd = INT_MIN;
    int smallest = INT_MAX;
    int smallest_2nd = INT_MAX;

    printf("Please enter 10 different non-negative integers:\n");

    for (counter = 0; counter < 10; ++counter) {
        scanf_s("%d", &user_input);

        if (user_input < 0) {
            printf_s("Invalid input, please enter a non-negative integer.\n");
            --counter;
            continue;
        }

        if (user_input < smallest) {
            smallest_2nd = smallest;
            smallest = user_input;
        } else if (user_input < smallest_2nd) {
            smallest_2nd = user_input;
        }

        if (user_input > largest) {
            largest_2nd = largest;
            largest = user_input;
        } else if (user_input > largest_2nd) {
            largest_2nd = user_input;
        }
    }

    printf_s("The largest number is: %d\n", largest);
    printf_s("The second largest number is: %d\n", largest_2nd);
    printf_s("The smallest number is: %d\n", smallest);
    printf_s("The second smallest number is: %d\n", smallest_2nd);

    // Part2
    int n;
    printf_s("Please enter a non-negative integer (1-10) to calculate its factorial: ");
    scanf_s("%d", &n);

    if (n < 1 || n > 10) {
        printf_s("Invalid input. Please enter a number between 1 and 10.\n");
        return 1;
    }

    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    printf_s("The factorial of %d is %d\n", n, factorial);

    return 0;
}
