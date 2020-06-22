//
// Created by 12751 on 2020-05-29.
//

#ifndef UNTITLED_LIANZHAN_H
#define UNTITLED_LIANZHAN_H


class lianzhan {

};


typedef struct Linknode{
    char data;
    struct Linknode *next;
}Linknode,*LiStack;


//初始化一个空栈
void InitLiStack(LiStack &S);

//判断栈是否为空
bool StacjEmpty(LiStack S);

//入栈(不带头结点）
bool Push(LiStack &S, char x);

//出栈(不带头结点)
bool Pop(LiStack &S, char &x);

//读取栈顶元素
bool GetTop(LiStack S, char &x);

//栈长度
int LenLiStack(LiStack S);

//打印栈
void PrintfLiStack(LiStack S);

int lianzhantext();



#endif //UNTITLED_LIANZHAN_H
