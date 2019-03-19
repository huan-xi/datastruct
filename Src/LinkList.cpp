//
// Created by huanxi on 2019/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "../Inc/LinkList.h"

void LL_Initiate(LinkList &L)
//������ĳ�ʼ������������һ����ͷ���Ŀյĵ�����
{
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
}

void LL_Free(LinkList &L)
// �ͷ������и�����㡣
{
    LinkList p;
    while (L) {
        p = L;
        L = L->next;
        free(p);
    }
}

bool LL_IsEmpty(LinkList L)
// �ж������Ƿ�Ϊ�ա�
{
    return L->next == NULL;
}

void LL_Create_H(LinkList &L, int n, ElemType e[])
// ����n������Ԫ�أ�����ͷ�巨������һ����ͷ���ĵ�����L��
{
    LNode *s;
    int i;
    LL_Initiate(L);
    for (i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode)); //�����½��
        s->data = e[i]; //����Ԫ��ֵ
        s->next = L->next;
        L->next = s;  //���뵽��ͷ
    }
}

void LL_Create_R(LinkList &L, int n, ElemType e[])
// ����n������Ԫ�أ�����β�巨������һ����ͷ���ĵ�����L��
{
    LNode *r, *s;
    int i;
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL; //����һ����ͷ���Ŀ�����
    r = L;  //βָ��rָ��ͷ���
    for (i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode)); //�����½��
        s->data = e[i]; //����Ԫ��ֵ
        s->next = NULL;
        r->next = s; //���뵽��β
        r = s;  //rָ���µ�β���
    }
}

void LL_Print(LinkList L)
// �����������
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
// �ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe����Ԫ�أ�i��ȡֵ��Χ[1,n+1]
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
// �ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�i��ȡֵ��Χ[1,n]
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
// �ڴ�ͷ���ĵ�����L�л�ȡ��i��Ԫ�ص�ֵ����e��i��ȡֵ��Χ[1,n]
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
//�ڴ�ͷ���ĵ�����L�в��ҵ�һ��ֵΪe��Ԫ�أ�
//�ҵ��򽫸�Ԫ���������е�λ�ø���i�������ظý��ָ�룬����i��ֵΪ0�����ؿ�ָ��
{
    // �������ﲹ����룬��ɱ�������
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
// ɾ����һ��ֵΪe������Ԫ��
{
    // �������ﲹ����룬��ɱ�������
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
        q = p->next; //��¼
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

void LL_Order(LinkList &L) {
    if (NULL == L->next) return;
    LNode *p = L->next, *q, *t, *r, *pre;
    L->next = NULL; //�Ͽ�ͷ���
    r = L;  //βָ��rָ��ͷ���
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
            //����ٺ���
            r->next = t;
            r = t;
        } else {
            //��p/**/qǰ�����
            t->next = pre->next;
            pre->next = t;
        }
        p = p->next;
    }
    LL_Free(p);
}

