#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int binary_printer(unsigned int dec_num);
 //function defined below main for part 2 so it is declared before main 
int main () {
 //PART 1 
 //variable declarations and definitions, first two numbers are 0 and 1
 int fib_num1 = 0; 
 int fib_num2 = 1;
 int next_fib_num;
 int counter = 1;
 //the fibonacci sequence generator
 printf("Fibonacci Sequence starts with:\n%d, %d", fib_num1, fib_num2);
 while(counter < 20) {
   next_fib_num = fib_num2 + fib_num1; //additon of two most recent terms
   fib_num1 = fib_num2; //shifts most recent terms to include addition above
   fib_num2 = next_fib_num;
   printf(", %d", next_fib_num);
   counter++;
 }
 printf("\n");

 //PART 2A
 binary_printer(2); //function call on binary printer for each test variable
 binary_printer(255);
 binary_printer(32);
 binary_printer(-1);
 binary_printer(-255);

 //PART 2B
 binary_printer((rand() % INT_MAX) + (rand() % INT_MIN));
 //function call on binary printer with random number input
 return 0;
}

//Binary printer: Takes decimal input and prints out string of its binary value
int binary_printer(unsigned int dec_num) {
  int special_int = (INT_MAX/2) + 1; //0b1000000000000000000000000000000, create a mask of all zeros except for 1 in leftmost bit
 printf("The decimal number %d in binary is: ", dec_num);
 int size_of_int;
 for(size_of_int = 0; size_of_int < 31; size_of_int++) {
   //if the chosen binary number has a 0 than it will get ANDed with 1 and print a 0
   if ((special_int & dec_num) == 0) { 
     printf("0");
   }
   //if the chosen binary number has a 1 than it will get ANDed with 1 and print a 1
   else {
     printf("1");
   }
   //The 1 in the special integer will be right shifted to check the next bit in the chosen binary number
   special_int = special_int >> 1;
 }
 printf("\n");
 return 0;
}
