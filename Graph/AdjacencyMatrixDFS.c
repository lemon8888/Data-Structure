//邻接矩阵深度优先遍历
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

void DFS(GraphAdjMatrix *G,int i){
    int j;
    visited[i]=TRUE;
    printf("%c ",G->ver[i]);
    for(j=0;j<G->numVertexes;j++){
        if(G->adjm[i][j]==1&&!visited[j]){
            DFS(G,j);
        }
    }
}

void DFSTraverse(GraphAdjMatrix *G){
    int i,j;
    printf("请输入遍历起始点下标：");
    scanf("%d",&i);
    for(j=0;j<G->numVertexes;j++){
        visited[j]=FALSE;
    }
    printf("深度优先遍历：");
    DFS(G,i);
    for(j=0;j<G->numVertexes;j++){
        if(!visited[j]){
            DFS(G,j);
        }
    }
}

int main(){
    GraphAdjMatrix *G=(GraphAdjMatrix*)malloc(sizeof(GraphAdjMatrix));
    CreateMGraph(G);
    MatrixTraverse(G);
    DFSTraverse(G);
    return 0;
}
