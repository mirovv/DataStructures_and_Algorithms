#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    unsigned int capacity;
    int* items;
    int top;
}stack;

stack* create(unsigned int capacity){
    stack* new_stack = malloc(sizeof(stack));
    new_stack->capacity = capacity;
    new_stack->top = -1;
    new_stack->items = malloc(sizeof(capacity * sizeof(int)));
    return new_stack;
}

void delete(stack* s){
    free(s->items);
    free(s);
}

int is_empty(stack* s){
    if (s->top == -1){
        return 1;
    }return 0;
}

int is_full(stack* s){
    if (s->top+1 == s->capacity){
        return 1;
    }return 0;
}

int get_capacity(stack* s){
    return s->capacity;
}

int num_items(stack* s){
    return s->top+1;
}

void push(stack* s, int val){
    if (is_full(s)){
        printf("Cannot push %d (Stack is full!!!)\n", val);
    }else{
        s->top++;
        printf("\nHELLO IM TOP: %d\n", s->top);
        s->items[s->top] = val;
    }
}

int pop(stack* s){
    if (is_empty(s)){
        printf("Cannot pop any element since the stack is EMPTY...\n");
        return -1;
    }else{
        int res = s->items[s->top];
        s->top--;
        return res;
    }
}

int peek(stack* s){
    if (is_empty(s)){
        printf("Cannot peek any element since the stack is EMPTY...\n");
        return -1;
    }else{
        return s->items[s->top];
    }
}

void print(stack* s){
    int i;
    if (is_empty(s)){
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

void is_equal(stack* s, stack* p){
    int i = get_capacity(s);
    int j = get_capacity(p);
    
    if (j < i){
        for(int x = 0; x < j; x++){
            if (s->items[x] != p->items[x]){
                printf("The two Stacks are not equal!!!\n-------------\nStack 1 at index %d: %d\nStack 2 at index %d: %d\n", x,s->items[x],x,p->items[x]);
                return;
            }
        }
        printf("The Stacks are equal :D!!!\n");
    }else{
        for(int x = 0; x < i; x++){
            if (s->items[x] != p->items[x]){
                printf("The two Stacks are not equal!!!\n-------------\nStack 1 at index %d: %d\nStack 2 at index %d: %d\n", x,s->items[x],x,p->items[x]);
                return;
            }
        }
        printf("The Stacks are equal :D!!!\n");
    }
}

stack* reverse(stack* s){
    stack* reverseStack = create(s->capacity);
    int i = s->capacity-1;
    for (i; i >= 0; i--){
        push(reverseStack, s->items[i]);
    }
    return reverseStack;
}

int main(){
    stack* firstStack = create(4);
    stack* myStack = create(4);
    int x = is_empty(myStack);
    printf("Is empty (1): %d\n", x);
    printf("Num. items: %d\n", num_items(myStack));
    push(myStack, 5);
    push(firstStack, 5);
    push(firstStack, 88);
    x = is_empty(myStack);
    printf("Is empty (0): %d\n", x);
    push(myStack, 9);
    is_equal(myStack,firstStack);
    push(myStack, 27);
    printf("Num. items: %d\n", num_items(myStack));
    push(myStack, 46);
    printf("Peek mashallah: %d\n", peek(myStack));
    print(myStack);
    printf("Num. items: %d\n", num_items(myStack));
    push(myStack, 23);
    print(myStack);
    printf("Peek: %d\n", peek(myStack));
    firstStack = reverse(myStack);
    print(firstStack);
    print(myStack);

}