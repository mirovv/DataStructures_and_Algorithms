#include <stdio.h>

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int A[], int l, int r, int m){
    int B[8];
    int i, j, k;


    for (i = l; i <= m; i++){ // "i <= m" geändert zu "i < m"
        B[i] = A[i];
    }

    for (i = m; i < r; i++){ // "i = m+1" ersetzt mit "i = m"
        B[r+m-i-1] = A[i]; // "r+m-i" ersetzt mit "r+m-i-1"
    }

    i = l;
    j = r - 1; // "j = r" ersetzt mit "j = r - 1", weil sonst auf Zeile 33 ein Zugriff auf eine Position ausserhalb der aktuellen Array-Grenzen erfolgt

    for (k = l; k < r; k++){
        if (B[i] < B[j]){
            A[k] = B[i];
            i++;
        }else{
            A[k] = B[j];
            j--;
        }
    }
}

void mergeSort(int A[], int l, int r){
    int m;
    if (l < r - 1){ // "l < r" geändert zu "l < r - 1", weil sonst der Algorithmus auf "Arrays" der Grösse 1 angewendet wird
        m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m, r); // "m+1" geändert zu "m", weil m ausserhalb des zu betrachtenden Arrays liegt und sonst ein Element verloren geht
        merge(A, l, r, m);
    }
}

int main(){
    int A[] = {5,2,4,7,1,3,6,2};
    int l = 0;
    int size = sizeof(A) / sizeof(A[0]);

    printf("Size: %d\n", size);

    printf("Array before Mergesort: ");
    printArray(A, size);

    mergeSort(A, l, size);

    printf("Array after Mergesort: ");
    printArray(A, size);

    return 0;
}