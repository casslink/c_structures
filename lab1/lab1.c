#include <stdio.h>
#include <math.h>
 
int main () {
 //Part 1: Printing Hello World
 printf("Hello World!\n\n"); //print statment for Hello World     
 
 //Part 2A: Evaluating Expressions
 //declaring variables for expressions
 double x = 2.55; //given x 
 double result1;
 double result2;

 //evaluate expression 3x^3 - 5x^2 + 6 for x = 2.55
 result1 = ((3 * pow(x,3)) - (5 * pow(x,2))) + 6;                 
 printf("First expression answer = %f\n", result1);

 //evaluate expression (3.31 * 10^-8 * 2.01 * 10^-7) / (7.16 * 10^-6 + 2.01 * 10^-8)
 result2 = (3.31 * pow(10,-8) * 2.01 * pow(10,-7)) / ((7.16 * pow(10,-6)) + (2.01 * pow(10,-8)));
 printf("Second expression answer = %.12f\n\n", result2);
  
 //Part 2B: For an integer i find next largest even multiple of another integer j
 //declatation of multiple i and j integers
 int i1 = 365, i2 = 12258, i3 = 996;
 int j1 = 7, j2 = 28, j3 = 4;
 int next_multiple1 = i1 + j1 - i1 % j1; //declaration of result and definition of formula
 int next_multiple2 = i2 + j2 - i2 % j2;
 int next_multiple3 = i3 + j3 - i3 % j3;

 printf("Next multiple of i = %d when j = %d is %d\n"
        "Next multiple of i = %d when j = %d is %d\n"
        "Next multiple of i = %d when j = %d is %d\n\n",
        i1, j1, next_multiple1,
        i2, j2, next_multiple2,
        i3, j3, next_multiple3);
 
 //Part 2C: Type Casting Results from Part 2B
 //type cast to double
 double next_multiple_double1 = (double) i1 + j1 - i1 % j1;
 double next_multiple_double2 = (double) i2 + j2 - i2 % j2;
 double next_multiple_double3 = (double) i3 + j3 - i3 % j3;

 //type cast to char         
 char next_multiple_char1 = (char) next_multiple_double1;
 char next_multiple_char2 = (char) next_multiple_double2;
 char next_multiple_char3 = (char) next_multiple_double3;

 //type cast to int
 int next_multiple_int1 = (int) next_multiple_double1;
 int next_multiple_int2 = (int) next_multiple_double2;
 int next_multiple_int3 = (int) next_multiple_double3;
 
 //print statements for each type cast: double, char, int in that order
 printf("Type cast to double:\n"
        "Next multiple of i = %d when j = %d is %f\n"
        "Next multiple of i = %d when j = %d is %f\n"
        "Next multiple of i = %d when j = %d is %f\n\n",
        i1, j1, next_multiple_double1,
        i2, j2, next_multiple_double2,
	i3, i3, next_multiple_double3);

 printf("Type cast to char:\n"
        "Next multiple of i = %d when j = %d is %c\n"
        "Next multiple of i = %d when j = %d is %c\n"
        "Next multiple of i = %d when j = %d is %c\n\n",
        i1, j1, next_multiple_char1,
        i2, j2, next_multiple_char2,
	i3, j3, next_multiple_char3);

 printf("Type cast to int:\n"
        "Next multiple of i = %d when j = %d is %d\n"
        "Next multiple of i = %d when j = %d is %d\n"
        "Next multiple of i = %d when j = %d is %d\n\n",
        i1, j1, next_multiple_int1,
        i2, j2, next_multiple_int2,
        i3, j3, next_multiple_int3);
  return 0;
}
