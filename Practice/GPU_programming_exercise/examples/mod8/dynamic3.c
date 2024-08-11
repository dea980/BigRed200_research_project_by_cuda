// Demonstrate realloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

#define WRD_BUF_SZ 250
#define INPUT_BUF_SZ 10

/*
    ** Types **

*/
typedef struct Word Word;
struct Word {
    char * word_string;
    int length;
    int occurances;
    Word * next_word;
};

/*
    ** Prototypes **
*/
void find_options(int argc, char *argv[]);
Word* have_seen(Word* wrd_list, Word* new_wrd);
Word* fetch_input_word();
Word* have_seen(Word* wrds, Word* aWord);
void print_report(Word * wrd_list);
int sum_chars(Word* wrds);
int count_words(Word* wrds);


/*
    ** Global Variables **
*/
// Define option flags
int opt_char_total = false, 
    opt_word_cnt = false,
    opt_word_pos = false,
    opt_word_sort = false,
    opt_verbose = false;


int main(int argc, char *argv[]) {
    Word *wrd_list = NULL, *last_wrd = NULL, *new_wrd, *seen_wrd;
    int wrd_cnt = 0;


    find_options(argc, argv);
    while ((new_wrd = fetch_input_word()) != NULL) {
        wrd_cnt++;
        if (wrd_list == NULL) {     // first word found
            wrd_list = new_wrd;
            last_wrd = new_wrd;
            continue;
        }
        if ((seen_wrd = have_seen(wrd_list, new_wrd)) == NULL) {  // novel word
            last_wrd->next_word = new_wrd;
            last_wrd = new_wrd;
        } else 
            seen_wrd->occurances++;    
    }
    print_report(wrd_list);
}

/*
    Reports the information about the words found.
*/
void print_report(Word * wrd_list) {
    assert(wrd_list != NULL);
    printf("Total characters in words: %d\n", sum_chars(wrd_list));
    printf("Word Count: %d\n", count_words(wrd_list));
    printf("Word list with positions:\n");
    do {
        printf("Word: %s  Length: %d   Occurances: %d\n",
            wrd_list->word_string, 
            wrd_list->length, 
            wrd_list->occurances);
        wrd_list = wrd_list->next_word;
    } while (wrd_list->next_word != NULL);
}

Word* have_seen(Word* wrds, Word* aWord) {
    Word* cur_wrd = wrds;
    // printf("Initial word: %s\n", cur_wrd->word_string);
    // printf("next_word: %p\n", cur_wrd->next_word);
    // printf("Looking for: %s\n", aWord->word_string);
    while(cur_wrd != NULL) {
        if (strcmp(cur_wrd->word_string, aWord->word_string) == 0) {
            // printf("Found word: %s\n", cur_wrd->word_string);
            return cur_wrd;
        }
        else 
            cur_wrd = cur_wrd->next_word;
    }
    return NULL;
}

int sum_chars(Word* wrds) {
    assert(wrds != NULL);
    int cnt = 0;
    while (wrds != NULL) {
        cnt += wrds->length;
        wrds = wrds->next_word;
    }
    return cnt;
}

int count_words(Word* wrds) {
    assert(wrds != NULL);
    int cnt = 0;
    while (wrds != NULL) {
        cnt++;
        wrds = wrds->next_word;
    }
    return cnt;
}

/*
    Processes all the arguments on the command line and sets the corresponding option
    global variables
*/
void find_options(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp("-s", argv[i]) == 0)
            opt_word_sort = true;
        if (strcmp("-c", argv[i]) == 0)
            opt_char_total = true;
        if (strcmp("-w", argv[i]) == 0)
            opt_word_cnt = true;
        if (strcmp("-p", argv[i]) == 0)
            opt_word_pos = true;
        if (strcmp("-v", argv[i]) == 0)
            opt_verbose = true;
    }

    // printf("DEBUG -- opt_verbose: %d\n", opt_verbose);
}

/* 
    Processes stdin characters until reaching EOF.
    Returns a word struct
*/
Word * fetch_input_word() {
    char * word_buffer = malloc(INPUT_BUF_SZ * sizeof(char));
    if (opt_verbose)
        printf("DEBUG -- allocating initial word buffer\n");
    int cntr = 0;
    int in_word = false;
    char next_char;

    while (EOF != (next_char = getchar())) {
        if (isalpha(next_char)) {
            word_buffer[cntr++] = next_char;
            in_word = true;
            if ((cntr % INPUT_BUF_SZ) == 0) {     // grow the buffer if filled
                int scale = (cntr / INPUT_BUF_SZ) + 1;
                if (opt_verbose)
                    printf("DEBUG -- reallocating word buffer: %d\n", scale);
                realloc(word_buffer, scale * INPUT_BUF_SZ * sizeof(char));
        }
        } else if (in_word)
            break;  // no longer processing a word
    }
    if (cntr == 0)
        return NULL;
    word_buffer[cntr] = '\0';
    Word * word = malloc(sizeof(Word));
    word->word_string = word_buffer;
    word->length = cntr;
    word->occurances = 1;
    word->next_word = NULL;
    if (opt_verbose)
        printf("DEBUG -- found word: %s\n", word->word_string);
    return word;
}

