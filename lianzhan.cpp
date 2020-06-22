//
// Created by 12751 on 2020-05-29.
//
#include <stdlib.h>
#include <stdio.h>
#include "lianzhan.h"

//初始化一个空栈
void InitLiStack(LiStack &S){
    S = (Linknode *)malloc(sizeof(Linknode));
    if(S==NULL){
        return ;
    }
    S->data = NULL;
    S->next = NULL;
};

//判断栈是否为空
bool StacjEmpty(LiStack S){
    if(S->data==NULL && S->next==NULL){
        return true;
    }else{
        return false;
    };
}

//入栈(不带头结点）
bool Push(LiStack &S, char x){
    if(S->data==NULL&&S->next==NULL){
        S->data=x;
        return true;
    }else{
        LiStack s = (Linknode *)malloc(sizeof(Linknode));
        if(s==NULL)
            return false;
        s->data=x;
        s->next=S;
        S=s;
        return true;
    }
}

//出栈(不带头结点)
bool Pop(LiStack &S, char &x){
    //为空栈
    if(S->data==NULL&&S->next==NULL){
        return false;
    };
    //只有一个节点
    if(S->data!=NULL&&S->next==NULL){
        x=S->data;
        S->data=NULL;
        return true;
    }
    Linknode *p,*q;
    q=S;
    x=q->data;
    S=S->next;
    free(q);
    return true;
}

//读取栈顶元素
bool GetTop(LiStack S, char &x){
    if(S->data==NULL){
        return false;
    }else{
        x=S->data;
        return true;
    }
}

//栈长度
int LenLiStack(LiStack S){
    int i=1;
    if(S->data==NULL&&S->next==NULL){
        return 0;
    }
    while(S->next!=NULL){
        i++;
        S=S->next;
    };
    return i;
}

//打印栈
void PrintfLiStack(LiStack S){
    int len=0;
    printf("打印栈：");
    if(S->data==NULL&&S->next==NULL){
        printf("空");
    }else{
        len=LenLiStack(S);
        for(int i=0;i<len;i++){
            printf("%c--",S->data);
            S=S->next;
        }
    }
    printf("。\n");
}

int lianzhantext(){
    LiStack s;
    char x;
    int len;
    InitLiStack(s);
    Push(s,'a');
    len=LenLiStack(s);
    printf("长度： %d\n",len);
    PrintfLiStack(s);
    Push(s,'b');
    len=LenLiStack(s);
    printf("长度： %d\n",len);
    PrintfLiStack(s);
    Push(s,'c');
    printf("长度： %d\n",len);
    printf("第一次：");
    PrintfLiStack(s);
    Pop(s,x);
    printf("第二次：");
    PrintfLiStack(s);
    Push(s,'d');
    len=LenLiStack(s);
    printf("长度： %d\n",len);
    printf("第三次：");
    PrintfLiStack(s);
    return 0;
};