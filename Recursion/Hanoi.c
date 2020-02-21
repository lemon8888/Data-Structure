//递归-汉诺塔
#include <stdio.h>
void move(int n,char x,char y,char z){
    if(1==n){
        printf("%c--->%c\n",x,z);
    }else{
        move(n-1,x,z,y);
        printf("%c--->%c\n",x,z);
        move(n-1,y,x,z);
    }
}

int main(){
    int n;
    printf("请输入汉诺塔层数：");
    scanf("%d",&n);
    printf("移动步骤如下：\n");
    move(n,'X','Y','Z');
    return 0;
}
