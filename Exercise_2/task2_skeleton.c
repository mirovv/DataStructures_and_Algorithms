/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 2                                                      *
 *                                                                          *
 * @author <Miro>                                                           *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

void recursiveSecondSmallest(int arr[], int n){
	int smallest, secondSmallest = 0;

	if (n == 0){
		return secondSmallest;
	}

	if (arr[n-1] > arr[n-2]){
		smallest = arr[n-2];
		secondSmallest = arr[n-1];
	}
}

int main() {
	printf("Values of array separated by spaces (non-number to stop): ");
	int arr[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &arr[pos]) == 1) {
		pos++;
	}
	// variable pos will contain number of integers read in from user


	printf("The second smallest number is: ");
	recursiveSecondSmallest(arr, pos);


	return 0;
}
