#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

void insert(Node** root, int val){
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if(*root == NULL){
        *root = newNode;
    }else{
        newNode->next = *root;
        *root = newNode;
    }
}

void printLL(Node** head){
    while(*head != NULL){
        if((*head)->next == NULL){
            printf("%d", (*head)->val);
        }else{
            printf("%d -> ", (*head)->val);
        }
        *head = (*head)->next;
    }
    printf("\n");
}

void merge(Node** l1, Node** l2){
    Node* s = NULL;
    Node* n = NULL;
    Node* o = NULL;
    if(*l1 && *l2 == NULL){
        printf("bruh");
        return;
    }
    else if(*l1 == NULL && *l2 != NULL){
        printf("asdf");
        *l1 = *l2;
        return;
    }
    else if(*l2 == NULL && *l1 != NULL){
        printf("wieso");
        *l2 = *l1;
        return;
    }
    else if((*l1)->val < (*l2)->val){
        Node* s = *l1;
        Node* n = (*l1)->next;
        Node* o = *l2;
        while(n && o != NULL){
            if(n->val < o->val){
                n = n->next;
                s = s->next;
            }else{
                s->next = o;
                o = o->next;
            }
            s = s->next;
        }
        if(n != NULL){
            s->next = o;
        }
        if(o != NULL){
            s->next = n;
        }
    }
    else{
        Node* s = *l2;
        Node* n = (*l2)->next;
        Node* o = *l1;
        while(n && o != NULL){
            if(n->val < o->val){
                n = n->next;
                s = s->next;
            }else{
                s->next = o;
                o = o->next;
            }
            s = s->next;
        }
        if(n != NULL){
            s->next = o;
        }
        if(o != NULL){
            s->next = n;
        }
    }

}


int main(){
    Node** l1 = malloc(sizeof(Node));
    Node** l2 = malloc(sizeof(Node));
    *l1 = NULL;
    *l2 = NULL;

    insert(l1, 83);
    insert(l1, 77);
    insert(l1, 33);
    insert(l1, 23);
    insert(l1, 8);
    insert(l1, 3);
    insert(l1, 2);
    insert(l1, 1);

    insert(l2, 69);
    insert(l2, 43);
    insert(l2, 21);
    insert(l2, 19);
    insert(l2, 7);
    insert(l2, 2);
    insert(l2, 1);
    insert(l2, 0);

    printf("List 1: \n");
    printLL(l1);
    printf("List 2: \n");
    printLL(l2);
    merge(l1,l2);
}