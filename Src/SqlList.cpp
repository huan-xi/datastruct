//
// Created by huanxi on 2019/3/7.
//

#include <malloc.h>
#include <cstdio>
#include "../Inc/SqlList.h"


void CreateList(SqlList *&L, ElemType a[], int n) {
    int i = 0;
    L = (SqlList *) (malloc(sizeof(SqlList)));
    while (i < n) {
        L->data[i] = a[i];
        i++;
    }
    L->length = i;
}

void DispList(SqlList *L) {
    if (L->length == 0) {
        printf("��û������\n");
        return;
    }
    for (int i = 0; i < L->length; ++i) {
        printf("��%dѧ����Ϣ��%s %s %.2f\n", i + 1, L->data[i].sno, L->data[i].sname, L->data[i].score);
    }
    printf("\n");
}

void InitList(SqlList *&L) {
    //����ռ�
    L = static_cast<SqlList *>(malloc(sizeof(SqlList)));
    L->length = 0;
}

void DestroyList(SqlList *&L) {
    free(L);
}

bool ListIsEmpty(SqlList *L) {
    return ListLength(L) == 0;
}

int ListLength(SqlList *L) {
    return L->length;
}

bool GetElem(SqlList *L, int i, ElemType &e) {
    if (i < 1 || i > L->length)return false;
    e = L->data[i - 1];
    return true;
}

bool UpdataElem(SqlList *&L, int i, ElemType e) {
    if (i < 1 || i > L->length)return false;
    L->data[i - 1] = e;
    return true;
}

int LocateElem(SqlList *L, ElemType e) {
    /*  int i = 0;
      while (i < L->length && e != L->data[i])i++; //�ṹ��Ҫ��д��ȷ���
      if (i >= L->length)return 0;
      return i + 1;*/
}

bool DelElemByIndex(SqlList *&L, int index) {
    int i;
    if (index < 1 || index > L->length) return false;
    index++;
    for (i = index; i < L->length; i--) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return true;
}

void AddElem(SqlList *&L, ElemType e) {
    if (L->length >= MaxSize)
        return;
    L->data[L->length] = e;
    L->length++;
}

bool InsertElem(SqlList *&L, int i, ElemType e) {
    int j;
    if (i < 1 || i > L->length + 1)return false;
    i--;
    for (j = L->length; j < i; j--) {
        L->data[j - 1] = L->data[j];
    }
    L->data[i]=e;
    L->length++;
}
