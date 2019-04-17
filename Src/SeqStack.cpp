//
// Created by huanxi on 19-3-20.
//

#include "../Inc/SeqStack.h"
#include <stdio.h>
#include <stdlib.h>

void SS_Initiate(SqStack &S)
// 顺序栈的初始化，即构造一个空的顺序栈
{
    S.elem = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    S.top=-1;
}

void SS_Free(SqStack &S)
// 释放顺序栈
{
    free(S.elem);
}

bool SS_IsEmpty(SqStack S)
// 判断顺序栈是否为空
{
    return S.top==-1;
}

bool SS_IsFull(SqStack S)
// 判断顺序栈是否为满
{
    return S.top==MAXSIZE-1;
}

void SS_Print(SqStack S)
//从栈底到栈顶输出所有元素
{
    int i;
    if(SS_IsEmpty(S))
    {
        printf("stack data: Empty!\n");
        return;
    }
    printf("stack data (from bottom to top):");
    for(i=0;i<=S.top;i++)
        printf(" %d", S.elem[i]);
    printf("\n");
}

void SS_Push(SqStack &S, ElemType e)
// 插入元素e为新的栈顶元素
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(S.top==MAXSIZE-1) return;
    S.top++;
    S.elem[S.top] =e;

    /********** End **********/
}

void SS_Pop(SqStack &S, ElemType *e)
// 删除S的栈顶元素，用e返回其值
{
    // 请在这里补充代码，完成本关任务
    if(S.top==-1) return;
    *e=S.elem[S.top];
    S.top--;
}

void SS_Top(SqStack S, ElemType *e)
// 获取栈顶元素赋给e
{
    // 请在这里补充代码，完成本关任务
    if(S.top ==-1) return;
    *e=S.elem[S.top];
}
