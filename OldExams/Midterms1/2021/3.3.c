#include <stdio.h>
#include <stdlib.h>


void smallestApexElement(int A[], int n){
    int res = -1;

    for (int i = 1; i < n-1; i++){
        if (A[i-1] <= A[i] && A[i] >= A[i+1]){
            if (res == -1){
                res = A[i];
            }else{
                if (A[i] <= res){
                    res = A[i];
                }
            }
        }
    }
    printf("%d", res);
}



int main(){
    int A[] = {7,19,6,14,18,20,5,10};
    int n = sizeof(A) / sizeof(int);

    smallestApexElement(A, n);

    return 1;
}