#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    unsigned int capacity;
    int* items;
    int top;
} stack;

stack* create(){
    stack* s = malloc(sizeof(stack));
    return s;
}

void delete(stack* s){
    free(s);
}

int is_empty(stack* s){
    if (s == NULL){
        return 0;
    }return 1;
}

int is_full(stack* s){
    int cnt = 0;
    stack* current = s;
    while (current != NULL){
        current = current->items;
        cnt++;
    }
    if (cnt == s->capacity){
        return 1;
    }else{
        return 0;
    }
}

int get_capacity(stack* s){
    return s->capacity;
}

int num_items(stack* s){
    int cnt = 0;
    stack* current = s;
    while (current != NULL){
        current = current->items;
        cnt++;
    }
    return cnt;
}

void push(stack* s, int val){
    s->items = val;
    s->top = val;
}

int pop(stack* s){
    int temp = s->items;
    s->top = s->items;
    s = s->items;
    return temp;
}

int peek(stack* s){
    return s->top;
}

void print(stack* s){
    stack* current = s;
    while (current != NULL){
        if (current->items != NULL){
            printf("%d -", current->top);
        }else{
            printf("%d", current->top);
            }
        current = current->items; 
    }
    printf("\n");
}

int is_equal(stack* s, stack* p){
    return 1;
}

// stack* reverse(stack* s){

//     return asdf;
// }

int main(){
    stack* myStack = create();
    push(myStack, 5);
    print(myStack);
    push(myStack, 9);
    print(myStack);
    int x = pop(myStack);
    print(myStack);
    printf("%d", x);
}