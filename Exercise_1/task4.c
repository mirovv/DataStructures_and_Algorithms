/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 4                                                      *
 *                                                                          *
 * @author <Miro>                                                           *
 ****************************************************************************/

#include <stdio.h>
const int MAX_LENGTH = 1000;

void findGap(int A[], int n){
	int i, j, t;

	int max = A[1] - A[0];

	for (i = 1; i < n; i++){
		j = i - 1;
		t = A[i] - A[j];
		if (t > max){
			max = t;
		}
	}
	printf("The biggest Gap is: %d\n", max);
	return;
}

void insertionSort(int A[], int n){
	int i, j, t;

	for (i = 1; i < n; i++){
		j = i - 1;
		t = A[i];
		while (j >= 0 && t < A[j]){
			A[j+1] = A[j];
			j -= 1;
		}
		A[j+1] = t;
	}
	findGap(A, n);
	return;
}

int main() {
	printf("Values of A separated by spaces (non-number to stop): ");
	int timestamps[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &timestamps[pos]) == 1) {
		pos++;
	}
	printf("The oldest timestamp is: %d\n", timestamps[0]);
	printf("The most recent timestamp is: %d\n", timestamps[pos]);
	insertionSort(timestamps, pos);


	return 0;
}