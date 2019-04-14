//
// Created by huanxi on 2019/4/9.
//
#include "../Inc/HuffmanTree.h"
#include "./Test.h"

void HuffmanTest() {
    int n = 15;
    char str[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g','h','i','j','k','l','m','n','o'};
    int fnum[] = {1192, 677, 541, 518, 462, 450, 242,195,190,181,174,157,138,124,123};
//    char str[] = {'a', 'b', 'c', 'd'};
//    int fnum[] = {1192, 677, 541, 518};
    HTNode ht[M];
    HCode hcd[N];
    for (int i = 0; i < n; ++i) {
        ht[i].data = str[i];
        ht[i].weight = fnum[i];
    }
    CreateHT(ht, n);
    CreateHCode(ht, hcd, n);
//    DispTree(ht,n);
    DispHCode(ht, hcd, n);
}
