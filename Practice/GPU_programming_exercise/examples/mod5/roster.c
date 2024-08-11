// Program allows input, manipulation, and report of students
#include <stdio.h>

#define MAX_ROSTER 100
#define ST_BITS 24
#define STUD_ID_MASK  0x00FFFFFF
#define GRADE_MASK 0xF0   
#define YEAR_MASK 0xFC 
#define UG_MASK 0xFD
#define ONLINE_MASK 0xFE


unsigned int encodeValue(unsigned int s, unsigned char v, char bits );
unsigned char decodeValue(unsigned int s, char bits);

unsigned int roster[MAX_ROSTER] = {};


int main(void) {
    unsigned int testID = 150;
    unsigned char grade = 15;
    unsigned char year = 2;
    unsigned char ugStatus = 1;
    unsigned char onlineStatus = 1;

    unsigned int student = 0;

    student = testID;
    printf("Test ID: %d  Grade: %2d Year: %2d UG: %s  Online: %s\n", 
            testID, grade, year,
            ugStatus ? "UG" : "Grad", 
            onlineStatus ? "Online" : "On Campus");

    
    student = encodeValue(student, grade);
    printf("encoded grade: %X\n", student);
    student = encodeValue(student, year);
    printf("encoded grade & year: %X\n", student);
    student = encodeValue(student, ugStatus);
    printf("encoded grade & year & UG: %X\n", student);
    student = encodeValue(student, onlineStatus);
    printf("Fully encoded student: %X\n", student);

    printf("\nStudent ID: %d\n", student & STUD_ID_MASK);
    printf("Student Grade: %2d Year: %2d, UG: %s Online: %s\n",
        decodeValue(student, GRADE_MASK),
        decodeValue(student, YEAR_MASK),
        decodeValue(student, UG_MASK) ? "UG" : "Grad",
        decodeValue(student, ONLINE_MASK) ? "Online" : "On Campus");

}

unsigned int encodeValue(unsigned int s, unsigned char v ) {
    return s | (v << ST_BITS);
}

unsigned char decodeValue(unsigned int s, unsigned char mask) {
    return (s >> ST_BITS) & mask;
}


