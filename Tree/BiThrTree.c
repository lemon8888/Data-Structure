//线索二叉树
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//线索存储标志位
//Link(0)：表示指向左右孩子的指针
//Thread(1)：表示指向前驱后继的线索
typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode{
    ElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode,*BiThrTree;

//全局变量，始终指向刚刚访问过的结点
BiThrTree pre;

//创建一颗二叉树，以前序遍历的方式输入数据
void CreateBiThrTree(BiThrTree *T){
    char c;
    scanf("%c",&c);
    if(' '==c){
        *T=NULL;
    }else{
        *T=(BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data=c;
        (*T)->ltag=Link;
        (*T)->rtag=Link;
        CreateBiThrTree(&(*T)->lchild);
        CreateBiThrTree(&(*T)->rchild);
    }
}

//中序遍历线索化
void InThreading(BiThrTree T){
    if(T){
        InThreading(T->lchild);//递归左孩子线索化
        if(!T->lchild){  //如果该结点没有左孩子，设置ltag为Thread，并把lchild指向上一个访问的结点
            T->ltag=Thread;
            T->lchild=pre;
        }
        if(!pre->rchild){
            pre->rtag=Thread;
            pre->rchild=T;
        }
        pre=T;
        InThreading(T->rchild);//递归右孩子线索化
    }
}

void InOrderThreading(BiThrTree *p,BiThrTree T){
    *p=(BiThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag=Link;
    (*p)->rtag=Thread;
    (*p)->rchild=*p;
    if(!T){
        (*p)->lchild=*p;
    }else{
        (*p)->lchild=T;
        pre=*p;
        InThreading(T);
        pre->rchild=*p;
        pre->rtag=Thread;
        (*p)->rchild=pre;
    }
}

void Visit(char c){
    printf("%c",c);
}

//中序遍历
void InOrderTraverse(BiThrTree T){
    BiThrTree p;
    p=T->lchild;
    while(p!=T){
        while(p->ltag==Link){
            p=p->lchild;
        }
        Visit(p->data);
        while(p->rtag==Thread&&p->rchild!=T){
            p=p->rchild;
            Visit(p->data);
        }
        p=p->rchild;
    }
}

int main(){
    BiThrTree P,T=NULL;
    CreateBiThrTree(&T);
    InOrderThreading(&P,T);
    printf("中序遍历结果为：");
    InOrderTraverse(P);
    return 0;
}
