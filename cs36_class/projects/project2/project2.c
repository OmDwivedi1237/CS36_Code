#include <stdio.h>

int main(void) {
    int numToCheck = 0;
    int divisor = 0;
    _Bool isPrime = 1; // 0 = false and 1 = true
    
    printf("%s", "\nThe prime numbers from 3 to 100 are:\n\n");
    
    // Outer for loop
    // Test only odd numbers to see if they are prime
    for (numToCheck = 3; numToCheck <= 100; numToCheck += 2) {
        isPrime = 1; // Reset, assume it is prime to start
        
        // Inner for loop
        // Divide number by odd integers from 3 to square root of numToCheck
        // If dividing and no remainder...number is not prime
        for (divisor = 3; divisor * divisor <= numToCheck && isPrime; divisor += 2) {
            if (numToCheck % divisor == 0) {
                isPrime = 0;
            }
        }
        
        if (isPrime) {
            printf("%i ", numToCheck);
        }
    }
    
    puts("\n");
    return 0;
}
