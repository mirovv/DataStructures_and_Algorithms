#include <stdio.h>

// linear search
// look for value v in array (first occurence)

// O(n) = n

int linearSearch(int arr1[], int value, int size){
    int i;

    for (i = 0; i < size; i++){
        if (arr1[i] == value){
            return i;
        }  
    }
    return -1;
}

int main(){
    int A1[] = {12, 33, 97, 14, 4, 8, 92, 48, 27, 64, 30, 6};

    int size_arr1 = sizeof(A1) / sizeof(int);

    int v = 92;

    int index = linearSearch(A1, v, size_arr1);

    printf("(Value is -1 if not in array)\nFirst occurence at: %d\n", index);

    return 0;
}