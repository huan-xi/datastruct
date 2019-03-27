//
// Created by huanxi on 2019/3/23.
//

#include "./Test.h"
#include "../Inc/SeqQueue.h"
#include "stdio.h"

void YangHuiTriangle(int i);

void RunYangHuiTriangleTest() {
    YangHuiTriangle(2);
}

/**
 *    1
 *   1 1
 *  1 2 1
 * 1 3 3 1
 *
 * @param row
 */
void YangHuiTriangle(int row) {
    SqQueue queue;
    int x, y;
    SQ_Initiate(&queue);
    for (int i = 0; i < row; ++i) { //行循环
        SQ_In(&queue, 1);
        //出队输出
        for (int k = 0; k <= i; ++k) {
            SQ_Out(&queue, &x);
            printf("%d ", x);
        }
        printf("\n");
    }
}

void RunSeqQueueTest() {
    SqQueue s;
    int e;
    SQ_Initiate(&s);
    SQ_In(&s, 21);
    SQ_In(&s, 21);
    SQ_In(&s, 32);
    SQ_In(&s, 443);
    SQ_In(&s, 5421);
    SQ_In(&s, 2431);
    SQ_Out(&s, &e);
    SQ_Head(s, &e);
    SQ_Print(s);
    printf("%d", e);
}
