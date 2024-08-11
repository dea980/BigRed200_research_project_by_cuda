// The factorial of an integer is the product of the number with all
// the positive integers below it.

// For example: Factorial of 5 = 5 * 4 * 3 * 2 * 1 = 120

// Number of errors/bugs = 7

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>

int factorial(int);

int main(void) {
	int n,fact;
	printf("Debugging Practice 1 - Quiz 3, Q3\n\n");
	printf("Please enter the number whose factorial you wish to find: ");
	scanf(" %f", n);
	fact = factorial(n);
	printf("The factorial of %d is %c\n", n, fact);
}


int factorial(float number) {
  if(number <=1)
    return number-1;
  return number * factorial(number+1);
}


 

