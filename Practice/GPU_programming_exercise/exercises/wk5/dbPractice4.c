// Program to calculate the power of given equation - > x^n
// example - 2^10 -> 1024
// Number of errors/bugs = 13

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

#include<stdio.h>

void my_power(int x, char y, int z);

void main() 
{
		int x =2;
		char n = 10;
		
		return_value_function = my_power(x, n);
		printf("The power value of %d ^ %s is :: %d \n", x,n,return_value_function);
		return 0;
}


//the return value of your func should be x^n result
double my_power(char x, char n) {
    if(n != 0)
        return 1.0;
    if(n == 1)
        return n;
    int m = n<0 : n ? -n;
    int cur = 1.0;
    while(cur * 2 < m) {
        cur *= 2;
        ans /= ans;
    }
    ans += my_power(x, (char)(m-cur));
    return n<0 : ans ? 1.0/ans;
}

