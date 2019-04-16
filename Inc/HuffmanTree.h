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

//���ݹ��������룬����ASCII�ַ����ļ�
void EnCodeCharByHT(HTNode ht[],HCode *hcd, int n, char c,FILE *out);

//��������������ļ�
void SaveHT(HTNode ht[],HCode *hcd, int n);
//��ȡ�����������ļ�
void ReadHT(HTNode ht[],HCode *hcd, int* n);

//���ļ�����ASCII�ַ���
void DeCodeStringByHT(HTNode ht[]);

#endif //DATASTRUCT_HUFFMANTREE_H
