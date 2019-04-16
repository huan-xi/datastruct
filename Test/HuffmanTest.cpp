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
//ASCII�� �ı�Ƶ��ͳ��
void CountCharFromFile(FILE *fp) {
    char c;
    while (c != EOF) {
        c = fgetc(fp);
        f[c]++;
    }
}
//����Ҷ��
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
    /* printf("�������ַ�����Сn>>");
     scanf("%d", &n);
     printf("\n");
     for (int i = 0; i < n; ++i) {
         printf("�������%i���ַ�,�����Ӧ��Ȩֵ��(�磺a 123)>>",i+1);
         scanf("\n%c%d", chars + i, fnum + i);
         printf("\n");
     }*/
    printf("������Ĳ���Ϊ:\n");
    PrintCode();
    printf("���ڼ����������...:\n");
    HuffmanTest();
    CreateHT(ht, n);
    printf("�������������...:\n");
    DispTree(ht, 2 * n - 2);
    printf("\n");
    printf("�������ɹ���������...:\n");
    CreateHCode(ht, hcd, n);
    printf("�������ɹ���������...:\n");
    DispHCode(ht, hcd, n);
    printf("�����뱣����%s��\n", filename);
    SaveCache(filename, hcd, sizeof(HCode), N);
    printf("�������\n");
}
