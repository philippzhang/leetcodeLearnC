//
// Created by zhangyangshuo on 2020/12/4.
//
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))
/**
 * 用链表存弧信息，一个存弧指向的顶点位置，第二存指向下条弧的指针，这样就将一个顶点指向的所有弧串起来
 */
typedef struct enode{
    int v_index;  //顶点
    struct encode *next_edge; //指向的边
};

/**
 * 在顶点存顶点名称和第一条依附顶点的弧
 */

typedef struct vnode{
    char data;
    struct enode *first_edge;
} vnode;

/**
 * 用数组存顶点，并加上顶点数和边数共同组成一个图
 */
typedef struct graph{
    int v_num;
    int e_num;
    vnode vs[SIZE]
} graph;


/**
 * 返回ch在matrix矩阵中的位置
 */
int get_position(graph g,char ch){
    int i;
    for(i=0;i<g.v_num;i++ ){
        if(g.vs[i].data==ch){
            return i;
        }
    }
    return -1;
}

void link_last(struct enode *list,struct enode *node){
    struct enode *p = list;
    while(p->next_edge){
        p=p->next_edge;
    }
    p->next_edge=node;
}

/**
 * 创建图
 * @return
 */
graph *create_graph(){
    char c1,c2;
    char nodes[] = {'A','B','C','D','E','F','G'};
    char edges[][2]={
            {'A', 'C'},
            {'A', 'D'},
            {'A', 'F'},
            {'B', 'C'},
            {'C', 'D'},
            {'E', 'G'},
            {'F', 'G'},
            {'D', 'G'},
            {'D', 'B'}
    };
    int v_len = LENGTH(nodes);
    int e_len = LENGTH(edges);
    int i,p1,p2;
    struct enode *enode1,*enode2;
    graph *pg;
    if((pg=(graph*)malloc(sizeof(graph)))==NULL){
        return NULL;
    }
    memset(pg,0,sizeof(graph));
    pg->v_num = v_len;
    pg->e_num = e_len;

    //初始化所有顶点
    for(i=0;i<pg->v_num;i++){
        pg->vs[i].data=nodes[i];
        pg->vs[i].first_edge=NULL;
    }
    /*初始化所有边,无向图的边为两个顶点共有，按指向顶点来定义可以算两条边，因此要挂在两个顶点的邻接表后面*/
    for(i=0;i<pg->e_num;i++){
        //获取顶点名
        c1 = edges[i][0];
        c2 = edges[i][1];
        //获取顶点在数组中的位置
        p1 = get_position(*pg,c1);
        p2 = get_position(*pg,c2);

        enode1 = (struct enode*)malloc(sizeof(struct enode));
        enode1->v_index=p2;

        if(pg->vs[p1].first_edge==NULL){
            pg->vs[p1].first_edge=enode1;
        }else{
            link_last(pg->vs[p1].first_edge,enode1);
        }

        enode2 = (struct enode*)malloc(sizeof(struct enode));
        enode2->v_index = p1;
        if(pg->vs[p2].first_edge ==NULL){
            pg->vs[p2].first_edge = enode2;
        }else{
            link_last(pg->vs[p2].first_edge,enode2);
        }

    }
    return pg;

}
//打印图
void print_graph(graph g)
{
    int i,j,k;
    struct enode *node;

    printf("List Graph:\n");
    for (i = 0; i < g.v_num; i++)
    {
        printf("%d(%c): ", i, g.vs[i].data);
        node = g.vs[i].first_edge;
        while (node != NULL)
        {
            printf("%d(%c) ", node->v_index, g.vs[node->v_index].data);
            node = node->next_edge;
        }
        printf("\n");
    }
}

int main() {
    /*创建图，并打印图*/
    graph *pg = create_graph();
    print_graph(*pg);
}
