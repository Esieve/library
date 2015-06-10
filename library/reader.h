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

extern preader readers;//读者链表的头指针

int find_reader(long ID,preader *prev,preader *cur);//定位读者
void insert_reader_information(preader reader);//录入读者信息
void insert_reader();//录入读者
void modify_reader();//修改读者
void delete_reader();//删除读者
void borrow_book();//借书
#endif