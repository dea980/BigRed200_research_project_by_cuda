#include <stdio.h>

void myFunc(int a[4]);
void myFunc2(int a);

int main(void) {

    int arr1[] = {1, 2,3, 4};
    int* aPtr = arr1;

    int myTemp = 0;
    int *pTemp;
    pTemp = &myTemp;
    *pTemp = 1200;

    printf("pTemp: %d  *pTemp: %p  &myTemp:%p\n", *pTemp, pTemp, &myTemp);


    printf("aPtr[3]: %d\n", aPtr[3]);
    printf("*(aPtr+3): %d\n", *(aPtr+3));
    printf("*(arr1 + 3): %d\n", *(arr1 + 3));
    printf("arr1+3: %p\n", arr1 + 3);

    // myFunc(arr1);
    // myFunc2(arr1[0]);
    // myFunc2(*arr1);

    // printf("&arr1[1]: %p  *arr1: %p\n", &arr1[0], &arr1);
    // printf("&arr1[1]: %d  *arr1: %d\n", sizeof(&arr1[0]), sizeof(arr1));

}

void myFunc(int a[4]) {
    printf("&a[1]: %p  *a: %p\n", &a[0], a);
}

void myFunc2(int b){
    printf("b: %d\n", b + 1);
}