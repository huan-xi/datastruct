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

//可以理解为String类型
typedef struct {
    char cd[N]; //存放哈夫曼编码
    int start;//cd[start ... n]
} HCode;


void CreateHT(HTNode ht[], int n);

void CreateHCode(HTNode ht[], HCode hcd[], int n) ;
void DispHCode(HTNode *hc, HCode *hcd, int n);

//计算深度
int BinTreeGetDepth(HTNode ht[], int i);
//找根节点
int BinTreeFindRoot(HTNode *ht, int n);

void DispTree(HTNode ht[], int n);
#endif //DATASTRUCT_HUFFMANTREE_H
