// Eduardo Sarno
// feb 5 ,2026

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
const unsigned int expected[ 13 ] = { 0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
const unsigned int NUMBER_OF_ROLLS = 36000000;

int roll_dice();
void roll_dice_probability(int , int []);

int main(){
    // seed 
    srand(time(NULL));
    int counts[13] = {0}; // setting to zero

    // get the array with probabilities filled
    roll_dice_probability(NUMBER_OF_ROLLS, counts); 

    printf("\tSum\tTotal\tExpected\tActual\n\n");

    
    for(int i = 2; i <= 12; i++)
    {
        float expected_procentage = expected[i] * 100.0 / 36.0;
        float actual_porcentage = counts[i] * 100.0 / NUMBER_OF_ROLLS;
        printf("\t%d\t%d\t%.3f%%\t\t%.3f%%\n", i, counts[i], expected_procentage, actual_porcentage);
    }
   
}

void roll_dice_probability(int number_of_rolls, int count_rolls[])
{

    for (int i = 0 ; i < number_of_rolls; i++){
        count_rolls[roll_dice()]++; // for each roll we ++ then rolled combination in the array
    }
}
int roll_dice(){

    // roll two dice
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    return die1 + die2;
}