#include <stdio.h>

// smallest element moved to the left

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n){

    for (int i = 0; i < n-1; i++){
        int smallest = i;
        printArray(arr, n);
        for (int j = i; j < n; j++){
            if (arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int A[] = {24, 15, 23, 1, 25, 9, 14, 7, 2};
    
    int n = sizeof(A) / sizeof(int);

    printf("Unsorted Array:\n");
    printArray(A, n);

    selectionSort(A, n);

    printf("Sorted Array:\n");
    printArray(A, n);

    return 0;
}
