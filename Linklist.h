//
// Created by 12751 on 2020-06-07.
//

#ifndef UNTITLED_LINKLIST_H
#define UNTITLED_LINKLIST_H


class Linklist {

};

typedef struct LNode{
    int No;
    char Name;
    struct LNode *NextNode;
}LNode,*LinkList;

//鏌ョ湅
void ShowLinkList (LinkList node);

//澶存彃鍏?
LinkList List_HeadInsert(LinkList &L ,LNode &node);

//灏炬彃鍏?
LinkList List_TailInsert(LinkList &L,LNode &node);

//鎸夐『搴忔煡鎵?
LinkList GetElembyKey(LinkList &L,int no);


LinkList GetElembyIndex(LinkList &L,int index);

//鎻掑叆鑺傜偣


void Linkexc();



#endif //UNTITLED_LINKLIST_H
