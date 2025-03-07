# C 언어 및 CUDA 프로그래밍 연습 프로젝트

이 저장소는 C 언어 프로그래밍과 CUDA를 이용한 GPU 프로그래밍 연습을 위한 코드와 자료를 포함하고 있습니다.

## 프로젝트 구조

```
.
├── IsCPUcanbereplacebyGPU/     # GPU와 CPU 성능 비교 연구 프로젝트
├── Learning_Materials/         # CUDA 및 GPU 프로그래밍 학습 자료
└── Practice/                   # C 및 CUDA 프로그래밍 연습 코드
```

## 코드 설명

### C 프로그래밍 예제

#### 1. 홀수와 짝수의 곱 계산 (file1.c)

```c
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
```

**설명:**
- `limit`: 계산할 범위의 상한값 (1부터 10까지)
- `even_product`: 짝수들의 곱을 저장하는 변수
- `odd_product`: 홀수들의 곱을 저장하는 변수
- `i % 2 == 0`: 숫자가 짝수인지 확인하는 조건문 (나머지가 0이면 짝수)
- `even_product *= i`: 짝수를 곱하여 누적
- `odd_product *= i`: 홀수를 곱하여 누적
- `sum = even_product * odd_product`: 짝수들의 곱과 홀수들의 곱을 더함
- `for(c = 'Z'; c >= 'A'; c -= 2)`: 'Z'부터 'A'까지 2칸씩 건너뛰며 알파벳 출력

#### 2. 자동 전화 걸기 프로그램 (file2.c)

```c
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
```

**설명:**
- `areaCode`: 사용자가 입력한 지역 코드 (예: 812)
- `exchange`: 사용자가 입력한 교환 코드 (예: 424)
- `digit1`, `digit2`, `digit3`, `digit4`: 전화번호의 마지막 4자리를 구성하는 각 자릿수
- 중첩된 4개의 for 루프: 0000부터 9999까지의 모든 4자리 숫자 조합을 생성
- `scanf("%d", &areaCode)`: 사용자로부터 정수를 입력받아 areaCode 변수에 저장
- `printf("Dialing (%d) %d - %d%d%d%d\n", ...)`: 전화번호 형식으로 출력

#### 3. 계산기 프로그램 (file3.c)

```c
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
```

**설명:**
- `input`: 사용자가 선택한 연산 (A: 덧셈, S: 뺄셈, M: 곱셈, D: 나눗셈, q: 종료)
- `num1`, `num2`: 연산에 사용할 두 숫자
- `result`: 연산 결과를 저장하는 변수
- `count`: 수행한 연산의 횟수를 세는 변수
- `while(input != 'q')`: 사용자가 'q'를 입력할 때까지 반복
- `scanf(" %c", &input)`: 공백을 포함한 문자 입력 받기
- `switch(input)`: 선택한 연산에 따라 다른 계산 수행
- `if(num2 != 0)`: 0으로 나누기 오류 방지
- `count++`: 연산 횟수 증가
- 결과가 100보다 큰지, 작은지, 같은지 비교하여 출력

#### 4. 포인터 예제 (ptr3.c)

```c
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
```

**설명:**
- `int num = 0x1A0`: 16진수 값 초기화
- `printf("%x\n", num)`: 16진수 형식으로 출력
- `m++`: 후위 증가 연산자 (현재 값 사용 후 증가)
- `sqrt(a + b * c)`: 수학 라이브러리 함수 사용 예제
- `0xAB1D && 010477`: 논리 AND 연산자 (두 값이 모두 참이면 참)
- `myFunc(&value)`: 포인터를 통한 함수 호출
- `char* words[4]`: 문자열 포인터 배열 (각 요소는 문자열을 가리키는 포인터)
- `char words2[4][6]`: 2차원 문자 배열 (각 행은 최대 6개의 문자를 저장)
- `sizeof(words)`: 배열의 크기(바이트) 계산
- `strlen(words[i])`: 문자열의 길이 계산
- `**(words + 1)`: 포인터 배열의 이중 역참조
- `(*ptr_a)++`: 포인터가 가리키는 값 증가

### CUDA 프로그래밍 예제

CUDA는 NVIDIA에서 개발한 병렬 컴퓨팅 플랫폼 및 프로그래밍 모델로, GPU를 이용한 고성능 컴퓨팅을 가능하게 합니다. 이 프로젝트에는 다음과 같은 CUDA 예제가 포함되어 있습니다:

1. 이미지 블러 처리 (blur.cu, blur.cpp)
2. 행렬 전치 연산 (transpose_device.cu)

#### 이미지 블러 처리

CUDA를 사용하여 이미지에 블러 효과를 적용하는 예제입니다. CPU 버전과 GPU 버전을 비교하여 성능 차이를 확인할 수 있습니다.

