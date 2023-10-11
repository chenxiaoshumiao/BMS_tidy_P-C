#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "FileWrite.h"
#include<stdio.h>

void generateBookISBN(char booknum[])
{
    for (int i = 0; i < MAX_ISBN; i++)
    {
        booknum[i] = '0' + rand() % 10;
    }
    booknum[MAX_ISBN] = '\0';
}

void generateBookName(char bookname[])
{
    char vowels[] = "aeiou";     //元音
    char consonants[] = "bcdfghjklmnpqrstvwxyz";//辅音
    int length = rand() % MAX_NAME + 1;   //书名长度随机分配为1-MAX_NAME之间
    int startWithVowel = rand() % 2;

    for (int i = 0; i < length; i++) {
        if (i % 2 == startWithVowel) {
            bookname[i] = vowels[rand() % strlen(vowels)];
        }
        else {
            bookname[i] = consonants[rand() % strlen(consonants)];
        }
    }
    bookname[length] = '\0';
}

void generateBookAuthName(char authname[])
{
    char vowels[] = "aeiou";     //元音
    char consonants[] = "bcdfghjklmnpqrstvwxyz";//辅音
    int length = rand() % MAX_AUTHNAME + 1;   //作者名长度随机分配为1-MAX_NAME之间
    int startWithVowel = rand() % 2;

    for (int i = 0; i < length; i++) {
        if (i % 2 == startWithVowel) {
            authname[i] = vowels[rand() % strlen(vowels)];
        }
        else {
            authname[i] = consonants[rand() % strlen(consonants)];
        }
    }
    authname[length] = '\0';
}

void generateBookPrice(float price)
{
    price = (float)(rand() % (int)(MAX_PRICE * 100) / 100.0);
}

void WriteIntoFile(Book book[], int count)
{
    FILE* file = fopen("books.text", "w");
    if (file == NULL)
    {
        printf("OPEN ERROR!");
        exit(-1);
    }
    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s  %s  %s  %.2f  %d\n", book[i].ISBN, book[i].name, book[i].auth, book[i].price, rand() % 5 + 1);
    }
    fclose(file);
    printf("Books imformation have written into the file!");
}


