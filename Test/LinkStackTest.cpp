//
// Created by huanxi on 19-3-20.
//

#include "Test.h"
#include "../Inc/LinkStack.h"
#include "stdio.h"
void RunLinkStackTest(){
    LinkStack s;
    int a;
    LS_Initiate(s);
    LS_Push(s,1);
    LS_Push(s,2);
    LS_Push(s,3);
    LS_Push(s,4);
   // LS_Pop(s,a);
//    printf("%d\n",a);
    LS_Print(s);
}