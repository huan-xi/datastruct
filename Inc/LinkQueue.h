//
// Created by huanxi on 2019/3/23.
//

#ifndef DATASTRUCT_LINKQUEUE_H
#define DATASTRUCT_LINKQUEUE_H


typedef int ElemType; //数据元素类型
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode;
typedef struct {
    QNode *front;//队头指针
    QNode *rear; //队尾指针
} LinkQueue;

void LQ_Initiate(LinkQueue *Q);//构造一个空队列
void LQ_Free(LinkQueue *Q);//释放队列
bool LQ_IsEmpty(LinkQueue Q);// 判断队列是否为空
void LQ_Print(LinkQueue Q);// 输出队列
int LQ_Length(LinkQueue Q);// 求队列的长度
void LQ_In(LinkQueue *Q, ElemType e);// 将e入队。即：插入元素e为Q的新的队尾元素。
void LQ_Out(LinkQueue *Q, ElemType *e);//从队列Q出队一个元素，即：删除Q的队头元素，用e返回其值。
void LQ_Head(LinkQueue Q, ElemType *head);//获取队列的队头元素，用head返回其值。

#endif //DATASTRUCT_LINKQUEUE_H
