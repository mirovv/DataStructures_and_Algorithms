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
    struct TreeNode* current = malloc(sizeof(struct TreeNode));
    current = root;
    while (current != NULL && current->val != val){
        if (val < current->val){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return current;
}
struct TreeNode* searchTreeRecursively(struct TreeNode* root, int val){

    // do I really need the current.. first I handled it all with root (same solution)
    // what is the point in returning the node???

    struct TreeNode* current = root;
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

// we need this if we need to delete a node with two children
// --> we can either place the smallest node of the right subtree of the node to be deleted in its place
// ----> or we can place the largest node of the left subtree in its place

// SMALLEST NODE
struct TreeNode* findTreeMin(struct TreeNode* root){
    struct TreeNode* current = root;

    // find the leftmost leaf
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

// LARGEST NODE
struct TreeNode* findTreeMax(struct TreeNode* root){
    struct TreeNode* current = root;

    while (current && current->right != NULL){
        current = current->right;
    }
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int val){
    struct TreeNode* current = malloc(sizeof(struct TreeNode));
    struct TreeNode* lagging = malloc(sizeof(struct TreeNode));
    current = root;
    lagging = NULL;
    
    // return if tree is empty
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
    if (current->right == NULL){
        if (lagging == NULL){
            root = current->left;
        }else if (lagging->left->val == current->val){
            lagging->left = current->left;
        }else{
            lagging->right = current->left;
        }
    }else if (current->left == NULL){
        if (lagging == NULL){
            root = current->right;
        }else if (lagging->left->val == current->val){
            lagging->left = current->right;
        }else{
            lagging->right = current->right;
        }
    }else{
        struct TreeNode* p = current->left;
        struct TreeNode* q = p;
        while (p->right != NULL){
            q = p;
            p = p->right;
        }
        if (lagging == NULL){
            root = p;
        }else if (lagging->left->val == current->val){
            lagging->left = p;
        }else{
            lagging->right = p;
        }
        p->right = current->right;
        if (q != p){
            q->right = p->left;
            p->left = current->left;
        }
    }
    return root;
}

struct TreeNode* delete(struct TreeNode* root, int val){

    // return if tree is empty
    if (root == NULL){
        return root;
    }
    // find the node to be deleted
    if (val < root->val){
        root->left = delete(root->left, val);
    }else if (val > root->val){
        root->right = delete(root->right, val);
    }else{
        // If the node has only one child or no child
        if (root->left == NULL){
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // if the node has 2 children, find maxValueNode of left subtree (or minValueNode of right subtree)
        struct TreeNode* temp = findTreeMax(root->left);

        // place the inorder successor in position of the node to be deleted
        root->val = temp->val;

        // delete the inorder successor
        root->left = delete(root->left, temp->val);

        
        /* IF YOU WANT TO REPLACE WITH MIN. VALUE OF RIGHT SUBTREE */

        // struct TreeNode* temp = findTreeMin(root->right);
        // root->val = temp->val;
        // root->right = delete(root->right, temp->val);
    
    }   
    return root;
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

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    // struct TreeNode* x = searchTreeRecursively(root, 5);
    // struct TreeNode* y = searchTreeLinearly(root, 5);
    printf("Inorder traversal: ");
    printTree(root);
    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("Inorder traversal: ");
    printTree(root);
    // printf("\nrecursive:  ");
    // printTree(x);
    // printf("\nlinear:  ");
    // printTree(y);
    // printf("\n");
    return 1;
}