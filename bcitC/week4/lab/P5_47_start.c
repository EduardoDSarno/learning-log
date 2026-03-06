// Exercise 5.47 Solution 
// Name: Eduardo Sarno
// Date: Jan 28, 2026

#define _CRT_SECURE_NO_WARNINGS
#define INITIAL_BANK_BALANCE 1000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// enumeration constants represent game status 
enum Status { CONTINUE, WON, LOST };

int rollDice( void ); // function prototype 
enum Status craps( void ); // function prototype 
void chatter( void ); // function prototype 

int main()
{ 
   enum Status result;     // result of current game 
   int wager = 0;          // wager for current game 
   int bankBalance = INITIAL_BANK_BALANCE; // current bank balance 
   int not_broke = 1;      // boolean flag to indicate if broke
   int continue_playing = 1;  // boolean flag to indicate if player wants to continue playing

   srand( (unsigned int) time( NULL ) ); // seed random number generator 

   // display current balance and prompt for wager 
   printf( "You have $%d in the bank.\n\n", bankBalance );
   printf( "Place your wager: " );
   scanf( "%d", &wager );

   // loop while not valid wager 
   while( wager <= 0 || wager > bankBalance ) // ES:  changed 1000 to bank balace
   { 
      printf( "Please bet a valid amount.\n" );
      scanf( "%d", &wager );
   } // end while 

   while (not_broke && continue_playing)
   {
      result = craps();

      if (result == WON){
         bankBalance += wager;
      }
      else if(result == LOST){
         bankBalance -= wager;
         if (bankBalance == 0) {
            puts("Sorry. You busted!");
            not_broke = 0;
            break;
         }
      }

      // asks if the player wanna conitnue to play
      printf( "You have $%d in the bank.\n\nDo you want to continue? (1 = yes, 0 = no): ", bankBalance );
      scanf("%d", &continue_playing);
      if (!continue_playing) 
      {
         break;
      }

      // display current balance and prompt for wager 
     
      printf( "Place your wager: " );
      scanf( "%d", &wager );

      // loop while not valid wager 
      while( wager <= 0 || wager > bankBalance ) // ES:  changed 1000 to bank balace
      { 
         printf( "Please bet a valid amount.\n" );
         scanf( "%d", &wager );
      } 
      
   }
} // end main 

// roll dice, calculate sum and display results 
int rollDice( void )
{ 
   int die1;    // first die value 
   int die2;    // second die value 
   int workSum; // sum of dice 
   
   die1 = 1 + rand() % 6; // pick random die1 value 
   die2 = 1 + rand() % 6; // pick random die2 value 
   workSum = die1 + die2; // sum die1 and die2 

   // display results of this roll 
   printf( "Player rolled %d + %d = %d\n", die1, die2, workSum );

   return workSum; // return sum of dice 
} // end function rollDice 

// craps plays one game of craps, returns result of game 
enum Status craps( void )
{ 
   int myPoint = 0; // player must make this point to win
   enum Status gameStatus = CONTINUE; // may be CONTINUE, WON, or LOST
   int sum = rollDice(); // first roll of the dice
   chatter();

   // determine game status based on sum of dice
   switch(sum) {
      // win on first roll
      case 7: // 7 is a winner
      case 11: // 11 is a winner          
         gameStatus = WON; 
         break;
      // lose on first roll
      case 2: // 2 is a loser
      case 3: // 3 is a loser
      case 12: // 12 is a loser
         gameStatus = LOST; 
         break;
      // remember point
      default:                  
         gameStatus = CONTINUE; // player should keep rolling
         myPoint = sum; // remember the point
         printf("Point is %d\n", myPoint);
         break; // optional
   }

   // while game not complete
   while (CONTINUE == gameStatus) { // player should keep rolling
      sum = rollDice(); // roll dice again
      chatter();

      // determine game status
      if (sum == myPoint) { // win by making point
         gameStatus = WON; 
      } 
      else if (7 == sum) { // lose by rolling 7
         gameStatus = LOST; 
      } 
   } 

   // display won or lost message
   if (WON == gameStatus) { // did player win?
      puts("Player wins");
   } 
   else { // player lost
      puts("Player loses");
   } 
   
   return gameStatus;
} // end function craps 

// chatter displays messages at random to create "chatter" 
void chatter( void )
{ 
   int select; // random number 
   puts(""); // print a blank line
   select = 1 + rand() % 6;

   // choose message at random 
   switch ( select ) { 

      case 1:
         printf( "Oh, you're going for broke, huh?\n" );
         break; // exit switch 

      case 2:
         printf( "Aw cmon, take a chance!\n" );
         break; // exit switch 
      
      case 3:
         printf( "Hey, I think this guy is going to break the bank!!\n" );
         break; // exit switch 
      
      case 4:
         printf("You're up big. Now's the time to cash in your chips!\n");
         break; // exit switch 
      
      case 5:
         printf( "Way too lucky! Those dice have to be loaded!\n" );
         break; // exit switch 
       
      case 6:
         printf( "Bet it all! Bet it all!\n" );
         break; // exit switch 
      
      default:
		  printf("ERROR!!! Reached default case in chatter() function.");
         break; // exit switch 
   } // end switch 
} // end function chatter 




 /*************************************************************************
 * (C) Copyright 1992-2013 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
