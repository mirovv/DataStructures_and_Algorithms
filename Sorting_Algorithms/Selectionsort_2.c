#include <stdio.h>

// biggest element moved to the right

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){

    for (int i = 0; i < n-1; i++){
        int biggest = n-i-1;
        printArray(arr, n);
        for (int j = n-i-1; j > -1; j--){
            if (arr[j] > arr[biggest]){
                biggest = j;
            }
        }
        int temp = arr[biggest];
        arr[biggest] = arr[n-i-1];
        arr[n-i-1] = temp;
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
