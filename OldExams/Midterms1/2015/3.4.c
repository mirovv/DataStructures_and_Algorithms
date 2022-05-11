#include <stdio.h>
#include <stdlib.h>


void recursiveBubbleSortVariant(int A[], int n){
    int i;
    if (n == 0) return;

    for (i = n-1; i>0; i--){
        if (A[i-1] > A[i]){
            int temp = A[i-1];
            A[i-1] = A[i];
            A[i] = temp;
        }
    }
    for (i = 0; i<n; i++){
        if (A[i-1] > A[i]){
            int temp = A[i-1];
            A[i-1] = A[i];
            A[i] = temp;
        }
    }
    for (i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    recursiveBubbleSortVariant(A, n-1);
}


int main(){
    int A[] = {8,5,10,1,3};
    int n = 5;

    recursiveBubbleSortVariant(A, n);

    for (int i = 0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 1;
}