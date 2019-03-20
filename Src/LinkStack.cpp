//
// Created by huanxi on 19-3-20.
//

#include "../Inc/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

void LS_Initiate(LinkStack &S)//����һ����ջ
{
    S = (StackNode *) malloc(sizeof(StackNode));
    S->next = NULL;
}

void LS_Free(LinkStack *S)//�ͷ�ջ
{
    StackNode *curr, *next;
    curr = *S;
    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}

bool LS_IsEmpty(LinkStack S)//�ж�ջ�Ƿ�Ϊ��
{
    return S == NULL;
}

int LS_Length(LinkStack S)//��ջ�ĳ���
{
    StackNode *p;
    int n;
    p = S->next;
    n = 0;
    while (p) {
        n++;
        p = p->next;
    }
    return n;
}

void LS_Print(LinkStack S)//��ջ����ջ��������������
{
    StackNode *p;
    if (LS_IsEmpty(S)) {
        printf("The stack: Empty!");
        return;
    }
    printf("The stack (from top to bottom):");
    for (p = S->next; p; p = p->next)
        printf(" %d", p->data);
    printf("\n");
}

/*
 * ����
 */
void LS_Push(LinkStack &S, ElemType e)//��Ԫ��e��ջ
{
    // �������ﲹ����룬��ɱ�������
    StackNode *p;
    p = (StackNode *) malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

void LS_Pop(LinkStack &S, ElemType &e)//��ջ����ջԪ�ظ���e
{
    // �������ﲹ����룬��ɱ�������
    StackNode *p;
    if (S->next == NULL) return;
    p = S->next;
    e = p->data;
    S->next = p->next;
}

void LS_Top(LinkStack S, ElemType *e)//��ջ��Ԫ�ظ���e��
{
    // �������ﲹ����룬��ɱ�������
    if (S->next == NULL) return;
    *e = S->next->data;
}


