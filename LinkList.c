#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}LinkList;

LinkList *head=NULL;
LinkList *end=NULL;
int num=0;//除头节点个数

LinkList* LinkListInit(int n); //初始化
LinkList* LinkListInsert(LinkList *L,int n,int elem); //在第i个节点前插入节点
LinkList* LinkListDelete(LinkList *L,int n); //删除节点
int LinkListTraversal(LinkList *L); //遍历
LinkList* LinkListClear(LinkList *L);//清空


int main(){
    LinkList *L;
    L=LinkListInit(5);
    for(int i=1;i<10;i++){
        LinkListInsert(L,i,i);
    }
    LinkListTraversal(L);
    LinkListClear(L);
    LinkListTraversal(L);
    return 0;
}

LinkList* LinkListInit(int n){
    LinkList *node;
    head=(LinkList*)malloc(sizeof(LinkList));
    end=head;
    for(int i=0;i<n;i++){
        node=(LinkList*)malloc(sizeof(LinkList));
        node->data=i;
        end->next=node;
        end=node;
        num++;
    }
    end->next = NULL;
    return head;
}

LinkList* LinkListInsert(LinkList *L,int n,int elem){
    LinkList *p,*s;
    p=L;
    int j=1;
    while(p&&j<n){
        p=p->next;
        j++;
    }
    if(!p||j>n) return 0;
    s=(LinkList*)malloc(sizeof(LinkList));
    s->data=elem;
    s->next=p->next;
    p->next=s;
    if(n==num+1){
        end=s; //移动尾指针
    }
    num++;
    return L;
}

int LinkListTraversal(LinkList *L){
    LinkList *p;
    p=L;
    while(p->next!=NULL){
        p=p->next;
        printf("data:%d\n",p->data);
    }
    return 1;
}

LinkList* LinkListDelete(LinkList *L,int n){
    LinkList *p,*s;
    p=L;
    int j=1;
    while(p&&j<n){
        p=p->next;
        j++;
    }
    if(!p||j>n) return 0;
    s=p->next;
    p->next=p->next->next;
    if(n==num){
        end=p;//移动尾指针
    }
    free(s);
    num--;
}

LinkList* LinkListClear(LinkList *L){
    LinkList *p,*q;
    p=L->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    end=head;
    L->next=NULL;
    num=0;
}
