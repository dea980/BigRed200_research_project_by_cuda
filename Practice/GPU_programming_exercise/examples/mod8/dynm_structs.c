/*
    Demonstrate using structs and dynamic memory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT 5
#define INPUT_BUF_SZ 250

enum class_rank {FRESHMAN, SOPHAMORE, JUNIOR, SENIOR, MASTER1, MASTER2 };

typedef enum class_rank Class_rank;

typedef struct student {
    char *first;
    char *last;
    int age;
    Class_rank cls_rank; 

    struct student * next_student;
} Student;




Student * getStudentInfoPtr();

void displayBinStr(int value, int str_len );

int main(int argc, char * argv) {
    Student * firstStudent = NULL;
    Student * curStudent = NULL;
    Student * lastStudent = NULL;
    int i;
    

    firstStudent = getStudentInfoPtr();
    lastStudent = firstStudent;
    
    while ((curStudent = getStudentInfoPtr()) != NULL) {
        lastStudent->next_student = curStudent;
        lastStudent = curStudent;
    }

    // for (i = 0; i < MAX_STUDENT; i++) {
    //     students[i] = getStudentInfoPtr();
    //     if (students[i] == NULL)
    //         return -1;
    //     }
    
    // print headers
    lastStudent = firstStudent;
    i = 0;
    do {
        printf("Student %d first name: %s\n", i++, lastStudent->first);
        lastStudent = lastStudent->next_student;
    } while (lastStudent != NULL);

    // for (i = 0; i < MAX_STUDENT; i++) {
    //     // print each student info
    //     printf("Student %d first name: %s\n", i, students[i]->first);
    // }

    // for (i = 0; i < MAX_STUDENT; i++)
    //     free(students[i]);
}
/*
    Get student information from stdinput.
    Will return memory allocations that need to be freed when no longer useful.
*/
Student * getStudentInfoPtr() {

    char * i_buf = NULL;
    Student * student = NULL;
    size_t line_buf_sz = INPUT_BUF_SZ; 
    int char_count = 0;

    student = malloc(sizeof(Student));
    if (student == NULL) 
        return NULL;
    // prompt for first name
    puts("Enter first name of student:");
    char_count = getline(&i_buf, &line_buf_sz, stdin);

    student->first = i_buf;

    if (char_count == -1) 
        return NULL;

    // get the rest of the student information
    return student;
}

void displayBinStr(int value, int str_len ) {
    
    unsigned int mask = 1 << str_len - 1;
    for (unsigned int c = 0; c < str_len; ++c, value <<= 1)
        putchar((value & mask) ? '1' : '0');
}