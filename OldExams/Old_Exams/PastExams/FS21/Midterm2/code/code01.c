#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* rearrange(struct node* h) {
  struct node *dummy1 = malloc(sizeof(struct node));
  struct node *dummy2 = malloc(sizeof(struct node));
  struct node * p1 = dummy1;
  struct node * p2 = dummy2;
  struct node *p = h;

  while (p != NULL) {
    if(p->val < h->val){
      p1->next = p;
      p1 = p1->next;
    } else {
      p2->next = p;
      p2 = p2->next;
    }
    p = p->next;
  }

  p1->next = dummy2->next;
  p2->next = NULL;

  struct node *newh = dummy1->next;
  free(dummy1);
  free(dummy2);
  return newh;
}

void printlinklist(struct node* h){
  struct node *p = h;
  while(p != NULL) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

int main() {
  struct node *h = malloc(sizeof(struct node));
  h->val = 5;
  h->next = NULL;

  struct node *n1 = malloc(sizeof(struct node));
  n1->val = 6;

  struct node *n2 = malloc(sizeof(struct node));
  n2->val = 1;
  
  struct node *n3 = malloc(sizeof(struct node));
  n3->val = 8;
  
  struct node *n4 = malloc(sizeof(struct node));
  n4->val = 3;

  h->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = NULL;
  printlinklist(h);

  struct node *newh = rearrange(h);
  printlinklist(newh);

}