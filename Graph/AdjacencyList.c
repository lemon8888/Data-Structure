//邻接表-有向
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100

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
        e->adjvex=j;
        e->next=L->adjList[i].first;
        L->adjList[i].first=e;
    }
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

int main(){
    GraphAdjList *L=(GraphAdjList*)malloc(sizeof(GraphAdjList));
    CreateALGraph(L);
    Traverse(L);
    return 0;
}
