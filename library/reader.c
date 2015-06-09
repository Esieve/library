#include "reader.h"

int find_reader(long ID,preader *prev,preader *cur){
    for (*cur=readers,*prev=NULL;*cur!=NULL&&ID>(**cur).ID;*prev=*cur,*cur=(**cur).next) {
    }
    //如果相等返回1，不等返回0
    if (*cur!=NULL&&ID==(**cur).ID) {
        return 1;
    }
    return 0;
}

void insert_reader_information(preader reader){
    printf("请输入读者姓名:");
    gets(reader->name);
    printf("请输入读者所在学院:");
    gets(reader->department);
    memset(reader->bookname,0,sizeof(reader->bookname));//字符串置0
}

void insert_reader(){
    preader cur,prev,new_reader;
    new_reader=malloc(sizeof(reader));
    if (new_reader==NULL) {
        printf("数据库已满，不能分配更多空间!\n\n");
        free(new_reader);
        return;
    }
    printf("请输入你想录入的读者编号:");
    scanf("%ld",&new_reader->ID);
    
    
    if (find_reader(new_reader->ID,&prev,&cur)==1) {
        printf("该读者编号已存在!\n\n");
        free(new_reader);
        return;
    }
    
    insert_reader_information(new_reader);
    
    new_reader->next=cur;
    if (prev==NULL) {
        readers=new_reader;
    }else{
        prev->next=new_reader;
    }
}

void modify_reader(){
    preader reader;//要修改的读者信息
    preader nullp;//仅作为参数传入，不需要其具体返回值
    long ID;//要修改的读者编号
    printf("请输入你想修改的读者编号:");
    scanf("%ld",&ID);
    if (find_reader(ID,&nullp,&reader)==1) {
        insert_reader_information(reader);
    }else{
        printf("该读者编号不存在!\n\n");
    }
}

void delete_reader(){
    long ID;//要删除的读者编号
    preader prev;//前一个指针
    preader cur;//当前指针
    printf("请输入你想删除的读者编号:");
    scanf("%ld",&ID);
    if (find_reader(ID,&prev,&cur)==1) {
        //第一个节点的删除要区分出来
        if (prev!=NULL) {
            prev->next=cur->next;
        }else{
            readers=cur->next;
        }
        printf("该读者已删除!\n\n");
        free(cur);//释放
    }else{
        printf("该读者编号不存在!\n\n");
    }
}

void borrow_book(){
    long ID;
    int serialNum;
    preader null_p1,reader;
    pbook null_p2,book;
    printf("请输入你的读者编号:");
    scanf("%ld",&ID);
    if (find_reader(ID,&null_p1,&reader)==1&&strlen(reader->bookname)==0) {
        printf("请输入你想借的图书编号:");
        scanf("%d",&serialNum);
        if (find_book(serialNum,&null_p2,&book)==1&&book->number>0) {
            book->number--;
            strcpy(reader->bookname,book->name);
            printf("借阅成功!\n\n");
        }else if (find_book(serialNum,&null_p2,&book)==0){
            printf("该图书编号不存在!\n\n");
        }else if (book->number==0){
            printf("该图书已全部借出!\n\n");
        }
    }else if (find_reader(ID,&null_p1,&reader)==0){
        printf("该读者编号不存在!\n\n");
    }else if (strlen(reader->bookname)!=0){
        printf("每名读者只能借一本书!\n\n");
    }   
}