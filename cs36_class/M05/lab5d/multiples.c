//THIS IS LAB5D NAMING CONVENTION IS DIFFERENT DUE TO INSTRUCTIONS
#include <stdio.h>

int multiple(int);

int main(void) {
   int y = 0; 

   printf("%s", "\nEnter an integer between 1 and 32000: ");
   scanf("%d", &y);
   puts("");

   //Block checks if the input is multiple of x 
   //and then prints the appropriate msg
   if (multiple(y)) {
      printf("%d is a multiple of X\n\n", y);
   }
   else {
      printf("%d is not a multiple of X\n\n", y);
   }
}

//takes in a int checks if input is a multiple of x
//return 0 if not
int multiple(int num) {
   //Initializes bitmask
   int mask = 1;
   int mult = 1;

   //Loop through first 10 bits of number
   //Exit if the set bit is found or all are checker
   for (int i = 1; (i <= 10) && (mult != 0); ++i) {
      if ((num & mask) != 0) { 
         mult = 0;
      }
      mask <<= 1;
   }
   return mult;
}
