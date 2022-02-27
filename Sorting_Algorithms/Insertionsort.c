#include <stdio.h>

// sort from left to right

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){

    for (int i = 1; i < n; i++){
        int j = i-1;
        int t = arr[i]; // copy of the element to be sorted
        printArray(arr, n);
        while (j >= 0 && t <= arr[j]){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = t;
    }
}

int main(){
    int A[] = {24, 15, 23, 1, 25, 9, 14, 7, 2};
    
    int n = sizeof(A) / sizeof(int);

    printf("Unsorted Array:\n");
    printArray(A, n);

    insertionSort(A, n);

    printf("Sorted Array:\n");
    printArray(A, n);

    return 0;
}