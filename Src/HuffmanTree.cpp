//
// Created by huanxi on 2019/4/9.
//


#include "stdio.h"
#include "../Inc/HuffmanTree.h"


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

//由ht 叶子节点构造完整的树
void CreateHT(HTNode ht[], int n) {
    int i, k, lnode, rnode;
    int min1, min2;
    for (i = 0; i < 2 * n - 1; ++i) {
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }
    for (i = n; i < 2 * n - 1; ++i) {
        min1 = min2 = 32767;
        lnode = rnode = -1;
        for (k = 0; k < i - 1; k++) {
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
            ht[lnode].parent = ht[rnode].parent = i;
            ht[i].weight = ht[lnode].weight + ht[rnode].weight;
            ht[i].lchild = lnode;
            int test = ht[i].lchild;
            ht[i].rchild = rnode;
        }
    }
}

void DispHCode(HTNode *hc, HCode *hcd, int n) {
    int i, k, j, sum = 0, m = 0;
    printf("输出哈弗曼编码:\n");
    for (i = 0; i < n; ++i) {
        j = 0;
        printf("\t%c:\t", hc[i].data);
        for (k = hcd[i].start; k < n; ++k) {
            printf("%c", hcd[i].cd[k]);
            j++;
        }
        m += hc[i].weight;
        sum += hc[i].weight * j;
    }
    printf("\n平均长度=%g\n", 1.0 * sum / n);
}

void DispTree(HTNode ht[], int n) {
    for (int i = 0; i < n; ++i) {

    }
}
