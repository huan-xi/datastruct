//
// Created by huanxi on 2019/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "../Inc/LinkList.h"

void LL_Initiate(LinkList &L)
//单链表的初始化，即：构造一个带头结点的空的单链表
{
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
}

void LL_Free(LinkList &L)
// 释放链表中各个结点。
{
    LinkList p;
    while (L) {
        p = L;
        L = L->next;
        free(p);
    }
}

bool LL_IsEmpty(LinkList L)
// 判断链表是否为空。
{
    return L->next == NULL;
}

void LL_Create_H(LinkList &L, int n, ElemType e[])
// 输入n个数据元素，采用头插法，创建一个带头结点的单链表L。
{
    LNode *s;
    int i;
    LL_Initiate(L);
    for (i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode)); //生成新结点
        s->data = e[i]; //输入元素值
        s->next = L->next;
        L->next = s;  //插入到表头
    }
}

void LL_Create_R(LinkList &L, int n, ElemType e[])
// 输入n个数据元素，采用尾插法，创建一个带头结点的单链表L。
{
    LNode *r, *s;
    int i;
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL; //建立一个带头结点的空链表
    r = L;  //尾指针r指向头结点
    for (i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode)); //生成新结点
        s->data = e[i]; //输入元素值
        s->next = NULL;
        r->next = s; //插入到表尾
        r = s;  //r指向新的尾结点
    }
}

void LL_Print(LinkList L)
// 输出整个链表。
{
    LNode *p;
    p = L->next;
    while (p) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

void LL_InsAt(LinkList &L, int i, ElemType e)
// 在带头结点的单链表L中第i个位置插入值为e的新元素，i的取值范围[1,n+1]
{
    LNode *p = L, *t;
    int j = 0;
    while (p != NULL && j < i - 1) {
        j++;
        p = p->next;
    }
    t = (LNode *) malloc(sizeof(LNode));
    t->data = e;
    t->next = p->next;
    p->next = t;
}

void LL_DelAt(LinkList L, int i)
// 在带头结点的单链表L中，删除第i个元素，i的取值范围[1,n]
{
    LNode *p = L, *t;
    int j = 1;
    while (p != NULL && j < i) {
        j++;
        p = p->next;
    }
    t = p->next;
    p->next = p->next->next;
    free(t);

}

void LL_GetAt(LinkList L, int i, ElemType *e)
// 在带头结点的单链表L中获取第i个元素的值赋给e，i的取值范围[1,n]
{
    int j = 1;
    LNode *p = L->next;
    while (p != NULL && j < i) {
        j++;
        p = p->next;
    }
    *e = p->data;
}

LNode *LL_FindValue(LinkList L, ElemType e, int *i)
//在带头结点的单链表L中查找第一个值为e的元素，
//找到则将该元素在链表中的位置赋给i，并返回该结点指针，否则i赋值为0并返回空指针
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int j = 1;
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
        j++;
    }
    *i = p == NULL ? 0 : j;
    return p;
    /********** End **********/
}

void LL_DelValue(LinkList L, ElemType e)
// 删除第一个值为e的数据元素
{
    // 请在这里补充代码，完成本关任务
    int j = 0;
    LNode *p = L;
    while (p != NULL && p->data != e) {
        p = p->next;
        j++;
    }

    if (p != NULL && p->data == e)
        LL_DelAt(L, j);
}

void LL_Reverse(LinkList &L) {
    if (NULL == L->next) return;
    LNode *p = L->next, *q;
    L->next = NULL;
    while (p != NULL) {
        q = p->next; //记录
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

void LL_Order(LinkList &L) {
    if (NULL == L->next) return;
    LNode *p = L->next, *q, *t, *r, *pre;
    L->next = NULL; //断开头结点
    r = L;  //尾指针r指向头结点
    while (p != NULL) {
        q = L->next;
        pre = L;
        while (q != NULL && p->data > q->data) {
            pre = q;
            q = q->next;
        }
        t = (LNode *) malloc(sizeof(LNode));
        t->data = p->data;
        t->next = NULL;
        if (q == NULL) {
            //添加再后面
            r->next = t;
            r = t;
        } else {
            //在p/**/q前面插入
            t->next = pre->next;
            pre->next = t;
        }
        p = p->next;
    }
    LL_Free(p);
}

