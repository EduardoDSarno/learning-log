
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// found out this is better than constants becuase is processed before compilation.
#define NUM_OF_QUERIES_TO_USER 10
#define SIZE_OF_LONGEST_ROMAN 20
#define INVALID_CHAR_STRING_SIZE SIZE_OF_LONGEST_ROMAN

int roman_char_to_num(char roman[], char invalid_char[]);
void to_uppercase(char str[]);

/**
* Main function will desing the roman char string to have max index of 20 
* max index possible for a roman number
* than loops tNUM_OF_QUERIES_TO_USER times 
 */
int main(){

    char roman_char[SIZE_OF_LONGEST_ROMAN];
    
    for (int i = 0; i < NUM_OF_QUERIES_TO_USER; i++){
        char invalid_char[INVALID_CHAR_STRING_SIZE] = "";
        
        printf("Input Roman numeral # %d: ", i + 1);
        scanf("%s", roman_char);

        int result = roman_char_to_num(roman_char, invalid_char);
        
        if (result == -1) {
            printf("\n%s Error - last character was not valid!!!\n\n", invalid_char);
        } else {
            to_uppercase(roman_char);
            printf("\n%s = %d\n\n", roman_char, result);
        }
    }
    return 0;
}

// function to make all the chart long in a String (char[])
void to_uppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// get roman using switch
int get_roman_value(char ch) {
    switch(toupper(ch)) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1;
    }
}


int roman_char_to_num(char roman[], char invalid_char[]){

    int num = 0;
    int invalid_char_count = 0; // keep track of the index of invalid chars so can print them in correct order
    for (int i = 0; roman[i] != '\0'; i++)
    {
        // simpify function calling syntax to make it clear.
        int current = get_roman_value(roman[i]); 
        int next = get_roman_value(roman[i + 1]);

        // we need to create the invalid_char string independently 
        // meaning that we will add valid digits to it, because the assignment
        // requires prefixes of the wrong character
        invalid_char[invalid_char_count] = toupper(roman[i]);
        invalid_char_count++;
        invalid_char[invalid_char_count] = '\0';

        // -1 means if it is invalid
        if (current == -1) {
            return -1;
        }

        // This is used to get the numbers such as IX or XIV...
        if (next != -1 && current < next)
        {
            num += (next - current);
            invalid_char[invalid_char_count] = toupper(roman[i + 1]);
            invalid_char_count++;
            invalid_char[invalid_char_count] = '\0';
            i++;
        }
        else 
        {
            num += current;
        }
    }
    return num;
}


