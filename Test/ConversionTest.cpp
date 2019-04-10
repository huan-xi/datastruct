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
        //»°”‡ ˝»Î’ª
        SS_Push(s, N % r);
        N /= r;
    }
    while (s.top != -1) {
        SS_Pop(s, &a);
        switch (a) {
            case 10:
                printf("%c", 'A');
                break;
            case 11:
                printf("%c", 'B');
                break;
            case 12:
                printf("%c", 'C');
                break;
            case 13:
                printf("%c", 'D');
                break;
            case 14:
                printf("%c", 'E');
                break;
            case 15:
                printf("%c", 'F');
                break;
            default:
                printf("%d", a);
        }

    }
}

void RunConversionTest() {
    Conversion(687, 16);
}
