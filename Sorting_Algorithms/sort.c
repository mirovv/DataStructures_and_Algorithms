#include <stdio.h>

void insertionSort(int arr[], int n){
    // ascending
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j > -1 && temp < arr[j]){ // change to > for descending
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void bubbleSort(int arr[], int n){

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){ // change to < for descending
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n){

    for (int i = 0; i < n-1; i++){
        int smallest = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[smallest]){ // change to > for descending
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
}

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int A[] = {24, 15, 23, 1, 25, 9, 14, 7, 2};
    
    int n = sizeof(A) / sizeof(int);

    insertionSort(A, n);
    printArray(A,n);


    return 0;
}