//邻接表深度遍历
#include<stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAXVEX 100

typedef int Boolean;
Boolean visited[MAXVEX];

typedef struct EdgeNode{  //边表节点
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode{    //顶点表结点
    char data;
    EdgeNode *first;
}VertexNode,AdjList[MAXVEX];
typedef struct{             //邻接表
    AdjList adjList;
    int numVertexes,numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList *L){
    int i,j,k;
    printf("请输入图的顶点数及边数：");
    scanf("%d %d",&L->numVertexes,&L->numEdges);
    getchar();
    printf("请输入图的顶点信息：");
    for(i=0;i<L->numVertexes;i++){
        scanf("%c",&L->adjList[i].data);
        L->adjList[i].first=NULL;
    }
    getchar();
    printf("请输入图的边信息：\n");
    for(k=0;k<L->numEdges;k++){
        printf("请输入图第%d条边的序号：",k+1);
        scanf("%d %d",&i,&j);
        EdgeNode *e=(EdgeNode*)malloc(sizeof(EdgeNode));
        EdgeNode *p=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex=j;
        e->next=L->adjList[i].first;
        L->adjList[i].first=e;
        p->adjvex=i;
        p->next=L->adjList[j].first;
        L->adjList[j].first=p;
    }
}

void NodeGet(GraphAdjList *L,int i,EdgeNode **p){
    if(!L->adjList[i].first){
        exit(0);
    }
    do{
        if(!L->adjList[i].first){
            *p=NULL;
        }else{
            *p=L->adjList[i].first;
        L->adjList[i].first=(*p)->next;
        }
    }while(visited[(*p)->adjvex]);
}

void Traverse(GraphAdjList *L){
    printf("邻接表：\n");
    int i;
    EdgeNode *p;
    for(i=0;i<L->numVertexes;i++){
        printf("%c",L->adjList[i].data);
        p=L->adjList[i].first;
        while(p){
            printf("-->%d",p->adjvex);
            p=p->next;
        }
        printf("\n");
    }
}

void DFS(GraphAdjList *L,int i){
    EdgeNode *p=(EdgeNode*)malloc(sizeof(EdgeNode));
    visited[i]=TRUE;
    printf("%c ",L->adjList[i].data);
    p=L->adjList[i].first;
    while(p){
        if(!visited[p->adjvex]){
            DFS(L,p->adjvex);
        }
        p=p->next;
    }
}

void DFSTraverse(GraphAdjList *L){
    int i,j;
    printf("请输入遍历起始点下标：");
    scanf("%d",&i);
    for(j=0;j<L->numVertexes;j++){
        visited[j]=FALSE;
    }
    printf("深度遍历：");
    DFS(L,i);
    for(j=0;j<L->numVertexes;j++){
        if(!visited[j]){
            DFS(L,j);
        }
    }
}

int main(){
    GraphAdjList *L=(GraphAdjList*)malloc(sizeof(GraphAdjList));
    CreateALGraph(L);
    Traverse(L);
    DFSTraverse(L);
    return 0;
}
