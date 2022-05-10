#include <stdio.h>
#include <stdlib.h>

// Array A and B are sorted in increasing order.
// Create function printDifference(A, sizeA, B, sizeB) prints each value of A that is not in B.

void printDifference(int A[], int sizeA, int B[], int sizeB){
    int i = 0; 
    int j = 0;
    while(i < sizeA && j < sizeB){
        if(A[i] < B[j]){
            printf("%d, ", A[i]);
            i++;
        }
        else if(A[i] > B[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    while(i < sizeA){
        printf("%d, ", A[i]);
        i++;
    }
}

int main(){
    int A[] = {1,2,2,3,6,10};
    int sizeA = sizeof(A) / sizeof(int);
    int B[] = {2,2,3,3,4};
    int sizeB = sizeof(B) / sizeof(int);

    printDifference(A, sizeA, B, sizeB);
}