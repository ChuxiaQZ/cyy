//
// Created by 12751 on 2020-06-07.
//


#include <clocale>
#include <malloc.h>
#include "Linklist.h"

void printf(const char string[27], int no, char name);

void ShowLinkList (LinkList list){

    if(list != NULL){
        printf("this is my %d\n" ,list->No);
        ShowLinkList(list->NextNode);
    }
}

//杈撳叆琛?澶寸粨鐐规彃鍏?
LinkList List_HeadInsert(LinkList &L , LNode &node){
    //鎻掑叆锛?


    node.NextNode = L->NextNode;
    L->NextNode = &node;

    return L;
}

//灏剧粨鐐规彃鍏?
LinkList List_TailInsert(LinkList &L,LNode &node){
    LinkList tempNode;
    if(L == NULL){
        L = (LinkList)malloc(sizeof(LNode));
        L->NextNode=NULL;
        tempNode = L;
    }else{
        tempNode= L->NextNode;
    };

    //鎵惧埌鏈€鍚庤妭鐐癸紒
    //
    while (tempNode != NULL && tempNode->NextNode != NULL){
        tempNode = tempNode->NextNode;
    }
    tempNode->NextNode = &node;
    return L;
}

//鎸夐渶鏌ユ壘
LinkList GetElembyKey(LinkList &L,int no){
    LinkList tempNode = L->NextNode;
    while ( tempNode != NULL  && tempNode->NextNode != NULL){
        if(tempNode->No == no) {
            return tempNode;
        }
        tempNode = tempNode->NextNode;
    }
    return tempNode;
};

//鎸夐『搴忔煡鎵?
LinkList GetElembyIndex1(LinkList &L,int index){
    //闄勪笂澶存寚閽?
    LinkList tempNode = L->NextNode;
    if(index <= 0 ){
        return  NULL;
    }
    for (int cout = 0; cout < index; cout++) {
        printf("111111");
        tempNode = tempNode -> NextNode;
    };
    return tempNode;
}

void Linkexc(){

    LinkList list = (LinkList)malloc(sizeof(LNode));
    list->NextNode=NULL;

    LNode node1 {1 ,'a',NULL};
    printf("----%d---",&node1);
    LNode node2 { 2 ,'b',NULL};
    LNode node3 {3 ,'c',NULL};
    LNode node4 {4 ,'e',NULL};


    list = List_HeadInsert(list,node1);
    list = List_HeadInsert(list,node2);
    list = List_HeadInsert(list,node3);
    list = List_TailInsert(list,node4);

    LinkList key = GetElembyKey(list,2);
    printf("-----------\n");

    printf("this is my found %d\n" , key->No);
    printf("-----------\n");

    LinkList key2 = GetElembyIndex1(list,2);
    printf("this is my index %d \n" , key2->No);

    printf("-----------\n");
    ShowLinkList(list->NextNode);


}