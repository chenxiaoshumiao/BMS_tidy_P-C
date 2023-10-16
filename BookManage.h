#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>     /*getch()函数使用的头文件*/
#include <windows.h>  /*Sleep()函数使用的头文件*/
#include <string.h>   /*strcmp()函数使用的头文件*/

#define LEN_BOOK sizeof(struct Book)
#define LEN_READER sizeof(struct Reader)
#define BOOK_DATA astBook[i].iNum,astBook[i].acName,astBook[i].acAuthor,astBook[i].acPress,astBook[i].iAmount
#define READER_DATA astReader[i].iNum,astReader[i].acName,astReader[i].acSex,astReader[i].iAmount,astReader[i].iMax,astReader[i].aiBookId
#define BOOK_NUM 200
#define READER_NUM 100


/*图书结构体：图书编号，图书名，图书作者，出版社，库存量*/
struct Book
{
	int iNum;
	char acName[15];
	char acAuthor[15];
	char acPress[15];
	int iAmount;
};

/*读者：读者编号，读者姓名，性别，可借书数,读者已借书的编号*/
struct Reader
{
	int iNum;
	char acName[15];
	char acSex[4];
	int iMax;
	int iAmount;
	int aiBookId[10];
};

struct Book astBook[BOOK_NUM];
struct Reader astReader[READER_NUM];

/*==============================菜单相关函数============================*/
void ShowMainMenu();
void ShowBookMenu();
void ShowBorrowReturnMenu();
void ShowModifyBookMenu();
void ShowModifyReaderMenu();
/*==============================文件读写相关函数============================*/
int ReadBookFile(char pcMode);
int ReadReaderFile(char pcMode);
void SaveBookFile(int iBookId);
void SaveReaderFile(int iReaderId);
/*==============================借还书管理相关函数============================*/
void BorrowBook();
void ReturnBook();
void BorrowReturnManage();
/*==============================图书管理相关函数============================*/
void ShowBook();//显示图书信息
void AddBook();//添加图书
void DeleteBook();//删除图书
void ModifyBook();//修改书籍信息
int SearchBook();//查找书籍
void ManageBook();//图书管理
/*==============================读者管理相关函数============================*/
void ShowReader();//显示读者信息
void AddReader();//添加读者信息
void DeleteReader();//删除用户
void ModifyReader();//修改用户信息
int SearchReader();//查找用户
void ManageReader();//用户信息管理
