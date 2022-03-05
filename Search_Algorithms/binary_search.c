#include <stdio.h>

// count occurence of each element of arr1 in arr2

int binarySearch(int arr[], int value, int size){
    int l = 0;
    int r = size - 1;
    int m = (l + r) / 2;

    while (l <= r && value != arr[m]){
        if (value < arr[m]){
            r = m - 1;
        }else{
            l = m + 1;
        }
        m = (l + r) / 2;
    }
    if (l <= r){
        return m;
    }
    return -1;
}

int main(){
    int A1[] = {4, 6, 8, 12, 14, 27, 30, 33, 48, 64, 92, 97};
    int size_arr1 = sizeof(A1) / sizeof(int);

    int v = 33;

    int index = binarySearch(A1, v, size_arr1);

    printf("Index of value: %d\n", index);

    return 0;
}