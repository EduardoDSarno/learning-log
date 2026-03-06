// Eduardo Sarno
// Jan 21,2026
#include <stdio.h>

int integerPower(int base,unsigned int exponent);

int main(){
    printf("%d\n", integerPower(2, 3));  //print
    return 0;
}

int integerPower(int base,unsigned int exponent)
{
    int result = 1;

    for (int i = 0; i < exponent; i++)
    {
       // printf("%d\n", result);
        result *= base;
    }
    //printf("%d", result);
    return result;
}
