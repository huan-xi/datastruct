//
// Created by huanxi on 2019/4/9.
//

#ifndef DATASTRUCT_HUFFMANTREE_H
#define DATASTRUCT_HUFFMANTREE_H

#define N 100
#define M 2*N-1

#include <stdio.h>
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

//根据哈夫曼编码，编码ASCII字符到文件
void EnCodeCharByHT(HTNode ht[],HCode *hcd, int n, char c,FILE *out);

//保存哈夫曼树到文件
void SaveHT(HTNode ht[],HCode *hcd, int n);
//读取哈夫曼树从文件
void ReadHT(HTNode ht[],HCode *hcd, int* n);

//从文件解码ASCII字符串
void DeCodeStringByHT(HTNode ht[]);

#endif //DATASTRUCT_HUFFMANTREE_H
