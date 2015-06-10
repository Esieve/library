#ifndef ____book__
#define ____book__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reader.h"

typedef struct book{
    char name[20];//图书名称
    int serialNum;//图书编号
    int number;//图书数量
    float price;//图书价格
    char group[20];// 图书种类(如：教材、著作等)
    char date[20];//图书出版日期，如20090101等
    char author[20];//图书作者
    char print[20];//出版社
    struct book *next;
}book,*pbook;

extern pbook library;//图书链表的头指针

int find_book(int number,pbook *prev,pbook *cur);//定位图书
void insert_book_information(pbook book);//输入图书信息
void print_book_information(pbook book);//打印图书信息
void insert_book();//录入图书
void modify_book();//修改图书
void delete_book();//删除图书
void search_book();//查找图书
void find_bookborrower();//查询图书的借阅人
#endif
