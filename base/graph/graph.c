//
// Created by zhangyangshuo on 2020/12/4.
//
#include <stdio.h>
#include <stdlib.h>
/**
 * 链表存储边信息
 */
typedef struct enode{
    int v_index;  //顶点
    struct encode *next_edge; //指向的边
};

typedef struct vnode{
    char data;
    enode *first_edge;
};