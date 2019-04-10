//
// Created by huanxi on 2019/4/9.
//
#include "../Inc/HuffmanTree.h"
#include "./Test.h"
void HuffmanTest() {
    int n = 7;
    char str[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int fnum[] = {1193, 321, 32, 432, 54, 532, 53};
    HTNode ht[M];
    HCode hcd[N];
    for (int i = 0; i < n; ++i) {
        ht[i].data = str[i];
        ht[i].weight = fnum[i];
    }
    CreateHT(ht,n);
    CreateHCode(ht,hcd,n);
    DispTree(ht,n);
    DispHCode(ht,hcd,n);
}
