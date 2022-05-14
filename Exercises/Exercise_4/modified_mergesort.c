#include <stdio.h>

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int A[], int l, int r, int m, char s[]){
    int B[9];
    int i, j, k;


    for (i = l; i < m; i++){ 
        B[i] = A[i];
    }

    for (i = m; i < r; i++){ 
        B[r+m-i-1] = A[i]; 
    }

    i = l;
    j = r - 1; 

    if (s[0] == 'a'){
        for (k = l; k < r; k++){
            if (B[i] < B[j]){
                A[k] = B[i];
                i++;
            }else{
                A[k] = B[j];
                j--;
            }
        }
    }else{
        for (k = l; k < r; k++){
            if (B[i] > B[j]){
                A[k] = B[i];
                i++;
            }else{
                A[k] = B[j];
                j--;
            }
        }
    }

}

void mergeSort(int A[], int l, int r, char s[]){
    int m;
    if (l < r - 1){ 
        m = (l + r) / 2;
        mergeSort(A, l, m, s);
        mergeSort(A, m, r, s); 
        merge(A, l, r, m, s);
    }
}

void alreadySorted(int A[], int l, int r, char s[]){
    int i;

    for (i = 0; i < r; i++){
        if (A[i] > A[i+1]){
            mergeSort(A, l, r, s);
            printf("\nArray is not sorted! Performing merge sort!!\n\n");
            break;
        }
    }
}

int main(){
    int A[] = {5,2,4,7,1,3,6,2,9};
    int l = 0;
    int size = sizeof(A) / sizeof(A[0]);
    char s[] = "ascending";

    printf("Size: %d\n", size);

    printf("Array before Mergesort: ");
    printArray(A, size);

    alreadySorted(A, l, size, s);

    printf("Array after Mergesort: ");
    printArray(A, size);

    return 0;
}