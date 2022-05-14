#include <stdio.h>

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int get_spans(int A[], int i, int* spans){
    int res = 0;
    int j;
    if (i <= 1){
        return 1;
    }else{
        for (j = 1; j <= i; j++){
            if (A[j-1] < A[j]){
                res++;
            }else{
                res = 1;
            }
        }
    }
    return res;
}
int main(){
    int A[] = {6,3,4,5,2};
    int size = sizeof(A) / sizeof(int);

    int spans[size];

    for (int i = 0; i < size; i++){
        spans[i] = get_spans(A,i, &i);
        printf("Span of s(A,%d): %d\n", i, spans[i]);
    }
    printArray(spans, size);

    // printf("Span of s(A,0): %d\n", get_span(A,0,size));
    // printf("Span of s(A,1): %d\n", get_span(A,1,size));
    // printf("Span of s(A,2): %d\n", get_span(A,2,size));
    // printf("Span of s(A,3): %d\n", get_span(A,3,size));
    // printf("Span of s(A,4): %d\n", get_span(A,4,size));
    
}