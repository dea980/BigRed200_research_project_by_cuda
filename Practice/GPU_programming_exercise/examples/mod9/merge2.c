// demonstrate using merge sort with generic function
#include <stdio.h>

int merge(int arr[], int low, int mid, int high, int (*compare) (void *, void *));
int merge_sort(int arr[], int low, int high);

int main(int argc, char* argv[]) {
    int demo[10] = {2,56,89,1,23,99,34,89,7,11};



    int inputvalue, i;
    if (argc > 1) {
        for (i = 0; i < 10; i++) {
            scanf(" %d", &inputvalue);
            demo[i] = inputvalue;
        }
    }
    merge_sort(demo, 0, 9);

    for (i = 0; i < 10; i++) {
        printf("%d: %d\n", i, demo[i]);
    }

}

int int_compare(int * a, int * b) {
    int val = 0;
    if (*a > *b)
        return 1;
    if (*a < *b) 
        return -1;
    return 0;
}

int merge(int arr[], int low, int mid, int high, 
          int (*compare)(void * item1, void * item2)) {
    
    int n1, n2, i, j, k;
    n1 = mid - low + 1;
    n2 = high - mid;
    int arr1[n1], arr2[n2];  // temp arrays to hold values

    // split the given array into two equal sized arrays
    for (i = 0; i< n1; i++)
        arr1[i]=arr[low + i];
    for (j = 0; j < n2; j++)
        arr2[j] = arr[mid + j + 1];
    
    i = 0;
    j = 0;
    for (k=low; k <= high; k++) {
        if (compare(arr1+i, arr2+j) <= 0) 
            arr[k] = arr1[i++];
        else 
            arr[k] = arr2[j++]; 
    }

    return 0;
}

int merge_sort(int arr[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high, *int_compare);
    }
    return 0;
}