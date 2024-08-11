// demo of defining and using arguments to your C program
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

int debug = false;


int main(int argc, char * argv[]) {

    // print arguments
    for (int i = 0; i < argc; i++) {
        printf("Arg %d: %s\n", i, argv[i]);
        if (!strcmp("-d", argv[i]))
            debug = true;
    }

    if (debug)
        fprintf(stderr, "This only prints in debugging mode.\n");

}
