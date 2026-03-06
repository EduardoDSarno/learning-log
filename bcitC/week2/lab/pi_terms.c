// Eduardo Sarno
// Jan 13,2026
// Obs: I paste the question in comments so I don't have to leave the editor to read the quesiton. :)


/*
 * Problem 4.26 – Calculating the Value of Pi
 *
 * Use the infinite series:
 *
 *   pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...)
 *
 * 1) Write a program that calculates successive approximations of pi
 *    by adding one term of the series at a time.
 *
 * 2) Print a table showing:
 *      - the number of terms used
 *      - the corresponding approximation of pi
 *
 * 3) Determine how many terms are required before the approximation
 *    first matches (when rounded) the following values:
 *      - 3.14
 *      - 3.141
 *      - 3.1415
 *      - 3.14159
 */


#include <stdio.h>

void pi_terms(){
    double pi = 0.0;
    int divisor = 1;
    int sign = 1;
    int term_number = 0;
    double inside_braquets = 0.0;
    
    int found_314159 = 0; // I am going to do only one because the idea is the same
    
    
    while (found_314159 == 0) 
    {
        inside_braquets += sign * (1.0 / divisor);
        divisor += 2;
        sign = -sign;
        term_number++; //count
        
        pi = inside_braquets * 4;
        
        
        if (found_314159 == 0 && (int)(pi * 100000) == 314159) {
            printf("3.14159 at term %d\n", term_number);
            found_314159 = 1;
        }
    }
}

 int main()
 {
    pi_terms();
    return 0;
 }