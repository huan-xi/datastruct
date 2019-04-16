//
// Created by huanxi on 2019/4/9.
//


#include "stdio.h"
#include "../Inc/HuffmanTree.h"
#include "math.h"
#include "../Inc/SeqQueue.h"
#include "../Inc/FileCache.h"

#define ElemType HTNode

/*
 * 根据哈弗曼树对叶子节点求哈夫曼编码
 * 编码过程：
 * 1. ht[i]叶子节点的start指向最后
 * 2. 找其父节点，若自己为左孩子则cd添加0，右节点为1 ，start--
 * 3. 重复2直到没有父节点
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
 * 由ht叶子节点数组 构造完整的哈夫曼树
 * 定理：节点 = 2 * 叶子 + 1
 * ht[]：
 *  ht[0] ~ ht[n-1] 为叶子 共n个
 *  ht[n] ~ ht[2n-2] 放非叶子节点 共2n-2个
 * 构建过程：
 * 1. 叶子字节赋初值为-1
 * 2. 从叶子节点（parent为-1）中找权值最小的节点构建新树（parent为i），新树的权重为这两个之和
 * 3. 将新树加入叶子节点中
 * 4. 重复操作2，3 直到2n-2个节点全部处理完
 * */
void CreateHT(HTNode ht[], int n) {
    int i, k, lnode, rnode;
    int min1, min2;
    for (i = 0; i < 2 * n - 1; ++i) { //关系域赋初值 -1
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }
    for (i = n; i < 2 * n - 1; ++i) {
        min1 = min2 = 32767;  //初值为权值最大
        lnode = rnode = -1;
        for (k = 0; k <= i - 1; k++)  //（第二层循环每次增加一次，即加入新树）寻找最小节点，lnode，rnode
            if (ht[k].parent == -1) {
                //min1 最小
                if (ht[k].weight < min1) { //比最小还小
                    min2 = min1; //将min2赋值为第二小
                    rnode = lnode;
                    min1 = ht[k].weight;//将min1赋值为新的最小
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        ht[lnode].parent = ht[rnode].parent = i;
        //构建非叶子节点
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
    }
}

void DispHCode(HTNode *hc, HCode *hcd, int n) {
    int i, k, j, sum = 0, m = 0;
    printf("输出哈弗曼编码:\n");
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
    printf("\n平均长度=%g\n", 1.0 * sum / m);
}

int BinTreeGetDepth(HTNode ht[], int i) {
    if (ht[i].rchild == -1 && ht[i].lchild == -1)return 0;
    int ld = BinTreeGetDepth(ht, ht[i].lchild);
    int rd = BinTreeGetDepth(ht, ht[i].rchild);
    return 1 + (ld > rd ? ld : rd);
}

/**
 * 输出树
 * @param ht 树
 * @param n
 */
void DispTree(HTNode ht[], int i) {
    if (ht[i].rchild == -1 && ht[i].lchild == -1) {
        printf("%d", ht[i].weight);
        return;
    }
    printf("%d", ht[i].weight);
    if (ht[i].lchild != -1 || ht[i].rchild != -1) {
        printf("(");
        DispTree(ht, ht[i].lchild);
        if (ht[i].rchild != -1) printf(",");
        DispTree(ht, ht[i].rchild);
        printf(")");
    }
}

void EnCodeCharByHT(HTNode ht[], HCode *hcd, int n, char c, FILE *out) {
    for (int i = 0; i < n; ++i) { //找编码
        if (ht[i].data == c) {
            for (int k = hcd[i].start; k <= n; ++k) {
                fputc(hcd[i].cd[k], out);
            }
        }
    }
}

char filename[] = "../Res/hfmTree";

void SaveHT(HTNode ht[], HCode *hcd, int n) {
    printf("将编码保存至%s中\n", filename);
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error failed to open file %s", filename);
        return;
    }
    fwrite(&n, 1, sizeof(int), fp); //保存n
    fwrite(ht, M, sizeof(HTNode), fp);//保存ht数组 数组长度，数组元素大小
    fwrite(hcd, N, sizeof(HCode), fp);//保存hcd数组
    fclose(fp);
}

void ReadHT(HTNode ht[], HCode *hcd, int *n) {
    printf("从文件%s中读取编码\n", filename);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error failed to open file %s", filename);
        return;
    }
    fread(n, 1, sizeof(int), fp); //读取n
    fread(ht, M, sizeof(HTNode), fp);//保存ht数组
    fread(hcd, N, sizeof(HCode), fp);//保存hcd数组
}
/*
 *  int k=2*n-2;//根节点位置
    if (ht[k]==)
 * */

/**
 * 哈夫曼 2n -2
 */
int BinTreeFindRoot(HTNode *ht, int n) {
    for (int i = 0; i <= 2 * n - 2; ++i) {
        if (ht[i].parent == -1)
            return i;
    }
    return -1;
}



