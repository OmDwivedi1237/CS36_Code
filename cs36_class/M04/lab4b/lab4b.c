#include <stdio.h>
#define MAX 5

int main(void) {
  
    int arr[MAX] = {4, 6, 2, 9, 3};
    // array of pointers to int for ascending order
    int* asc[MAX] = {};
    int* desc[MAX] = {};
    
    // Sets pointer arrays to point to arr[]
    for (size_t i = 0; i < MAX; i++) {
        asc[i] = &arr[i];
        desc[i] = &arr[i];
    }

    // Sort pointer array asc[] in ascending order
    for (size_t i = 0; i < MAX; i++) {
        for (size_t j = 0; j < MAX - 1; j++) {
            if (*asc[j] > *asc[j+1]) {
                int* temp = asc[j];
                asc[j] = asc[j+1];
                asc[j+1] = temp;
            }
        }
    }
    
    for (size_t i = 0; i < MAX; i++) {
        for (size_t j = 0; j < MAX - 1; j++) {
            if (*desc[j] < *desc[j+1]) {
                int* temp = desc[j];
                desc[j] = desc[j+1];
                desc[j+1] = temp;
            }
        }
    }
    
    printf("\nOriginal | Ascending | Descending\n");
    for (int i = 0; i < MAX; i++) {
        printf("%2i %12i %12i\n", arr[i], *asc[i], *desc[i]);
    }
    puts("");
}
