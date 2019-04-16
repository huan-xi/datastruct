//
// Created by huanxi on 2019/4/9.
//
#include"../Inc/HuffmanTree.h"
#include "./Test.h"
#include "stdio.h"
#include "../Inc/FileCache.h"

char chars[] = {};
int fnum[] = {0};
int n = 0;
HTNode ht[M];
HCode hcd[N];


void printHT() {
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
            printf("%-4c |", ht[i].data);
    }

    printf("\n");
    for (int i = -1; i < n; ++i) {
        if (i == -1)
            printf("|");
        else
            printf("%-4d |", ht[i].weight);
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

void dispCodeAndTree();

//ASCII�� �ı�Ƶ��ͳ��
void CountCharFromFile(FILE *fp) {
    char c;
    while ((c = fgetc(fp)) != EOF) {
        f[c]++;
    }
}

//����Ҷ��
void buildHT() {
    n = 0;
    for (int i = 0; i < 128; ++i) {
        if (f[i] != 0) {
            ht[n].data = i;
            ht[n].weight = f[i];
            n++;
        }
    }
}

void printHeader() {
    printf("************************************\n");
    printf("�������������ѡ�����²�����\n");
    printf("0���˳�����\n");
    printf("1�������ַ�Ƶ�ʴ������벢�ұ��浽hfmTree\n");
    printf("2����hfmTree�ж�ȡ�����������͹��������뵽�ڴ�\n");
    printf("3�������ǰ�ڴ��й����������͹���������\n");
    printf("4����ToBeTran.txt���������CodeFile.txt\n");
    printf("5����CodeFile.txt���������TextFile.txt\n");
    printf("6��ͳ���ļ��ַ��Զ�����\n");
    printf("7��������ѹ����ѹ��ascii.txt�ļ���code.hz\n");
    printf("8����������ѹ����ѹcode.hz��asciiTest.txt\n");
    printf("************************************\n");
}


/*
 * �����ļ�
 * ���ݴ����ڴ��ܵĹ��������룬��in�б��������out �ļ���
 */
void encodeFile(FILE *in, FILE *out) {
    char c;
    while ((c = fgetc(in)) != EOF) {
        EnCodeCharByHT(ht, hcd, n, c, out);
    }
}

/*
 * �����ļ�
 * �����ڴ��еĹ��������룬��in�н��������out �ļ���
 */
void decodeFile(FILE *in, FILE *out) {
    char c;
    int k = 2 * n - 2; //���ڵ�
    while ((c = fgetc(in)) != EOF) {
        if (c == '0') k = ht[k].lchild;
        else k = ht[k].rchild;
        if (ht[k].lchild == -1 && ht[k].rchild == -1) {
            printf("%c", ht[k].data);
            fputc(ht[k].data, out);
            k = 2 * n - 2;
        }
    }
}

/*
 * ���codeFile
 */
void dispCodeFile(FILE *in) {
    char c;
    int i = 0;
    int count = 50;//50 ����
    while ((c = fgetc(in)) != EOF) {
        i++;
        printf("%c", c);
        if (i == count) {
            printf("\n");
            i = 0;
        }

    }
}


//���й���������
void RunHuffmanTest() {
    FILE *in;
    FILE *out;
    printHeader();
    int f = -1, index;
    while (f != 0) {
        printHeader();
        printf("����������ѡ����>>");
        scanf("%d", &f);
        getchar(); //�����ַ� ��ֵ�����
        switch (f) {
            case 1:
                printf("�������ַ�����Сn>>");
                scanf("%d", &n);
                printf("\n");
                for (int i = 0; i < n; ++i) {
                    printf("�������%i���ַ�,�����Ӧ��Ȩֵ��(�磺a 123)>>", i + 1);
                    scanf("\n%c%d", chars + i, fnum + i);
                    printf("\n");
                }
                for (int i = 0; i < n; ++i) {
                    ht[i].data = chars[i];
                    ht[i].weight = fnum[i];
                }
                printf("������Ĳ���Ϊ:\n");
                printHT();
                CreateHT(ht, n);
                printf("�������������:");
                DispTree(ht, 2 * n - 2);
                printf("\n");
                CreateHCode(ht, hcd, n);
                printf("�����������������:");
                DispHCode(ht, hcd, n);
                SaveHT(ht, hcd, n);
                printf("�������\n");
                break;
            case 3:
                dispCodeAndTree();
                break;
            case 5:
                if (n==0){
                    printf("�ڴ���û�б�����Ϣ�����ļ��ж�ȡ");
                    ReadHT(ht, hcd, &n);
                    printf("��ȡ���\n");
                }
                in = fopen("../Res/CodeFile.txt", "r");
                out = fopen("../Res/TextFile.txt", "w");
                decodeFile(in, out);
                printf("\n�������");
                fclose(in);
                fclose(out);
                break;
            case 4:
                in = fopen("../Res/ToBeTran.txt", "r");
                out = fopen("../Res/CodeFile.txt", "w");
                if (in == NULL || out == NULL) {
                    printf("���ļ�ʧ��");
                    return;
                }
                //����
                encodeFile(in, out);
                fclose(in);
                fclose(out);
                //��������ļ�
                in = fopen("../Res/CodeFile.txt", "r");
                dispCodeFile(in);
                printf("\n");
                fclose(in);
                break;
            case 2:
                ReadHT(ht, hcd, &n);
                printf("��ȡ���\n");
                break;
            case 6:
                 in = fopen("../Res/ToBeTran.txt", "r");
                if (in == NULL) {
                    printf("���ļ�ʧ��");
                    return;
                }
                CountCharFromFile(in);
                buildHT();
                printf("ͳ�����:\n");
                printHT();
                CreateHT(ht, n);
                CreateHCode(ht, hcd, n);
                dispCodeAndTree();
                break;
            case 7:
            case 8:
                printf("��ʵ��");
                break;
        }
    }
}

void dispCodeAndTree() {
    if (n == 0)printf("��ǰû����Ϣ\n");
    else {
        printf("��������Ϊ:");
        DispTree(ht, 2 * n - 2);
        printf("\n");
        printf("����������Ϊ");
        DispHCode(ht, hcd, n);
    }
}