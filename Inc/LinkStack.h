//
// Created by huanxi on 19-3-20.
//

#ifndef DATASTRUCT_LINKSTACK_H
#define DATASTRUCT_LINKSTACK_H


typedef int ElemType; //数据元素类型
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
}StackNode, *LinkStack;

void LS_Initiate(LinkStack &S);//构造一个空栈
void LS_Free(LinkStack *S);//释放栈
bool LS_IsEmpty(LinkStack S);//判断栈是否为空
int LS_Length(LinkStack S);//求栈的长度
void LS_Print(LinkStack S);//从栈顶到栈底输出各结点数据
void LS_Push(LinkStack &S, ElemType e);//将元素e进栈
void LS_Pop(LinkStack &S, ElemType &e);//出栈。出栈元素赋给e
void LS_Top(LinkStack S, ElemType *e);//读栈顶元素赋给e。



#endif //DATASTRUCT_LINKSTACK_H
