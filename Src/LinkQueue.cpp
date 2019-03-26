/*************************************************************
    date: January 2019
    ���е����Ӵ洢  ʵ���ļ�
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Inc/LinkQueue.h"

//����һ���ն���
void LQ_Initiate(LinkQueue *Q) {
    Q->front = (QNode *) malloc(sizeof(QNode));
    Q->front->next = NULL;
    Q->rear = Q->front;
}

//�ͷŶ���
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
// �ж϶����Ƿ�Ϊ��
{
    return Q.front == Q.rear;
}

void LQ_Print(LinkQueue Q)
// �������
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
// ����еĳ���
{
    // �������ﲹ����룬��ɱ�������
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
//��ȡ���еĶ�ͷԪ�أ���head������ֵ��
{
    // �������ﲹ����룬��ɱ�������
    if (LQ_IsEmpty(Q)) return;
    *head = Q.front->next->data;
}

