#include <stdio.h>

const int SIZE = 10;

int main (void) {
  
  int array_values[SIZE];
  int save = 0;

  for (int i = 0; i < SIZE; i++) {
    array_values[i] = i * i;
    save = array_values[i];
    printf_s("array_values[%i] = %i\n", i, save);
  }
}
