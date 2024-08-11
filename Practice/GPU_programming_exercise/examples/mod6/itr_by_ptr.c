// Sample showing iterating over an array by pointers.
#include <stdio.h>

#define SIZE 10

int main(void) {
    int arr[] = {1,2,3,4,5,6,7,8,9,0};

    for (int * p = arr; p < arr + SIZE; p++) {
        printf("%d @ %p\n", *p, p);
    }
}

