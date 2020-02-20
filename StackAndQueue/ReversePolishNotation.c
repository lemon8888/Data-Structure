//逆波兰式（中缀表达式转后缀表达式）
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Stack_Init_Size 100
#define Stack_Increment 10

typedef char ElemType;

typedef struct {
    ElemType *top;
    ElemType *base;
    int stacksize;
}sqStack;

void StackInit(sqStack **s);//初始化。注意函数值使用结构体的指针是要确保该指针指向的数据为有效值，这样指针才是有效的。
void StackPush(sqStack *s,ElemType data);//存入数据
void StackPop(sqStack *s,ElemType *data);//取出数据
void StackDestroy(sqStack *s);//销毁
int StackLen(sqStack *s);//栈内数据个数

int main(){
    char c,e;
    sqStack *s;
    int len,sum=0;
    StackInit(&s);
    printf("请输入中缀表达式,并且#结束\n");
    scanf("%c",&c);
    while(c!='#'){
        while(c>='0'&&c<='9'){
            printf("%c",c);
            scanf("%c",&c);
            if(c<'0'||c>'9'){
                printf(" ");
            }
        }
        if(')'==c){
            StackPop(s,&e);
            while('('!=e){
                printf("%c ",e);
                StackPop(s,&e);
            }
        }else if('+'==c||'-'==c){
            if(!StackLen(s)){
                StackPush(s,c);
            }else{
                do{
                    StackPop(s,&e);
                    if('('==e){
                        StackPush(s,e);
                    }else{
                        printf("%c ",e);
                    }
                }while(StackLen(s)&&'('!=e);
                StackPush(s,c);
            }
        }else if('*'==c||'/'==c||'('==c){
            StackPush(s,c);
        }else if('#'==c){
            break;
        }else{
            printf("输入错误\n");
            return -1;
        }
        scanf("%c",&c);
    }
    while(StackLen(s)){
        StackPop(s,&e);
        printf("%c ",e);
    }
    getchar();//去掉回车
    return 0;
}

void StackInit(sqStack **s){
    *s=(sqStack*)malloc(sizeof(sqStack));
    (*s)->base=(ElemType*)malloc(sizeof(ElemType)*Stack_Init_Size);
    if(!(*s)->base) exit(0);
    (*s)->top=(*s)->base;
    (*s)->stacksize=Stack_Init_Size;
}

void StackPush(sqStack *s,ElemType data){
    if(s->top-s->base == s->stacksize-1){
        s->base=(ElemType*)realloc(s->base,sizeof(ElemType)*(s->stacksize+Stack_Increment));
        if(!s->base) exit(0);
        s->stacksize=s->stacksize+Stack_Increment;
    }
    *(s->top)=data;
    s->top++;
}

void StackPop(sqStack *s,ElemType *data){
    if(s->top==s->base)  exit(0);
    *data=*--(s->top);
}

void StackDestroy(sqStack *s){
    int i,len;
    len=s->top-s->base;
    for(i=0;i<len;i++){
        free(s->base);
        s->base++;
    }
    s->base=s->top=NULL;
    s->stacksize=0;
}

int StackLen(sqStack *s){
    return (s->top-s->base);
}
