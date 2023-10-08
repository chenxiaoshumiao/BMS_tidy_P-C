#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BOOKS 100
#define MAX_ISBN 15
#define MAX_NAME 50
#define MAX_AUTHNAME 10
#define MAX_PRICE 100.0

typedef struct {
    char ISBN[MAX_ISBN];
    char name[MAX_NAME + 1];
    char auth[MAX_AUTHNAME + 1];
    float price;
    int inventory;//¿â´æÊýÁ¿
} Book;

// Function to generate a random ISBN
void generateISBN(char ISBN[]) {
    for (int i = 0; i < 13; i++) {
        ISBN[i] = '0' + rand() % 10;
    }
    ISBN[13] = '\0';
}

// Function to generate a random book name
void generateName(char name[]) {
    char vowels[] = "aeiou";
    char consonants[] = "bcdfghjklmnpqrstvwxyz";

    int length = rand() % MAX_NAME + 1;
    int startWithVowel = rand() % 2;

    for (int i = 0; i < length; i++) {
        if (i % 2 == startWithVowel) {
            name[i] = vowels[rand() % strlen(vowels)];
        }
        else {
            name[i] = consonants[rand() % strlen(consonants)];
        }
    }
    name[length] = '\0';
}
void generateAuth(char auth[]) {
    char vowels[] = "aeiou";
    char consonants[] = "bcdfghjklmnpqrstvwxyz";

    int length = rand() % MAX_AUTHNAME + 1;
    int startWithVowel = rand() % 2;

    for (int i = 0; i < length; i++) {
        if (i % 2 == startWithVowel) {
            auth[i] = vowels[rand() % strlen(vowels)];
        }
        else {
            auth[i] = consonants[rand() % strlen(consonants)];
        }
    }
    auth[length] = '\0';
}

// Function to generate a random book price
float generatePrice() {
    return (float)(rand() % (int)(MAX_PRICE * 100)) / 100.0;
}

// Function to save the books to a file
void saveBooksToFile(Book books[], int count) {
    FILE* file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {

        fprintf(file, "%s %s %s %.2f %d\n", books[i].ISBN, books[i].name, books[i].auth, books[i].price, rand() % 5 + 1);
    }

    fclose(file);
    printf("Books saved to file!\n");
}

int main() {
    srand(time(NULL));

    Book books[MAX_BOOKS];

    for (int i = 0; i < MAX_BOOKS; i++) {
        generateISBN(books[i].ISBN);
        generateName(books[i].name);
        generateAuth(books[i].auth);
        books[i].price = generatePrice();
    }

    saveBooksToFile(books, MAX_BOOKS);

    return 0;
}
