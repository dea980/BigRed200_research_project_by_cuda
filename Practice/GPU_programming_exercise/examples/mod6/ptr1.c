// simple program to play with pointers
#include <stdio.h>

void revArray(int *array, int **revArray);
void printArr(int* array, int size);
void printArr2(int array[5]);

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};

    int* ptr1 = arr;

    printf("Address of array: %p\n", arr);
    printf("Address of array: %p\n", &arr);
    

    printf("ptr1 Address of array: %p\n", ptr1);
    printf("&ptr1 Address of array: %p\n", &ptr1);

    printArr(arr, 5);
    printArr(&arr,5);
    printArr2(arr);
    printArr2(&arr);
    printArr2(&arr[0]);
    printArr2(ptr1);
    printArr2(arr);
/*
    printf("Address pointed to by ptr: %p\n", ptr1);
    printf("Value in pointer: %d\n", *ptr1);

    int *ptr2 = ptr1 + 2;

    printf("Value in ptr + 2: %d\n", *ptr2);
    printf("Value in ptr + 2: %d\n", *(ptr1 + 2));

    int *revArr[5] = {};
    revArray(arr, revArr);

    for (int i = 0; i < 5; i++) {
        printf("Index - %d  Arr: %d  @ %p  revArr: %d @ %p\n",
            i, arr[i], &arr[i], *revArr[i], revArr[i]);
    }
*/
}

void printArr2(int array[5]) {
    printf("Calling printArr\n");
    printArr(array, 5);
}

void printArr(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, *(array+i));
    }
}

void revArray(int* array, int** revArr) {
    for (int i = 0; i < 5; i++) {
        revArr[4-i] = &array[i];
    }
}