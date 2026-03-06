// Eduardo Sarno
// Student Id: A01435361
// Date Feb 27, 2026
// Version 1.1.0

#include "unique_numbers.h"

/* This main function will create an array with unique numbers and set it to 0
    with the size required. Then will loop through unique numbers size
    and ask the user to enter a number for each loop
    it will check if it is valid
    it will check if it is unique
    if so the number will be added to the unique 
    numbers array*/
int main(void){
    int unique_numbers[NUM_OF_UNIQUE_NUMBERS] = {0};
    int numbers_added_count = 0;

    int i = 1;
    while (i <= NUM_OF_UNIQUE_NUMBERS) 
    {
        printf("\nEnter # %d : ", i);

        int num;
        scanf(" %d", &num);

        // validate
        if(num < VALID_RANGE_MIN || num > VALID_RANGE_MAX){
            printf("The number entered is not in the valid range of 10 to 100\n");
            continue;
        }

        // check if it is unique
        if(isUnique(num, unique_numbers, numbers_added_count)){
            printf("The number: %d is unique\n", num);
            unique_numbers[numbers_added_count] = num;
            numbers_added_count++;
        }  
        i++;
    }
    printf("\nAll of the unique numbers found are:\n\n");
    for (int j = 0; j < numbers_added_count; j++) {
        printf("%6d", unique_numbers[j]);
        if(((j + 1) % 5 == 0)) printf("\n"); // new line every 5 items
    }
    puts(""); // new line for formatting

} 

/* This function is a hleper that checks if the number is unique
    within the numbers already added (avoid using full length to be faster)*/
int isUnique(int num, int unique_numbers[], int numbers_added_count){
    for (int i = 0; i < numbers_added_count; i++) {
        if (unique_numbers[i] == num) {
            return 0;
        }
    }
    return 1;
}

