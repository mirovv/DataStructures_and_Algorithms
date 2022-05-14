#include <stdio.h>
#include <stdlib.h>

struct node { 
  int value;
  struct node* left;
  struct node* right; 
};

int min(int n1, int n2) {
  if(n1 < n2) return n1;
  else return n2;
}

int smallest(struct node* p, int v) {
    if (p == NULL) { return v; }
    return min(smallest(p->left,v),
               min(smallest(p->right,v), p->value));
}

int main() {
  struct node* root = (struct node*)malloc(sizeof(struct node)); 
  struct node* second = (struct node*)malloc(sizeof(struct node)); 
  struct node* third = (struct node*)malloc(sizeof(struct node)); 
  struct node* fourth = (struct node*)malloc(sizeof(struct node)); 
  struct node* fifth = (struct node*)malloc(sizeof(struct node)); 

  root->value = 2;
  
  root->left = second;
  root->right = third;
  
  second->value = 5;
  second->left = fourth;
  second->right = NULL;

  third->value = -1;
  third->left = NULL;
  third->right = fifth;
  
  fourth->value = -10;
  fourth->left = NULL;
  fourth->right = NULL;

  fifth->value = 0;
  fifth->left = NULL;
  fifth->right = NULL;

printf("Smallest elem = %d\n", smallest(root,root->value));
}

/*
gcc Task2.c -o Task2; ./Task2
*/
