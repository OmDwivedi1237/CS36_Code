#include <stdio.h>
#define SIZE 10

// Function prototypes --do not change--
void find_two_largest(const int[], int, int*, int*);
void find_ave_sum(const int[], int, double*, int*);
void printArray_with_pointer(const int[], int);

int main(void) {
    // initialize array
    int theArray[SIZE] = {11, 5, 2, 9, 15, 3, 8, 21, 4, 38};

    puts("\nThe array: ");
    printArray_with_pointer(theArray, SIZE);

    // find largest and second largest
    int largestOne_index = 0;
    int largestTwo_index = 0;
    find_two_largest(theArray, SIZE, &largestOne_index, &largestTwo_index);

    // print largest and second largest
    printf("Largest element: %d (at index %d)\n", theArray[largestOne_index], largestOne_index);
    printf("Second largest element: %d (at index %d)\n", theArray[largestTwo_index], largestTwo_index);

    // find average and sum
    double ave = 0;
    int sum = 0;
    find_ave_sum(theArray, SIZE, &ave, &sum);

    // print average and sum
    printf("Average of array elements: %.2f\n", ave);
    printf("Sum of array elements: %d\n", sum);

    return 0;
}

void find_two_largest(const int toFind[], int theSize, int* large1, int* large2) {
    *large1 = 0;  // Index of largest
    *large2 = 0;  // Index of second largest
    
    for (int i = 1; i < theSize; i++) {
        if (toFind[i] > toFind[*large1]) {
            *large2 = *large1;
            *large1 = i;
        } else if (toFind[i] > toFind[*large2] && i != *large1) {
            *large2 = i;
        }
    }
}

void find_ave_sum(const int sum_ave[], int theSize, double* theAve, int* theSum) {
    *theSum = 0;
    
    for (int i = 0; i < theSize; i++) {
      *theSum += sum_ave[i];
    }
    
    *theAve = (double)*theSum / theSize;
}

void printArray_with_pointer(const int toPrint[], int theSize) {
    const int* ptr = toPrint;
    
    for (int i = 0; i < theSize; i++) {
      printf("%d ", *ptr);
      ptr++;
    }
    
    printf("\n");
}
