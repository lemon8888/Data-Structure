//邻接矩阵广度优先遍历
#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 100
#define TRUE 1
#define FALSE 0

typedef int Boolean;
Boolean visited[MAXVEX];

typedef struct GraphAdjMatrix{
    char ver[MAXVEX];
    int adjm[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
}GraphAdjMatrix;

typedef struct QueueNode{
    int data;
    struct QueueNode *next;
}QueueNode;

typedef struct{
    QueueNode *front;
    QueueNode *rear;
}QueueLink;

void CreateMGraph(GraphAdjMatrix *G){
    int i,j,k;
    printf("请输入图的顶点数及边数：");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    getchar();
    printf("请输入图的顶点信息：");
    for(i=0;i<G->numVertexes;i++){
        scanf("%c",&G->ver[i]);
    }
    getchar();
    for(i=0;i<G->numVertexes;i++){
        for(j=0;j<G->numVertexes;j++){
            G->adjm[i][j]=0;
        }
    }
    printf("请输入图的边信息：\n");
    for(k=0;k<G->numEdges;k++){
        printf("请输入图第%d条边的序号：",k+1);
        scanf("%d %d",&i,&j);
        G->adjm[i][j]=1;
        G->adjm[j][i]=1;
    }
}

void MatrixTraverse(GraphAdjMatrix *G){
    int i,j;
    printf("邻接矩阵：\n");
    for(i=0;i<G->numVertexes;i++){
        for(j=0;j<G->numVertexes;j++){
            printf("%d  ",G->adjm[i][j]);
        }
        printf("\n");
    }
}

void QueueInit(QueueLink **Q){
    *Q=(QueueLink*)malloc(sizeof(QueueLink));
    (*Q)->front=(*Q)->rear=(QueueNode*)malloc(sizeof(QueueNode));
    (*Q)->front->next=NULL;
}

void QueueInsert(QueueLink *Q,int data){
    QueueNode *q=(QueueNode*)malloc(sizeof(QueueNode));
    q->data=data;
    q->next=NULL;
    Q->rear->next=q;
    Q->rear=q;
}

void QueueGet(QueueLink *Q,int *data){
    if(Q->front==Q->rear){
        printf("无顶点");
    }
    QueueNode *p;
    p=Q->front->next;
    *data=p->data;
    if(p==Q->rear){
        Q->rear=Q->front;
        Q->front->next=NULL;
    }else{
        Q->front->next=p->next;
    }
    free(p);
}

int QueueEmpty(QueueLink *Q){
    if(Q->front==Q->rear){
        return 1;
    }
    return 0;
}

void BFSTraverse(GraphAdjMatrix *G){
    int i,j,k,get;
    QueueLink *Q;
    printf("请输入遍历起始点下标：");
    scanf("%d",&i);
    for(j=0;j<G->numVertexes;j++){
        visited[j]=FALSE;
    }
    QueueInit(&Q);
    QueueInsert(Q,i);
    visited[i]=TRUE;
    for(j=0;j<G->numVertexes;j++){
        if(G->adjm[i][j]&&!visited[j]){
            QueueInsert(Q,j);
            visited[j]=TRUE;
        }
    }
    printf("广度优先遍历：");
    while(!QueueEmpty(Q)){
            QueueGet(Q,&get);
            printf("%c ",G->ver[get]);
    }
    for(j=0;j<G->numVertexes;j++){
        if(!visited[j]){
            QueueInsert(Q,j);
            visited[j]=TRUE;
            printf("%c ",G->ver[j]);
            while(!QueueEmpty(Q)){
                QueueGet(Q,&get);
                for(k=0;k<G->numVertexes;k++){
                    if(G->adjm[get][k]&&!visited[k]){
                        QueueInsert(Q,k);
                        visited[k]=TRUE;
                        printf("%c ",G->ver[k]);
                    }
                }
            }
        }
    }
}

int main(){
    GraphAdjMatrix *G=(GraphAdjMatrix*)malloc(sizeof(GraphAdjMatrix));
    CreateMGraph(G);
    MatrixTraverse(G);
    BFSTraverse(G);
    return 0;
}
