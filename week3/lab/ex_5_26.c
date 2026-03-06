// Eduardo Sarno
// Jan 21,2026

#include <stdio.h>

int isperfectNumber(int num);
int perfectNumberRange(int rangeMin, int rangeMax);

const int TRUE = 1;

int main(){
    perfectNumberRange(1, 1000);
    return 0;
}

int perfectNumberRange(int rangeMin, int rangeMax)
{

    for (int i = rangeMin; i <= rangeMax; i++)
    {
        if (isperfectNumber(i) == TRUE)
        {
            printf("%d = 1", i); // always prints 1 because one will always be a factor
            
            for (int j = 2; j < i; j++) // than from 2 to the number before i since i is not included
            {
                if (i % j == 0)
                {
                    printf(" + %d", j); // the numbers that are factor are printed
                }
            }
            printf("\n");
        }
    }
    return 0;
}

int isperfectNumber(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    return sum == num; // 1 if true, 0 if is false
}
