//
// Created by 12751 on 2020-06-06.
//

#ifndef UNTITLED_SHUNXUBIAO_H
#define UNTITLED_SHUNXUBIAO_H

#define MaxSize 10 //������󳤶�

typedef struct{
    int data[MaxSize];	//��̬����������Ԫ��
    int length; //˳���ǰ����
}SqList; //˳���Ľṹ��

//��ʼ��˳���
void InitList(SqList &L);

//����
bool ListInsert(SqList &L,int i,int e);

//ɾ��
bool ListDelete(SqList &L,int i,int &e);

//��ֵ����
int LocateElem (SqList L,int e);

//��ӡ˳���
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
