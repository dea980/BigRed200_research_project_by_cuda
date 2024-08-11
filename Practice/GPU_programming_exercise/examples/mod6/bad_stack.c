// demo of using pointers to automatic variables

# include <stdio.h>

// prototype for 
int * myFunc(int value);

int main(void) {

    int a = 11;
    int *ptrA = &a;    

    int *newValue = myFunc(a);
    printf("The value from myFunc was: %d\n", *newValue);


}

// returns pointer to calculated value
int * myFunc(int value) {
    int myVal = value * 10;
    return &myVal;
}
