//
// Created by huanxi on 2019/3/23.
//

#include "./Test.h"
#include "../Inc/SeqQueue.h"
#include "stdio.h"

void YangHuiTriangle(int i);

void RunYangHuiTriangleTest() {
    YangHuiTriangle(6);
}

/**
 *    1
 *   1 1
 *  1 2 1
 * 1 3 3 1
 *第n行有n个数，
 * 两边是1.
 * 中间的某个数，等于上一行的两个相邻数之和
 * @param row
 */
void YangHuiTriangle(int row) {
    SqQueue queue;
    int x, y;
    SQ_Initiate(&queue);
    SQ_In(&queue, 1); //第一行的1
    for (int i = 2; i <= row; ++i) { //行循环
        SQ_In(&queue, 1); //第i行的首1
        //出队输出
        for (int k = 1; k <= i-2; ++k) { //列循环 打印前一行
            //获取第i行的中间元素
            SQ_Head(queue, &y);
            SQ_Out(&queue, &x);
            printf("%d ", y);
            SQ_Head(queue, &x);
            SQ_In(&queue, x + y);//入队次数i-1
        }
        SQ_Head(queue, &y);
        SQ_Out(&queue,&x);
        printf("%d \n",y);
        SQ_In(&queue, 1); //第i行的尾1
    }
    //输入最后一行
    while(!SQ_IsEmpty(queue)){
        SQ_Out(&queue,&x);
        printf("%d ",x);
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
