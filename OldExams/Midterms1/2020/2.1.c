#include <stdio.h>
#include <stdlib.h>


void weirdBinarySearch(int A[], int n){
    int l = 0;
    int r = n - 1;
    int m = (l + r) / 2;

    while (l != r && l != m && r != m){
        if(A[m-1] < A[m]){
            l = m;
            m = (l + r) / 2;
        }else{
            r = m;
            m = (l + r) / 2;
        }
    }
    printf("%d", A[m]);
}


int main(){
    int A[] = {1,2,4,5,7,19,6,3};
    int size = sizeof(A) / sizeof(int);

    weirdBinarySearch(A, size);
    
    return 1;
}