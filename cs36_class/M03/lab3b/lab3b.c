#include <limits.h>
#include <stdio.h>

#define SIZE 20

int sumArray(const int[], size_t);
void sortArray(int[], size_t);
int findLargest(const int[], size_t);
void printArray(const int[], size_t);

int main(void) {

  int theArray[SIZE] = {5, 8, 3, 9, 14, 2,  5, 1, 15, 0, 5, 7, 2, 8, 11, 10, 9, 2, 1, 7};

  // Print array
  puts("\n--------------------------------------\n");
  puts("The original array: ");
  printArray(theArray, SIZE);
  puts("\n--------------------------------------\n");

  // Sum the array
  int sum = sumArray(theArray, SIZE);
  printf("The sum of all elements in the array is: %i", sum);
  puts("\n\n--------------------------------------\n");

  // Find largest
  int largest = findLargest(theArray, SIZE);
  printf("The largest number in the array is: %i", largest);
  puts("\n\n--------------------------------------\n");

  // Sort the array
  puts("Let's sort the array");
  sortArray(theArray, SIZE);
  printArray(theArray, SIZE);
  puts("\n--------------------------------------\n");
}

int sumArray(const int toSum[], size_t theSize) {
  int sum = 0;
  for (int i = 0; i < theSize; i++) {
    sum = sum + toSum[i];
  }
  return sum;
}

int findLargest(const int toFind[], size_t theSize) {
  int largest = toFind[0];
  for (int i = 0; i < theSize; i++) {
    if (largest < toFind[i + 1]) {
      largest = toFind[i + 1];
    }
  }
  return largest;
}

void sortArray(int toSort[], size_t theSize) {
  int temp;
  for (int i = 0; i < theSize - 1; i++) {
    for (int j = 0; j < theSize - i - 1; j++) {
      if (toSort[j] > toSort[j + 1]) {
        temp = toSort[j];
        toSort[j] = toSort[j + 1];
        toSort[j + 1] = temp;
      }
    }
  }
}

void printArray(const int toPrint[], size_t theSize) {

  printf("\n%s%9s\t|\t%s%9s\n", "Element", "Value", "Element", "Value");

  size_t halfSize = theSize / 2;
  for (size_t j = 0; j < halfSize; ++j) {
    printf("%7lu%9d    |", j, toPrint[j]);
    printf("%10lu%9d\n", (j + halfSize), toPrint[j + halfSize]);
  }
}
