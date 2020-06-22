//
// Created by 12751 on 2020-05-29.
//

#include "lianshu.h"



#include <stdlib.h>
#include <stdio.h>


//��ʼ������
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->nxet=NULL;
}

//���
void EnQueue(LinkQueue &Q,BiTree x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data=x;
    s->nxet=NULL;
    Q.rear->nxet=s;
    Q.rear=s;
}

//����
bool DeQueue(LinkQueue &Q,BiTree &x){
    if(Q.front==Q.rear)
        return false;
    LinkNode *p=Q.front->nxet;
    x=p->data;
    Q.front->nxet=p->nxet;
    if(Q.rear==p){
        Q.rear=Q.front;
    }
    free(p);
    return true;
}

//����Ϊ��
bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear){
        return true;
    }else{
        return false;
    }
}

void InitTree(BiTree &B){
    B = (BiTree)malloc(sizeof(BiTNode));
    B->data = 1;
    B->lchild = NULL;
    B->rchild = NULL;
    B->parent = NULL;
}

void IncreasaBiTree(BiTree &B,int x){
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = x;
    p->lchild = NULL;
    p->rchild = NULL;
    p->parent = B;
    if(B->lchild == NULL){
        B->lchild = p;
    }else{
        B->rchild = p;
    }
}

//�������
void PreOrder(BiTree T){
    if(T!=NULL){
        printf("%d--",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//�������
void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);
        printf("%d--",T->data);
        InOrder(T->rchild);
    }
}

//�������
void PostOrder(BiTree T){
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%d--",T->data);
    }
}

//�������
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){
        DeQueue(Q,p);
        printf("%d--",p->data);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            EnQueue(Q,p->rchild);
        }
    }
}

void PreCreateBiTree(BiTree &T){
    int x;
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    if(p==NULL){
        printf("û�ڴ�\n");
        return;
    }

    scanf("%d",&x);
    if(x!=0){
        T=p;
        p->data=x;
        PreCreateBiTree(T->lchild);
        PreCreateBiTree(T->rchild);
    }else{
        T=p;
        p->data=x;
    }
}

void CreateBiTree(String &XS,String ZS,BiTree &T){
    while(!CunzaiString(ZS,XS->data)){
        XS=XS->next;
    }
    BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
    T=p;
    T->lchild=T->rchild=NULL;
    String s1,s2;
    int i,j,len;
    p->data=XS->data;
    IncreasaString(s1);
    IncreasaString(s2);
    len = LenString(ZS);
    i = WeizhiString(ZS,XS->data);
    for(j=1;j<=len;j++){
        if(j<i){
            insertString(s1,ZS->data);
        }
        if(j>i){
            insertString(s2,ZS->data);
        }
        ZS=ZS->next;
    }
    if(len==1){
        XS->next;
        return;
    }
    if(s1->next!=NULL)
        CreateBiTree(XS->next,s1->next,T->lchild);
    if(s2->next!=NULL)
        CreateBiTree(XS->next,s2->next,T->rchild);
}

int lianshutext(){
    String xx,zx;
    BiTree root,root2,root3;
    InitTree(root);
    IncreasaBiTree(root,2);
    IncreasaBiTree(root->lchild,4);
//	IncreasaBiTree(root->lchild->lchild,0);
    IncreasaBiTree(root->lchild->lchild,8);
//	IncreasaBiTree(root->lchild->lchild->rchild,0);
//	IncreasaBiTree(root->lchild->lchild->rchild,0);
    IncreasaBiTree(root->lchild,5);
//	IncreasaBiTree(root->lchild->rchild,0);
//	IncreasaBiTree(root->lchild->rchild,0);
    IncreasaBiTree(root,3);
    IncreasaBiTree(root->rchild,6);
//	IncreasaBiTree(root->rchild->lchild,0);
//	IncreasaBiTree(root->rchild->lchild,0);
//	IncreasaBiTree(root->rchild,0);
    printf("���������");
    PreOrder(root);
    printf("��\n");
    printf("���������");
    InOrder(root);
    printf("��\n");
    printf("���������");
    PostOrder(root);
    printf("��\n");

    IncreasaString(xx);
    IncreasaString(zx);
    insertString(xx,1);
    insertString(xx,2);
    insertString(xx,4);
    insertString(xx,8);
    insertString(xx,5);
    insertString(xx,3);
    insertString(xx,6);
    insertString(zx,8);
    insertString(zx,4);
    insertString(zx,2);
    insertString(zx,5);
    insertString(zx,1);
    insertString(zx,6);
    insertString(zx,3);
    PrintfString(xx->next);
    PrintfString(zx->next);
    printf("��ʼ������\n");
    CreateBiTree(xx->next,zx->next,root2);
    printf("���������");
    PreOrder(root2);
    printf("��\n");
    printf("���������");
    InOrder(root2);
    printf("��\n");
    printf("���������");
    PostOrder(root2);
    printf("��\n");
    return 0;
}
