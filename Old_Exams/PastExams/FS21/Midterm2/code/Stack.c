#include<stdlib.h>
#include<stdio.h>


typedef struct stackADT {
	int *arr;
	int size;
	int top;
} stack;

void initialize(stack *s, int n) {
	s->size = n;
	s->arr = malloc(n*sizeof(int));
	s->top = -1;
}

void push(stack *s, int value){
	if (s->top < (s->size-1)){
		s->top++;
		s->arr[s->top]=value;
	}
	else{
		printf("%s\n", "Stack Overflow");
	}
}

int peek(stack *s){
	if(s->top >= 0 ){
		return s->arr[s->top];
	}
	return -1;
}

int pop(stack *s){
	if (s->top >= 0 ){ 
          int x = s->arr[s->top]; 
          s->top--; 
          return x; 
       } 
       else{ 
           printf("%s\n", "Stack Underflow");
       } 
       return -1;
}

int size(stack *s){
	return s->size;
}

int capacity(stack *s){
	return s->size-s->top-1;
}

void insert(stack *A,stack *B,int val){
	if(capacity(A)>(size(A)/2) || capacity(B)>(size(B)/2)){ 
		if(capacity(A)!=size(A)){
			if(val<peek(A)){
				while(val<peek(A)){
					push(B,pop(A));
				}
				push(A,val);
			}else{
				while(val>peek(B) && capacity(B)<size(B)){
					push(A,pop(B));
				}
				push(B,val);
			}
			
			printf("Out: %d, %d\n ",capacity(A),capacity(B));
			while(capacity(B)-capacity(A)>1){
				printf("1: %d, %d\n ",capacity(A),capacity(B));
				push(B,pop(A));
				printf("1: %d, %d\n ",capacity(A),capacity(B));
			}
			while(capacity(A)>capacity(B)){
				printf("2: %d, %d\n ",capacity(A),capacity(B));
				push(A,pop(B));
				printf("2: %d, %d\n ",capacity(A),capacity(B));
			}
			
		}else{
			push(A,val);
		}
	}else{
		printf("Stack Overflow:\n");
	}
}

void printStack(stack *s) {
	if (s->size > 0) {
		int i;
		printf("[ ");
		for (i = 0; i <= s->top; i++) {
			printf("%d ", s->arr[i]);
		}
		printf("]\n");
	}
}

int main() {
	stack *A = malloc(sizeof(stack));
	stack *B = malloc(sizeof(stack));
	initialize(A, 10);
	initialize(B, 10);
	printf("%d \n", capacity(A));
	printf("%d \n", size(A));
	insert(A,B,5);
	printStack(A);
	printStack(B);
	insert(A,B,4);
	printStack(A);
	printStack(B);
	insert(A,B,3);
	printStack(A);
	printStack(B);
	insert(A,B,2);
	printStack(A);
	printStack(B);
	insert(A,B,1);
	printStack(A);
	printStack(B);
	insert(A,B,1);
	printStack(A);
	printStack(B);
	insert(A,B,4);
	printStack(A);
	printStack(B);
	insert(A,B,3);
	printStack(A);
	printStack(B);
	insert(A,B,2);
	printStack(A);
	printStack(B);
	printStack(A);
	printStack(B);
	insert(A,B,1);
	printStack(A);
	printStack(B);
	//printf("Pop one from first stack: %d\n", pop1(s));
	//printf("Pop one from second stack: %d\n", pop2(s));
	return 0;
}
// Linux, Mac: gcc task1.c -o task1; ./task1
// Windows: gcc task1.c -o task1; task1
