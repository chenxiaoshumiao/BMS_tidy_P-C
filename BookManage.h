#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>     /*getch()����ʹ�õ�ͷ�ļ�*/
#include <windows.h>  /*Sleep()����ʹ�õ�ͷ�ļ�*/
#include <string.h>   /*strcmp()����ʹ�õ�ͷ�ļ�*/

#define LEN_BOOK sizeof(struct Book)
#define LEN_READER sizeof(struct Reader)
#define BOOK_DATA astBook[i].iNum,astBook[i].acName,astBook[i].acAuthor,astBook[i].acPress,astBook[i].iAmount
#define READER_DATA astReader[i].iNum,astReader[i].acName,astReader[i].acSex,astReader[i].iAmount,astReader[i].iMax,astReader[i].aiBookId
#define BOOK_NUM 200
#define READER_NUM 100


/*ͼ��ṹ�壺ͼ���ţ�ͼ������ͼ�����ߣ������磬�����*/
struct Book
{
	int iNum;
	char acName[15];
	char acAuthor[15];
	char acPress[15];
	int iAmount;
};

/*���ߣ����߱�ţ������������Ա𣬿ɽ�����,�����ѽ���ı��*/
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

/*==============================�˵���غ���============================*/
void ShowMainMenu();
void ShowBookMenu();
void ShowBorrowReturnMenu();
void ShowModifyBookMenu();
void ShowModifyReaderMenu();
/*==============================�ļ���д��غ���============================*/
int ReadBookFile(char pcMode);
int ReadReaderFile(char pcMode);
void SaveBookFile(int iBookId);
void SaveReaderFile(int iReaderId);
/*==============================�軹�������غ���============================*/
void BorrowBook();
void ReturnBook();
void BorrowReturnManage();
/*==============================ͼ�������غ���============================*/
void ShowBook();//��ʾͼ����Ϣ
void AddBook();//���ͼ��
void DeleteBook();//ɾ��ͼ��
void ModifyBook();//�޸��鼮��Ϣ
int SearchBook();//�����鼮
void ManageBook();//ͼ�����
/*==============================���߹�����غ���============================*/
void ShowReader();//��ʾ������Ϣ
void AddReader();//��Ӷ�����Ϣ
void DeleteReader();//ɾ���û�
void ModifyReader();//�޸��û���Ϣ
int SearchReader();//�����û�
void ManageReader();//�û���Ϣ����
