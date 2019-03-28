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
 *��n����n������
 * ������1.
 * �м��ĳ������������һ�е�����������֮��
 * @param row
 */
void YangHuiTriangle(int row) {
    SqQueue queue;
    int x, y;
    SQ_Initiate(&queue);
    SQ_In(&queue, 1); //��һ�е�1
    for (int i = 2; i <= row; ++i) { //��ѭ��
        SQ_In(&queue, 1); //��i�е���1
        //�������
        for (int k = 1; k <= i-2; ++k) { //��ѭ�� ��ӡǰһ��
            //��ȡ��i�е��м�Ԫ��
            SQ_Head(queue, &y);
            SQ_Out(&queue, &x);
            printf("%d ", y);
            SQ_Head(queue, &x);
            SQ_In(&queue, x + y);//��Ӵ���i-1
        }
        SQ_Head(queue, &y);
        SQ_Out(&queue,&x);
        printf("%d \n",y);
        SQ_In(&queue, 1); //��i�е�β1
    }
    //�������һ��
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
