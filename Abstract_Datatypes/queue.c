#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int* item;
    int capacity;
    int head;
    int tail;
}Queue;

Queue* createQueue(Queue* Q, int capacity){
    Queue* newQ = malloc(sizeof(Queue));
    newQ->capacity = capacity;
    newQ->head = 0;
    newQ->tail = 0;
    newQ->item = malloc(sizeof(capacity * sizeof(int)));
    return newQ;
}

void printQueue(Queue* Q){
    int i;
    for (i = Q->head; i < Q->capacity - Q->tail; i++){
        printf("%d -", Q->item[i % Q->capacity]);
    }
    printf("\n");
}

int isFull(Queue* Q){
    if (Q->head == (Q->tail + 1) % Q->capacity){
        return 1;
    }return 0;
}

int isEmpty(Queue* Q){
    if (Q->head == Q->tail){
        return 1;
    }return 0;
}


void enqueue(Queue* Q, int val){
    if (Q == NULL){
        return;
    }else if (isFull(Q)){
        printf("Queue is full!\n");
        return;
    }else{
        Q->item[Q->tail] = val;
        Q->tail = (Q->tail + 1) % Q->capacity;
    }
}

int dequeue(Queue* Q){
    if (isEmpty(Q)){
        printf("Queue is empty!\n");
        return 0;
    }else{
        int temp = Q->item[Q->head];
        Q->head = (Q->head + 1) % Q->capacity;
        return temp;
    }
}

int main(){
    Queue* MyQueue = createQueue(MyQueue, 10);
    enqueue(MyQueue, 7);
    enqueue(MyQueue, 6);
    enqueue(MyQueue, 5);
    enqueue(MyQueue, 4);
    enqueue(MyQueue, 3);
    enqueue(MyQueue, 2);
    enqueue(MyQueue, 10);
    enqueue(MyQueue, 9);
    enqueue(MyQueue, 8);
    printQueue(MyQueue);
    int test = dequeue(MyQueue);
    printQueue(MyQueue);
    // int x = dequeue(MyQueue);
    // printf("%d\n", x);
    // x = dequeue(MyQueue);
    // printf("%d\n", x);
    // x = dequeue(MyQueue);
    // printf("%d\n", x);
    // x = dequeue(MyQueue);
    // printf("%d\n", x);
    // x = dequeue(MyQueue);
    // printf("%d\n", x);


    return 1;
}