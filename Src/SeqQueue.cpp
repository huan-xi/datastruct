//
// Created by huanxi on 2019/3/21.
//

#include "../Inc/SeqQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SQ_Initiate(SqQueue *Q)
// 顺序队列的初始化，即构造一个空的顺序队列
{
    Q->elem = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    Q->front = Q->rear = 0;
}

void SQ_Free(SqQueue *Q)
// 释放顺序队列
{
    free(Q->elem);
}

bool SQ_IsEmpty(SqQueue Q)
// 判断顺序队列是否为空，为空返回true，否则返回false。
{
    return Q.front == Q.rear;
}

bool SQ_IsFull(SqQueue Q)
// 判断顺序队列是否为满，为满返回true,否则返回false。
{
    return (Q.rear + 1) % MAXSIZE == Q.front;
}

int SQ_Length(SqQueue Q)
// 队列长度
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

void SQ_Print(SqQueue Q)
//依次输出队列中的每个元素
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
// 将e入队。即：插入元素e为Q的新的队尾元素。
{
    if (SQ_IsFull(*Q))return;
    Q->elem[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}

void SQ_Out(SqQueue *Q, ElemType *e)
// 从队列Q出队一个元素，即：删除Q的队头元素，用e返回其值。
{
    if (SQ_IsEmpty(*Q)) return;
    Q->front = (Q->front + 1) % MAXSIZE;
    *e = Q->elem[Q->front];
}

void SQ_Head(SqQueue Q, ElemType *head)
// 获取队列的队头元素，用head返回其值。
{
    if (SQ_IsEmpty(Q)) return;
    *head = Q.elem[Q.front];
}
