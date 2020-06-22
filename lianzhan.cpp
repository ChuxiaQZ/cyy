//
// Created by 12751 on 2020-05-29.
//
#include <stdlib.h>
#include <stdio.h>
#include "lianzhan.h"

//��ʼ��һ����ջ
void InitLiStack(LiStack &S){
    S = (Linknode *)malloc(sizeof(Linknode));
    if(S==NULL){
        return ;
    }
    S->data = NULL;
    S->next = NULL;
};

//�ж�ջ�Ƿ�Ϊ��
bool StacjEmpty(LiStack S){
    if(S->data==NULL && S->next==NULL){
        return true;
    }else{
        return false;
    };
}

//��ջ(����ͷ��㣩
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

//��ջ(����ͷ���)
bool Pop(LiStack &S, char &x){
    //Ϊ��ջ
    if(S->data==NULL&&S->next==NULL){
        return false;
    };
    //ֻ��һ���ڵ�
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

//��ȡջ��Ԫ��
bool GetTop(LiStack S, char &x){
    if(S->data==NULL){
        return false;
    }else{
        x=S->data;
        return true;
    }
}

//ջ����
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

//��ӡջ
void PrintfLiStack(LiStack S){
    int len=0;
    printf("��ӡջ��");
    if(S->data==NULL&&S->next==NULL){
        printf("��");
    }else{
        len=LenLiStack(S);
        for(int i=0;i<len;i++){
            printf("%c--",S->data);
            S=S->next;
        }
    }
    printf("��\n");
}

int lianzhantext(){
    LiStack s;
    char x;
    int len;
    InitLiStack(s);
    Push(s,'a');
    len=LenLiStack(s);
    printf("���ȣ� %d\n",len);
    PrintfLiStack(s);
    Push(s,'b');
    len=LenLiStack(s);
    printf("���ȣ� %d\n",len);
    PrintfLiStack(s);
    Push(s,'c');
    printf("���ȣ� %d\n",len);
    printf("��һ�Σ�");
    PrintfLiStack(s);
    Pop(s,x);
    printf("�ڶ��Σ�");
    PrintfLiStack(s);
    Push(s,'d');
    len=LenLiStack(s);
    printf("���ȣ� %d\n",len);
    printf("�����Σ�");
    PrintfLiStack(s);
    return 0;
};