#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 100    //最多100本书
#define MAX_ISBN 15      //书号最长15位
#define MAX_NAME 50      //书名最长50
#define MAX_AUTHNAME 10  //作者名最多10个字母
#define MAX_PRICE 100.0  //价格100以内

typedef struct {
    char ISBN[MAX_ISBN];//图书编号
    char name[MAX_NAME + 1];  //书名
    char auth[MAX_AUTHNAME + 1]; //作者
    float price;    //价格
    int inventory;//库存数量
} Book;

void generateBookISBN(char booknum[]);//随机生成书号

void generateBookName(char bookname[]);//随机生成书名

void generateBookAuthName(char authname[]);//随机生成作者名字

void generateBookPrice(float price);//随机随机生成书价

//void BookInventory(int inv);//生成库存数量

void WriteIntoFile(Book book[], int count);//写入文件booktxt
