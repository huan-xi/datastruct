//
// Created by huanxi on 2019/4/9.
//

#ifndef DATASTRUCT_HUFFMANTREE_H
#define DATASTRUCT_HUFFMANTREE_H

#define N 50
#define M 2*N-1

typedef struct {
    char data;
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode;

//�������ΪString����
typedef struct {
    char cd[N]; //��Ź���������
    int start;//cd[start ... n]
} HCode;


void CreateHT(HTNode ht[], int n);

void CreateHCode(HTNode ht[], HCode hcd[], int n) ;
void DispHCode(HTNode *hc, HCode *hcd, int n);

//�������
int BinTreeGetDepth(HTNode ht[], int i);
//�Ҹ��ڵ�
int BinTreeFindRoot(HTNode *ht, int n);

void DispTree(HTNode ht[], int n);
#endif //DATASTRUCT_HUFFMANTREE_H
