// C 언어 포인터와 연산자 예제
#include <stdio.h>
#include <string.h>
#include <math.h>

int myFunc(int* a);

int main(void) {
    // 16진수 출력 예제
    int num = 0x1A0;
    printf("16진수 값 출력: %x\n", num);

    // 후위 증가 연산자 예제
    int m = 9;
    // m++는 현재 값(9)을 사용한 후 증가, 그 다음 (m % 5)에서는 m이 10이 됨
    printf("후위 증가 연산 결과: %d\n", (m++ + (m % 5)));

    // 수학 함수 사용 예제
    float a = 7.0, b = 7.0, c = 6.0;
    printf("sqrt(a + b * c) 결과: %.2f\n", sqrt(a + b * c));

    // 논리 연산자 예제 (0이 아닌 값은 모두 참)
    printf("논리 AND 연산 결과: %x\n", 0xAB1D && 010477);

    // 포인터 함수 호출 예제
    int value = 100;
    printf("함수 호출 전 값: %d\n", value);
    printf("함수 반환 값: %d, 저장된 값: %d\n", myFunc(&value), value);

    // 문자열 포인터 배열 예제 (주석 해제하여 사용 가능)
    char* words[4] = {"Hello", "Good", "Dig", "Cat"};
    char words2[4][6] = {"Hello", "Good", "Dig", "Cat"};

    printf("words 배열 크기: %lu 바이트\n", sizeof(words));
    
    int totalSize = 0;
    for (int i = 0; i < 4; i++) {
        totalSize += strlen(words[i]);
    }
    printf("words 문자열 총 길이: %d\n", totalSize);

    printf("words2 배열 크기: %lu 바이트\n", sizeof(words2));
    printf("words2 첫 번째 문자: %c\n", words2[0][0]);

    printf("words+1 역참조 결과: %c\n", **(words + 1));
    printf("words[1] 역참조 결과: %c\n", *(words[1]));
    printf("words[1][0] 결과: %c\n", words[1][0]);

    return 0;
}

int myFunc(int* ptr_a) {
    (*ptr_a)++;  // 포인터가 가리키는 값 증가
    printf("포인터 주소: %p, 역참조 값: %d\n", ptr_a, *ptr_a);
    return *ptr_a;
}