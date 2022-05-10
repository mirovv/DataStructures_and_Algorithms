// selection sort recursive

#include <stdio.h>
#include <stdlib.h>

void recursiveSelectionSort(int A[], int n){
    if (n == 1){
        return;
    }
    int k = n-1;
    for (int i = 0; i < n-1; i++){
        if(A[k] < A[i]){
            int temp = A[k];
            A[k] = A[i];
            A[i] = temp;
        }
    }
    recursiveSelectionSort(A, n-1);
}

int main(){
    int A[] = {6,1,14,8,9,23};
    int size = sizeof(A) / sizeof(int);

    recursiveSelectionSort(A, size);

    for(int i = 0; i < size; i++){
        printf("%d, ",A[i]);
    }

}