#ifndef ____reader__
#define ____reader__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

typedef struct reader{
    char name[20];//姓名
    char department[20];//所在学院
    long ID;//读者编号
    char bookname[20];//所借图书名称
    struct reader *next;
}reader,*preader;

extern preader readers;

int find_reader(long ID,preader *prev,preader *cur);
void insert_reader_information(preader reader);
void insert_reader();
void modify_reader();
void delete_reader();
void borrow_book();
#endif