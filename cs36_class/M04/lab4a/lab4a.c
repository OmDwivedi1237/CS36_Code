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
// TO DO: print largest and second largest
//
//
// find average and sum
double ave = 0;
int sum = 0;
find_ave_sum(theArray, SIZE, &ave, &sum);
// print average and sum
// TO DO: print average and sum of array
//
//
}
void find_two_largest(const int toFind[], int theSize, int* large1, int* large2){
  
  
  
}
void find_ave_sum(const int sum_ave[], int theSize, double* theAve, int* theSum){
//
//TO DO - find average and sum of array
// set the pointer parameter variables to ave and sum
}
void printArray_with_pointer(const int toPrint[], int theSize){
//
//TO DO - use a pointer to get each value in the array
// dereference the pointer to print the value
}
