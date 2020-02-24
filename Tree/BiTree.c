//二叉树前序遍历
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

//建立树节点
void CreateBiTree(BiTree *T){
    char c;
    scanf("%c",&c);
    if(' '==c){
        *T=NULL;
    }else{
        *T=(BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data=c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

//取数据
void Visit(char c,int level){
    printf("%c位于第%d层\n",c,level);
}

//前序遍历
void PreOderTraversal(BiTree T,int level){
    if(T){
        Visit(T->data,level);
        PreOderTraversal(T->lchild,level+1);
        PreOderTraversal(T->rchild,level+1);
    }
}

int main(){
    int level=1;
    BiTree T=NULL;
    CreateBiTree(&T);
    PreOderTraversal(T,level);
    return 0;
}
