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

void bubble_sort(int arr[], int n){

    for (int i = 0; i < n-1; i++){
        //printArray(arr, n);
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int A[] = {24, 15, 23, 1, 25, 9, 14, 7, 2};
    
    int n = sizeof(A) / sizeof(int);

    printf("Unsorted Array:\n");
    printArray(A, n);

    bubble_sort(A, n);

    printf("Sorted Array:\n");
    printArray(A, n);

    return 0;
}
