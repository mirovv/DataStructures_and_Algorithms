// Sturcutre of a C program

// Imports
#include <stdio.h>

// Definitions
#define MAX 100
#define PI 3.14

// Function declarations

float area(float r);

// Main function
int main() {
	int x;
	x = MAX;
	int area = area(x);
}

// Function definition

float area(float r) {
	return PI*r*r;
}


// data types - int, char, float, long - static typing - declarations vs definitions
int i = 3; // %d
char c; // %c
float f; // %f
double d; // %d

// Operators, arithmetic, comparison, logical (&& || !)
// + - * / %
// == <= >= != < >
// !(x > 0)
// i++: returns i and then adds 1
// ++i: adds 1 then returns

// arrays - arrays, strings - declarations & definitions, indexing
int A[4] = {1, 2, 3, 4};

char A[] = "Hello"; // {'H', 'e', 'l', 'l', 'o', '\0'}


// conditionals - booleans, if else
// No bools - 0 treated as false, otherwise true

int b = -576;

if (b < 1000) {
	...
} if else (b < 5000) {
	...
} else {
	...
}



// control flow - for, while, do while
int i;
for (i = 0; i < MAX; i++) {
	...
}

int i = 0;
while (i++ < MAX) {
	...
}

do {
	...
} while (i++ < MAX)



// functions - declaration before use, return type, arguments

void printhello(char s[]) {
	printf("Hello %s!\n", s);
}




// IO - stdio, printf, scanf
int i = 32;
float f = 3.14;

char s[] = "Hello";

printf("The second largest element is %d\n", i);

int a, b, c;

char s[30];

scanf("%29s", &s);

int scanf( args ) {
	read what user wrote and assign that to variables
	return number of assignments made
}




SUBLIME TEXT



// 2 6 -4 2 8 9








