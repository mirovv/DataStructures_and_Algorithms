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
    Node* current = *root;
    while(current && current->right != NULL){
        current = current->right;
    }
    return current;
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
        preorderTreewalk(&(*root)->left);
        preorderTreewalk(&(*root)->right);
    }
}

void postorderTreewalk(Node** root){
    if (*root != NULL){
        postorderTreewalk(&(*root)->left);
        postorderTreewalk(&(*root)->right);
        printf("%d ", (*root)->data);
    }
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
    Node* current = *root;
    if(current == NULL){
        printf("\nNode does not exist in Tree!\n");
        return NULL;
    }else{
        while (current != NULL){
            if(current->left == x || current->right == x){
                parent = current;
                break;
            }else if(x->data < current->data){
                current = current->left;
            }else{
                current = current->right;
            }
        }
    }
    return parent;
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
    printf("\nDeleting node with value %d\n", deleteMe->data);
    if (deleteMe == NULL){
        printf("\nNode does not exist in Tree!\n");
        return;
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
            if(parent->left == deleteMe){ // deleteMe is a left child
                if(deleteMe->left == NULL){ // deleteMe has no left child
                    parent->left = deleteMe->right;
                }else{
                    parent->left = deleteMe->left;
                }
            }else{ // deleteMe is a right child
                if(deleteMe->left == NULL){ // deleteMe has no left child
                    parent->right = deleteMe->right;
                }else{
                    parent->right = deleteMe->left;
                }
            }
        }
        // Case 3: if deleteMe has two children
        else{
            Node* successor = TreeMax(&deleteMe->left);
            Node* parentSucc = findParent(root, successor);
            printf("\nMax Successor of %d is %d", deleteMe->data, successor->data);

            if(parent == NULL){ // if deleteMe is root
                printf("\nvalue parentSucc: %d", parentSucc->data);
                parentSucc->right = successor->left;
                successor->left = (*root)->left;
                successor->right = (*root)->right;
                *root = successor;
            }else{  // deleteMe is internal Node
                if(parent->left == deleteMe){   // if deleteMe is left child of parent
                    printf("\nis left child of parent\n");
                    if(parentSucc != deleteMe){
                        successor->left = deleteMe->left;
                    }
                    successor->right = deleteMe->right;
                    parentSucc->left = NULL;
                    parent->left = successor;
                }else{  // if deleteMe is right child of parent
                    printf("\nis right child of parent\n");
                    if(parentSucc->right != deleteMe){
                        successor->right = deleteMe->right;
                    }
                    successor->left = deleteMe->left;
                    parentSucc->right = NULL;
                    parent->right = successor;
                }
            }
        }
    }
    free(deleteMe);
}

void minAggregate(Node** root){
    while (*root != NULL){
        minAggregate(&(*root)->left);
        if ((*root)->left != NULL){
            (*root)->data += (*root)->left->data;
        }
        
        minAggregate(&(*root)->right);
        if ((*root)->right != NULL){
            (*root)->data += (*root)->right->data;
        }        
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
    
    delete(root, 5);
    printf("\nPostorder: ");
    postorderTreewalk(root);
    printf("\nInorder: ");
    inorderTreewalk(root);

    printf("\n-----------------------------\n");
    Node** test = malloc(sizeof(Node));
    *test = NULL;
    insert(test, 10);
    insert(test, 3);
    insert(test, 20);
    insert(test, 1);
    insert(test, 7);
    insert(test, 15);
    insert(test, 21);
    insert(test, 12);
    insert(test, 17);
    inorderTreewalk(test);
    minAggregate(test);
    inorderTreewalk(test);
    printf("\n-----------------------------\n");

    
    return 1;   
}