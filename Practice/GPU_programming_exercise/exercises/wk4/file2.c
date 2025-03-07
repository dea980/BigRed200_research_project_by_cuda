// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 812, exchange = 424
Output :
812-424-0001
812-424-0002
812-424-0003
.
.
812-424-9998
812-424-9999
 */

#include<stdio.h>
  
int main(){
   int digit1, digit2, digit3, digit4;
   int areaCode, exchange;
   
   printf("Hello, I am a telemarketing calling making program.\n");
   printf("Enter a three-digit area code: ");
   scanf("%d", &areaCode);
   
   printf("Enter a three-digit exchange to call: ");
   scanf("%d", &exchange);
   
   // 0000부터 9999까지 모든 4자리 숫자 조합 생성
   for(digit1 = 0; digit1 <= 9; ++digit1){
        for(digit2 = 0; digit2 <= 9; ++digit2){
            for(digit3 = 0; digit3 <= 9; ++digit3){
                for(digit4 = 0; digit4 <= 9; ++digit4){
                    printf("Dialing (%d) %d - %d%d%d%d\n",
                           areaCode, exchange, digit1, digit2, digit3, digit4);
                    printf("I am calling to tell you to buy a subscription to Dogs Monthly!\n");
                }
            }
        }
   }
    
   printf("\nCalls completed\n");
   return 0;
}