#include <stdio.h>

// print array
void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int left(int x){
    return x * 2 + 1;
}

int right(int x){
    return x * 2 + 2;
}

void heapify(int A[], int i, int n){
    int m, l, r, temp;

    m = i;
    l = left(i);
    r = right(i);

    if (l < n && A[l] > A[m]){
        m = l;
    }
    if (r < n && A[r] > A[m]){
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
        heapify(A, i, n);
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
        heapify(A, 0, s);
    }
}

int main(){
    int A[] = {11, 0, 9 ,19, 8, 1, 5, 13, 18, 7};
    int size = sizeof(A) / sizeof(A[0]);

    printf("Size: %d\n", size);

    printf("Array before Heapsort: ");
    printArray(A, size);

    heapsort(A, size);

    printf("Array after Heapsort: ");
    printArray(A, size);

    return 0;
}