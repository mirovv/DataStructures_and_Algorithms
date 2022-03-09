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

int selectionSort(int arr[], int n, int k){

    for (int i = 0; i < k; i++){
        int smallest = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
    return arr[k-1];
}

int main(){
    int A[] = {24, 15, 23, 1, 25, 9, 14, 7, 2};

    int k = 5;
    
    int n = sizeof(A) / sizeof(int);

    int k_th_smallest_element = selectionSort(A, n, k);

    printf("\nThe k-th smallest element of Array: \n");
    printArray(A, n);
    printf("\nIs: %d", k_th_smallest_element);

    return 0;
}
