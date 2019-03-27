//
// Created by huanxi on 2019/3/23.
//
#include "Test.h"
#include "../Inc/LinkQueue.h"

void RunLinkQueueTest() {
    LinkQueue q;
    int a;
    LQ_Initiate(&q);
    LQ_In(&q, 12);
    LQ_Out(&q, &a);
    LQ_In(&q, 14);
    LQ_In(&q, 12);
    LQ_Out(&q, &a);
    LQ_Out(&q, &a);
    LQ_Out(&q, &a);
    LQ_In(&q, 15);
    LQ_In(&q, 13);
    LQ_In(&q, 16);
    LQ_In(&q, 17);
    LQ_Print(q);
}
