//维吉尼亚加密--明文、密钥限大写字母
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

long num=0;//统计输入字符
long Mnum=0,Knum=0;//Mnum明文字符数，Knum密钥字符数
int Mflag=0,Kflag=0;//Mflag明文标记，Kflag密钥标记

typedef char ElemType;
typedef int Status;

typedef struct DualNode{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode, *DuLinkList;

Status DuLinkListInit(DuLinkList *L);//初始化字母表-双向循环链表
void Caesar(DuLinkList *L,int i);//凯撒加密，移动字母表
Status CharListInit(char **p);//输入字符串

int main(){
    DuLinkList L;//L字母表
    char *Message,*Key;//Message明文，Key密钥
    int m,n;//n为字母表移动次数，m为字母表移动后指针后移次数（寻找加密对应的字母）
    DuLinkListInit(&L);
    Mflag=1;
    printf("请输入明文：");
    CharListInit(&Message);
    Kflag=1;
    printf("请输入密钥：");
    CharListInit(&Key);
    if(Mnum!=Knum){
        printf("明文密钥不对等");
    }else{
        printf("维吉尼亚密文：");
        for(long i=0;i<Mnum;i++){
            n=Key[i]-'A';//字母表移动
            Caesar(&L,n);
            m=Message[i]-'A';//指针移动
            for(long j=0;j<=m;j++){
                L=L->next;
            }
            printf("%c",L->data);
            DuLinkListInit(&L);//重置字母表
        }
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
        i=i-1;
        (*L)=(*L)->next;
        do
        {
            (*L)=(*L)->prior;
        }while(++i);
    }
}

Status CharListInit(char **p){
    char ch='\0';
	long num=0;
    *p=NULL;
	while(1){
		ch=getchar();
		if(ch!='\n'){
			num++;
			if(num==1){
				*p=(char*)malloc(sizeof(char));
				(*p)[num-1]=ch;
			}
			else{
				*p=(char* )realloc(*p,sizeof(char)*num);
				(*p)[num-1]=ch;
			}
		}
		else{
			break;
		}
	}
	if(Mflag==1){
        Mnum=num;
        Mflag=0;
        num=0;
    }
    if(Kflag==1){
        Knum=num;
        Kflag=0;
        num=0;
    }
	return OK;
}
