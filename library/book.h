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


extern pbook library;

int find_book(int number,pbook *prev,pbook *cur);
void insert_book_information(pbook book);
void print_book_information(pbook book);
void insert_book();
void modify_book();
void delete_book();
void search_book();
void find_bookborrower();
#endif
