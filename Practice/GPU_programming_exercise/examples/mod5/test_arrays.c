// program to test various things about C arrays
#include <stdio.h>
#include <string.h>

char aColor2[] = "teal";
const char *color2Ptr = "teal";

char anyColor[];        // throws a warning

int main(void) {

    char aColor[] = "aqua";
    char aColor3[] = "aqua";
    const char *colorPtr = "aqua";

    // anyColor = aColor; compiler disallows because declared arrays are static

    printf("aColor3 %p aColor %p\n",  // proves while static do not point to same array
            aColor3, aColor);
            
    // print out a sample of the first 10 error messages
    for (int i = 0; i < 11; i++) {
        printf("Error message for %d: %s \n", i, strerror(i));
    }
20
    // test string comparison
    char str1[40] = "Hello Kurt";
    char str2[40];
    strcpy(str2, str1);
    printf("str1(%p): %s str2(%p): %s\n",
        str1, str1, str2, str2);
    printf("str1(%p) is the same as str2(%p): %s\n",
        str1, str2, str1 == str2 ? "TRUE" : "FALSE");
    printf("str1(%p) is the same as str2(%p): %s\n",
        str1, str2, strcmp(str1, str1) == 0 ? "TRUE" : "FALSE");

    int diffFlag = 1;
    for (int i = 0; i < 40; i++) {
        diffFlag &= str1[i] == str2[i] && diffFlag;
        printf("Strings match: [%c] == [%c] %s %d diffflag: %d\n", 
            str1[i], str2[i],  str1[i] == str2[i] ? "True" : "False", str1[i] == str2[i], diffFlag);
        if (str1[i] == '\0' || str2[i] == '\0')
            break;
    }
    printf("Strings match: %s", diffFlag ? "True" : "False");
    

    // read a string from stdin into a short buffer
    /*
    printf("Enter some text greater than 5 characters fallowed by return.\n");
    char buffer[5];
    char lBuffer[256];
    fgets(buffer, 5, stdin);
    //print("first part is %s", )
    fgets(lBuffer, 256, stdin);
    printf("First 5 chars: %s  remainder of entry: %s\n", buffer, lBuffer);
    */

}