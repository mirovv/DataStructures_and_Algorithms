#include <stdio.h>

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i <= size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int LomutoPartition(int A[], int l, int r){
    int pivot, i, j, temp;

    pivot = A[r]; // pivot element (we take the right most element)
    i = l - 1; // lagging pointer

    for (j = l; j < r; j++){

        if (A[j] <= pivot){
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            // printArray(A,9); // uncomment this line to see all swaps (ussert de aller letzt!)
        }
    }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i+1;
}

void QuickSort(int A[], int l, int r){
    int m;
    if (l < r){
        m = LomutoPartition(A, l, r);
        QuickSort(A, l, m-1); // smallest elements
        QuickSort(A, m+1, r); // largest elements
    }
}

int main(){
    int A[] = {11, 0, 9 ,19, 8, 5, 1, 13, 18, 7};
    int size = sizeof(A) / sizeof(A[0]) - 1;

    printf("Array before Quicksort (Lomuto): \n");
    printArray(A, size);

    QuickSort(A, 0, size);

    printf("Array after Quicksort (Lomuto): ");
    printArray(A, size);

    return 0;
} 