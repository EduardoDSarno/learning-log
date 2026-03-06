// Eduardo Sarno
// Jan 13,2026
// Obs: I paste the question in comments so I don't have to leave the editor to read the quesiton. :)

/*
------------------------------------------------------------
3.19 (Interest Calculator)

The simple interest on a loan is calculated using:
    interest = principal * rate * days / 365;

Sample Input/Output Dialog:

Enter loan principal (-1 to end): 1000.00
Enter interest rate: .1
Enter term of the loan in days: 365
The interest charge is $100.00

Enter loan principal (-1 to end): 1000.00
Enter interest rate: .08375
Enter term of the loan in days: 224
The interest charge is $51.40

Enter loan principal (-1 to end): -1
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
double interest_loan_calcualtion(double principal, double rate, double days){
    int const DAYS_IN_YEAR = 365;
    double interest = 0.0;

    if (principal < 0) 
    {
        printf("principal must be bigger than 0");

        exit(1); // learn that is like rust panic()! stop program to run
    }

    interest = principal * rate * days / DAYS_IN_YEAR;

    return interest;

}

int main(){
    printf("$%.2f\n", interest_loan_calcualtion(1000.00, 0.1, 365));
    return 0;
}