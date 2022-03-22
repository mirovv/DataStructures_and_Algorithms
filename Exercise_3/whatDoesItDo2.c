#include <stdio.h>

void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int whatDoesItDo2(int arr[], int n, int k){
    int i,j;
    int maxi;
    int sum = 0;
    int swap;

    for (i = 0; i < n; i++){
        maxi = i;
        for (j = i; j < n; j+=k){
            if (arr[j] > arr[maxi]){
                maxi = j;
            }
        }
        sum += arr[maxi];
        swap = arr[i];
        arr[i] = arr[maxi];
        arr[maxi] = swap;
    }
    printArray(arr, n);
    return sum;
}

int main(){
    int A[] = {1,3,5,4,2,6,8};
    int size = sizeof(A) / sizeof(A[0]);
    int k = 3;

    int result = whatDoesItDo2(A, size, k);

    printf("\nThe result is: %d\n", result);
}