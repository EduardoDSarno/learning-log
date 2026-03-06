#include <stdio.h>
#include <ctype.h>

int getRomanValue(char c);

int main(void)
 {
    int i;
    int c;
    int total;
    int previous_value;
    int actual_value;
    int invalid_char;
    
    
    for (i = 1; i <= 10; i++) // looping through the max number of requests starting at 1 to 10
    {
        total = 0;
        previous_value = 0;
        invalid_char = 0;
        
        printf("Input Roman numeral # %d: ", i);
        
        
        while ((c = getchar()) != '\n' && c != EOF) 
        {
            c = toupper(c);
            putchar(c);
            
            if (!invalid_char)
             {
                actual_value = getRomanValue(c);
                
                if (actual_value == -1) 
                {
                    // had to assing to 1 so the if statment is triggered below for simplicity
                    invalid_char = 1;
                } 
                else 
                {
                    // in romans to get number such as 4,9 we need to compare if the current value is smaller than the next
                    // but since we can not see next (due to the requirments ) we need to put in a variable and comapre
                    if (actual_value > previous_value && previous_value != 0)
                     {
                        // use the *2 previous_value to remove the preivous added value (since we can only read on at time)
                        // and to remove the now desired previous_value and than add the actual_value to work around not being able
                        // to see the next char
                        total = total - 2 * previous_value + actual_value; 
                    } 
                    else 
                    {
                        total = total + actual_value;
                    }
                    previous_value = actual_value;
                }
            }
            
            if (invalid_char) {
                while ((c = getchar()) != '\n' && c != EOF) {
                }
                printf(" Error - last character was not valid!!!\n\n");
                break;
            }
        }
        
        if (!invalid_char) {
            printf(" = %d\n\n", total);
        }
    }
    
    printf("THAT'S ALL FOLKS :)"); // last line from the sample output
    return 0;
}

int getRomanValue(char c) {
    switch(toupper(c)) {
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
