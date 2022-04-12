#include <stdio.h>

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i <= size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int HoarePartition(int A[], int l, int r){
    int pivot, i, j, temp;

    pivot = A[r];
    i = l - 1;
    j = r + 1;

    while (1){
        do j--; while (A[j] > pivot);
        do i++; while (A[i] < pivot);

        if (i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }else{
            return i;
        }
    }
}

void QuickSort(int A[], int l, int r){
    int m;
    if (l < r){
        m = HoarePartition(A, l, r);
        QuickSort(A, l, m-1); // smallest elements
        QuickSort(A, m, r); // largest elements
    }
}


int main(){
    int A[] = {11, 0, 9 ,19, 8, 1, 5, 13, 18, 7};
    int size = sizeof(A) / sizeof(A[0]) - 1;

    printf("Array before Quicksort (Hoare): ");
    printArray(A, size);

    QuickSort(A, 0, size);

    printf("Array after Quicksort (Hoare): ");
    printArray(A, size);

    return 0;
} 