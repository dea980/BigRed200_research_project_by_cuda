/*
    Demonstrate using structs and dynamic memory.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 5
#define INPUT_BUF_SZ 250

typedef struct {
    char *first;
    char *last;
    int age;
    char class_standing; 
    Student * next_student;
} Student; 


Student * getStudentInfoPtr();
Student getStudentInfo();


int main(int argc, char * argv) {
    Student * students = NULL;
    Student * aStudent = NULL;
    Student * lastStudent = NULL;

    int i;
    students = getStudentInfoPtr();
    lastStudent = students;
    while ((aStudent = getStudentInfoPtr()) != NULL) {
        lastStudent->next_student = aStudent;
        aStudent= lastStudent;
    }

    lastStudent = students;
    do {
        printf("Student %d first name: %s\n", lastStudent->first);
        lastStudent = lastStudent->next_student;
    } (lastStudent != NULL);

    for (i = 0; i < MAX_STUDENT; i++) {
        students= getStudentInfoPtr();
        if (students[i] == NULL)
            return -1;
        }
    
    // print headers
    for (i = 0; i < MAX_STUDENT; i++) {
        // print each student info
        printf("Student %d first name: %s\n", i, students[i]->first);
    }

    for (i = 0; i < MAX_STUDENT; i++)
        free(students[i]);
}
/*
    Get student information from stdinput.
*/
Student * getStudentInfoPtr() {

    char * i_buf = NULL;
    Student * student = NULL;
    // come back to this definition
    size_t line_buf_sz = INPUT_BUF_SZ + 1;
    int char_count = 0;

    student = malloc(sizeof(Student));
    if (student == NULL) 
        return NULL;
    // prompt for first name
    puts("Enter first name of student:");
    char_count = getline(&i_buf, &line_buf_sz, stdin);

    student->first = i_buf;

    // get the rest of the student information
    return student;
}