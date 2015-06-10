#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "reader.h"

pbook library=NULL;
preader readers=NULL;

int main() {
    char code;//保存操作代码
    printf("欢迎使用！\n\n输入字母I或i录入图书或读者信息\n输入字母M或m修改图书或读者信息\n输入字母D或d删除图书或读者信息\n输入字母S或s查询图书信息\n输入字母B或b办理借书\n输入字母F或f查询某图书的借阅人信息\n输入字母Q或者q退出程序\n\n");
    for (;;) {
        printf("请输入操作代码:");
        scanf(" %c",&code);
        switch (code) {
            case 'I':case 'i':
                printf("\n输入字母B或b录入图书信息\n输入字母R或r录入读者信息\n\n");
                printf("请输入操作代码:");
                scanf(" %c",&code);
                
                switch (code) {
                    case 'B':case 'b':
                        insert_book();
                        break;
                    case 'R':case 'r':
                        insert_reader();
                        break;
                    default:
                        printf("输入错误，请重新输入!\n\n");
                        break;
                }
                break;
            case 'M':case 'm':
                printf("\n输入字母B或b修改图书信息\n输入字母R或r修改读者信息\n\n");
                printf("请输入操作代码:");
                scanf(" %c",&code);
                
                switch (code) {
                    case 'B':case 'b':
                        modify_book();
                        break;
                    case 'R':case 'r':
                        modify_reader();
                        break;
                    default:
                        printf("输入错误，请重新输入!\n\n");
                        break;
                }
                break;
            case 'D':case 'd':
                printf("\n输入字母B或b删除图书信息\n输入字母R或r删除读者信息\n\n");
                printf("请输入操作代码:");
                scanf(" %c",&code);
                
                switch (code) {
                    case 'B':case 'b':
                        delete_book();
                        break;
                    case 'R':case 'r':
                        delete_reader();
                        break;
                    default:
                        printf("输入错误，请重新输入!\n\n");
                        break;
                }
                break;
            case 'S':case 's':
                search_book();
                break;
            case 'B':case 'b':
                borrow_book();
                break;
            case 'F':case 'f':
                find_bookborrower();
                break;
            case 'Q':case 'q':
                printf("程序已退出!");
                return 0;
            default:
                printf("输入错误，请重新输入!\n\n");
                break;
        }
    }
    return 0;
}
