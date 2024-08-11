// exploring an issue from the video
#include <stdio.h>
#include <string.h>
#include <math.h>

int myFunc(int* a);

int main(void) {
    // int a = 100, b = 200;
    // const int*  ptr_a = &a;
    // int* ptr2;

    int num = 0x1A0;
    printf("%x\n", num);

    int m = 9;
    printf("%d\n",( m++ + (m % 5) ) );

    float a = 7.0, b = 7.0, c = 6.0;
    printf("%.2f", sqrt(a + b * c));

    printf("\n\n%x\n", 0xAB1D && 010477);
 

    // (*ptr_a)++;
    // ptr_a = &b;
    // ptr_a++;

    // char* ptr10[4];
    // char * const ptr11[4];

    // char* words[4] = {"Hello", "Good", "Dig", "Cat"};
    // char words2[4][6] = {"Hello", "Good", "Dig", "Cat"};

    // printf("%d\n", sizeof(words));
    // int totalSize = 0;
    // for (int i = 0; i <4; i++) {
    //     totalSize += strlen(words[i]);
    // }
    // printf("Totalsize words: %d\n", totalSize);

    // printf("Totalsize words2: %d\n", sizeof(words2));
    // printf("%c\n", words2[0][0]);

    // printf("%c\n", **(words + 1));
    // printf("%c\n", *(words[1]));
    // printf("%c\n", words[1][0]);


    


    // printf("Value: %d   Memory: %p\n", a, ptr_a);

    
    // printf("Address of a: %p\n", &a);
    // printf("The value returned: %d and the value stored: %d\n", myFunc(&a), a);

}



int myFunc(int* ptr_a) {
    (*ptr_a)++;
    printf("Pointer value: %p Dereferenced value: %d\n", ptr_a, *ptr_a );
    return *ptr_a;

}