//
// Created by huanxi on 2019/3/17.
//  ��ͷ�ڵ����ջ
//
#ifndef DATASTRUCT_LINKLIST_H
#define DATASTRUCT_LINKLIST_H

typedef int ElemType;
typedef struct LNode{
    ElemType   data;       //������
    struct LNode  *next;   //ָ����
}LNode,*LinkList;     // LinkListΪָ��ṹ��LNode��ָ������

//������ĳ�ʼ������������һ����ͷ���Ŀյĵ�����
void LL_Initiate(LinkList &L);

// �ͷ������и������
void LL_Free(LinkList &L);

// �ж������Ƿ�Ϊ�ա�
bool LL_IsEmpty(LinkList L);

// �����������
void LL_Print(LinkList L);
// ����n������Ԫ�أ�����ͷ�巨������һ����ͷ���ĵ�����L��
void LL_Create_H(LinkList &L,int n,ElemType e[]);
void LL_InsAt(LinkList &L, int i, ElemType e);
// ����n������Ԫ�أ�����β�巨������һ����ͷ���ĵ�����L��
void LL_Create_R(LinkList &L, int n, ElemType e[]);
// ɾ����һ��ֵΪe������Ԫ��
void LL_DelValue(LinkList L, ElemType e);
// �ڴ�ͷ���ĵ�����L�л�ȡ��i��Ԫ�ص�ֵ����e��i��ȡֵ��Χ[1,n]
void LL_GetAt(LinkList L, int i, ElemType *e);

void LL_DelAt(LinkList L,int i);
//�ڴ�ͷ���ĵ�����L�в��ҵ�һ��ֵΪe��Ԫ�أ�
//�ҵ��򽫸�Ԫ���������е�λ�ø���i�������ظý��ָ�룬����i��ֵΪ0�����ؿ�ָ��
LNode *LL_FindValue(LinkList L, ElemType e,int *i);

//����List
void LL_Reverse(LinkList &L);

//�ǵݼ�����
void LL_Order(LinkList &L);
#endif //DATASTRUCT_LINKLIST_H
