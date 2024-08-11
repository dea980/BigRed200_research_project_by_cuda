

#include <stdio.h>

#define SIZE 10

int mergeSort(char *a[], int size);
void splitMerge(char *temp[], int begin, int end, char *arr[]);
void merge(char *arr1[], int begin, int middle, int end, char *arr2[]);
int strCompare(char *str1, char *str2);

#define STR_MAX 10
int main(void) {
    int demo[SIZE] = {2,56,89,1,23,99,34,89,7,11};
    char strList[SIZE][STR_MAX] = {
        "hello",
        "goodbye",
        "ant",
        "computer"
    };
    char *strPtrs[SIZE];
    for (int i = 0; i < SIZE; i++)
        strPtrs[i] = (char *)(strList + i);

    mergeSort(strPtrs, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("[%d]  %s\n", i, strPtrs[i]);

}

int mergeSort(char *a[], int size) {
    char *temp[size];
    for (int i = 0; i < size; i++)
        temp[i] = a[i];
    
    splitMerge(temp, 0, size, a);
}

void splitMerge(char *temp[], int begin, int end, char *arr[]) {
    if (end - begin <= 1)
        return;
    int middle = (end + begin)/2;
    splitMerge(arr, begin, middle, temp);
    splitMerge(arr, middle, end, temp);

    merge(temp, begin, middle, end, arr);
}

void merge(char **arr1, int begin, int middle, int end, char **arr2) {
    int i =  begin, j = middle;

    for (int k = begin; k < end; k++) {
        if (i < middle && (j >= end || strCompare(arr1[i],arr1[j]))) 
            arr2[k] = arr1[i++];
        else
            arr2[k] = arr1[j++];     
    }
}

int strCompare(char *str1, char *str2) {
    for(int i = 0; i < STR_MAX; i++) 
        if (str1[i] == str2[i])
            continue;
        else if (str1[i] < str2[i])
            return 1;
        else 
            return 0;
}