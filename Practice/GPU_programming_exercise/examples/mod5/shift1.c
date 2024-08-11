// program to demonstrate use of shift operator
#include <stdio.h>

int main(void) {
    unsigned long myNum = 25;

    printf("Shifting right %lu\n", myNum);

    for (int i = 0; i < 8; i++) {
        myNum <<= 1;
        printf("Result of shifting %d: %lu\n", i+1, myNum);
    }

    printf("Shifting left %lu\n", myNum);
    for (int i = 0; i < 8; i++) {
        myNum >>= 1;
        printf("Result of shifting %d: %lu\n", i+1, myNum);
    }
}