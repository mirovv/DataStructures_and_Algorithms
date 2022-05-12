#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int A[], int B[], int n){
    int res = 0;
    for (int i = 0; i < n; i++){
        res += (A[i] + B[i]) * pow(10,n-1-i);
        printf("Iteration %d --> Result = %d\n", i, res);
    }
    return res;
}


int main(){

    int A[] = {1,2,3};
    int B[] = {1,1,0};
    int n = 3;

    printf("%d", sum(A,B,n));

    return 1;
}