//THIS IS LAB5B NAMING CONVENTION WAS REQUIRED WHICH IS WHY THIS IS NAMED SCAN
#include <stdio.h>


int main () {
  //PART 1
  int hex  = 0;
  char s[20] = "";

  printf("%s","Enter a hexadecimal value (ie. 0x4A): " );
  scanf_s("%i", &hex);

  printf("%s","Input String less than 20 characters: " );
  scanf_s("%[^a]", s);
  //PART 2
  printf("hex is: 0X%X\n", hex);
  printf("s is: %s\n", s);
}
