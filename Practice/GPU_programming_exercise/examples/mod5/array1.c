
#include <stdio.h>


void myFunc(int a);
void myFunc2(int a[]);

int main(void) {
    int foo2[3] = {4,5,6};
    // int foo[4][3] = { {10,20,30}};
    int myVar = 100;

    // foo2 == &foo2[0];

    myFunc(myVar);
    printf("Main myVar: %d\n", myVar);

    // myFunc(foo2);

    printf("Main foo2[0]: %d\n", foo2[0]);
    myFunc2(foo2);
    printf("Main foo2[0]: %d\n", foo2[0]);

}

void myFunc2(int * a) {
    for (int i = 0; i < 3; i++) {
        printf("myFunc a[%d]: %d  -- a + i: %d\n", i, a[i], *(a + i));
    }

    // a[0] *= a[0];
    // printf("myFunc2 a[0]: %d\n", a[0]);
}

void myFunc(int a) {
    a *= a;
    printf("myFunc a: %d\n", a);
}