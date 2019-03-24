//
// Created by huanxi on 2019/3/21.
//

#ifndef DATASTRUCT_SEQQUEUE_H
#define DATASTRUCT_SEQQUEUE_H


#define  MAXSIZE 100     //最大长度
typedef int ElemType;
typedef  struct {
    ElemType  *elem;     //数组空间的起始地址
    int front; // 存放队头元素的下标
    int rear;  // 存放队尾元素的下一个位置的下标
}SqQueue;

void SQ_Initiate(SqQueue *Q);// 顺序队列的初始化，即构造一个空的顺序队列
void SQ_Free(SqQueue *Q);// 释放顺序队列
bool SQ_IsEmpty(SqQueue Q);// 判断顺序队列是否为空，为空返回true，否则返回false。
bool SQ_IsFull(SqQueue Q);// 判断顺序队列是否为满，为满返回true,否则返回false。
int SQ_Length(SqQueue Q);// 求队列长度
void SQ_Print(SqQueue Q);//依次输出队列中的每个元素
void SQ_In(SqQueue *Q, ElemType e);// 将e入队。即：插入元素e为Q的新的队尾元素。
void SQ_Out(SqQueue *Q, ElemType *e);// 从队列Q出队一个元素，即：删除Q的队头元素，用e返回其值。
void SQ_Head(SqQueue Q, ElemType *head);// 获取队列的队头元素，用head返回其值。



#endif //DATASTRUCT_SEQQUEUE_H
