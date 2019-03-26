/*************************************************************
    date: January 2019
    队列的链接存储  实现文件
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Inc/LinkQueue.h"

//构造一个空队列
void LQ_Initiate(LinkQueue *Q) {
    Q->front = (QNode *) malloc(sizeof(QNode));
    Q->front->next = NULL;
    Q->rear = Q->front;
}

//释放队列
void LQ_Free(LinkQueue *Q) {
    QNode *curr, *next;
    curr = Q->front->next;
    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(Q->front);
}

bool LQ_IsEmpty(LinkQueue Q)
// 判断队列是否为空
{
    return Q.front == Q.rear;
}

void LQ_Print(LinkQueue Q)
// 输出队列
{
    QNode *p;
    if (LQ_IsEmpty(Q)) {
        printf("The queue is: empty. \n");
        return;
    }
    p = Q.front->next;
    while (p) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
}

int LQ_Length(LinkQueue Q)
// 求队列的长度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = 0;
    QNode *p = Q.front->next;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;

    /********** End **********/
}

void LQ_In(LinkQueue *Q, ElemType e) {
    QNode *p = (QNode *) malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

void LQ_Out(LinkQueue *Q, ElemType *e) {
    if (LQ_IsEmpty(*Q)) return;
    *e = Q->front->data;
    Q->front = Q->front->next;
}

void LQ_Head(LinkQueue Q, ElemType *head)
//获取队列的队头元素，用head返回其值。
{
    // 请在这里补充代码，完成本关任务
    if (LQ_IsEmpty(Q)) return;
    *head = Q.front->next->data;
}

