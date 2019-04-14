//
// Created by huanxi on 2019/4/9.
//


#include "stdio.h"
#include "../Inc/HuffmanTree.h"
#include "math.h"
#include "../Inc/SeqQueue.h"

#define ElemType HTNode

/*
 * ���ݹ���������Ҷ�ӽڵ������������
 * ������̣�
 * 1. ht[i]Ҷ�ӽڵ��startָ�����
 * 2. ���丸�ڵ㣬���Լ�Ϊ������cd���0���ҽڵ�Ϊ1 ��start--
 * 3. �ظ�2ֱ��û�и��ڵ�
 */
void CreateHCode(HTNode ht[], HCode hcd[], int n) {
    int i, f, c;
    HCode hc;
    for (i = 0; i < n; ++i) {
        hc.start = n;
        c = i;
        f = ht[i].parent;
        while (f != -1) {
            if (ht[f].lchild == c) hc.cd[hc.start--] = '0';
            else hc.cd[hc.start--] = '1';
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
}

/*
 * ��htҶ�ӽڵ����� ���������Ĺ�������
 * �����ڵ� = 2 * Ҷ�� + 1
 * ht[]��
 *  ht[0] ~ ht[n-1] ΪҶ�� ��n��
 *  ht[n] ~ ht[2n-2] �ŷ�Ҷ�ӽڵ� ��2n-2��
 * �������̣�
 * 1. Ҷ���ֽڸ���ֵΪ-1
 * 2. ��Ҷ�ӽڵ㣨parentΪ-1������Ȩֵ��С�Ľڵ㹹��������parentΪi����������Ȩ��Ϊ������֮��
 * 3. ����������Ҷ�ӽڵ���
 * 4. �ظ�����2��3 ֱ��2n-2���ڵ�ȫ��������
 * */
void CreateHT(HTNode ht[], int n) {
    int i, k, lnode, rnode;
    int min1, min2;
    for (i = 0; i < 2 * n - 1; ++i) { //��ϵ�򸳳�ֵ -1
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }
    for (i = n; i < 2 * n - 1; ++i) {
        min1 = min2 = 32767;  //��ֵΪȨֵ���
        lnode = rnode = -1;
        for (k = 0; k <= i - 1; k++)  //���ڶ���ѭ��ÿ������һ�Σ�������������Ѱ����С�ڵ㣬lnode��rnode
            if (ht[k].parent == -1) {
                //min1 ��С
                if (ht[k].weight < min1) { //����С��С
                    min2 = min1; //��min2��ֵΪ�ڶ�С
                    rnode = lnode;
                    min1 = ht[k].weight;//��min1��ֵΪ�µ���С
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        ht[lnode].parent = ht[rnode].parent = i;
        //������Ҷ�ӽڵ�
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
    }
}

void DispHCode(HTNode *hc, HCode *hcd, int n) {
    int i, k, j, sum = 0, m = 0;
    printf("�������������:\n");
    for (i = 0; i < n; i++) {
        j = 0;
        printf("\t%c:\t", hc[i].data);
        for (k = hcd[i].start; k <= n; ++k) {
            printf("%c", hcd[i].cd[k]);
            j++;
        }
        m += hc[i].weight;
        sum += hc[i].weight * j;
    }
    printf("\nƽ������=%g\n", 1.0 * sum / m);
}

int BinTreeGetDepth(HTNode ht[], int i) {
    if (ht[i].rchild == -1 && ht[i].lchild == -1)return 0;
    int ld = BinTreeGetDepth(ht, ht[i].lchild);
    int rd = BinTreeGetDepth(ht, ht[i].rchild);
    return 1 + (ld > rd ? ld : rd);
}

/**
 * �����
 * @param ht ��
 * @param n
 */
void DispTree(HTNode ht[], int i) {
    if (ht[i].rchild == -1 && ht[i].lchild == -1)return;
    printf("%d", ht[i].weight);
    if (ht[i].lchild!=-1||ht[i].rchild!=-1){
        printf("(");
        DispTree(ht, ht[i].lchild);
        if (ht[i].rchild != -1) printf(",");
        DispTree(ht, ht[i].rchild);
        printf(")");
    }
}

/**
 * 2n -2
 */
int BinTreeFindRoot(HTNode *ht, int n) {
    for (int i = 0; i <= 2 * n - 2; ++i) {
        if (ht[i].parent == -1)
            return i;
    }
}



