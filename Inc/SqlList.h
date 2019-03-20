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
 * 将数组转为sqllist
 * @param L  sqllist指针
 * @param a 输入数组
 * @param n 长度
 */
void CreateList(SqlList *&L, ElemType a[], int n);

/**
 * 打印sqllist
 * @param L
 */
void DispList(SqlList *L);

void InitList(SqlList *&L);

void DestroyList(SqlList *&L);

bool ListIsEmpty(SqlList *L);

int ListLength(SqlList *L);
/*
 * 逻辑位置删除
 */
bool DelElemByIndex(SqlList *&L,int index);
/**
 * 获取第i位元素 没有返回false
 * @param L
 * @param i
 * @param e
 * @return
 */
bool GetElem(SqlList *L, int i, ElemType &e);

bool UpdateElem(SqlList *&L, int i, ElemType e);

/**
 * 查找逻辑位置
 * @return 元素逻辑位置，没找到返回0
 */
int LocateElem(SqlList *L, ElemType e);

void AddElem(SqlList *&L, ElemType e);

/**
 * 插入元素
 * @param L
 * @param i  逻辑位置
 * @param e
 * @return 是否插入成功
 */
bool InsertElem(SqlList *&L, int i, ElemType e);
#endif //DATASTRUCT_SQLLIST_H
