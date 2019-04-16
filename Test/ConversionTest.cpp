//
// Created by huanxi on 19-3-20.
//

#include <stdio.h>
#include "Test.h"
#include "../Inc/SeqStack.h"

void Conversion(int N, int r);

void Conversion(int N, int r) {
    SqStack s;
    int a;
    SS_Initiate(s);
    while (N != 0) {
        //取余数入栈
        SS_Push(s, N % r);
        N /= r;
    }
    while (s.top != -1) {
        SS_Pop(s, &a);
        printf("%x", a);

    }
}

void RunConversionTest() {
    Conversion(687, 16);
}
