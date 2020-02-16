//约瑟夫问题
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}LinkList;

LinkList *head=NULL;
LinkList *end=NULL;

LinkList* LinkListInit(int n); //初始化

int main(){
    int n=41,k=3;//n=总人数，k为间隔
    LinkList *L,*p,*s;
    L=LinkListInit(n);
    p=L;
    while(p->next!=p){
        for(int i=1;i<k-1;i++){
            p=p->next;
        }
        printf("%d->",p->next->data);
        s=p->next;
        p->next=p->next->next;
        p=p->next;
        free(s);
    }
    printf("%d",p->data);
    return 0;
}

LinkList* LinkListInit(int n){
    LinkList *node;
    head=(LinkList*)malloc(sizeof(LinkList));
    head->data=1;
    end=head;
    end->next=head;
    for(int i=2;i<=n;i++){
        node=(LinkList*)malloc(sizeof(LinkList));
        node->data=i;
        end->next=node;
        end=node;
    }
    end->next = head;
    return head;
}
