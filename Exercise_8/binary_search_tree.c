#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val){
    struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int val){
    if (root == NULL){
        root = createNode(val);
    }else if (val < root->val){ // left
        root->left = insert(root->left, val);
    }else{ // right
        root->right = insert(root->right, val);
    }
    return root;
}

struct TreeNode* searchTreeLinearly(struct TreeNode* root, int val){
    while (root != NULL && root->val != val){
        if (val < root->val){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return root;
}

struct TreeNode* findTreeMin(struct TreeNode* root){
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

struct TreeNode* searchTreeRecursively(struct TreeNode* root, int val){

    // do I really need the current.. first I handled it all with root (same solution)
    // what is the point in returning the node???

    struct TreeNode* current = malloc(sizeof(struct TreeNode));
    current = root;
    if (root == NULL){
        printf("\nDoes not exist in tree\n");
        return root;
    }else if (val < current->val){ // node must be to the left
        return searchTreeRecursively(current->left, val);
    }else if (val > current->val){ // node must be to the right
        return searchTreeRecursively(current->right, val);
    }else{
        return current;
    }
}

struct TreeNode* delete(struct TreeNode* root, int val){
    struct TreeNode* current = malloc(sizeof(struct TreeNode));
    struct TreeNode* lagging = malloc(sizeof(struct TreeNode));
    current = root;
    if (root == NULL){
        return root;
    }
    while (current->val != val){
        lagging = current;
        if (current->val < val){
            current = current->right;
        }else{
            current = current->left;
        }
    }
    if (current->left == NULL && current->right == NULL){ 
        // node to be deleted has no children
        free(current);
    }else if (current->left == NULL){
        // node has one child (left or right)
    }
}

void printTree(struct TreeNode* root){
    if(root != NULL){
        printTree(root->left);
        printf("%d ", root->val);
        printTree(root->right);
    }
}

int main(){
    struct TreeNode* root = NULL;

    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);

    printTree(root);
    printf("\n");
    struct TreeNode* x = searchTreeRecursively(root, 5);
    struct TreeNode* y = searchTreeLinearly(root, 5);
    printTree(root);
    printf("\nrecursive:  ");
    printTree(x);
    printf("\nlinear:  ");
    printTree(y);
    printf("\n");
    return 1;
}