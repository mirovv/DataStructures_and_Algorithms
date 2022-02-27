/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 2                                                      *
 *                                                                          *
 * @author <Miro>                                                      *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

void BS(char A[]) {
	char b_string[3000];
	char vowels[] = {'A','a','E','e','I','i','O','o','U','u'};
	int size = 0;
	int i = 0;
	int j;


	while (A[i] != '\0'){
		size += 1;
		i += 1;
	}

	int count = 0;

	for (i = 0; i < size*3; i++){
		b_string[i] = A[i];
		printf("%c", A[i]);
		for (j = 0; j < 10; j++){
			if (A[i] == vowels[j]){
				printf("b");
				printf("%c", A[i]);
			}
		}
	}
}

int count_vowels(char A[]){
	char vowels[] = {'A','a','E','e','I','i','O','o','U','u'};
	int total_vowels = 0;
	int size = 0;
	int i = 0;
	int j;

	while (A[i] != '\0'){
		size += 1;
		i += 1;
	}

	for (i = 0; i < size; i++){
		for (j = 0; j < 10; j++){
			if (A[i] == vowels[j]){
				total_vowels += 1;
			}
		}
	}

	return total_vowels;
}

int main() {
	char input_string[MAX_LENGTH + 1];
	printf("Enter a string: ");
	scanf("%[^\n]s", input_string);
	int count = count_vowels(input_string);
	printf("The string contains of total %d vowels!\n", count);

	BS(input_string);
	

	return 0;
}
