//
// Created by huanxi on 2019-04-14.
//

#ifndef DATASTRUCT_FILECACHE_H
#define DATASTRUCT_FILECACHE_H

char *GetCacheFilePath();

/**
 * 保存变量到缓存
 * @param filename 缓存文件名
 * @param var 变量地址
 * @param size 大小
 * @param count 数量
 */
void SaveCache(char *filename, void *var, int size, int count);

/*
 * 从文件缓存中读值到变量
 */
void ReadCache(char *filename, void *buffer, int size, int count);

#endif //DATASTRUCT_FILECACHE_H
