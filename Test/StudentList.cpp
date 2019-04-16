#include <stdio.h>
#include "string.h"
#include "../Inc/SqlList.h"
#include "./Test.h"

void print_header() {
    printf("************************************\n");
    printf("请根据您的需求选择如下操作；\n");
    printf("0、退出程序\n");
    printf("1、初始化顺序表\n");
    printf("2、插入数据\n");
    printf("3、修改数据\n");
    printf("4、输出数据\n");
    printf("5、删除数据\n");
    printf("6、添加数据数据\n");
    printf("7、成绩化分\n");
    printf("************************************\n");
}

void insertList();

void updateList(int index);

void delStudent(int index);

bool assertList();

Student newStudent(char *sno, char *sname, float score);

void addList();


void SortList(SqlList *students);

SqlList *students = NULL;

int RunStudentList() {
    int f = -1, index;
    while (f != 0) {
        print_header();
        printf("请输入数字选择功能>>");
        scanf("%d", &f);
        getchar(); //吸收字符 奇怪的问题
        switch (f) {
            case 1 :
                InitList(students);
                printf("顺序表初始化完毕！\n");
                break;
            case 2:
                insertList();
                break;
            case 6:
                addList();
                break;
            case 3:
                printf("请输入要修改第几个学生的数据>>");
                scanf("%d", &index);
                updateList(index);
                break;
            case 4:
                if (!assertList()) break;
                DispList(students);
                break;
            case 5:
                printf("请输入要删除第几个学生的数据>>");
                scanf("%d", &index);
                delStudent(index);
                break;
            case 7:
                //输出两次
                break;
            case 0:
                break;
            default:
                printf("没有该功能，请从新选择\n");
        }
    }
    DestroyList(students);
    return 0;
}



void insertList() {
    char sname[8];
    char sno[12];
    float score;
    char end = 0;
    int index = 0;
    if (!assertList())return;
    printf("请输入您要插入的学生表中的学生序号、学号、名字、分数(用空格隔开，若输入结束请在最后输入#号)\n");
    while (end != '#') {
        scanf("%d%s", &index, &sno);
        scanf("%s%f%c", &sname, &score, &end);
        InsertElem(students, index, newStudent(sno, sname, score));
    }
}

//断言list已初始化
bool assertList() {
    if (students == NULL)printf("学生表未初始化\n");
    return students != NULL;
}

void delStudent(int index) {
    if (!assertList())return;
    if (DelElemByIndex(students, index)) printf("删除元素成功\n");
    else printf("删除元素失败\n");
}

void updateList(int index) {
    printf("请输入您要修改的学生学号、名字、分数");
    char sname[8];
    char sno[12];
    float score;
    if (!assertList())return;
    scanf("%s", &sno);
    scanf("%s%f", &sname, &score);
    if (UpdateElem(students, index, newStudent(sno, sname, score))) printf("更新元素成功\n");
    else printf("更新元素失败\n");
}

void addList() {
    char sname[8];
    char sno[12];
    float score;
    char end = 0;
    if (!assertList())return;
    printf("请输入您要添加到的学生表中的学生学号、名字、分数(用空格隔开，若输入结束请在最后输入#号)\n");
    while (end != '#') {
        scanf("%s", &sno);
        scanf("%s%f%c", &sname, &score, &end);
        AddElem(students, newStudent(sno, sname, score));
    }
}


Student newStudent(char *sno, char *sname, float score) {
    Student s;
    if (!strlen(sno) || !strlen(sname) || score < 0) {
        printf("输入参数错误\n");
        return s;
    }
    s.score = score;
    strcpy(s.sname, sname);
    strcpy(s.sno, sno);
    return s;
}


