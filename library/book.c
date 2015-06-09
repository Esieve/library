#include "book.h"


int find_book(int number,pbook *prev,pbook *cur){
    for (*cur=library,*prev=NULL;*cur!=NULL&&number>(**cur).serialNum;*prev=*cur,*cur=(**cur).next) {
    }
    //如果相等返回1，不等返回0
    if (*cur!=NULL&&number==(**cur).serialNum) {
        return 1;
    }
    return 0;
}

void insert_book_information(pbook book){
    printf("请输入图书名称:");
    scanf(" %s",book->name);
    printf("请输入图书数量:");
    scanf("%d",&book->number);
    printf("请输入图书价格:");
    scanf("%f",&book->price);
    printf("请输入图书种类:");
    scanf(" %s",book->group);
    printf("请输入图书出版日期:");
    scanf(" %s",book->date);
    printf("请输入图书作者:");
    scanf(" %s",book->author);
    printf("请输入图书出版社:");
    scanf(" %s",book->print);
}

void print_book_information(pbook book){
    printf("\n图书名称:%s\n图书编号:%d\n图书数量:%d\n图书价格:%f\n图书种类:%s\n图书出版日期:%s\n图书作者:%s\n图书出版社:%s\n\n",book->name,book->serialNum,book->number,book->price,book->group,book->date,book->author,book->print);
}

void insert_book(){
    pbook cur,prev,new_book;
    new_book=malloc(sizeof(book));
    if (new_book==NULL) {
        printf("数据库已满，不能分配更多空间!\n\n");
        free(new_book);
        return;
    }
    printf("请输入你想录入的图书编号:");
    scanf("%d",&new_book->serialNum);
    
    if (find_book(new_book->serialNum,&prev,&cur)==1) {
        printf("该图书编号已存在!\n\n");
        free(new_book);
        return;
    }
    
    insert_book_information(new_book);
    
    new_book->next=cur;
    if (prev==NULL) {
        library=new_book;
    }else{
        prev->next=new_book;
    }
    printf("录入成功!\n\n");
}

void modify_book(){
    pbook book;//要修改的图书
    pbook nullp;//仅作为参数传入，不需要其具体返回值
    int number;//要修改的图书编号
    printf("请输入你想修改的图书编号:");
    scanf("%d",&number);
    if (find_book(number,&nullp,&book)==1) {
        insert_book_information(book);
        printf("修改成功!\n\n");
    }else{
        printf("该图书编号不存在!\n\n");
    }
}

void delete_book(){
    int number;//要删除的图书编号
    pbook prev;//前一个指针
    pbook cur;//当前指针
    printf("请输入你想删除的图书编号:");
    scanf("%d",&number);
    if (find_book(number,&prev,&cur)==1) {
        //第一个节点的删除要区分出来
        if (prev!=NULL) {
            prev->next=cur->next;
        }else{
            library=cur->next;
        }
        printf("该图书已删除!\n\n");
        free(cur);//释放
    }else{
        printf("该图书编号不存在!\n\n");
    }
}

void search_book(){
    char information[20],str_serialNum[20];//保存查询信息；保存图书编号转化的字符串
    int code;//操作代码
    int i=0;//记录设备是否存在，不存在为0

    printf("输入1按图书名称查询\n输入2按图书编号查询\n输入3按图书作者查询\n输入4按图书出版社查询\n请输入:");
    scanf(" %d",&code);
    printf("请输入你想查询的信息:");
    scanf(" %s",information);
    
    if (code==1) {
        for (pbook p=library;p!=NULL;p=p->next) {
            if (strcmp(information,p->name)==0) {
                print_book_information(p);
                i++;
            }
        }
    }else if (code==2){
        for (pbook p=library;p!=NULL;p=p->next) {
            sprintf(str_serialNum, "%d",p->serialNum);//将图书编号转化为字符串,统一比较
            if (strcmp(information,str_serialNum)==0) {
                print_book_information(p);
                i++;
            }
        }
    }else if (code==3){
        for (pbook p=library;p!=NULL;p=p->next) {
            if (strcmp(information,p->author)==0) {
                print_book_information(p);
                i++;
            }
        }
    }else if (code==4){
        for (pbook p=library;p!=NULL;p=p->next) {
            if (strcmp(information,p->print)==0) {
                print_book_information(p);
                i++;
            }
        }
    }else{
        printf("代码输入错误!\n\n");
        return;
    }
    if (i==0) {
        printf("该图书不存在!\n\n");
    }
}

void find_bookborrower(){
    int serialNum,i;
    pbook null_p,book;
    preader reader;
    printf("请输入你想查询借阅人的图书编号:");
    scanf("%d",&serialNum);
    if (find_book(serialNum,&null_p,&book)==1) {
        for (preader p=readers;p!=NULL;p=p->next) {
            if (strcmp(book->name,reader->bookname)) {
                printf("%s\n",reader->name);
                i++;
            }
        }
        if (i==0) {
            printf("该图书无借阅人!\n\n");
        }
    }else{
        printf("该图书编号不存在!\n\n");
    }
}