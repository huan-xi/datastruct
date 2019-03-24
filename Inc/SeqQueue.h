//
// Created by huanxi on 2019/3/21.
//

#ifndef DATASTRUCT_SEQQUEUE_H
#define DATASTRUCT_SEQQUEUE_H


#define  MAXSIZE 100     //��󳤶�
typedef int ElemType;
typedef  struct {
    ElemType  *elem;     //����ռ����ʼ��ַ
    int front; // ��Ŷ�ͷԪ�ص��±�
    int rear;  // ��Ŷ�βԪ�ص���һ��λ�õ��±�
}SqQueue;

void SQ_Initiate(SqQueue *Q);// ˳����еĳ�ʼ����������һ���յ�˳�����
void SQ_Free(SqQueue *Q);// �ͷ�˳�����
bool SQ_IsEmpty(SqQueue Q);// �ж�˳������Ƿ�Ϊ�գ�Ϊ�շ���true�����򷵻�false��
bool SQ_IsFull(SqQueue Q);// �ж�˳������Ƿ�Ϊ����Ϊ������true,���򷵻�false��
int SQ_Length(SqQueue Q);// ����г���
void SQ_Print(SqQueue Q);//������������е�ÿ��Ԫ��
void SQ_In(SqQueue *Q, ElemType e);// ��e��ӡ���������Ԫ��eΪQ���µĶ�βԪ�ء�
void SQ_Out(SqQueue *Q, ElemType *e);// �Ӷ���Q����һ��Ԫ�أ�����ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��
void SQ_Head(SqQueue Q, ElemType *head);// ��ȡ���еĶ�ͷԪ�أ���head������ֵ��



#endif //DATASTRUCT_SEQQUEUE_H
