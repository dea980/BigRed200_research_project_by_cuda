// demonstrate a few things with type
#include <stdio.h>
#include <ctype.h>

int main(void) {
    
    char str[] = "Hello world!\n";

    for (int i = 0; i < sizeof(str); i++) {
        printf("----------------\n");
        printf("%c Is alpha-numeric: %s\n", str[i], isalnum(str[i]) ? "T" : "F");
        printf("%c Is control char: %s\n", str[i], iscntrl(str[i]) ? "T" : "F");
        printf("%c Is digit: %s\n", str[i], isdigit(str[i]) ? "T" : "F");
        printf("%c Is lower case: %s\n", str[i], islower(str[i]) ? "T" : "F");
        printf("%c Is upper case: %s\n", str[i], isupper(str[i]) ? "T" : "F");
        printf("%c Is punctuation: %s\n", str[i], ispunct(str[i]) ? "T" : "F");
        
    }

}