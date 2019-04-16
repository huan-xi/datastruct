//
// Created by huanxi on 2019-04-14.
//

#ifndef DATASTRUCT_FILECACHE_H
#define DATASTRUCT_FILECACHE_H
char * GetCacheFilePath();

//写变量到二进制文件
void SaveCache(char * filename,void * var,int size, int count);
//读二进制文件到变量
void ReadCache(char *filename,void *buffer, int size, int count);

#endif //DATASTRUCT_FILECACHE_H
