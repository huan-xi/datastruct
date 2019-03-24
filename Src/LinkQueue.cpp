//
// Created by huanxi on 2019/3/23.
//

#include "../Inc/LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����һ���ն���
void LQ_Initiate(LinkQueue *Q)
{
    Q->front=(QNode *)malloc(sizeof(QNode));
    Q->front->next=NULL;
    Q->rear=Q->front;
}

//�ͷŶ���
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
// �ж϶����Ƿ�Ϊ��
{
    return Q.front==Q.rear;
}

void LQ_Print(LinkQueue Q)
// �������
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
// ����еĳ���
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/


    /********** End **********/
}

void LQ_In(LinkQueue *Q, ElemType e)
// ��e��ӡ���������Ԫ��eΪQ���µĶ�βԪ�ء�
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/


    /********** End **********/
}

void LQ_Out(LinkQueue *Q, ElemType *e)
//�Ӷ���Q����һ��Ԫ�أ�����ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/


    /********** End **********/
}

void LQ_Head(LinkQueue Q, ElemType *head)
//��ȡ���еĶ�ͷԪ�أ���head������ֵ��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/


    /********** End **********/
}

