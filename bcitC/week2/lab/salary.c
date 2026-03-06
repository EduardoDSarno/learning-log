// Eduardo Sarno
// Jan 13,2026
// Obs: I paste the question in comments so I don't have to leave the editor to read the quesiton. :)


/*
------------------------------------------------------------
3.20 (Salary Calculator)

The company pays:
- Straight time for the first 40 hours
- Time-and-a-half for hours worked over 40

Sample Input/Output Dialog:

Enter # of hours worked (-1 to end): 39
Enter hourly rate of the worker ($00.00): 10.00
Salary is $390.00

Enter # of hours worked (-1 to end): 40
Enter hourly rate of the worker ($00.00): 10.00
Salary is $400.00

Enter # of hours worked (-1 to end): 41
Enter hourly rate of the worker ($00.00): 10.00
Salary is $415.00

Enter # of hours worked (-1 to end): -1
------------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
double salary(int worked_hours_weekly, double worker_hourly_rate_cad){
    double salary = 0;

    // consts
    double const MINIMUN_WORK_RATE_CAD = 0.0;
    int    const MINIMUN_WORKED_HOURS_WEEKLY = 0;
    int    const OVER_TIME_PAY_QUALIFICATION_HOURS =40;
    double const OVER_TIME_PAY_INCREASE_MULTIPLIER = 1.5;


    if (worked_hours_weekly < MINIMUN_WORKED_HOURS_WEEKLY || worker_hourly_rate_cad < MINIMUN_WORK_RATE_CAD){
        printf("both worked hours and hourly rate can not be negative");

        // exit code if error (stop)
        exit(1);
    }

    if (worked_hours_weekly > OVER_TIME_PAY_QUALIFICATION_HOURS){
        int over_time_hours = worked_hours_weekly - OVER_TIME_PAY_QUALIFICATION_HOURS;

        salary += over_time_hours * (worker_hourly_rate_cad * OVER_TIME_PAY_INCREASE_MULTIPLIER);

        worked_hours_weekly -= over_time_hours;
    }

    salary += worked_hours_weekly * worker_hourly_rate_cad;
    return salary;
}

int main(void){  
    printf("$%.2f\n", salary(41, 10.0)); 
    return 0;  
}