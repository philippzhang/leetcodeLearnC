//
// Created by zhangyangshuo on 2020/12/2.
//
#include <stdio.h>
#include <stdlib.h>
//用链表实现栈
typedef struct Node{
    int data;
    struct Node *next;
} node;

int isEmpty(node *p){
    return p->next==NULL;
}

node *createStack(){
    node *p = (node*)malloc(sizeof(node));
    p->next = NULL;
    return p;
}

node *push(node *p,int x){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
    return p;
}

void pop(node *p){
    node *temp;
    if(p->next==NULL){
        printf("null");
    }else{
        temp = p->next;
        p->next=temp->next;
        free(temp);
    }
}

void display(node *p){
    node *temp = p;
    while(temp->next){
        printf("%d ",temp->next->data);
        temp = temp->next;
    }
    printf("%c",'\n');
}

int main(){
    node *p = createStack();
    push(p,1);
    push(p,2);
    push(p,3);
    display(p);
    pop(p);
    display(p);
    pop(p);
    display(p);
}