#include <stdio.h>
#include <stdlib.h>

int EqualAsSets(int A[], int sizeA, int B[], int sizeB){
    int result = 1;
    int i, j;

    for (i = 0; i < sizeA; i++){
        for (j = 0; j < sizeB; j++){
            if (A[i] == B[j]){
                result = 1;
                break;
            }else{
                result = 0;
            } 
        }
        if (result == 0){
            return 0;
        }
    }
    for (j = 0; j < sizeB; j++){
        for (i = 0; i < sizeA; i++){
            if (A[i] == B[j]){
                result = 1;
                break;
            }else{
                result = 0;
            }
        }
        if (result == 0){
            return 0;
        } 
    }            
    return result;
}

int main(){
    int A[] = {2,2,2,2,3,3,4,4,4,5};
    int sizeA = sizeof(A) / sizeof(int);
    int B[] = {2,2,3,3,3,4,4,5};
    int sizeB = sizeof(B) / sizeof(int);

    printf("%d\n", EqualAsSets(A, sizeA, B, sizeB));
    
}