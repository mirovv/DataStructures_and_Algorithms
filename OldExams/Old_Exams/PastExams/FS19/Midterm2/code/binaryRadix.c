#include <stdlib.h>
#include <stdio.h>
#include "string.h"

struct radixTreeNode {
  int hasValue ;
  struct radixTreeNode* left;
  struct radixTreeNode* right;
};

struct radixTreeNode* createNewNode(){
	struct radixTreeNode* newNode = NULL;
	newNode = malloc(sizeof(struct radixTreeNode));
	newNode->hasValue = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
	
}

void insert(struct radixTreeNode** root, char val[], int N){
	if(*root == NULL){
		*root = createNewNode();
	}
	
	struct radixTreeNode* current = *root;
	int idx = 0;

	while(idx<N){
		if(val[idx] == '0'){
			if(current->left == NULL){
				current->left = createNewNode();
			} 
			current = current->left;	
		} else{
			if(current->right == NULL){
				current->right = createNewNode();
			}	
			current = current->right;
		}
		idx = idx +1;
	}
	current->hasValue = 1;
}

	void display(char str[], int N){
		int i;
		for(i= 0;i<=N;i++){
			printf("%c",str[i]);
		}
		printf("\n");
	}
	void preOrder(struct radixTreeNode* root,char str[], char v, int level){
	  if(root == NULL) return;
	  
	  if(level >= 0){
		str[level] = v;
	  }
	  if(root->hasValue == 1) display(str,level);
	  preOrder(root->left,str,'0',level+1);	
	  preOrder(root->right,str,'1',level+1);
	}

int main(){
	struct radixTreeNode* root= createNewNode();
	
    char inp[100] = "1000010";
	insert(&root,inp,7);
	strcpy(inp,"00");
	insert(&root,inp,2);
	strcpy(inp,"01");
	insert(&root,inp,2);
	//strcpy(inp,"0000");
	//insert(&root,inp,4);
	strcpy(inp,"100");
	insert(&root,inp,3);
	strcpy(inp,"011");
	insert(&root,inp,3);
	strcpy(inp,"1000000");
	insert(&root,inp,7);
	char tmp[100];				
	preOrder(root,tmp,'0',-1);
	return 0;
}





