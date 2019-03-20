//
// Created by huanxi on 19-3-20.
// ˳��ջ
//

#ifndef DATASTRUCT_SEQSTACK_H
#define DATASTRUCT_SEQSTACK_H

#define  MAXSIZE 100     //��󳤶�
typedef int ElemType;
typedef  struct {
    ElemType  *elem;     //ָ������Ԫ�ص���ʼ��ַ
    int  top;          //ջ��Ԫ�ص��±�
}SqStack;

void SS_Initiate(SqStack *S);// ˳��ջ�ĳ�ʼ����������һ���յ�˳��ջ
void SS_Free(SqStack * S);// �ͷ�˳��ջ
bool SS_IsEmpty(SqStack S);// �ж�˳��ջ�Ƿ�Ϊ��
bool SS_IsFull(SqStack S);// �ж�˳��ջ�Ƿ�Ϊ��
void SS_Print(SqStack S);//��ջ�׵�ջ���������Ԫ��
void SS_Push(SqStack *S, ElemType e);// ����Ԫ��eΪ�µ�ջ��Ԫ��
void SS_Pop(SqStack *S, ElemType *e);// ɾ��S��ջ��Ԫ�أ���e������ֵ
void SS_Top(SqStack S, ElemType *e);// ��ȡջ��Ԫ�ظ���e


#endif //DATASTRUCT_SEQSTACK_H
