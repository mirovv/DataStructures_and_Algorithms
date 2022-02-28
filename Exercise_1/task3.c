/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 3                                                      *
 *                                                                          *
 * @author <Miro>                                                           *
 ****************************************************************************/

#include <stdio.h>

void printArray(int arr[], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int A[], int n) {
	int i, j = 0;
	int k, t;

	for (i = 0; i < n-1; i++){
		k = i;
		for (j = i; j < n; j++){
			if (A[j] < A[k]){
				k = j;
			}
		}
		t = A[k];
		A[k] = A[i];
		A[i] = t;
	}
	printArray(A, n);
	return;
}

void evenOddSelectionSort(int A[], int n){
	int E[100];
	int O[100];
	int size = n;
	int counter_e = 0;
	int counter_o = 0;

	for (int i = 0; i < size; i++){
		if (A[i] % 2 == 0){
			E[counter_e] = A[i];
			counter_e++;
		}else{
			O[counter_o] = A[i];
			counter_o++;
		}
	}
	int size_e = sizeof(E) / sizeof(int);
	int size_o = sizeof(O) / sizeof(int);

	printf("Sorted even numbers: ");
	selectionSort(E, size_e);
	printf("Sorted odd numbers: ");
	selectionSort(O, size_o);

	return;
}

int main(int argc, const char * argv[]) {
	int A[100];
	int n = 0;

	printf("Values of A separated by spaces (non-number to stop):");
	
	while (scanf("%d", &A[n]) == 1) {
		n++;
	}

	scanf("%*s");
	
	printf("Result: \n");
	evenOddSelectionSort(A, n);
}