#include <stdio.h>
#include <stdlib.h>

void countingSort(int A[], int B[], int n, int m){

    for (int i = 0; i<n; i++){
        int val = A[i];
        B[val] = B[val]+1;
    }
    for (int i = 0; i<m; i++){
        for (int j = 0; j<B[i]; j++){
            printf("%d  ", i);
        }
    }
}


int main(){
    int A[] = {5,0,2,4,3,6,1,1,5,5,0,6,0,0,2,4};
    int n = 16;
    int m;
    int B[7] = {0,0,0,0,0,0,0};
    countingSort(A, B, n, 7);

}
