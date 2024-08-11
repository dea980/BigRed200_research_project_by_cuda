// program to demonstrate printing binary from hex
#include <stdio.h>

void printBinary(unsigned char val, char array[], int a_size);

int main(void) {

    unsigned char myNum = 0xAC;
    char array[9] = {};             // buffer for binary representation C-string

    printBinary(myNum, array, sizeof(array));
    printf("My number %x in binary is %s", myNum, array);

}

// Expected binary representation in C-string returned in array
// s is the size of the array passed in
void printBinary(unsigned char val, char array[], int s) {

    for (int i = s - 2; i > -1; i--) {      // why subtract 2 from the size?
        array[i] = (val & 1) ? '1' : '0';   // tenary operator ; what's the result of the bitwise and
        val >>= 1;                     // left shift effectively divide by 2
    }
}