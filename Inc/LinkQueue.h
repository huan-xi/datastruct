//
// Created by huanxi on 2019/3/23.
//

#ifndef DATASTRUCT_LINKQUEUE_H
#define DATASTRUCT_LINKQUEUE_H


typedef int ElemType; //����Ԫ������
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode;
typedef struct {
    QNode *front;//��ͷָ��
    QNode *rear; //��βָ��
} LinkQueue;

void LQ_Initiate(LinkQueue *Q);//����һ���ն���
void LQ_Free(LinkQueue *Q);//�ͷŶ���
bool LQ_IsEmpty(LinkQueue Q);// �ж϶����Ƿ�Ϊ��
void LQ_Print(LinkQueue Q);// �������
int LQ_Length(LinkQueue Q);// ����еĳ���
void LQ_In(LinkQueue *Q, ElemType e);// ��e��ӡ���������Ԫ��eΪQ���µĶ�βԪ�ء�
void LQ_Out(LinkQueue *Q, ElemType *e);//�Ӷ���Q����һ��Ԫ�أ�����ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��
void LQ_Head(LinkQueue Q, ElemType *head);//��ȡ���еĶ�ͷԪ�أ���head������ֵ��

#endif //DATASTRUCT_LINKQUEUE_H
