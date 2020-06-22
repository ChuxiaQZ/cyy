//
// Created by 12751 on 2020-05-29.
//

#include "lianchuang.h"
#include <stdlib.h>
#include <stdio.h>

//初始化
void IncreasaString(String &S){
    S = (StringNode*) malloc (sizeof(StringNode));
    S->data=-1;
    S->next=NULL;
}
//插入
void insertString(String &S,int x){
    StringNode *n =S;
    while(n->next != NULL){
        n=n->next;
    }
    StringNode *s = (StringNode*) malloc (sizeof(StringNode));
    s->data=x;
    s->next=NULL;
    n->next=s;
}
//求串长
int LenString(String S){
    if(S==NULL){
        return 0;
    }
    int x=1;
    while(S->next != NULL){
        x++;
        S=S->next;
    }
    return x;
}
//输出串
void PrintfString(String S){
    int i,j;
    j=LenString(S);
    for(i=0;i<j;i++){
        printf("%d",S->data);
        S=S->next;
    }
    printf("\n");
}

int WeizhiString(String S,int x){
    int i=1;
    while(S!=NULL){
        if(S->data==x){
            return i;
        }else{
            S=S->next;
        }
    }
    return 0;
}

bool CunzaiString(String S,int x){
    while(S!=NULL){
        if(S->data==x){
            return true;
        }else{
            S=S->next;
        }
    }
    return false;
}

void zhuanghua(String S,String &SS){
    String s1,s2;
    IncreasaString(s1);
    IncreasaString(s2);
    int len,lens,ss;
    int i;
    int j;
    len = LenString(S);
    i=len/2+1;
    for(j=1;j<=len;j++){
        if(j<i){
            insertString(s1,S->data);
            lens=LenString(s1->next);
            ss=S->data;
        }
        if(j==i){
            insertString(SS,S->data);
            ss=S->data;
        }
        if(j>i){
            insertString(s2,S->data);
            ss=S->data;
        }
        S=S->next;
    }
    if(len==1)
        return;
    zhuanghua(s1->next,SS);
    zhuanghua(s2->next,SS);
}

int lianchuangtext(){
    String xx,zx;
    IncreasaString(xx);
    IncreasaString(zx);
    insertString(zx,0);
    insertString(zx,4);
    insertString(zx,8);
    insertString(zx,2);
    insertString(zx,0);
    insertString(zx,5);
    insertString(zx,0);
    insertString(zx,1);
    insertString(zx,0);
    insertString(zx,6);
    insertString(zx,0);
    insertString(zx,3);
    insertString(zx,0);
    insertString(zx,0);
    insertString(zx,0);
    PrintfString(zx->next);
    zhuanghua(zx->next,xx);
    PrintfString(xx->next);
    return 0;
}