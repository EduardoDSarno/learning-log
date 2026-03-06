/*
====================================
Self-Review Exercises
====================================

2.1 Fill-In the blanks in each of the following.

a) Every C program begins execution at the function MAIN().

b) Every function’s body begins with TYPE and ends with '}'.

c) Every statement ends with a(n) ;.

d) The STUDIO.H (PRINTF FN) standard library function displays information on the screen.

e) The escape sequence \n represents the NEXT_LINE character, which causes the
   cursor to position to the beginning of the next line on the screen.

f) The SCANF standard library function obtains data from the keyboard.

g) The conversion specification SYNTAX (%d..) in a printf or scanf format control
   string indicates that an integer will be output or input, respectively.

h) Whenever a new value is placed in a memory location, that value overrides
   the previous value in that location. This process is said to be OVERWRITING.

i) When a value is read from a memory location, the value in that location is
   preserved; this process is said to be NON-DESTRUCTIVE.

j) The IF statement is used to make decisions.


------------------------------------

2.2 State whether each of the following is true or false. If false, explain why.

a) Function printf always begins printing at the beginning of a new line. 
    F
    IF YOU LOOK AT THE DOCS YOU WILL SEE THAT THE PRINF PART SAYS THAT 
    "it does not automatically insert newline characters — you must include them yourself in the format string if you want a new line."

b) Comments cause the computer to display the text after // on the screen
   when the program is executed.
   F
   COMMENTS ARE JUST DIAPLYED ON THE EDITOR (OR CODE FILE) FOR THE DEVELOPERS, IT IS NOT USED BY THE COMPUTER IN ANY WAY

c) The escape sequence \n in a printf format control string positions the
   output cursor to the beginning of the next line.
   T

d) All variables must be defined before they’re used.
T

e) All variables must be given a type when they’re defined.
T

f) C considers the variables number and numBer to be identical.
F
THE COMPILER SEE VARIABLES CASES AS DIFFERENT CHARACTERS (SINCE THEY ARE DIFF IN ASCII)

g) Definitions can appear anywhere in the body of a function.
(defintions are any statement on which an entity is created and some memory is alocated to it ) T

h) All arguments following the format control string in a printf function
   must be preceded by an ampersand (&).
   F
format control does not use & it just read the values it does not passes them. So it does not need the &.

i) The remainder operator (%) can be used only with integer operands.
T

j) The arithmetic operators *, /, %, + and - all have the same precedence.
F
NO, LIKE MATH * AND /, HAVE HIGHER PRECEDENT THE + -

k) A program that prints three lines of output must contain three printfs.
F 
YOU CAN USE LOOPS FOR EX OR ITERATORS ETC


------------------------------------

2.3 Write a single C statement to accomplish each of the following.

a) Define the variable number to be of type int and initialize it to 0.

b) Prompt the user to enter an integer. End your prompting message with a
   colon (:) followed by a space and leave the cursor positioned after the space.

c) Read an integer from the keyboard and store the value in integer variable a.

d) If number is not equal to 7, display "number is not equal to 7."

e) Display "This is a C program." on one line.

f) Display "This is a C program." on two lines so the first line ends with C.

g) Display "This is a C program." with each word on a separate line.

h) Display "This is a C program." with the words separated by tabs.

*/

// Exercise 2.3 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void exercise_2_3( void )
{ 
   // a & b & c
   int integer = 0;

   printf( "%s", "Input an integer: " ); // prompt
   scanf( "%d", &integer ); // read integer

   if (&integer != 7){
      printf("%s", "number is not equal to 7.");
   };
   printf("%s", "Sucess");


}



void efgh(char text[])
{
   // // e
   // printf("%s\n\n", text);

   // // f
   // char *first = text;   // start of string
   // char *second = NULL;

   // // \0 is the end
   // for (int i=0; text[i] != '\0' ;i++)
   // {
   //    if (text[i]  == 'C')
   //    {
   //       text[i+1]   = '\0'; // +1 to grab C
   //       second = &text[i + 2]; // +2 to go over  C and grab program
   //       break;
   //    }
   // }

   // printf("First: %s\n", first);
   // printf("Second: %s\n", second);


   //g
   
   // for (int i=0; text[i] != '\0' ;i++){
   //    if (text[i] == ' ')
   //    {
   //       text[i] = '\n';
   //    }
   // }
   // printf("%s", text);

   

   //h
   for (int i=0; text[i] != '\0' ;i++){
      if (text[i]  == ' ')
      {
         text[i] = '-';
      }
   }
   printf("%s", text);

}

int main( void )
{
   char txt[] = "This is a C program.";
   efgh(txt);
   //exercise_2_3();
   return 0;
}


/*
====================================
Exercises
====================================

2.19 (Arithmetic, Largest Value and Smallest Value)

Write a program that inputs three different integers from the keyboard,
then displays the sum, the average, the product, the smallest and the
largest of these numbers. Use only the single-selection form of the if
statement you learned in this chapter. The screen dialogue should appear
as follows:

Enter three different integers: 13 27 14
Sum is 54
Average is 18
Product is 4914
Smallest is 13
Largest is 27


------------------------------------

2.22 (Odd or Even)

Write a program that reads an integer and determines and displays whether
it’s odd or even. Use the remainder operator. An even number is a multiple
of two. Any multiple of two leaves a remainder of zero when divided by 2.
*/
