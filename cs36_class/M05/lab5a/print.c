//THIS IS LAB5A NAMING CONVENTION WAS NEEDED AS PER INSTRUCTIONS
#include <stdio.h>

int main () {
  //PART 1
  int a = 1427;
  double b = 1427.0;

  printf("PART 1\n\na in octal is: 0%o\n", a);
  printf("a in hexadecimal is: 0X%X\n", a);
  printf("a in hexadecimal is also: 0x%x\n", a);

  printf("b wihtout a decimal point is: %.0f\n", b);
  printf("b with 2 digits after the decimal point is: %.2f\n", b);


  //PART 2 
  int c = 873;
  double d = 123.94536;
  char e[] = "Star Wars: A New Hope";

  printf("\nPART 2\n\nc with four digits of precision is: %.4i\n", c);
  printf("c with nine digits of precision is: %.9i\n", c);
  printf("d with three digits of precision is: %.3lf\n", d);
  printf("d in scientific notion with 3 digits of precision is: %.3e\n", d);
  printf("d printed and rounded to: %*.*lf\n", 4, 0, d);
  printf("e but only the first 9 chars is: %.9s", e);

  
}
