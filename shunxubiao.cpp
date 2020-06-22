//
// Created by 12751 on 2020-06-06.
//
#include <stdio.h>
#include "shunxubiao.h"


//��ʼ��˳���
void InitList(SqList &L){
    for(int i=0;i<MaxSize;i++){
        L.data[i]=0;	//��������Ԫ������ΪĬ�ϳ�ʼֵ0 ,����ʼ���ڴ���������������ݡ�
    }
    L.length=0;	//��ʼ����Ϊ0
}

//����
bool ListInsert(SqList &L,int i,int e){
    if(i<1 ||i>L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

//ɾ��
bool ListDelete(SqList &L,int i,int &e){
    if(i<1 ||i<L.length)
        return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

//��ֵ����
int LocateElem (SqList L,int e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

//��ӡ˳���
bool PrintfSqList(SqList L){
    if (L.length==0){
        printf("˳���Ϊ�գ�\n");
        return false;
    }
    for(int i=0;i<L.length;i++){
        printf("��%d��������%d\n",i+1,L.data[i]);
    }
    return true;
}

//ɾ����Сֵ��Ԫ�أ���������ֵ���ճ���λ�������һ��Ԫ���
bool timu1(SqList &L,int &x){
    if(L.length==0) {
        printf("˳���Ϊ�գ�\n");
        return false;
    }
    int weizhi=0;
    x=L.data[weizhi];
    for(int i=0;i<L.length;i++){
        if(x>L.data[i]){
            x=L.data[i];
            weizhi=i;
        }
    }
    L.data[weizhi]=L.data[L.length-1];
    L.length--;
    return true;
}

//��˳�������Ԫ������
bool timu2(SqList &L){
    if(L.length == 0){
        printf("˳���Ϊ�գ�\n");
        return false;
    }
    int value;
    for(int i=0;i<L.length/2;i++){
        value=L.data[i];
        L.data[i]=L.data[L.length-1-i];
        L.data[L.length-1-i]=value;
    }
    return true;
}

//ɾ������ֵΪx����Ԫ�أ�ʱ�临�Ӷ�Ϊn,�ռ�Ϊ1
bool timu3(SqList &L,int x){
    if(L.length == 0){
        printf("˳���Ϊ�գ�\n");
        return false;
    }
    int num = 0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]==x){
            num++;
        }else{
            if(num!=0){
                L.data[i-num]=L.data[i];
            }
        }
    }
    L.length=L.length-num;
    return true;
};
//��Ŀ��������

bool timu3_2(SqList &L,int x){
    if(L.length == 0){
        printf("˳���Ϊ�գ�\n");
        return false;
    }
    int k = 0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]!=x){
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length=k;
    return true;
};

//ɾ����ֵ��s,t֮�������Ԫ��
bool timu4(SqList &L,int s,int t){
    if(L.length==0||s>=t){
        printf("˳���Ϊ�գ�����S��T�Ƿ���\n");
        return false;
    }
    int k = 0;
    for(int i=0;i<L.length;i++){
        if(!(L.data[i]>s&&L.data[i]<t)){
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length=k;
    return true;
}

//ɾ����ֵ��s,t֮��(����s,t)������Ԫ��
bool timu5(SqList &L,int s,int t){
    if(L.length==0||s>=t){
        printf("˳���Ϊ�գ�����S��T�Ƿ���\n");
        return false;
    }
    int k = 0;
    for(int i=0;i<L.length;i++){
        if(!(L.data[i]>=s&&L.data[i]<=t)){
            L.data[k]=L.data[i];
            k++;
        }
    }
    L.length=k;
    return true;
}

//�������ɾ��ֵ�ظ���Ԫ��
bool timu6(SqList &L){
    if(L.length == 0){
        printf("˳���Ϊ�գ�\n");
        return false;
    }
    int i ,j;
    for(i=0,j=1;j<L.length;j++){
        if(L.data[i]!=L.data[j]){
            L.data[++i]=L.data[j];
        }
    }
    L.length=i+1;
    return true;
}

//�����������ϲ���һ���µ����������
bool timu7(SqList L1,SqList L2,SqList &L3){
    if(L1.length+L2.length>MaxSize){
        printf("������󳤶�\n");
        return false;
    }
   int i=0,j=0,k=1;
   while(i<L1.length&&j<L2.length){
       if(L1.data[i]<=L2.data[j]){
           ListInsert(L3,k++,L1.data[i++]);
       }else{
           ListInsert(L3,k++,L2.data[j++]);
       }
   }
   while(i<L1.length){
       ListInsert(L3,k++,L1.data[i++]);
   }
    while(j<L2.length){
        ListInsert(L3,k++,L2.data[j++]);
    }
    return true;
}

void shunxubiao(){
    SqList l,l2;
    InitList(l);
    ListInsert(l,1,2);
    ListInsert(l,2,6);
    ListInsert(l,3,8);
    ListInsert(l,4,1);
    ListInsert(l,5,9);
    ListInsert(l,1,2);
    ListInsert(l,2,6);
    PrintfSqList(l);
    printf("----\n");
    int x=0;
    if(timu1(l,x)){
        printf("��Ŀ1�ɹ���\n");
    }else{
        printf("��Ŀ1ʧ�ܣ�\n");
    };
    PrintfSqList(l);
    printf("----\n");
    if(timu2(l)){
        printf("��Ŀ2�ɹ���\n");
    }else{
        printf("��Ŀ2ʧ�ܣ�\n");
    };
    PrintfSqList(l);
    printf("----\n");
    if(timu4(l,2,6)){
        printf("��Ŀ4�ɹ���\n");
    }else{
        printf("��Ŀ4ʧ�ܣ�\n");
    };
    PrintfSqList(l);
    printf("----\n");
    if(timu5(l,2,6)){
        printf("��Ŀ5�ɹ���\n");
    }else{
        printf("��Ŀ5ʧ�ܣ�\n");
    };
    PrintfSqList(l);
    printf("----\n");
    InitList(l2);
    ListInsert(l2,1,1);
    ListInsert(l2,2,1);
    ListInsert(l2,3,2);
    ListInsert(l2,4,2);
    ListInsert(l2,5,2);
    ListInsert(l2,6,3);
    PrintfSqList(l2);
    if(timu6(l2)){
        printf("��Ŀ6�ɹ���\n");
    }else{
        printf("��Ŀ6ʧ�ܣ�\n");
    };
    PrintfSqList(l2);
    printf("----\n");
    SqList l11,l22,l33;
    InitList(l11);
    InitList(l22);
    InitList(l33);
    ListInsert(l11,1,1);
    ListInsert(l11,2,3);
    ListInsert(l11,3,4);
    ListInsert(l11,4,7);
    ListInsert(l22,1,2);
    ListInsert(l22,2,5);
    ListInsert(l22,3,8);
    ListInsert(l22,4,9);
    if(timu7(l11,l22,l33)){
        printf("��Ŀ7�ɹ���\n");
    }else{
        printf("��Ŀ7ʧ�ܣ�\n");
    };
    PrintfSqList(l33);
    printf("----\n");
}