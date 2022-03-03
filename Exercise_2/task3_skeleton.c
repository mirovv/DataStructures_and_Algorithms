/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 3                                                      *
 *                                                                          *
 * @author <Miro>                                                           *
 ****************************************************************************/

#include <stdio.h>

int blinks(int n){
	int res;
	if (n <= 0){return 0;}
	if (n == 1){return 1;}
	if (n == 2){return 2;}
	if (n == 3){return 3;}
	else{
		res = blinks(n-1) + blinks(n-2);
	}
	return res;
}

int main() {
	int input;
	int output;

	printf("Enter the number of blinks: \n");
	scanf("%d", &input);

	output = blinks(input);

	printf("Total number of blink variations is: %d", output);

	return 0;
}
