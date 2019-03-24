//
// Created by huanxi on 2019/3/21.
//

#include "../Inc/SeqQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SQ_Initiate(SqQueue *Q)
// ˳����еĳ�ʼ����������һ���յ�˳�����
{
    Q->elem = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    Q->front = Q->rear = 0;
}

void SQ_Free(SqQueue *Q)
// �ͷ�˳�����
{
    free(Q->elem);
}

bool SQ_IsEmpty(SqQueue Q)
// �ж�˳������Ƿ�Ϊ�գ�Ϊ�շ���true�����򷵻�false��
{
    return Q.front == Q.rear;
}

bool SQ_IsFull(SqQueue Q)
// �ж�˳������Ƿ�Ϊ����Ϊ������true,���򷵻�false��
{
    return (Q.rear + 1) % MAXSIZE == Q.front;
}

int SQ_Length(SqQueue Q)
// ���г���
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

void SQ_Print(SqQueue Q)
//������������е�ÿ��Ԫ��
{
    int i;
    if (SQ_IsEmpty(Q)) {
        printf("queue is emtpy");
        return;
    }
    for (i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE)
        printf(" %d", Q.elem[i]);
    printf("\n");
}

void SQ_In(SqQueue *Q, ElemType e)
// ��e��ӡ���������Ԫ��eΪQ���µĶ�βԪ�ء�
{
    if (SQ_IsFull(*Q))return;
    Q->elem[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}

void SQ_Out(SqQueue *Q, ElemType *e)
// �Ӷ���Q����һ��Ԫ�أ�����ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��
{
    if (SQ_IsEmpty(*Q)) return;
    Q->front = (Q->front + 1) % MAXSIZE;
    *e = Q->elem[Q->front];
}

void SQ_Head(SqQueue Q, ElemType *head)
// ��ȡ���еĶ�ͷԪ�أ���head������ֵ��
{
    if (SQ_IsEmpty(Q)) return;
    *head = Q.elem[Q.front];
}
