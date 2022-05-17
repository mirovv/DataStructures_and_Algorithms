#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* push(Node* stack, int val){
    // insert at the beginning
    if (stack == NULL){
        stack = malloc(sizeof(Node));
        stack->next = NULL;
        stack->val = val;
    }else{
        Node* temp = malloc(sizeof(Node));
        temp->val = val;
        temp->next = stack;
        stack = temp;
    }
    return stack;
}
// Node* deleteFirstElement(Node* stack){
//     Node* firstNode = stack;
//     Node* temp = stack->next;
//     stack = temp;
//     free(firstNode);
//     return stack;
// }

int pop(Node* stack){
    // delete first element and return it
    if (stack == NULL){
        printf("Stack is empty!\n");
        return -1;
    }else{
        int res = stack->val;
        Node* firstNode = stack;
        Node* temp = stack->next;
        stack = temp;
        free(firstNode);
        return res;
    }
}

void printStack(Node* stack){
    if (stack == NULL){
        printf("  Empty\n");
    }
    Node* current = stack;
    while(current != NULL){
        if(current->next != NULL){
            printf(" %d --", current->val);
        }else{
            printf(" %d", current->val);
        }
        current = current->next;
    }
}


int main(){
    Node* myStack = NULL;
    printf("Should print 'Empty': -->");
    printStack(myStack);
    myStack = push(myStack, 5);
    myStack = push(myStack, 9);
    myStack = push(myStack, 22);
    myStack = push(myStack, 7);
    printf("\n\nShould print: 7 -- 22 -- 9 -- 5\n");
    printStack(myStack);
    printf("\n\nShould print 7: --> %d\n", pop(myStack));
    printf("\n\nShould print: 22 -- 9 -- 5\n");
    printStack(myStack);
    // pop(myStack);
    // pop(myStack);
    // pop(myStack);
    // printf("Should print 'Stack is empty': -->");
    // printStack(myStack);



    return 1;
}