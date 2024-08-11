// demo of process communication with popen
#include <stdio.h>
#include <stdlib.h>

void print_all(FILE *stream) {
    int c;
    while (EOF != (c = getc(stream))) {
        putchar(c);
        // fprintf(stderr, "printing %d\n", c);
    }
    fflush(stdout);
}

int main(int argc, char* argv[]) {
    FILE *stream;

    if ((stream = popen("ls -l", "r")) == NULL) {
        perror("ls -l");
        exit(EXIT_FAILURE);
    } 
    print_all(stream);
    pclose(stream);
    exit(EXIT_SUCCESS);

}