//
// Created by huanxi on 2019/3/7.
//

#ifndef DATASTRUCT_SQLLIST_H
#define DATASTRUCT_SQLLIST_H

#define MaxSize 50
//typedef int ElemType;
typedef struct {
    char sname[8];
    char sno[12];
    float score;
} Student;

typedef Student ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqlList;

/**
 * ������תΪsqllist
 * @param L  sqllistָ��
 * @param a ��������
 * @param n ����
 */
void CreateList(SqlList *&L, ElemType a[], int n);

/**
 * ��ӡsqllist
 * @param L
 */
void DispList(SqlList *L);

void InitList(SqlList *&L);

void DestroyList(SqlList *&L);

bool ListIsEmpty(SqlList *L);

int ListLength(SqlList *L);
/*
 * �߼�λ��ɾ��
 */
bool DelElemByIndex(SqlList *&L,int index);
/**
 * ��ȡ��iλԪ�� û�з���false
 * @param L
 * @param i
 * @param e
 * @return
 */
bool GetElem(SqlList *L, int i, ElemType &e);

bool UpdateElem(SqlList *&L, int i, ElemType e);

/**
 * �����߼�λ��
 * @return Ԫ���߼�λ�ã�û�ҵ�����0
 */
int LocateElem(SqlList *L, ElemType e);

void AddElem(SqlList *&L, ElemType e);

/**
 * ����Ԫ��
 * @param L
 * @param i  �߼�λ��
 * @param e
 * @return �Ƿ����ɹ�
 */
bool InsertElem(SqlList *&L, int i, ElemType e);
#endif //DATASTRUCT_SQLLIST_H
