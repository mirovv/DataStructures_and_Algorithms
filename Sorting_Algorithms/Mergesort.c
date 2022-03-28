#include <stdio.h>

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int A[], int l, int r, int m){
    int B[8];
    int i, j, k;


    for (i = l; i <= m; i++){
        B[i] = A[i];
    }

    for (i = m+1; i < r; i++){
        B[r+m-i] = A[i];
    }

    i = l;
    j = r;

    for (k = l; k < r; k++){
        if (B[i] < B[j]){
            A[k] = B[i];
            i++;
        }else{
            A[k] = B[j];
            j--;
        }
    }
}

void mergeSort(int A[], int l, int r){
    int m;
    if (l < r){
        m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, r, m);
    }
}

int main(){
    int A[] = {5,2,4,7,1,3,6,2};
    int l = 0;
    int size = sizeof(A) / sizeof(A[0]);

    printf("Size: %d\n", size);

    printf("Array before Mergesort: ");
    printArray(A, size);

    mergeSort(A, l, size);

    printf("Array after Mergesort: ");
    printArray(A, size);

    return 0;
}