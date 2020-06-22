//
// Created by 12751 on 2020-06-06.
//
#include <stdio.h>
#include "shunxubiao.h"


//初始化顺序表
void InitList(SqList &L){
    for(int i=0;i<MaxSize;i++){
        L.data[i]=0;	//所有数据元素设置为默认初始值0 ,不初始化内存会有遗留的脏数据。
    }
    L.length=0;	//初始长度为0
}

//插入
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

//删除
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

//按值查找
int LocateElem (SqList L,int e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

//打印顺序表
bool PrintfSqList(SqList L){
    if (L.length==0){
        printf("顺序表为空！\n");
        return false;
    }
    for(int i=0;i<L.length;i++){
        printf("第%d个，内容%d\n",i+1,L.data[i]);
    }
    return true;
}

//删除最小值的元素，并返回其值，空出的位置由最后一个元素填补
bool timu1(SqList &L,int &x){
    if(L.length==0) {
        printf("顺序表为空！\n");
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

//将顺序表所有元素逆置
bool timu2(SqList &L){
    if(L.length == 0){
        printf("顺序表为空！\n");
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

//删除所有值为x数据元素，时间复杂度为n,空间为1
bool timu3(SqList &L,int x){
    if(L.length == 0){
        printf("顺序表为空！\n");
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
//题目三方法二

bool timu3_2(SqList &L,int x){
    if(L.length == 0){
        printf("顺序表为空！\n");
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

//删除其值在s,t之间的所有元素
bool timu4(SqList &L,int s,int t){
    if(L.length==0||s>=t){
        printf("顺序表为空！或者S和T非法！\n");
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

//删除其值在s,t之间(包括s,t)的所有元素
bool timu5(SqList &L,int s,int t){
    if(L.length==0||s>=t){
        printf("顺序表为空！或者S和T非法！\n");
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

//有序表中删除值重复的元素
bool timu6(SqList &L){
    if(L.length == 0){
        printf("顺序表为空！\n");
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

//将两个有序表合并成一个新的有序表并返回
bool timu7(SqList L1,SqList L2,SqList &L3){
    if(L1.length+L2.length>MaxSize){
        printf("超过最大长度\n");
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
        printf("题目1成功！\n");
    }else{
        printf("题目1失败！\n");
    };
    PrintfSqList(l);
    printf("----\n");
    if(timu2(l)){
        printf("题目2成功！\n");
    }else{
        printf("题目2失败！\n");
    };
    PrintfSqList(l);
    printf("----\n");
    if(timu4(l,2,6)){
        printf("题目4成功！\n");
    }else{
        printf("题目4失败！\n");
    };
    PrintfSqList(l);
    printf("----\n");
    if(timu5(l,2,6)){
        printf("题目5成功！\n");
    }else{
        printf("题目5失败！\n");
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
        printf("题目6成功！\n");
    }else{
        printf("题目6失败！\n");
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
        printf("题目7成功！\n");
    }else{
        printf("题目7失败！\n");
    };
    PrintfSqList(l33);
    printf("----\n");
}