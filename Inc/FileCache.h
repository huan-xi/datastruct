//
// Created by huanxi on 2019-04-14.
//

#ifndef DATASTRUCT_FILECACHE_H
#define DATASTRUCT_FILECACHE_H
char * GetCacheFilePath();
void SaveCache(char * filename,void * var,int size, int count);
void ReadCache(char *filename,void *buffer, int size, int count);
#endif //DATASTRUCT_FILECACHE_H
