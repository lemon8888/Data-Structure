//邻接矩阵
#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100

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
    for(k=0;k<G->numVertexes;k++){
        printf("请输入图第%d条边的序号：",k+1);
        scanf("%d %d",&i,&j);
        G->adjm[i][j]=1;
        G->adjm[j][i]=1;
    }
}

void Traverse(GraphAdjMatrix *G){
    int i,j;
    printf("邻接矩阵：\n");
    for(i=0;i<G->numVertexes;i++){
        for(j=0;j<G->numVertexes;j++){
            printf("%d  ",G->adjm[i][j]);
        }
        printf("\n");
    }
}

int main(){
    GraphAdjMatrix *G=(GraphAdjMatrix*)malloc(sizeof(GraphAdjMatrix));
    CreateMGraph(G);
    Traverse(G);
    return 0;
}
