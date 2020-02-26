//链队列
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node* next;
}Qnode,*QueuePrt;

typedef struct{
    QueuePrt front;
    QueuePrt rear;
}QueueLink;

void QueueInit(QueueLink **s);//初始化
void QueueInsert(QueueLink *s,ElemType e);//插入数据
void QueueGet(QueueLink *s,ElemType *e);//取出数据
void QueueTraversal(QueueLink *s);//遍历
void QueueDestroy(QueueLink *s);//销毁

int main(){
    QueueLink *s;
    QueueInit(&s);
    for(int i=0;i<5;i++){
        QueueInsert(s,i);
    }
    ElemType e;
    QueueGet(s,&e);
    QueueTraversal(s);
    return 0;
}

void QueueInit(QueueLink **s){
    *s=(QueueLink*)malloc(sizeof(QueueLink));
    (*s)->front=(*s)->rear=(QueuePrt)malloc(sizeof(Qnode));
    if(!(*s)->front) exit(0);
    (*s)->front->next=NULL;
}

void QueueInsert(QueueLink *s,ElemType e){
    QueuePrt p;
    p=(QueuePrt)malloc(sizeof(Qnode));
    p->data=e;
    p->next=NULL;
    s->rear->next=p;
    s->rear=p;
}

void QueueGet(QueueLink *s,ElemType *e){
    if(s->rear==s->front) exit(0);
    QueuePrt p;
    p=s->front->next;
    *e=p->data;
    if(p==s->rear){
        s->rear=s->front;
        s->front->next=NULL;
    }else{
        s->front->next=p->next;
    }
    free(p);
}

void QueueDestroy(QueueLink *s){
    while(s->front){
        s->rear=s->front->next;
        free(s->front);
        s->front=s->rear;
    }
}

void QueueTraversal(QueueLink *s){
    QueuePrt p;
    p=s->front->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}
