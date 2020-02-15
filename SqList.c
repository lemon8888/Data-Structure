//ÏßÐÔ±í
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
typedef struct{
    int *elem;
    int length;
    int listsize;
}SqList;

int ListInit(SqList *L);
int ListInsert(SqList *L,int i,int elem);
int ListDelete(SqList *L,int i);
int ListTraversal(SqList *L);

int main()
{
    SqList L;
    ListInit(&L);
    for(int i=0;i<10;i++){
        ListInsert(&L,i,i);
    }
    ListTraversal(&L);
    ListDelete(&L,4);
    ListTraversal(&L);
    return 0;
}

int ListInit(SqList *L){
    L->elem=(int *)malloc(sizeof(int)*LIST_INIT_SIZE);
    if(!L->elem) exit(0);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    printf("LIST INIT SCUSSESS!\n");
    return 1;
}

int ListInsert(SqList *L,int i,int elem){
    if(L->length==LIST_INIT_SIZE) return 0;
    if(i<1||i>L->length+1) return 0;
    for(int k=L->length-1;k>i;k--){
            L->elem[k+1]=L->elem[k];
    }
    L->elem[i-1]=elem;
    L->length++;
    return 1;
}

int ListTraversal(SqList *L){
    for(int i=0;i<L->length;i++){
        printf("%d ",L->elem[i]);
    }
    printf("\n");
    return 1;
}

int ListDelete(SqList *L,int i){
    if(i<1||i>L->length) return 0;
    for(int k=i-1;k<L->length;k++){
        L->elem[k]=L->elem[k+1];
    }
    L->length--;
    return 1;
}
