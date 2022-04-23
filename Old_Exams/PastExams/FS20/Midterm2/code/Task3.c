#include <stdlib.h>
#include <stdio.h>

struct node {
  int val;
  struct node* next;
};

void append(struct node** rootA, int val) {
  struct node* curr;
  struct node* new = malloc(sizeof(struct node));
  new->val = val;
  new->next = NULL;
  if (*rootA == NULL) { *rootA = new; }
  else {
    curr = *rootA;
    while (curr->next != NULL) curr = curr->next;
    curr->next = new;
  }
}

void merge(struct node** A, struct node** B){
    if (*A == NULL && *B == NULL) return;
    else if (*A == NULL) { *A = *B; return; }
    else if (*B == NULL ) { *B = *A; return; }
    struct node* curr = *A;
    struct node* next = *B;
    while (next != NULL) {
        struct node* temp = next;
        next = curr->next;
  	    curr->next = temp;
        curr = temp;
    }
    *B = *A;
}

void print(struct node* rootA) {
  struct node* curr = rootA;
  printf("[ ");
  while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("]\n");
}

void main() {
  struct node* rootA = NULL;
  struct node* rootB = NULL;

  merge(&rootA,&rootB);
  print(rootA);
  print(rootB);
	
  append(&rootA, 2);
  append(&rootA, 3);
  append(&rootA, 4);
  merge(&rootA,&rootB);
  print(rootA);
  print(rootB);

	rootB = rootA;
	rootA = NULL;
  merge(&rootA,&rootB);
  print(rootA);
  print(rootB);
		
	rootB = NULL;
  append(&rootB, 6);
  append(&rootB, 7);
  append(&rootB, 8);
  merge(&rootA,&rootB);
  print(rootA);
  print(rootB);
}

/*
  gcc Task3.c -o Task3; ./Task3
*/
