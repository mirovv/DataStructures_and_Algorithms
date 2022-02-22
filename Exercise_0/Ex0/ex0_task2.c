#include <stdio.h>

int main() {
    int A[] = {0,3,4,2,4,6,9,97,11,8,1,9}; 

    int max;
    int second;

    if (A[0] <= A[1]){
        int max = A[1];
        int second = A[0];
    }else{
        int max = A[0];
        int second = A[1];
    }

    int array_size = sizeof(A) / sizeof(int);
    
    for (int i = 0; i < array_size; i++){
        if (A[i] > max){
            max = A[i];
        }else if (A[i] < max && A[i] > second){
            second = A[i];
        }
    }

    printf("The largest number is: %d\n", max);
    printf("The second largest character of Array A is: %d\n", second);
    

    return 0;
}