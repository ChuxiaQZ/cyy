//
// Created by 12751 on 2020-05-29.
//

#ifndef UNTITLED_LIANCHUANG_H
#define UNTITLED_LIANCHUANG_H


class lianchuang {

};


//链式串
typedef struct StringNode{
    int data;
    struct StringNode *next;
}StringNode ,*String;

//串

//初始化
void IncreasaString(String &S);
//插入
void insertString(String &S,int x);
//求串长
int LenString(String S);
//输出串
void PrintfString(String S);
//查询元素的位置
int WeizhiString(String S,int x);
//判断元素是否存在
bool CunzaiString(String S,int x);

void zhuanghua(String S,String &SS);

int lianchuangtext();

#endif //UNTITLED_LIANCHUANG_H
