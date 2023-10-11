#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 100    //���100����
#define MAX_ISBN 15      //����15λ
#define MAX_NAME 50      //�����50
#define MAX_AUTHNAME 10  //���������10����ĸ
#define MAX_PRICE 100.0  //�۸�100����

typedef struct {
    char ISBN[MAX_ISBN];//ͼ����
    char name[MAX_NAME + 1];  //����
    char auth[MAX_AUTHNAME + 1]; //����
    float price;    //�۸�
    int inventory;//�������
} Book;

void generateBookISBN(char booknum[]);//����������

void generateBookName(char bookname[]);//�����������

void generateBookAuthName(char authname[]);//���������������

void generateBookPrice(float price);//�������������

//void BookInventory(int inv);//���ɿ������

void WriteIntoFile(Book book[], int count);//д���ļ�booktxt
