//
// Created by huanxi on 2019/4/9.
//
#include"../Inc/HuffmanTree.h"
#include "./Test.h"
#include "stdio.h"
#include "../Inc/FileCache.h"
char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'};
int fnum[] = {1192, 677, 541, 518, 462, 450, 242, 195, 190, 181, 174, 157, 138, 124, 123};
int n = 15;
char filename[] = "hcd.bin";
HTNode ht[M];
HCode hcd[N];

void HuffmanTest() {
    for (int i = 0; i < n; ++i) {
        ht[i].data = chars[i];
        ht[i].weight = fnum[i];
    }
}

void PrintCode() {
    for (int i = 0; i < n; ++i) {
        if (i == 0)printf("+-----");
        else if (i == n - 1)printf("------+");
        else
            printf("------");
    }
    printf("\n");
    for (int i = -1; i < n; ++i) {
        if (i == -1)
            printf("|");
        else
            printf("%-4c |", chars[i]);
    }

    printf("\n");
    for (int i = -1; i < n; ++i) {
        if (i == -1)
            printf("|");
        else
            printf("%-4d |", fnum[i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        if (i == 0)printf("+-----");
        else if (i == n - 1)printf("------+");
        else
            printf("------");
    }
    printf("\n");
}

int f[128] = {0};
//ASCII码 文本频率统计
void CountCharFromFile(FILE *fp) {
    char c;
    while (c != EOF) {
        c = fgetc(fp);
        f[c]++;
    }
}
//构建叶子
void buildHT(){
    n=0;
    for (int i = 0; i < 128; ++i) {
        if (f[i]!=0){
            ht[i].data=i;
            ht[i].weight=f[i];
            n++;
        }
    }
}

void RunHuffmanTest(){
    FILE *fp=fopen("../Doc/ToBeTran.txt","r");
    CountCharFromFile(fp);
    fclose(fp);
    buildHT();
    PrintCode();
    CreateHT(ht, n);
    CreateHCode(ht, hcd, n);
    DispHCode(ht, hcd, n);
}


void RunHuffmanTest2() {
    /* printf("请输入字符集大小n>>");
     scanf("%d", &n);
     printf("\n");
     for (int i = 0; i < n; ++i) {
         printf("请输入第%i个字符,和其对应的权值列(如：a 123)>>",i+1);
         scanf("\n%c%d", chars + i, fnum + i);
         printf("\n");
     }*/
    printf("您输入的参数为:\n");
    PrintCode();
    printf("正在计算哈夫曼树...:\n");
    HuffmanTest();
    CreateHT(ht, n);
    printf("夫曼树计算完毕...:\n");
    DispTree(ht, 2 * n - 2);
    printf("\n");
    printf("正在生成哈夫曼编码...:\n");
    CreateHCode(ht, hcd, n);
    printf("正在生成哈夫曼编码...:\n");
    DispHCode(ht, hcd, n);
    printf("将编码保存至%s中\n", filename);
    SaveCache(filename, hcd, sizeof(HCode), N);
    printf("保存完毕\n");
}
