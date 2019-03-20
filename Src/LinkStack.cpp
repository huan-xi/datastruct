//
// Created by huanxi on 19-3-20.
//

#include "../Inc/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

void LS_Initiate(LinkStack &S)//构造一个空栈
{
    S = (StackNode *) malloc(sizeof(StackNode));
    S->next = NULL;
}

void LS_Free(LinkStack *S)//释放栈
{
    StackNode *curr, *next;
    curr = *S;
    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}

bool LS_IsEmpty(LinkStack S)//判断栈是否为空
{
    return S == NULL;
}

int LS_Length(LinkStack S)//求栈的长度
{
    StackNode *p;
    int n;
    p = S->next;
    n = 0;
    while (p) {
        n++;
        p = p->next;
    }
    return n;
}

void LS_Print(LinkStack S)//从栈顶到栈底输出各结点数据
{
    StackNode *p;
    if (LS_IsEmpty(S)) {
        printf("The stack: Empty!");
        return;
    }
    printf("The stack (from top to bottom):");
    for (p = S->next; p; p = p->next)
        printf(" %d", p->data);
    printf("\n");
}

/*
 * 插入
 */
void LS_Push(LinkStack &S, ElemType e)//将元素e进栈
{
    // 请在这里补充代码，完成本关任务
    StackNode *p;
    p = (StackNode *) malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

void LS_Pop(LinkStack &S, ElemType &e)//出栈。出栈元素赋给e
{
    // 请在这里补充代码，完成本关任务
    StackNode *p;
    if (S->next == NULL) return;
    p = S->next;
    e = p->data;
    S->next = p->next;
}

void LS_Top(LinkStack S, ElemType *e)//读栈顶元素赋给e。
{
    // 请在这里补充代码，完成本关任务
    if (S->next == NULL) return;
    *e = S->next->data;
}


