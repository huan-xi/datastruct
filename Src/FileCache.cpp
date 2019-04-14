//
// Created by huanxi on 2019-04-14.
//

#include "../Inc/FileCache.h"
#include "string.h"
#include "stdio.h"

char filepath[] = "/Users/huanxi/cfile/";

char * GetCacheFilePath(){
    return filepath;
}

void SaveCache(char *filename, void *var, int size, int count) {
    char file[132];
    strcpy(file,filepath);
    strcat(file, filename);
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) {
        printf("Error failed to open file %s", file);
        return;
    }
    fwrite(var, count, size, fp);
    fclose(fp);
}

void ReadCache(char *filename,void *buffer, int size, int count){
    char file[132];
    strcpy(file,filepath);
    strcat(file, filename);
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("Error failed to read file %s", file);
        return;
    }
    if (fread(buffer,size,count,fp)!=count){
        printf("file read error\n");
        return;
    }
    fclose(fp);
}