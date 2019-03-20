//
// Created by huanxi on 19-3-20.
//

#ifndef DATASTRUCT_LINKSTACK_H
#define DATASTRUCT_LINKSTACK_H


typedef int ElemType; //����Ԫ������
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;

void LS_Initiate(LinkStack &S);//����һ����ջ
void LS_Free(LinkStack *S);//�ͷ�ջ
bool LS_IsEmpty(LinkStack S);//�ж�ջ�Ƿ�Ϊ��
int LS_Length(LinkStack S);//��ջ�ĳ���
void LS_Print(LinkStack S);//��ջ����ջ��������������
void LS_Push(LinkStack &S, ElemType e);//��Ԫ��e��ջ
void LS_Pop(LinkStack &S, ElemType &e);//��ջ����ջԪ�ظ���e
void LS_Top(LinkStack S, ElemType *e);//��ջ��Ԫ�ظ���e��



#endif //DATASTRUCT_LINKSTACK_H
