//
// Created by huanxi on 2019/3/17.
//
#include "../Inc/LinkList.h"
#include "./Test.h"

int RunLinkTest() {
    LinkList L;
    int a[4] = {3333, 415, 55, 66};
    LL_Create_R(L, 4, a);
    LL_InsAt(L, 5, 12);
    LL_InsAt(L, 1, 13);
    LL_Reverse(L);
    LL_Order(L);
    LL_Print(L);
    return 0;
}
