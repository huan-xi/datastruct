//
// Created by huanxi on 2019/3/23.
//

#include "../Inc/LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//构造一个空队列
void LQ_Initiate(LinkQueue *Q)
{
    Q->front=(QNode *)malloc(sizeof(QNode));
    Q->front->next=NULL;
    Q->rear=Q->front;
}

//释放队列
void LQ_Free(LinkQueue *Q)
{
    QNode *curr,*next;
    curr=Q->front->next;
    while(curr) {
        next = curr->next;
        free(curr);
        curr=next;
    }
    free(Q->front);
}

bool LQ_IsEmpty(LinkQueue Q)
// 判断队列是否为空
{
    return Q.front==Q.rear;
}

void LQ_Print(LinkQueue Q)
// 输出队列
{
    QNode *p;
    if (LQ_IsEmpty(Q))  {
        printf("The queue is: empty. \n");
        return;
    }
    p=Q.front->next;
    while(p)
    {
        printf(" %d", p->data);
        p=p->next;
    }
    printf("\n");
}

int LQ_Length(LinkQueue Q)
// 求队列的长度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/


    /********** End **********/
}

void LQ_In(LinkQueue *Q, ElemType e)
// 将e入队。即：插入元素e为Q的新的队尾元素。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/


    /********** End **********/
}

void LQ_Out(LinkQueue *Q, ElemType *e)
//从队列Q出队一个元素，即：删除Q的队头元素，用e返回其值。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/


    /********** End **********/
}

void LQ_Head(LinkQueue Q, ElemType *head)
//获取队列的队头元素，用head返回其值。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/


    /********** End **********/
}

