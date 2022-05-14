#include <stdlib.h>
#include <stdio.h>

struct node {
  int hasVal ;
  struct node* left;
  struct node* right;
};

struct node* insert(struct node* p, char s[], int i, int n) {
	if (p == NULL) {
		p = malloc(sizeof(struct node));
		p->hasVal = 0;
		p->left = NULL;
		p->right = NULL;
	}
	if (i == n) p->hasVal = 1;
	else if (s[i] == '0') p->left = insert(p->left,s,i+1,n);
	else p->right = insert(p->right,s,i+1,n);
	return p;
}

void preOrder(struct node* root, int i, int level){
  if (root == NULL) return;
  if (root->hasVal == 1) printf("%0*d\n", level, i);
  preOrder(root->left, 10*i, level+1);	
  preOrder(root->right, 10*i+1, level+1);
}

int main(){
	struct node* root = malloc(sizeof(struct node));
	root->left = NULL;
	root->right = NULL;
	root->hasVal = 0;
	
	root = insert(root,"1000010",0,7);
	root = insert(root,"00",0,2);
	root = insert(root,"10",0,2);
	root = insert(root,"01",0,2);
	root = insert(root,"100",0,3);
	root = insert(root,"011",0,3);
	root = insert(root,"1000000",0,7);
	preOrder(root,0,0);
}

/*

gcc -o binRad binRad.c; ./binRad

*/
