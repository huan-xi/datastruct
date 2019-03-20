//
// Created by huanxi on 19-3-20.
// 顺序栈
//

#ifndef DATASTRUCT_SEQSTACK_H
#define DATASTRUCT_SEQSTACK_H

#define  MAXSIZE 100     //最大长度
typedef int ElemType;
typedef  struct {
    ElemType  *elem;     //指向数据元素的起始地址
    int  top;          //栈顶元素的下标
}SqStack;

void SS_Initiate(SqStack *S);// 顺序栈的初始化，即构造一个空的顺序栈
void SS_Free(SqStack * S);// 释放顺序栈
bool SS_IsEmpty(SqStack S);// 判断顺序栈是否为空
bool SS_IsFull(SqStack S);// 判断顺序栈是否为满
void SS_Print(SqStack S);//从栈底到栈顶输出所有元素
void SS_Push(SqStack *S, ElemType e);// 插入元素e为新的栈顶元素
void SS_Pop(SqStack *S, ElemType *e);// 删除S的栈顶元素，用e返回其值
void SS_Top(SqStack S, ElemType *e);// 获取栈顶元素赋给e


#endif //DATASTRUCT_SEQSTACK_H
