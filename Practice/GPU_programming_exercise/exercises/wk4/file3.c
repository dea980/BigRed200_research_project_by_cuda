/*Debugging quiz - File No: 3 */
/* This program should perform the duties of a calculator
    The program should ask for the input until 'q' is entered.
    For each operation, print the result and then print whether the result is >100 or <100 or equal to 100
    Finally, print the number of calculations done until 'q' is entered */

// Check for possible logical errors and rectify them


#include<stdio.h>

int main(void){
  char input = 0;
  int num1, num2, result = 0, count = 0;
   
  while(input != 'q')
  {
    printf("Welcome to the Calculator\nOperation choices:\tAddition(A)\n\t\t\tSubtraction(S)\n\t\t\tMultiplication(M)\n\t\t\tDivision(D)\nEnter choice: ");

    scanf(" %c", &input);

    if(input == 'q') {
      break;  // 'q'가 입력되면 루프 종료
    }

    if(input == 'A' || input == 'S' || input == 'M' || input == 'D'){
      printf("Enter both numbers in required sequence: ");
      scanf("%d %d", &num1, &num2);
      
      switch(input){
          case 'A':
                  result = num1 + num2;  // 덧셈 연산 수정
                  break;
          case 'S':
                  result = num1 - num2;  // 뺄셈 연산 수정
                  break;
          case 'M':
                  result = num1 * num2;  // 곱셈 연산 수정
                  break;
          case 'D':
                  if(num2 != 0) {
                    result = num1 / num2;  // 나눗셈 연산 추가
                  } else {
                    printf("오류: 0으로 나눌 수 없습니다.\n");
                    continue;
                  }
                  break;
          default:
                  printf("잘못된 연산자입니다.\n");
                  continue;
      }
      
      printf("Result is %d\n", result);
      
      if(result > 100){
        printf("Greater than 100.\n");
      }
      else if(result < 100) {
        printf("Less than 100\n");
      }
      else {
        printf("Equal to 100\n");
      }
      
      count++;  // 연산 횟수 증가
    } else {
      printf("Please choose a valid operation\n");
    }
  }
  
  printf("Number of operations performed: %d\n", count);
  printf("Quit the menu.\n");
  return 0;
}