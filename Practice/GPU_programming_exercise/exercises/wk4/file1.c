/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

#include <stdio.h>

int main(){
    int limit = 10, even_product = 1, odd_product = 1, sum = 0;
    char c;
    int i;
    
    printf("The value of limit is %d\n", limit);
    
    for(i = 1; i <= limit; ++i){
       if(i % 2 == 0){  // 짝수 확인
           even_product *= i;  // 짝수의 곱
       } else {  // 홀수 확인
           odd_product *= i;  // 홀수의 곱
       }
    }
    
    sum = even_product * odd_product;  // 홀수와 짝수 곱의 합
    printf("The Sum = %d\n", sum);
    
    // 'Z'부터 'B'까지 2칸씩 건너뛰며 출력
    for(c = 'Z'; c >= 'A'; c -= 2){
        printf("%c ", c);
    }
    printf("\n");
    
    return 0;
}