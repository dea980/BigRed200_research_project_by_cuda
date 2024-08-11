// sample to show const use with pointer
#include <stdio.h>

int main(void) {

    int a, b = 10;
    const int * p1;
    int * const p2 = &b;

    p1 = &b;
    // p2 =  &b;  /* compiler error */

    // *p1 = 99;     /* compiler error */
    *p2 = 99;  

    printf("p1 -> %d\n", *p1);
    printf("p2 -> %d\n", *p2);

}
