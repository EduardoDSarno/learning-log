// Eduardo Sarno
// feb 5 ,2026

#include <stdio.h>

const unsigned int TOTAL_SEATS = 10;
const unsigned int FIRST_CLASS_SEATS = 5;

int chose_firstclass_seat(int seats[]);
int chose_economy_seat(int seats[]);

int main() {
    int seats[TOTAL_SEATS] = {0};
    int option;
    char response;
    int all_seats_full = 0;

    while (!all_seats_full) 
    {
        printf("Please type 1 for \"first class\"\n");
        printf("Please type 2 for \"economy\"\n");
        printf("?");
        scanf("%d", &option);

        if (option == 1) 
        {
            int seat_num = chose_firstclass_seat(seats);
            if (seat_num > 0) 
            {
                printf("Your seat assigmnet is %d in first class\n\n", seat_num);
            } 
            else {
                printf("The first class section is full.\n");

                printf("Would you like to sit in the economy section ( Y or N )? ");
                scanf(" %c", &response);
                
                if (response == 'y' || response == 'Y')
                 {
                    seat_num = chose_economy_seat(seats);

                    if (seat_num > 0) 
                    {
                        printf("Your seat assignment is %d in economy\n\n", seat_num);
                    }
                } else {
                    printf("Next flight leaves in 3 hours.\n\n");
                }
            }
        }
        else if (option == 2) 
        {
            int seat_num = chose_economy_seat(seats);
            if (seat_num > 0) 
            {
                printf("Your seat assigmnet is %d in economy\n\n", seat_num);
            } 
            else 
            {
                printf("The economy section is full.\n");
                printf("Would you like to sit in the first class setcion (Y or N)?");

                scanf(" %c", &response);
                
                if (response == 'y' || response == 'Y') {
                    seat_num = chose_firstclass_seat(seats);
                    if (seat_num > 0) {
                        printf("Your seat assignment is %d in first class\n\n", seat_num);
                    }
                } else {
                    printf("Next flight leaves in 3 hours.\n\n");
                }
            }
        }

        //flag
        all_seats_full = 1;

        for (int i = 0; i < TOTAL_SEATS; i++) 
        {
            if (seats[i] == 0) {
                all_seats_full = 0;
                break;
            }
        }

        

        if (all_seats_full) {
            printf("All seats for this flight are sold.\n");
        }
    }

    return 0;
}

// functions to avoid repeating the loops

int chose_firstclass_seat(int seats[]) 
{
    for (int i = 0; i < FIRST_CLASS_SEATS; i++) {
        if (seats[i] == 0) {
            seats[i] = 1;
            return i + 1;
        }
    }
    return 0;
}

int chose_economy_seat(int seats[]) 
{
    for (int i = FIRST_CLASS_SEATS; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            seats[i] = 1;
            return i + 1;
        }
    }
    return 0;
}
