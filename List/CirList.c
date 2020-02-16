//循环链表
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct node{
    int data;
    struct node* next;
}LinkList;

LinkList *head=NULL;
LinkList *end=NULL;
int num=0;//节点个数

LinkList* LinkListInit(int n); //初始化
LinkList* LinkListInsert(LinkList *L,int n,int elem); //在第i个节点前插入节点
LinkList* LinkListDelete(LinkList *L,int n); //删除节点
int LinkListTraversal(LinkList *L); //遍历


int main(){
    LinkList *L;
    L=LinkListInit(10);
    LinkListDelete(L,10);
    LinkListTraversal(L);
    return 0;
}

LinkList* LinkListInit(int n){
    LinkList *node;
    head=(LinkList*)malloc(sizeof(LinkList));
    head->data=1;
    end=head;
    end->next=head;
    num++;
    for(int i=2;i<=n;i++){
        node=(LinkList*)malloc(sizeof(LinkList));
        node->data=i;
        end->next=node;
        end=node;
        num++;
    }
    end->next = head;
    return head;
}

LinkList* LinkListInsert(LinkList *L,int n,int elem){
    LinkList *p,*s;
    p=L;
    int j=1;
    while(j<n-1){
        p=p->next;
        j++;
    }
    if(n>num+1||j>n) return 0;
    s=(LinkList*)malloc(sizeof(LinkList));
    s->data=elem;
    s->next=p->next;
    p->next=s;
    if(n==num+1){
        end=s;//移动尾指针
    }
    num++;
    return L;
}

LinkList* LinkListDelete(LinkList *L,int n){
    LinkList *p,*s;
    p=L;
    int j=1;
    while(j<n-1){
        p=p->next;
        j++;
    }
    if(n>num+1||j>n) return 0;
    s=p->next;
    p->next=p->next->next;
    if(n==num){
        end=p;//移动尾指针
    }
    free(s);
    num--;
}

int LinkListTraversal(LinkList *L){
    LinkList *p;
    p=L;
    while(p->next!=NULL){
        printf("data:%d\n",p->data);
        p=p->next;
        Sleep(300);
    }
    return 1;
}
