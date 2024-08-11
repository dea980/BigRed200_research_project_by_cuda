// Demo showing using malloc to dynamically allocate and release memory
#include <stdio.h> 
#include <stdlib.h>

// Function prototypes
int * alloc_intarr(int elements);
void display_array(int * arr, int size);
void set_array(int * arr, int size);

// Entry point
int main(void) {

    int* arr1;
    int* arr2;


    arr1 = alloc_intarr(5);
    if (arr1 == NULL)
        return 1;
    printf("Arr1 pre-initialized:\n");
    display_array(arr1, 5);
    set_array(arr1, 5);
    printf("Arr1 post-initialized:\n");
        display_array(arr1, 5);

    arr2 = alloc_intarr(6);
    if (arr2 == NULL)
        return 1;
    printf("Arr2 pre-initialized:\n");
    display_array(arr2, 6);
    set_array(arr2, 6);
    printf("Arr2 post-initialized:\n");
    display_array(arr2, 6);

    free(arr1);    
    free(arr2);

}

// Displays the content of the array with some decoration
void display_array(int * arr, int size) {
    int i;
    printf("-------------------------------\n");
    for (i = 0; i < size; i++) {
        printf("Val: %d  Addr: %p\n", arr[i], arr+i);
    }
    printf("\n\n");
}

// sets the content of the arry with squares 
void set_array(int * arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = i * i;
    }

}

// allocates the requested array size
int* alloc_intarr(int e) {
    int* a;

    a = malloc(e * sizeof(int));
    if (a == NULL)
        // do whatever is appropriate with no memory
        return NULL;
    return a;

}