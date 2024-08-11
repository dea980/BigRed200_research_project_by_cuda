// code exploring multi-dim arrays
#include <stdio.h>

#define MAX_SIZE 3

void print_2darr(short arr[][3], int rows, int cols);
void print_3darr(short arr[][3][3], int rows, int cols, int slices);
void print_2darr_col(short array[][3], int rows, int cols);
// void print_4darr(char arr[][3], int rows, int cols, int slices, int);

int main(void) {

    short arr2d[MAX_SIZE][MAX_SIZE] = {{1,2,3}, {4,5,6}};

    short arr3d[MAX_SIZE][MAX_SIZE][MAX_SIZE] = { {{10,20,30},2,3}, {{40,50,60},5,6}};
    
    // short arr4d[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE] = {{100,200,300}, {400,500,600}};

    // for (int i = 0; i < MAX_SIZE; i++) {
    //     for (int j = 0; j < MAX_SIZE; j++) {
    //         printf("arr[%d][%d]: %d  @ %p\n", i, j, array[i][j], &array[i][j]);
    //     }
    // }
    print_2darr(arr2d, MAX_SIZE, MAX_SIZE);
    print_2darr_col(arr2d, MAX_SIZE, MAX_SIZE);
    print_3darr(arr3d, MAX_SIZE, MAX_SIZE, MAX_SIZE);

}

void print_2darr( short array[][3], int rows, int cols) {
    printf("\nPrinting 2 dim array.\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d", array[i][j]);
        }
        printf("   ---  ");
        for (int j = 0; j < cols; j++) {
            printf("%p ", &array[i][j]);
        }
        printf("\n");
    }
 
}

void print_2darr_col(short array[][3], int rows, int cols) {
    printf("\nPrinting 2 dim array (column ranked).\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d", array[j][i]);
        }
        printf("   ---  ");
        for (int j = 0; j < cols; j++) {
            printf("%p ", &array[j][i]);
        }
        printf("\n");
    }

}

void print_3darr( short array[][3][3], int rows, int cols, int slices) {
    printf("\nPrinting 3 dim array.\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < slices; k++) {
                printf("%2d ",array[i][j][k]);
            }
            printf("   ---  ");
            for (int k = 0; k < slices; k++) {
                printf("%p ",&array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

}

// void print_4darr( char array[][3], int rows, int cols) {
//        for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("array[%d][%d]: %d  @ %p\n", i, j, array[i][j], &array[i][j]);
//         }
//     }
 
// }