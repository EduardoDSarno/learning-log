#include <stdio.h>
double poly_two(double a, double b, double c, double x ); 

int main(){

    double a;
    double b;
    double c;
    double x;
    
    
    printf("\nThis program evaluates the 2nd degree polynomial  a*x*x + b*x + c\n\n");

    // for a
    printf("Enter the value for the 'a' coefficient (must be a non-zero value): ");
    scanf("%lf", &a);

    // crashni if a is 0
    if (a == 0)
    {
        printf("a can not be 0");
        return -1;
    }


    // b
    printf("\nEnter the value for the 'b' coefficient: ");
    scanf("%lf", &b);

    //c
    printf("\nEnter the value for the 'c' coefficient: ");
    scanf("%lf", &c);
    //x
    printf("\nEnter the value for the 'x' input into the polynomial: ");
    scanf("%lf", &x);

    poly_two(a, b, c, x);

    return 0;
}

double poly_two(double a, double b, double c, double x )
{
    double result = a * x * x + b * x + c;

    printf("\n\nThe result when x = %.4lf is: %.4lf\n\n", x, result);

    return result;
}