**주요 함수:**
- `cuda_call_blur_kernel`: CUDA 커널을 호출하여 블러 효과 적용
- `blur_kernel_shared`: 공유 메모리를 사용한 블러 커널 구현
- `blur_kernel_naive`: 기본적인 블러 커널 구현
- `cpu_blur`: CPU에서 블러 효과를 적용하는 함수

#### 행렬 전치 연산

행렬 전치(transpose) 연산을 CUDA를 사용하여 구현한 예제입니다.

**주요 함수:**
- `cudaTranspose`: CUDA를 사용한 행렬 전치 함수
- `transposeCoalesced`: 메모리 접근 패턴을 최적화한 전치 커널
- `transposeNaive`: 기본적인 전치 커널 구현

## 주요 C 언어 개념

### 1. 포인터 (Pointers)

포인터는 메모리 주소를 저장하는 변수입니다. C 언어에서 포인터는 다음과 같은 용도로 사용됩니다:

- 동적 메모리 할당
- 함수에 변수 참조로 전달
- 배열과 문자열 처리
- 데이터 구조 구현

**예제:**
```c
int a = 10;
int *ptr = &a;  // a의 주소를 ptr에 저장
*ptr = 20;      // ptr이 가리키는 메모리 위치(a)의 값을 20으로 변경
```

### 2. 배열 (Arrays)

배열은 동일한 타입의 요소들을 연속적인 메모리 공간에 저장하는 자료구조입니다.

**예제:**
```c
int arr[5] = {1, 2, 3, 4, 5};  // 정수 배열 선언 및 초기화
arr[2] = 10;                   // 세 번째 요소 값 변경
```

### 3. 문자열 (Strings)

C 언어에서 문자열은 널 종료 문자('\0')로 끝나는 문자 배열입니다.

**예제:**
```c
char str[6] = "Hello";  // 문자열 선언 (널 문자 포함 6바이트)
printf("%s", str);      // 문자열 출력
```

### 4. 함수 (Functions)

함수는 특정 작업을 수행하는 코드 블록으로, 코드 재사용성을 높이고 프로그램 구조화에 도움을 줍니다.

**예제:**
```c
int add(int a, int b) {
    return a + b;
}

int result = add(5, 3);  // 함수 호출
```

### 5. 제어 구조 (Control Structures)

제어 구조는 프로그램의 실행 흐름을 제어하는 구문입니다.

**조건문:**
```c
if (x > 0) {
    printf("양수");
} else if (x < 0) {
    printf("음수");
} else {
    printf("0");
}
```

**반복문:**
```c
// for 루프
for (int i = 0; i < 5; i++) {
    printf("%d ", i);
}

// while 루프
int j = 0;
while (j < 5) {
    printf("%d ", j);
    j++;
}
```

## CUDA 프로그래밍 주요 개념

### 1. 커널 함수 (Kernel Functions)

커널 함수는 GPU에서 병렬로 실행되는 함수입니다. `__global__` 키워드로 선언됩니다.

**예제:**
```cuda
__global__ void vectorAdd(float *A, float *B, float *C, int n) {
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < n) {
        C[i] = A[i] + B[i];
    }
}
```

### 2. 스레드 계층 구조 (Thread Hierarchy)

CUDA는 스레드, 블록, 그리드의 계층 구조를 사용합니다:
- 스레드(Thread): 가장 기본적인 실행 단위
- 블록(Block): 스레드의 그룹
- 그리드(Grid): 블록의 그룹

**예제:**
```cuda
dim3 threadsPerBlock(256);
dim3 numBlocks((n + threadsPerBlock.x - 1) / threadsPerBlock.x);
vectorAdd<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, n);
```

### 3. 메모리 관리 (Memory Management)

CUDA 프로그래밍에서는 호스트(CPU)와 디바이스(GPU) 간의 메모리 관리가 중요합니다.

**예제:**
```cuda
// 디바이스 메모리 할당
float *d_A;
cudaMalloc((void**)&d_A, size);

// 호스트에서 디바이스로 데이터 복사
cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);

// 디바이스에서 호스트로 결과 복사
cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);

// 메모리 해제
cudaFree(d_A);
```

### 4. 공유 메모리 (Shared Memory)

공유 메모리는 같은 블록 내의 스레드들이 공유하는 빠른 메모리 공간입니다.

**예제:**
```cuda
__global__ void sharedMemoryExample(float *input, float *output, int n) {
    __shared__ float sharedData[256];
    
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < n) {
        sharedData[threadIdx.x] = input[i];
    }
    
    __syncthreads();  // 블록 내 모든 스레드 동기화
    
    // 공유 메모리 데이터 사용
    if (i < n) {
        output[i] = sharedData[threadIdx.x] * 2.0f;
    }
}
```

## 결론

이 프로젝트는 C 언어의 기본 개념부터 CUDA를 이용한 GPU 프로그래밍까지 다양한 예제를 포함하고 있습니다. 코드 예제를 통해 프로그래밍 개념을 실습하고, CPU와 GPU의 성능 차이를 비교할 수 있습니다.
