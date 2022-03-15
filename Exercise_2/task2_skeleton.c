/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 2                                                      *
 *                                                                          *
 * @author <Miro>                                                           *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

void recursiveSecondSmallest(int arr[], int n, int smallest, int second, int counter){
	int temp;
	if (counter == n){
		printf("%d", second);
		return;
	}else{
		if (arr[counter] < smallest){
			temp = smallest;
			smallest = arr[counter];
			second = temp;
		}else if (arr[counter] > smallest && arr[counter] < second){
			second = arr[counter];
		}
		counter++;
		return recursiveSecondSmallest(arr, n, smallest, second, counter);
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
	int smallest, secondSmallest;
	int counter = 2;

	if (arr[0] < arr[1]){
		smallest = arr[0];
		secondSmallest = arr[1];
	}else{
		smallest = arr[1];
		secondSmallest = arr[0];
	}
	recursiveSecondSmallest(arr, pos, smallest, secondSmallest, counter);


	return 0;
}
