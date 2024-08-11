// Demonstrate realloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define WRD_BUF_SZ 250
#define INPUT_BUF_SZ 10


char * get_user_input(int * buf_size);
int find_word(char * const in_buf, int buf_size, char * wrd_buf, int strt_index);


int main(void) {
    
    int i_buf_sz = 0;
    printf("Input a line with words(^D to end):\n");
    char * input_buffer = get_user_input(&i_buf_sz);
    // printf("DEBUG -- Buffer: %d\n", i_buf_sz);
    // return 0;
    

    int index = 0;
    while (index < i_buf_sz) {
        int new_index = 0;
        char * wrd_buf = malloc(WRD_BUF_SZ);
        if (wrd_buf == NULL) 
            break;
        new_index = find_word(input_buffer, i_buf_sz, wrd_buf, index);
        if (new_index == index) {
            break;
        } else 
            index = new_index;
        int word_length = strlen(wrd_buf);
        char * rsz_wrd_buf = realloc(wrd_buf, word_length + 1);
        if (rsz_wrd_buf == NULL)
            break;
        printf("Word: %s Length: %d String Addr:%p\n", rsz_wrd_buf, (int)strlen(rsz_wrd_buf), wrd_buf);
        
    }
    
}


// Returns an input_buffer that it allocates. (Caller must free it.)
// takes a pointer to the buffer size and returns the total size of the buffer 

char * get_user_input(int * buf_size) {
    int char_cnt = 0;

    char * i_buf = malloc(INPUT_BUF_SZ * sizeof(char));
    int i_buf_sz = INPUT_BUF_SZ;
    if (i_buf == NULL) 
        return NULL;

    char next_char;
    while (EOF != (next_char = getchar())) {
        i_buf[char_cnt++] = next_char;
        
        if (char_cnt > i_buf_sz) {
            printf("DEBUG -- Reallocating buffer: %d to %d\n", char_cnt, i_buf_sz *2);
            char * tmp_buf;
            i_buf_sz *= 2;
            tmp_buf = realloc(i_buf, i_buf_sz * sizeof(char));
            if (tmp_buf == NULL)
                return NULL;
            else
                i_buf = tmp_buf;
        }
    }
    i_buf[char_cnt] = ' ';
    *buf_size = i_buf_sz;
    return i_buf;
}

// Takes an input buffer and scans it for the next word (a-zA-Z separated by non letters)
// Also takes starting index to the input buffer.
// takes a word buffer allocated by the caller to store the word. 
// returns the new index position for the input_buffer
int find_word(char * const in_buf, int buf_size, char * wrd_buf, int strt_index) {
    int w_index = 0;
    int i_index = strt_index;
    int in_word = false;

    while (i_index < buf_size) {
        if (isalpha(in_buf[i_index])) {
            wrd_buf[w_index++] = in_buf[i_index++];
            in_word = true;
        } else {
            if (in_word)
                break;   // we have left the word when we no longer see alpha's
            i_index++;
        }    
    }
    wrd_buf[w_index] = '\0';
    return i_index;
}
