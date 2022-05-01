#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode{
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
}TreeNode;

typedef struct Stack{
    int capacity;
    int* items;
    int top;
}Stack;

void printArray(int arr[]){

    for(int i = 0; i < 10; i++){
        printf("%d, ", arr[i]);
    }
}

Stack* createStack(int size){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->capacity = size;
    newStack->items = malloc(sizeof(size * sizeof(int)));
    newStack->top = -1;
    return newStack;
}

int isfullStack(Stack* s){
    if (s->top+1 == s->capacity){
        return 1;
    }return 0;
}

int isemptyStack(Stack* s){
    if (s->top == -1){
        return 1;
    }return 0;
}

void pushStack(Stack* s,int val){
    if (isfullStack(s)){
        printf("\nStack is full\n");
    }else{
        s->top++;
        s->items[s->top] = val;
    }
}

int popStack(Stack* s){
    if (isemptyStack(s)){
        printf("\nStack is empty\n");
        return -1;
    }else{
        int temp = s->items[s->top];
        s->top--;
        return temp;
    }
}

void printStack(Stack* s){
    int i;
    if (isemptyStack(s)){
        printf("Stack is empty\n");
    }
    for (i = 0; i <= s->top; i++){
        if (i < s->top){
            printf("%d - ", s->items[i]);
        }else{
            printf("%d\n", s->items[i]);
        }
    }
}

TreeNode* createNode(int val){
    TreeNode* newNode = malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int val){
    if (root == NULL){
        root = createNode(val);
    }else{
        if (root->val < val){
            root->right = insertNode(root->right, val);
        }else{
            root->left = insertNode(root->left, val);
        }
    }
    return root;
}

int countNodes(TreeNode* root){
    if (root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

Stack* inorderTraversal(TreeNode* root, Stack* s){
    if (root != NULL){
        inorderTraversal(root->left, s);
        pushStack(s, root->val);
        inorderTraversal(root->right, s);
    }
    return s;
}

void printInorderTree(TreeNode* root){
    if(root != NULL){
        printInorderTree(root->left);
        printf("%d ", root->val);
        printInorderTree(root->right);
    }
}

void printPreorderTree(TreeNode* root){
    if (root != NULL){
        printf("%d ", root->val);
        printPreorderTree(root->left);
        printPreorderTree(root->right);
    }
}

TreeNode* searchTreeLinearly(struct TreeNode* root, int val){
    struct TreeNode* current = root;
    while (current != NULL && current->val != val){
        if (val < current->val){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, int val){
    TreeNode* x = searchTreeLinearly(root, val);
    if (x == NULL){
        return root;
    }
    TreeNode* current = root;
    TreeNode* parent = NULL;
    while (current != x){
        parent = current;
        if (current->val < x->val){
            current = current->right;
        }else{
            current = current->left;
        }
    }
    // Leaf and root case
    if (current->right == NULL){
        if (parent == NULL){ // this is the case when the node to be deleted is root itself
            root = current->left;
        }else if (parent->left == current){ // if it's a left child, make left child the new child
            parent->left = current->left;
        }else{
            parent->right = current->left;
        }
    }else if (current->left == NULL){ // mirror case
        if (parent == NULL){ // root case
            root = current->right;
        }else if (parent->right == current){ // if it's a right child, make right child the new child 
            parent->right = current->right;
        }else{
            parent->left = current->right;
        }
    // 2 children cases
    }else{
        TreeNode* maxLeft = current->left;
        TreeNode* parentMaxLeft = maxLeft;
        // now maxLeft and parent it the right way
        while (maxLeft->right != NULL){
            parentMaxLeft = maxLeft;
            maxLeft = maxLeft->right;
        }
        if (parent == NULL){ // we are at root (exchange with maxLeft)
            root = maxLeft;
        }else if (parent->left == current){ // if it's a left child
            parent->left = maxLeft; // let parent.left point to maxLeft
        }else{
            parent->right = maxLeft;
        }
        maxLeft->right = current->right; // append the rest of the tree to maxLeft.right
        if (maxLeft != parentMaxLeft){
            parentMaxLeft->right = maxLeft->left;
            maxLeft->left = current->left;
        }
    }
    free(current);
    return root;
}

TreeNode* buildBalancedTree(Stack* s, int l, int r){
    if (l > r){
        return NULL;
    }
    int m = (l+r) / 2;
    TreeNode* newBalancedTree = malloc(sizeof(TreeNode));
    newBalancedTree->val = s->items[m];
    newBalancedTree->left = buildBalancedTree(s, l, m-1);
    newBalancedTree->right = buildBalancedTree(s, m+1, r);
    return newBalancedTree;
}

int main(){
    TreeNode* root = NULL;

    TreeNode* test = NULL;

    test = insertNode(test, 5);
    test = insertNode(test, 4);
    test = insertNode(test, 3);
    test = insertNode(test, 2);
    test = insertNode(test, 1);

    root = insertNode(root, 12);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 18);
    root = insertNode(root, 15);
    root = insertNode(root, 17);
    root = insertNode(root, 22);
    root = insertNode(root, 19);
    root = insertNode(root, 20);

    printf("test: ");
    printPreorderTree(test);
    int amtTest = countNodes(test);
    Stack* tstack = createStack(amtTest);
    inorderTraversal(test, tstack);
    printStack(tstack);
    test = buildBalancedTree(tstack, 0, amtTest-1);
    printf("\n");
    printPreorderTree(test);
    printf("\n");
    printf("\n");



    int amountNodes = countNodes(root);
    Stack* stack = createStack(amountNodes);

    inorderTraversal(root, stack);
    printStack(stack);

    root = deleteNode(root, 5);
    printf("Inorder traversal: ");
    printInorderTree(root);
    printf("\n");
    printf("Preorder traversal: ");
    printPreorderTree(root);
    printf("\n");
    amountNodes = countNodes(root);
    stack = createStack(amountNodes);
    inorderTraversal(root, stack);
    printStack(stack);
    root = buildBalancedTree(stack, 0, amountNodes-1);
    printf("Inorder traversal: ");
    printInorderTree(root);
    printf("\n");
    printf("Preorder traversal: ");
    printPreorderTree(root);
    printf("\n");


    return 1;
}