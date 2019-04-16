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

//ASCII码 文本频率统计
void CountCharFromFile(FILE *fp) {
    char c;
    while ((c = fgetc(fp)) != EOF) {
        f[c]++;
    }
}

//构建叶子
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
    printf("请根据您的需求选择如下操作；\n");
    printf("0、退出程序\n");
    printf("1、输入字符频率创建编码并且保存到hfmTree\n");
    printf("2、从hfmTree中读取哈夫曼树，和哈夫曼编码到内存\n");
    printf("3、输出当前内存中哈夫曼树，和哈夫曼编码\n");
    printf("4、将ToBeTran.txt编码输出到CodeFile.txt\n");
    printf("5、将CodeFile.txt解码输出到TextFile.txt\n");
    printf("6、统计文件字符自动编码\n");
    printf("7、哈夫曼压缩，压缩ascii.txt文件到code.hz\n");
    printf("8、哈夫曼解压，解压code.hz到asciiTest.txt\n");
    printf("************************************\n");
}


/*
 * 编码文件
 * 根据存在内存总的哈夫曼编码，将in中编码输出到out 文件中
 */
void encodeFile(FILE *in, FILE *out) {
    char c;
    while ((c = fgetc(in)) != EOF) {
        EnCodeCharByHT(ht, hcd, n, c, out);
    }
}

/*
 * 解码文件
 * 根据内存中的哈夫曼编码，将in中解码输出到out 文件中
 */
void decodeFile(FILE *in, FILE *out) {
    char c;
    int k = 2 * n - 2; //根节点
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
 * 输出codeFile
 */
void dispCodeFile(FILE *in) {
    char c;
    int i = 0;
    int count = 50;//50 换行
    while ((c = fgetc(in)) != EOF) {
        i++;
        printf("%c", c);
        if (i == count) {
            printf("\n");
            i = 0;
        }

    }
}


//运行哈夫曼测试
void RunHuffmanTest() {
    FILE *in;
    FILE *out;
    printHeader();
    int f = -1, index;
    while (f != 0) {
        printHeader();
        printf("请输入数字选择功能>>");
        scanf("%d", &f);
        getchar(); //吸收字符 奇怪的问题
        switch (f) {
            case 1:
                printf("请输入字符集大小n>>");
                scanf("%d", &n);
                printf("\n");
                for (int i = 0; i < n; ++i) {
                    printf("请输入第%i个字符,和其对应的权值列(如：a 123)>>", i + 1);
                    scanf("\n%c%d", chars + i, fnum + i);
                    printf("\n");
                }
                for (int i = 0; i < n; ++i) {
                    ht[i].data = chars[i];
                    ht[i].weight = fnum[i];
                }
                printf("您输入的参数为:\n");
                printHT();
                CreateHT(ht, n);
                printf("夫曼树计算完毕:");
                DispTree(ht, 2 * n - 2);
                printf("\n");
                CreateHCode(ht, hcd, n);
                printf("哈夫曼编码生成完毕:");
                DispHCode(ht, hcd, n);
                SaveHT(ht, hcd, n);
                printf("保存完毕\n");
                break;
            case 3:
                dispCodeAndTree();
                break;
            case 5:
                if (n==0){
                    printf("内存中没有编码信息，从文件中读取");
                    ReadHT(ht, hcd, &n);
                    printf("读取完毕\n");
                }
                in = fopen("../Res/CodeFile.txt", "r");
                out = fopen("../Res/TextFile.txt", "w");
                decodeFile(in, out);
                printf("\n解码完毕");
                fclose(in);
                fclose(out);
                break;
            case 4:
                in = fopen("../Res/ToBeTran.txt", "r");
                out = fopen("../Res/CodeFile.txt", "w");
                if (in == NULL || out == NULL) {
                    printf("打开文件失败");
                    return;
                }
                //编码
                encodeFile(in, out);
                fclose(in);
                fclose(out);
                //输出编码文件
                in = fopen("../Res/CodeFile.txt", "r");
                dispCodeFile(in);
                printf("\n");
                fclose(in);
                break;
            case 2:
                ReadHT(ht, hcd, &n);
                printf("读取完毕\n");
                break;
            case 6:
                 in = fopen("../Res/ToBeTran.txt", "r");
                if (in == NULL) {
                    printf("打开文件失败");
                    return;
                }
                CountCharFromFile(in);
                buildHT();
                printf("统计完毕:\n");
                printHT();
                CreateHT(ht, n);
                CreateHCode(ht, hcd, n);
                dispCodeAndTree();
                break;
            case 7:
            case 8:
                printf("待实现");
                break;
        }
    }
}

void dispCodeAndTree() {
    if (n == 0)printf("当前没有信息\n");
    else {
        printf("哈夫曼树为:");
        DispTree(ht, 2 * n - 2);
        printf("\n");
        printf("哈夫曼编码为");
        DispHCode(ht, hcd, n);
    }
}