//
// Created by 12751 on 2020-06-06.
//

#ifndef UNTITLED_SHUNXUBIAO_H
#define UNTITLED_SHUNXUBIAO_H

#define MaxSize 10 //定义最大长度

typedef struct{
    int data[MaxSize];	//静态数组存放数据元素
    int length; //顺序表当前长度
}SqList; //顺序表的结构体

//初始化顺序表
void InitList(SqList &L);

//插入
bool ListInsert(SqList &L,int i,int e);

//删除
bool ListDelete(SqList &L,int i,int &e);

//按值查找
int LocateElem (SqList L,int e);

//打印顺序表
bool PrintfSqList(SqList L);

bool timu1(SqList &L,int &x);

bool timu2(SqList &L);

bool timu3(SqList &L,int x);

bool timu3_2(SqList &L,int x);

bool timu4(SqList &L,int s,int l);

bool timu5(SqList &L,int s,int l);

bool timu6(SqList &L);

bool timu7(SqList L1,SqList L2,SqList &L3);

void shunxubiao ();

#endif //UNTITLED_SHUNXUBIAO_H
