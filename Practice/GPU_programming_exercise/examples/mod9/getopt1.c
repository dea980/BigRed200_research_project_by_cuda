// demo of processing options with the getopt_long call in unistd.h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>



int main(int argc, char* argv[]) {

    char *filepath;
    
    FILE *fp;
    int opt;
    int verbose = false;
    int lines = false;
    char prefix[50] = {0};
     

    while ((opt = getopt(argc, argv, "vhlp:")) != -1) {
        switch(opt) {
            case 'v': 
                verbose = true;
                fprintf(stderr, "Will print debugging lines.\n");
                break;
            case 'h':
                fprintf(stderr, "Usage: %s [-l] [-h] [-v] [-p prefix] name\n",
                           argv[0]);
                exit(EXIT_SUCCESS);
                break;
            case 'l':
                lines = true;
                fprintf(stderr, "Will print line number before each line.\n");
                break;
            case 'p':
                strcpy(prefix,optarg);
                fprintf(stderr, "Will use the following prefix for each line: %s\n", prefix);
                break;
            default: // '?' or illegal option discovered
                fprintf(stderr, "Usage: %s [-l] [-h] [-v] [-p prefix] name\n",
                           argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    filepath = argv[optind];
    if (filepath == NULL) {
        fprintf(stderr, "Filename required.\n");
        fprintf(stderr, "Usage: %s [-l] [-h] [-v] [-p prefix] name\n",
                           argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("File to open is %s\n", filepath);

    fp = fopen(filepath, "r");
    if (!fp) {
        perror("Failed to open file.");
        exit(EXIT_FAILURE);
    }

    ssize_t line_size;
    char *line_buffer = NULL;
    size_t line_buffer_size = 0;
    int line_count = 0;
    
    line_size = getline(&line_buffer, &line_buffer_size, fp);
    while (line_size >= 0) {
        line_count++;

        if (lines) 
            printf("%4d\t", line_count);
        if (prefix[0] != 0)
            printf("%s", prefix);
        printf("%s",line_buffer);
        line_size = getline(&line_buffer, &line_buffer_size, fp);
    }

    fclose(fp);




}
