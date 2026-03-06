// Exercise 2.22 Solution
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <conio.h>

int main( void )
{ 
   int integer; // integer input by user

   printf( "%s", "Input an integer: " ); // prompt
   scanf( "%d", &integer ); // read integer

   // test if integer is even
   if ( integer % 2 == 0 ) {
      printf( "%d is an even integer\n", integer );
   } // end if

   // test if integer is odd
   if ( integer % 2 != 0 ) {
      printf( "%d is an odd integer\n", integer );
   } // end if

   return 0;

} // end main



 /**************************************************************************
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
