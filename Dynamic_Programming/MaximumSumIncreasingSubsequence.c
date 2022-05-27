#include <stdio.h>
#include <stdlib.h>

int main(){
    int A[] = {5, 14, 3, 22, 1, 32, 51, 9};
    int n = 8;

    int S[n];
    for(int i = 0; i<n; i++){
        S[i] = A[i];
    }
    for (int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j] && S[i] < S[j]+A[i]){
                S[i] = S[j] + A[i];
            }
        }
    }
    for(int i = 0; i<n; i++){
        printf("%d, ", S[i]);
    }
    printf("\n");

    int max = S[0];
    for(int i = 0; i<n; i++){
        if(S[i] > max){
            max = S[i];
        }
    }
    printf("\nMax: %d", max);
}