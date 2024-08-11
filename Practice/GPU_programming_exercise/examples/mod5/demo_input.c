// program to demo stdin, stdout, stderr
#include <stdio.h>


int main(void) {

    char input[256]; 
    char quit_flag = 1;

    // Simple menu choice
    while (quit_flag) {
        int cnt = 0;
        char code;

        fprintf(stdout, "enter a code and values on each line:\n");
        fgets(input, 256, stdin);
        cnt = sscanf(input, "%c", &code); 
        if (cnt < 1) {
            fprintf(stderr, "Unreadable code %s\n", input);
            continue;
        }    
        switch (code) {
            case 'A':
            case 'a':
                {int hours;
                int rate;
                cnt = sscanf(input, "%c %d %d", &code, &hours, &rate);
                fprintf(stdout, "read: %d Code A: hours: %d rate: %d\n", cnt, hours, rate);
                break;}
            case 'B':
            case 'b':
                {char make[25] = {};
                char model[25] = {};
                sscanf(input, "%c %s %s", &code, make, model);
                fprintf(stdout, "Code %c: Make: %s Model:%s\n", code, make, model);
                break;}
            case 'Q':
            case 'q':
                fprintf(stderr, "Exiting normally\n");
                quit_flag = 0;
                break;
            default: 
                fprintf(stderr, "No valid option entered.\n");
                break;

        }
    }
}