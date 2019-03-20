//
// Created by huanxi on 2019/3/17.
//  带头节点的链栈
//
#ifndef DATASTRUCT_LINKLIST_H
#define DATASTRUCT_LINKLIST_H

typedef int ElemType;
typedef struct LNode{
    ElemType   data;       //数据域
    struct LNode  *next;   //指针域
}LNode,*LinkList;     // LinkList为指向结构体LNode的指针类型

//单链表的初始化，即：构造一个带头结点的空的单链表
void LL_Initiate(LinkList &L);

// 释放链表中各个结点
void LL_Free(LinkList &L);

// 判断链表是否为空。
bool LL_IsEmpty(LinkList L);

// 输出整个链表。
void LL_Print(LinkList L);
// 输入n个数据元素，采用头插法，创建一个带头结点的单链表L。
void LL_Create_H(LinkList &L,int n,ElemType e[]);
void LL_InsAt(LinkList &L, int i, ElemType e);
// 输入n个数据元素，采用尾插法，创建一个带头结点的单链表L。
void LL_Create_R(LinkList &L, int n, ElemType e[]);
// 删除第一个值为e的数据元素
void LL_DelValue(LinkList L, ElemType e);
// 在带头结点的单链表L中获取第i个元素的值赋给e，i的取值范围[1,n]
void LL_GetAt(LinkList L, int i, ElemType *e);

void LL_DelAt(LinkList L,int i);
//在带头结点的单链表L中查找第一个值为e的元素，
//找到则将该元素在链表中的位置赋给i，并返回该结点指针，否则i赋值为0并返回空指针
LNode *LL_FindValue(LinkList L, ElemType e,int *i);

//逆置List
void LL_Reverse(LinkList &L);

//非递减排序
void LL_Order(LinkList &L);
#endif //DATASTRUCT_LINKLIST_H
