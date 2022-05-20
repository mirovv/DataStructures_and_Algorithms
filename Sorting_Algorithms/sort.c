#include <stdio.h>

void insertionSort(int arr[], int n){
    // ascending
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j > -1 && temp < arr[j]){ // change to > for descending
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void bubbleSort(int arr[], int n){

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){ // change to < for descending
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n){

    for (int i = 0; i < n-1; i++){
        int smallest = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[smallest]){ // change to > for descending
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
}

void merge(int A[], int l, int r, int m){
    int B[9];
    int i, j, k;


    for (i = l; i < m; i++){ // "i <= m" geändert zu "i < m"
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

void heapify(int A[], int i, int n){
    int m, l, r, temp;
    m = i;
    l = i * 2 + 1;
    r = i * 2 + 2;

    if (l < n && A[l] < A[m]){ // > for min heap
        m = l;
    }
    if (r < n && A[r] < A[m]){ // > for min heap
        m = r;
    }
    if (i != m){
        temp = A[i];
        A[i] = A[m];
        A[m] = temp;
        heapify(A, m, n);
    }
}
void buildHeap(int A[], int n){
    int i;
    for (i = n / 2; i >= 0; i--){
        max_heapify(A, i, n);
    }
}
void heapsort(int A[], int n){
    int s = n;
    int i, temp;
    buildHeap(A, n);
    for (i = n-1; i > 0; i--){
        temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        s--;
        max_heapify(A, 0, s);
    }
}



void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int A[] = {24, 15, 23, 1, 25, 9, 14, 7, 2};
    
    int n = sizeof(A) / sizeof(int);

    mergeSort(A, 0, n);
    printArray(A,n);


    return 0;
}