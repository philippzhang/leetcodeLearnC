//
// Created by zhangyangshuo on 2020/12/4.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
/**
 * 二叉查找树
 */
typedef struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
} tree;

int find(tree *t,int x){
    int i = 0;
    if(t==NULL){
        return -1;
    }
    if(t->data==x){
        return i;
    }else if(x<t->data){
        i++;
        find(t->left,x);
    }else if(x>t->data){
        i++;
        find(t->right,x);
    }
}

tree *findMin(tree *t){
    if(t==NULL){
        return NULL;
    }else if(t->left==NULL){
        return t;
    }else{
        return findMin(t->left);
    }
}

tree *findMax(tree *t){
    if(t!=NULL){
        while(t->right!=NULL){
            t=t->right;
        }
    }
    return t;
}

tree *init(tree *t,int x){
    if(t==NULL){
        t = malloc(sizeof(tree));
        t->data=x;
        t->left = NULL;
        t->right = NULL;
        return t;
    }else if(t->left==NULL){
        t->left=init(t->left,x);
        return t;
    }else{
        t->right=init(t->right,x);
        return t;
    }
}

tree *insertSort(tree *t,int x){
    if(t==NULL){
        t = malloc(sizeof(tree));
        t->data = x;
        t->left = NULL;
        t->right = NULL;
    }else if(x<t->data){
        t->left = insertSort(t->left,x);
    }else if(x>t->data){
        t->right = insertSort(t->right,x);
    }
    return t;
}

tree *delete(tree *t,int x){
    tree *temp;
    if(t==NULL){
        printf("element is null!\n");
    } else if(x<t->data){
        t->left=delete(t->left,x);
    } else if(x>t->data){
        t->right=delete(t->right,x);
    }else if(t->left && t->right){//t->data ==x and t has two clildren
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = delete(t->right,t->data);
    }else{//one  or zero children
        temp = t;
        if(t->left==NULL){
            t=t->right;
        }
        if(t->right==NULL){
            t=t->left;
        }
        free(temp);
    }
    return t;
}

void preTravel(tree *t){
    if(t==NULL){
        return ;
    }
    printf("%d ",t->data);
    preTravel(t->left);
    preTravel(t->right);
}

void midTravel(tree *t){
    if(t==NULL){
        return;
    }
    midTravel(t->left);
    printf("%d ",t->data);
    midTravel(t->right);
}

void postTravel(tree *t){
    if(t==NULL){
        return;
    }
    postTravel(t->left);
    postTravel(t->right);
    printf("%d ",t->data);
}

int main(){
    tree *t=NULL;
    int i = 0;
    for(i=0;i<SIZE;i++){
        t = init(t,i);
    }
    preTravel(t);
    printf("\n");
    midTravel(t);
    printf("\n");
    postTravel(t);
    printf("\n");
}