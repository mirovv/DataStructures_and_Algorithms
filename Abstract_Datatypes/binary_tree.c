#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* right;
    struct Node* left;
}Node;

void insert(Node** root, int data){
    if(*root == NULL){
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(data <= (*root)->data){
        insert(&(*root)->left, data);
    }
    else{
        insert(&(*root)->right, data);
    }
}

Node* search(Node** root, int value){
    if(*root == NULL){
        printf("\nNode does not exist in Tree!\n");
        return NULL;
    }else if (value == (*root)->data){
        return *root;
    }else if(value < (*root)->data){
        return search(&(*root)->left, value);
    }else{
        return search(&(*root)->right, value);
    }
}

Node* TreeMin(Node** root){
    while (*root && (*root)->left != NULL){
        *root = (*root)->left;
    }
    return *root;
}

Node* TreeMax(Node** root){
    while(*root && (*root)->right != NULL){
        *root = (*root)->right;
    }
    return *root;
}

Node* findSuccessor(Node** root, int x){
    Node* findSuccessorOfMe = search(root, x);
    Node* successor = NULL;
    if (findSuccessorOfMe == NULL){
        return NULL;
    }else{
    // Case 1: if findSuccessorOfMe->right != NULL
    // --> leftmost node of right subtree
        if(findSuccessorOfMe->right != NULL){
            successor = TreeMin(&(*root)->right);
        }
    // Case 2: if findSuccessorOfMe->right == NULL
    // --> successor of findSuccessorOfMe is lowest ancestor whose left subtree contains findSuccessorOfMe
        else{
            while((*root)->data != x){
                if(x < (*root)->data){
                    successor = *root;
                    *root = (*root)->left;
                }else{
                    *root = (*root)->right;
                }
            }
        }
    }
    return successor;
}

Node* findParent(Node** root, Node* x){
    Node* parent = NULL;
    if(*root == NULL){
        printf("\nNode does not exist in Tree!\n");
        return NULL;
    }else if((*root)->left == x || (*root)->right == x){
        return *root;
    }else if(x->data < (*root)->data){
        return findParent(&(*root)->left, x);
    }else{
        return findParent(&(*root)->right, x);
    }
}

void delete(Node** root, int x){
    // delete node with value x
    Node* deleteMe = search(root, x);
    Node* parent = NULL;
    Node* current = *root;

    while (current->data != x){
        parent = current;
        if (x < current->data){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    printf("\nDeleting node with value %d", deleteMe->data);
    if (deleteMe == NULL){
        printf("\nNode does not exist in Tree!\n");
    }else{
        // Case 1: if deleteMe has no children
        if(deleteMe->left == NULL && deleteMe->right == NULL){
            if(deleteMe == *root){
                *root = NULL;
            }else{
                if(parent->left == deleteMe){
                    parent->left = NULL;
                }else{
                    parent->right = NULL;
                }
            }
        }
        // Case 2: if deleteMe has one child
        else if(deleteMe->left == NULL || deleteMe->right == NULL){
            if(deleteMe == current){
                if(deleteMe->left != NULL){
                    parent->left = deleteMe->left;
                }else{
                    parent->right = deleteMe->right;
                }
            }
        }
        // Case 3: if deleteMe has two children
        else{
            Node* successor = NULL;
            if (deleteMe->left != NULL){
                successor = TreeMax(&deleteMe->left);
                printf("\nMax Successor of %d is %d", deleteMe->data, successor->data);
            }else{
                successor = TreeMin(&deleteMe->right);
                printf("\nMin Successor of %d is %d", deleteMe->data, successor->data);
            }
            parent = findParent(root, successor);
            // if(deleteMe == *root){
            //     successor->left = (*root)->left;
            //     successor->right = (*root)->right;
            //     *root = successor;
            // }
        }
    }
    free(deleteMe);
}

void inorderTreewalk(Node** root){
    if (*root != NULL){
        inorderTreewalk(&(*root)->left);
        printf("%d ", (*root)->data);
        inorderTreewalk(&(*root)->right);
    }
}

void preorderTreewalk(Node** root){
    if (*root != NULL){
        printf("%d ", (*root)->data);
        inorderTreewalk(&(*root)->left);
        inorderTreewalk(&(*root)->right);
    }
}

void postorderTreewalk(Node** root){
    if (*root != NULL){
        inorderTreewalk(&(*root)->left);
        inorderTreewalk(&(*root)->right);
        printf("%d ", (*root)->data);
    }
}


int main(){
    Node** root = malloc(sizeof(Node));
    *root = NULL;
    insert(root, 9);
    insert(root, 4);
    insert(root, 5);
    insert(root, 12);
    insert(root, 2);
    insert(root, 1);
    insert(root, 6);
    insert(root, 10);
    insert(root, 11);
    insert(root, 13);
    printf("\nInorder: ");
    inorderTreewalk(root);
    printf("\nPreorder: ");
    preorderTreewalk(root);
    printf("\nPostorder: ");
    postorderTreewalk(root);
    // if (search(root, 1) != NULL){
    //     printf("\n%d\n", search(root, 1)->data);
    // }else{
    //     printf("Does not exist");
    // }
    // printf("\nSuccessor of 5: %d", findSuccessor(root, 5)->data);
    // printf("\nSuccessor of 4: %d", findSuccessor(root, 4)->data);
    // delete(root, 6);
    // printf("\nInorder: ");
    // inorderTreewalk(root);
    delete(root, 9);
    printf("\nInorder: ");
    inorderTreewalk(root);
    

    
    return 1;   
}