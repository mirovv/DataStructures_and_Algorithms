#include <stdio.h>

// count occurence of each element of arr1 in arr2

int linearSearchOccurence(int arr1[], int arr2[], int size_1, int size_2){
    int i,j;
    int counter = 0;

    for (i = 0; i < size_1; i++){
        for (j = 0; j < size_2; j++){
            if (arr1[i] == arr2[j]){
                counter++;
            }
        }
    }
    return counter;
}

int main(){
    int A1[] = {12, 33, 97, 14, 4, 8, 92, 48, 27, 64, 30, 6};
    int A2[] = {52, 38, 97, 23, 7, 49, 87, 50, 23, 4, 9, 87};

    int size_arr1 = sizeof(A1) / sizeof(int);
    int size_arr2 = sizeof(A2) / sizeof(int);

    int duplicates = linearSearchOccurence(A1, A2, size_arr1, size_arr2);

    printf("Duplicates: %d\n", duplicates);

    return 0;
}