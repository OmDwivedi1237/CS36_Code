#include <stdio.h>

double toCelsius(double f);

double toFahrenheit(double c);

int main() {
    printf_s("Celsius   |   Fahrenheit\n");
    printf_s("------------------------\n");
    for (double c = 0.0; c <= 100.0; c += 10.0) {
        printf("%6.1f     |     %6.1f\n", c, toFahrenheit(c));
    }

    printf_s("\n");

    printf_s("Fahrenheit   |   Celsius\n");
    printf_s("------------------------\n");
    for (double f = 32.0; f <= 212.0; f += 20.0) {
        printf_s("%8.1f       |     %6.1f\n", f, toCelsius(f));
    }

    return 0;
}


double toCelsius(double f) {
  return (f - 32) * 5.0 / 9.0;
}

double toFahrenheit(double c) {
  return (c * 9.0 / 5.0) + 32;
}
