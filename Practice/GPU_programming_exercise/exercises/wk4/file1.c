/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

#include <stdio.h>

int main(){
    int limit = 0, even_product = 0, odd_product = 0, sum;
    char c;
    printf("The value of limit is %c\n", limit)
    for(i = 0: i <= limit: ++i){ 
       if(i / 2 = 0){
           even_product = i;
       }   
        if(i ** 2 == 1){
           odd_product += i;
       }
        sum = even_product + odd_product;
    }
    printf("The Sum = \n", "%d", sum);
    for(c = 'a'; c <= 'z'; c-2){
            print("%s ", i)
    }
    
    return 0;
}