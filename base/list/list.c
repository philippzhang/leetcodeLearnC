//
// Created by zhangyangshuo on 2020/11/30.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} node;
/*初始化链表：
1.首先给头指针分配空间，将头指针赋给temp
2.其次给每一个元素分配空间
3.将内容赋给当前节点的data,NULL赋给当前节点的next指针
4.把当前节点赋给(头指针)上一个节点的next指针
5.上一节点指针后移，准备初始化下个元素
6.最后返回当前链表的头指针*/
node *initnode(int n){
    int i;
    node *p = (node*)malloc(sizeof(node));
    node *temp = p;
    for(i =0;i<n;i++){
        node *a = (node*)malloc(sizeof(node));
        a->data = i ;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

/*指定位置插入元素：
1.将头指针赋给temp
2.temp一直遍历直到指定位置
3.给需要插入的元素分配空间，并将内容赋给分配好空间的元素
4.将插入位置的后一元素赋给要插入元素的next指针
5.将插入元素赋给temp的next指针
6.最后返回当前链表的头指针*/
node *insertElement(node *p,int element, int pos){
    int i;
    node *temp = p;
    for(i=0;i<pos;i++){
        temp = temp->next;
    }
    node *c = (node*)malloc(sizeof(node));
    c->data = element;
    c->next  = temp->next;
    temp->next = c;
    return p;
}

/*删除指定位置的元素:
1.将头指针赋给temp
2.temp一直遍历直到指定位置
3.声明一个变量代表待删除节点
4.将待删除节点的下一节点赋给待删除节点的上一节点的next指针
5.释放待删除节点空间
6.最后返回当前链表的头指针*/
node *deleteElement(node *p,int pos){
    int i;
    node *temp = p;
    for(i= 0;i<pos;i++){
        temp = temp->next;
    }
    node *c = temp->next;
    temp->next = c->next;
    free(c);
    return p;

}

/*查询指定元素的位置：
1.将头指针赋给temp
2.temp一直遍历直到temp节点的值等于要查询的元素
3.返回当前节点的index
4.如果链表遍历结束也未找到指定节点，返回-1
*/
int selectElement(node *p,int element){
    node *temp = p;
    int i = 0;
    while(temp->next){
        temp = temp->next;
        if(temp->data==element){
            return i;
        }
        i++;
    }
    return -1;
}
/*更新链表指定节点的值*/
node *updateElement(node *p, int pos, int newElement){
    int i;
    node *temp =p;
    for(i=0;i<pos;i++){
        temp = temp->next;
    }
    node *update = temp->next;
    update->data = newElement;
    return p;
}

/*遍历链表*/
void display(node *p){
    node *temp =p;
    while(temp->next){
        temp = temp->next;
        printf("%d ",temp->data);
    }
    printf("\n");
}

void deleteList(node *p){
    node *temp = p;
    node *next;
    p->next ==NULL;
    while(temp->next){
        next = temp->next;
        free(next);
        temp = temp->next;
    }
}


int main(){
    node *p = initnode(10);
    display(p);
    printf("在第4的位置的插入元素5:\n");
    p = insertElement(p,5,4);
    display(p);
    printf("删除第3个元素");
    p = deleteElement(p,3);
    display(p);
    printf("查找元素2的位置为:\n");
    int address = selectElement(p,2);
    if (address == -1){
        printf("没有元素");
    }else{
        printf("元素2的位子为 %d\n",address);
    }
    printf("更改第3的职位的数为7: \n");
    p = updateElement(p, 3, 7);
    display(p);
    deleteList(p);
    display(p);

}