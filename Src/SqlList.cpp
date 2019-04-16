//
// Created by huanxi on 2019/3/7.
//

#include <stdio.h>
#include <stdlib.h>
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
        printf("还没有数据\n");
        return;
    }
    for (int i = 0; i < L->length; ++i) {
        printf("第%d学生信息：%s %s %.2f\n", i + 1, L->data[i].sno, L->data[i].sname, L->data[i].score);
    }
    printf("\n");
}

void InitList(SqlList *&L) {
    //分配空间
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

bool UpdateElem(SqlList *&L, int i, ElemType e) {
    if (i < 1 || i > L->length)return false;
    L->data[i - 1] = e;
    return true;
}

int LocateElem(SqlList *L, ElemType e) {
    /*  int i = 0;
      while (i < L->length && e != L->data[i])i++; //结构体要重写相等方法
      if (i >= L->length)return 0;
      return i + 1;*/
}

bool DelElemByIndex(SqlList *&L, int index) {
    int j;
    if(index<1||index>L->length)//i值不合法
        return false;
    for(j=index;j<=L->length-1;j++)//前移
        L->data[j-1]=L->data[j];
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
    if(L->length==MaxSize)//表满
         return false;
    for(j=L->length-1;j>=i-1;j--)//后移
        L->data[j+1]=L->data[j];
    L->data[i-1]=e;
    L->length++;
}
