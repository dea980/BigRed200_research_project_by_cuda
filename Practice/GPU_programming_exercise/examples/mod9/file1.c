// demonstration of opening a file
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int e = EXIT_SUCCESS;
    
    // default to file output.txt if no file specified
    char *path = (argc > 1) ? argv[1] : "output.txt";

    /* Open file for writing. Other options:
        r  - read only
        a  - append only
        r+ - read and write
        a+ - read and append
    */
   FILE *file = fopen(path, "w");

   if (!file) {
       perror(path);
       return EXIT_FAILURE;
   }

   if (fputs("Output in file.\n", file) == EOF) {
       perror(path);
       e = EXIT_FAILURE;
   }

    // why check if fclose is successful?
   if (fclose(file)) {
       perror(path);
       return EXIT_FAILURE;
   }

    return e;



}