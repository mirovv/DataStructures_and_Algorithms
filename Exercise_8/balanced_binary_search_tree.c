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

TreeNode* deleteNode(TreeNode* root, int val){
    if (root == NULL){
        return root;
    }
}

TreeNode* buildBalancedTree(TreeNode* root, Stack* s){

}

int main(){
    TreeNode* root = NULL;

    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 7);
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 14);
    root = insertNode(root, 4);

    int amountNodes = countNodes(root);
    Stack* stack = createStack(amountNodes);

    inorderTraversal(root, stack);
    printStack(stack);


    return 1;
}