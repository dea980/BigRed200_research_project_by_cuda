// demo a few fucntions with C
#include <stdio.h> 
#include <strings.h>

char str1[] = "Hello World";
char str2[] = "Hello|World|how|do|you|do";
char *token;

int main(void) {
    token = strtok(str2, "|");
    printf("First token: %s\n", token);

    while ( token != NULL ) {
        printf("Token: %s\n", token);
        token = strtok(NULL,"|");
    }

    char src[40];
    char dest[100];

    strcpy(src, "Sample text.");
    strcpy(dest, src);
    printf("%s", dest);


}