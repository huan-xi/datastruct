#include <stdio.h>
#include "string.h"
#include "../Inc/SqlList.h"
#include "./Test.h"

void print_header() {
    printf("************************************\n");
    printf("�������������ѡ�����²�����\n");
    printf("0���˳�����\n");
    printf("1����ʼ��˳���\n");
    printf("2����������\n");
    printf("3���޸�����\n");
    printf("4���������\n");
    printf("5��ɾ������\n");
    printf("6�������������\n");
    printf("7���ɼ�����\n");
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
        printf("����������ѡ����>>");
        scanf("%d", &f);
        getchar(); //�����ַ� ��ֵ�����
        switch (f) {
            case 1 :
                InitList(students);
                printf("˳����ʼ����ϣ�\n");
                break;
            case 2:
                insertList();
                break;
            case 6:
                addList();
                break;
            case 3:
                printf("������Ҫ�޸ĵڼ���ѧ��������>>");
                scanf("%d", &index);
                updateList(index);
                break;
            case 4:
                if (!assertList()) break;
                DispList(students);
                break;
            case 5:
                printf("������Ҫɾ���ڼ���ѧ��������>>");
                scanf("%d", &index);
                delStudent(index);
                break;
            case 7:
                //�������
                break;
            case 0:
                break;
            default:
                printf("û�иù��ܣ������ѡ��\n");
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
    printf("��������Ҫ�����ѧ�����е�ѧ����š�ѧ�š����֡�����(�ÿո��������������������������#��)\n");
    while (end != '#') {
        scanf("%d%s", &index, &sno);
        scanf("%s%f%c", &sname, &score, &end);
        InsertElem(students, index, newStudent(sno, sname, score));
    }
}

//����list�ѳ�ʼ��
bool assertList() {
    if (students == NULL)printf("ѧ����δ��ʼ��\n");
    return students != NULL;
}

void delStudent(int index) {
    if (!assertList())return;
    if (DelElemByIndex(students, index)) printf("ɾ��Ԫ�سɹ�\n");
    else printf("ɾ��Ԫ��ʧ��\n");
}

void updateList(int index) {
    printf("��������Ҫ�޸ĵ�ѧ��ѧ�š����֡�����");
    char sname[8];
    char sno[12];
    float score;
    if (!assertList())return;
    scanf("%s", &sno);
    scanf("%s%f", &sname, &score);
    if (UpdataElem(students, index, newStudent(sno, sname, score))) printf("����Ԫ�سɹ�\n");
    else printf("����Ԫ��ʧ��\n");
}

void addList() {
    char sname[8];
    char sno[12];
    float score;
    char end = 0;
    if (!assertList())return;
    printf("��������Ҫ��ӵ���ѧ�����е�ѧ��ѧ�š����֡�����(�ÿո��������������������������#��)\n");
    while (end != '#') {
        scanf("%s", &sno);
        scanf("%s%f%c", &sname, &score, &end);
        AddElem(students, newStudent(sno, sname, score));
    }
}


Student newStudent(char *sno, char *sname, float score) {
    Student s;
    if (!strlen(sno) || !strlen(sname) || score < 0) {
        printf("�����������\n");
        return s;
    }
    s.score = score;
    strcpy(s.sname, sname);
    strcpy(s.sno, sno);
    return s;
}


