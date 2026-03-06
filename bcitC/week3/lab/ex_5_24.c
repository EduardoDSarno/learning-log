// Eduardo Sarno
// Jan 21,2026

#include <stdio.h>

// constants for best pratctice NO MAGIC NUMBERS
double const CELSIUS_TO_FAHRENHEIT_RATIO = 9.0 / 5.0;
double const FREEZING_POINT_FAHRENHEIT = 32.0;
double const FAHRENHEIT_TO_CELSIUS_RATIO = 5.0 / 9.0;
int const MAXIMUN_VALUE_REQUIRED_CELSIUS = 100;

double toCelsius(double fahrenheit);
double toFahrenheit(double celsius);

int main(void){

    // priting just one table because they both are the same thing, just changing sides
    // and the question is asking to minimize the size of output
    printf("Celsius   Fahrenheit   |   Fahrenheit   Celsius\n");
    printf("-----------------------------------------------\n");

    for (double c = 0.0; c <= MAXIMUN_VALUE_REQUIRED_CELSIUS; c += 1) {
        double f = toFahrenheit(c);
        printf("%10.1f   %.1f   |   %10.1f   %.1f\n", c, f, f, toCelsius(f)); // use the 10 for formmating
    }
    
    return 0;
}

double toCelsius(double fahrenheit){

    
    double celsius = 0.0;

    celsius = (fahrenheit - FREEZING_POINT_FAHRENHEIT) * FAHRENHEIT_TO_CELSIUS_RATIO;
    
    return celsius;
}

double toFahrenheit(double celsius){

    
    double fahrenheit = 0.0;

    fahrenheit = (celsius * CELSIUS_TO_FAHRENHEIT_RATIO) + FREEZING_POINT_FAHRENHEIT;
    
    return fahrenheit;
}

