//
// Created by 12751 on 2020-05-29.
//

#ifndef UNTITLED_LIANSHU_H
#define UNTITLED_LIANSHU_H


class lianshu {

};

#include "lianchuang.h"


typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
    struct BiTNode *parent;
}BiTNode,*BiTree;


//链式队列结点
typedef struct LinkNode{
    BiTNode *data;
    struct LinkNode *nxet;
}LinkNode;

typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

//初始化队列
void InitQueue(LinkQueue &Q);

//入队
void EnQueue(LinkQueue &Q,BiTree x);

//出队
bool DeQueue(LinkQueue &Q,BiTree &x);

//队列为空
bool IsEmpty(LinkQueue Q);

void InitTree(BiTree &B);

void IncreasaBiTree(BiTree &B,int x);

//先序遍历
void PreOrder(BiTree T);

//中序遍历
void InOrder(BiTree T);

//后序遍历
void PostOrder(BiTree T);

//层序遍历
void LevelOrder(BiTree T);

void PreCreateBiTree(BiTree &T);

void CreateBiTree(String &XS,String ZS,BiTree &T);

int lianshutext();

#endif //UNTITLED_LIANSHU_H
