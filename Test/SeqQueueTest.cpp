//
// Created by huanxi on 2019/3/23.
//

#include "./Test.h"
#include "../Inc/SeqQueue.h"
#include "stdio.h"
void RunSeqQueueTest() {
    SqQueue s;int e;
    SQ_Initiate(&s);
    SQ_In(&s,21);
    SQ_In(&s,21);
    SQ_In(&s,32);
    SQ_In(&s,443);
    SQ_In(&s,5421);
    SQ_In(&s,2431);
    SQ_Out(&s,&e);
    SQ_Head(s,&e);
    SQ_Print(s);
    printf("%d",e);
}
