// Exercise 2.19 Solution
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main( void )
{ 
   int var1; // define first integer
   int var2; // define second integer
   int var3; // define third integer
   int smallest; // smallest integer
   int largest; // largest integer
   
   printf( "%s", "Input three different integers: " ); // prompt user
   scanf( "%d%d%d", &var1, &var2, &var3 ); // read three integers

   // output sum, average and product of the three integers
   printf( "Sum is %d\n", var1 + var2 + var3 );
   printf( "Average is %d\n", ( var1 + var2 + var3 ) / 3 );
   printf( "Product is %d\n", var1 * var2 * var3 );
   
   smallest = var1; // assume first number is the smallest
   
   if ( var2 < smallest ) 
   { // is b smaller?
      smallest = var2;
   } // end if
      
   if ( var3 < smallest ) { // is c smaller?
      smallest = var3;
   } // end if
      
   printf( "Smallest is %d\n", smallest );

   largest = var1; // assume first number is the largest
   
   if ( var2 > largest ) { // is b larger?
      largest = var2;
   } // end if

   if ( var3 > largest ) { // is c larger?
      largest = var3;
   } // end if

   printf( "Largest is %d\n", largest );

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
