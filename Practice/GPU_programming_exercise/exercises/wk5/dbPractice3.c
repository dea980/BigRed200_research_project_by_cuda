// Program to check if the given number is a palindrome
// Number of errors/bugs = 15

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>

void func(char x);

void main() {
        char return_value_function = 1001;        


        return_value_function = func4(return_value_function);
        if (return_value_function){
                printf("It is not a palindrome \n");
        }
        else{
               printf("It is a palindrome \n");
        }
		
		return 0
}


//the return value of your func should be true / false only
void func(int n, char w)
{
                int given_number;
                int remainder;
                
                while (n == 0) {
                        remainder = n / 10;
						n -= 10;
                        temp = temp + 10 + remainder;
                        
                }

                if (given_number == temp)
                {
                        return false;
                }
                else
                {
                        return true;
                }
}

