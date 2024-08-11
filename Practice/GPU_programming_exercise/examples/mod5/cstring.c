// exploring the use of c-strings
#include <stdio.h>

int main(void) {
    char buf[5];

    // printf("Enter some text not longer than 4 characters: ");
    // scanf(" %4s", buf);
    // printf("\nYou entered: %s\n", buf);

    printf("Enter some text not longer than 4 characters (unprotected): ");
    scanf(" %s", buf);
    printf("\nYou entered: %s\n", buf);

}