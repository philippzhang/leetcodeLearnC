//
// Created by zhangyangshuo on 2020/12/3.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Queue{
    int capacity;
    int front;
    int rear;
    int size;
    int data[MAX_SIZE];
} Queue;

int isEmpty(Queue *Q){
    return Q->size ==0;
}

int isFull(Queue *Q){
    return Q->size == Q->capacity;
}

void init(Queue *Q){
    Q->size = 0;
    Q->front = 1;
    Q->rear = 0;
    Q->capacity = MAX_SIZE;
}

static int succ(int value ,Queue *Q){
    if(++value == Q->capacity){
        value = 0;
    }
    return value;
}

/**
 * 入队列
 * @param x
 * @param Q
 */
void enQueue(int x,Queue *Q){
    if(isFull(Q)){
        printf("%s\n","Full queue");
    }else{
        Q->size++;
        Q->rear = succ(Q->rear,Q);
        Q->data[Q->rear] = x;
    }
}

/**
 * 移除队列
 * @param Q
 */
int deQueue(Queue *Q){
    int temp;
    if(isEmpty(Q)){
        printf("%s\n","Empty queue");
    }else{
        Q->size--;
        temp = Q->data[Q->front];
        Q->front = succ(Q->front,Q);
        return temp;
    }
}

void disposeQueue(Queue *Q){
    free(Q->data);
    free(Q);
}

int main(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    init(q);
    int i;
    //printf("%s\n","队列处理:");
    for(i=0;i<MAX_SIZE;i++){
        enQueue(i,q);
    }
    for (i = 0;  i<MAX_SIZE ; i++) {
        printf("%d\n",deQueue(q));
    }
    disposeQueue(q);
}