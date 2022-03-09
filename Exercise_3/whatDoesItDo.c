#include <stdio.h>

int whatDoesItDo(int arr[], int n, int k){
    int i,j;
    int result = -1000;
    int current;

    for (i = 0; i < n; i++){
        current = 0;
        for (j = i; j < n; j+=k){
            current += arr[j];
        }
        if (current > result){
            result = current;
        }
    }
    return result;
}

int main(){
    int A[] = {1,3,5,4,2,6,8};
    int size = sizeof(A) / sizeof(A[0]);
    int k = 3;

    int result = whatDoesItDo(A, size, k);

    printf("\nThe result is: %d\n", result);
}