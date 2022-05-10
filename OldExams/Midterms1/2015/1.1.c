#include <stdio.h>
#include <stdlib.h>

void printDifference(int A[], int sizeA, int B[], int sizeB){
    int i, j;
    int result = 0;
    for (i = 0; i < sizeA; i++){
        for (j = 0; j < sizeB; j++){
            if (A[i] == B[j]){
                result = 1;
                break;
            }else{
                continue;
            }
        }
        if (result == 1){
            result = 0;
        }else{
            printf("%d ", A[i]);
        }
    }
}

int main(){
    int A[] = {1,2,2,3,6,10};
    int sizeA = sizeof(A) / sizeof(int);
    int B[] = {2,2,3,3,4};
    int sizeB = sizeof(B) / sizeof(int);

    printDifference(A, sizeA, B, sizeB);
}