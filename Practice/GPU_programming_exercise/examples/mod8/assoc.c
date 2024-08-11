// experimenting with assoicativity

#include <stdio.h>

int main(void) {

    int a = 3;
    int b = 10;

    printf("%d\n", a++ + 3 - b * 10 - 4 + ++a);
    printf("%d\n", a++ + 3 - b * 10 - 4 + ++a);


}