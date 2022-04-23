#include <stdlib.h>
#include <stdio.h>

struct TreeNode{
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

void insert(struct TreeNode** root, int val) {
  struct TreeNode* newTreeNode = NULL; 	
  struct TreeNode* prev = NULL; 	
  struct TreeNode* current = *root;
  newTreeNode = malloc(sizeof(struct TreeNode));
  newTreeNode->val = val;
  newTreeNode->left = NULL;
  newTreeNode->right = NULL;
  while (current != NULL) {
    prev = current;
    if (val < current->val){
      current = current->left;
    } else{
      current = current->right;
    }      
  }
  if (prev == NULL) {
    *root = newTreeNode;
  } else if (val < prev->val) {
    prev->left = newTreeNode;
  } else {
    prev->right = newTreeNode;
  }
}

int max(int a ,int b){
	if(a>b) return a;
	return b;
}
int MaxRank(struct TreeNode* node, int rank){
    if (node == NULL) { return 0;	}
    int rankR = MaxRank(node->right, rank);
    node->val = max(rank,rankR);
    int rankL = MaxRank(node->left,node->val+1);
    return max(rankL,node->val+1);
}


void printTreeRecursive(struct TreeNode *root) {
  if (root == NULL)
    return;
  if (root->left != NULL) {
    printf("  %d -- %d\n", root->val, root->left->val);
    printTreeRecursive(root->left);
  }
  if (root->right != NULL) {
    printf("  %d -- %d\n", root->val, root->right->val);
    printTreeRecursive(root->right);
  }
}

void printTree(struct TreeNode *root) {
  printf("graph g {\n");
  printTreeRecursive(root);
  printf("}\n");
}


int main() {
  struct TreeNode* root= NULL;
  printf("Inserting: 10, 3, 1, 7, 20, 15, 12, 17, 21\n");
  insert(&root, 10);
  insert(&root, 3);
  insert(&root, 1);
  insert(&root, 7);
  insert(&root, 20);
  insert(&root, 15);
  insert(&root, 12);
  insert(&root, 17);
  insert(&root, 21);
  printTree(root);
  MaxRank(root,0);
  printTree(root);
  

  return 0;
}
