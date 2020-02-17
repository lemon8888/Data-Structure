//循环链表
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}LinkList;

LinkList *head=NULL;
LinkList *end=NULL;
int num=0;//节点个数

LinkList* LinkListInit(int n); //初始化
LinkList* LinkListInsert(LinkList *L,int n,int elem); //在第i个节点前插入节点
LinkList* LinkListDelete(LinkList **L,int n); //删除节点
int LinkListTraversal(LinkList *L); //遍历


int main(){
    LinkList *L;
    L=LinkListInit(5); //初始化5 个节点 包括第一个头结点
	LinkListTraversal(L); //遍历删除之前的链表
	printf("**************************\n");
    LinkListDelete(&L,5);//删除第5个节点
	LinkListTraversal(L);
	printf("**************************\n");
	LinkListDelete(&L,4);
	LinkListTraversal(L);
	printf("**************************\n");
	LinkListDelete(&L,3);
	LinkListTraversal(L);
	printf("**************************\n");
	LinkListDelete(&L,2);
	LinkListTraversal(L);
	printf("**************************\n");
	LinkListDelete(&L,1);//删除第1个节点（头结点）
	LinkListTraversal(L);
	printf("**************************\n");
    LinkListTraversal(L);//遍历删除之后的链表

    return 0;
}

LinkList* LinkListInit(int n){
    LinkList *node;
    head=(LinkList*)malloc(sizeof(LinkList));
    head->data=1;
    head->next=NULL;
    end=head;
    num++;
	int i = 2;
    for(i=2;i<=n;i++){
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

LinkList* LinkListDelete(LinkList **L,int n){
    LinkList *p,*s;
    p=*L;
    int j=1;
    while(j<n-1){
        p=p->next;
        j++;
    }
    if(n>num+1||j>n) return 0;
    if(p->next==p){
        free(p);
        *L=NULL;  // 要想改变全函数外的指针的指向  参数要传指针的地址   这样的话下面的删除函数在链表为空时 判断L==NULL 才成立。
        head=NULL;
        end=NULL;
        num--;
        return *L;
    }
    s=p->next;
    p->next=p->next->next;
    if(n==num){
        end=p;//移动尾指针
    }
    free(s);
    num--;
}

int LinkListTraversal(LinkList *L){
    if(L==NULL) return 0;
    LinkList *p;
    p=L;
    while(p->next!=NULL){
        printf("data:%d\n",p->data);
		if(p->next != L){
			p=p->next;
		}
		else {
			break;
		}
    }
    return 1;
}
