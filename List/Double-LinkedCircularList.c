//双向循环链表-凯撒加密
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct DualNode{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode, *DuLinkList;

Status DuLinkListInit(DuLinkList *L);
void Caesar(DuLinkList *L,int i);

int main(){
    DuLinkList L;
    int i,n;
    DuLinkListInit(&L);
    printf("请输入一个整数：");
    scanf("%d",&n);
    printf("\n");
    Caesar(&L,n);
    for(int i=0;i<26;i++){
        L=L->next;
        printf("%c",L->data);
    }
    return 0;
}

Status DuLinkListInit(DuLinkList *L){
    DualNode *p,*q;
    *L=(DuLinkList)malloc(sizeof(DualNode));
    if(!(*L)){
        return ERROR;
    }
    (*L)->next=(*L)->prior=NULL;
    p=(*L);
    for(int i=0;i<26;i++){
        q=(DuLinkList)malloc(sizeof(DualNode));
        if(!q){
            return ERROR;
        }
        q->data='A'+i;
        q->prior=p;
        q->next=p->next;
        p->next=q;
        p=q;
    }
    p->next=(*L)->next;
    (*L)->next->prior=p;
    return OK;
}

void Caesar(DuLinkList *L,int i){
    if(i>0){
        do{
            (*L)=(*L)->next;
        }while(--i);
    }
    if(i<0){
        do{
            (*L)=(*L)->prior;
        }while(++i);
    }
}
