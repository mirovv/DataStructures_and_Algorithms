#include <stdlib.h>
#include <stdio.h>

struct node {
	int k;
	struct node* n;
	struct node* p;
};

struct node *h, *t, *a, *b;


void append(struct node** h,struct node** t, int val) {
	struct node* new = malloc(sizeof(struct node));
	new->k = val;
	new->n = NULL;
	new->p = NULL;
	
	if(*h == NULL){
		*h = new;
		*t = new;
	}else{
		(*t)->n = new;
		new->p = *t;
		*t = new;
	}
}

struct node* search(struct node* h, int val){
	struct node* curr = h;
	if (curr != NULL){
		while (curr != NULL) {
			if(curr->k == val){
				return curr;
			}
			curr = curr->n;
		}
	}
	return curr;
}

void xchg(struct node* a, struct node* b,
					struct node** h,struct node** t){
	
	struct node* ap = a->p;
	struct node* an = a->n;
	struct node* bp = b->p;
	struct node* bn = b->n;
	
	if (an == b) {
		b->n = a;
		a->p = b;
	} else {
		an->p = b;
		bp->n = a;
		b->n = an;
		a->p = bp;
	}
	if (ap != NULL) {ap->n = b;} else {*h = b;}
	if (bn != NULL) {bn->p = a;} else {*t = a;}
	b->p = ap;	
	a->n = bn; 
}

void print(struct node* h) {
	struct node* curr = h;

	printf("[ ");
	if (curr != NULL){
		while (curr != NULL) {
			printf("%d ", curr->k);
			curr = curr->n;
		}
		//printf("%d ", curr->k);
	}
	printf("]\n");
}

int main() {
	
	h = NULL;
	t = NULL;
	printf("Appending 10 and 20 to list: \n");
	append(&h,&t,10);
	append(&h,&t,20);
	print(h);
	xchg(search(h,10),search(h,20),&h,&t);
	printf("Exchanging 10 and 20 in list: \n");
	print(h);
	append(&h,&t,30);
	append(&h,&t,40);
	append(&h,&t,50);
	printf("Appending 30,40 and 50 to list: \n");
	print(h);
	xchg(search(h,20),search(h,40),&h,&t);
	printf("Exchanging 20 and 40 in list: \n");
	print(h);
	xchg(search(h,30),search(h,20),&h,&t);
	printf("Exchanging 30 and 20 in list: \n");
	print(h);
	xchg(search(h,40),search(h,10),&h,&t);
	printf("Exchanging 40 and 10 in list: \n");
	print(h);
	xchg(search(h,30),search(h,50),&h,&t);
	printf("Exchanging 30 and 50 in list: \n");
	print(h);
	append(&h,&t,60);
	printf("Appending 60 to list: \n");
	print(h);
	xchg(search(h,50),search(h,60),&h,&t);
	printf("Exchanging 50 and 60 in list: \n");
	print(h);
	return 0;
}
// Linux, Mac: gcc linkedlist.c -o linkedlist; ./linkedlist
// Windows: gcc linkedlist.c -o linkedlist; linkedlist
