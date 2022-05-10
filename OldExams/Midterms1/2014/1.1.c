#include <stdio.h>
#include <stdlib.h>


void printCounts(int A[], int n){
    int count = 1;
    int previous;
    for (int i = 0; i < n; i++){
        if (A[i] == previous){
            continue;
        }
        for (int j = i+1; j < n; j++){
            if (A[i] == A[j]){
                count++;
            }
        }
        previous = A[i];
        printf("(%d, %d)", A[i], count);
        count = 1;
    }

}


int main(){
    int A[] = {1,2,2,2,2,3,3,4,4,4,5,6};
    int size = sizeof(A) / sizeof(int);

    printCounts(A, size);


}