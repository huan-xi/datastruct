//
// Created by huanxi on 19-3-20.
//

#include "../Inc/SeqStack.h"
#include <stdio.h>
#include <stdlib.h>

void SS_Initiate(SqStack &S)
// ˳��ջ�ĳ�ʼ����������һ���յ�˳��ջ
{
    S.elem = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    S.top=-1;
}

void SS_Free(SqStack &S)
// �ͷ�˳��ջ
{
    free(S.elem);
}

bool SS_IsEmpty(SqStack S)
// �ж�˳��ջ�Ƿ�Ϊ��
{
    return S.top==-1;
}

bool SS_IsFull(SqStack S)
// �ж�˳��ջ�Ƿ�Ϊ��
{
    return S.top==MAXSIZE-1;
}

void SS_Print(SqStack S)
//��ջ�׵�ջ���������Ԫ��
{
    int i;
    if(SS_IsEmpty(S))
    {
        printf("stack data: Empty!\n");
        return;
    }
    printf("stack data (from bottom to top):");
    for(i=0;i<=S.top;i++)
        printf(" %d", S.elem[i]);
    printf("\n");
}

void SS_Push(SqStack &S, ElemType e)
// ����Ԫ��eΪ�µ�ջ��Ԫ��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if(S.top==MAXSIZE-1) return;
    S.top++;
    S.elem[S.top] =e;

    /********** End **********/
}

void SS_Pop(SqStack &S, ElemType *e)
// ɾ��S��ջ��Ԫ�أ���e������ֵ
{
    // �������ﲹ����룬��ɱ�������
    if(S.top==-1) return;
    *e=S.elem[S.top];
    S.top--;
}

void SS_Top(SqStack S, ElemType *e)
// ��ȡջ��Ԫ�ظ���e
{
    // �������ﲹ����룬��ɱ�������
    if(S.top ==-1) return;
    *e=S.elem[S.top];
}
