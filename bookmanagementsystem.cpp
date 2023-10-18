#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
typedef int Status;
#define MAX_USERS 200
#define MAX_BOOKS 200
#define MAX_ISBN 14
#define MAX_BOOK_NAME 20
#define MAX_AUTH_NAME 10
#define MAX_ROLE 7
#define Max_ACCOUNT 11
#define Max_ACCOUNT_NUME 11
// Structure to store book information
typedef struct
{
    char ISBN[MAX_ISBN];
    char name[MAX_BOOK_NAME + 1];
    char auth[MAX_AUTH_NAME + 1];
    float price;
    int inventory; // �������
} Book;
typedef struct {
    Book *elem;             //�洢�ռ��ַ
    int length;             //��ǰ˳�����ʵ��Ԫ�صĸ���
    int listsize;               //��ǰ����Ĵ洢����
} SqListBook;
typedef struct
{
    char account[Max_ACCOUNT + 1];
    char accountNume[Max_ACCOUNT_NUME + 1];
    char role[MAX_ROLE + 1];
    int lendNumber; // �������� ��һ���������屾�飩
    char ISBNS[66];
} User;
typedef struct
{
	User *elem;             //�洢�ռ��ַ
    int length;             //��ǰ˳�����ʵ��Ԫ�صĸ���
    int listsize;
}SqListUser;
//˳����ʼ�� 
void initSqListBooks(SqListBook &books){
	books.elem = new Book[MAX_BOOKS];
	if(!books.elem) exit(0);
	books.length = 0;
}
void initSqListUsers(SqListUser &users){
	users.elem = new User[MAX_USERS];
	if(!users.elem) exit(0);
	users.length = 0;
}
//��½����
int logOn(SqListUser &users,User &user){
	while(1){
		int a = 1;
		char userAccount[2000],userAccountNume[2000],admin[6] = "admin";
		printf("�����������˺�(<=11λ)��");
		scanf("%s",userAccount);
		if(strlen(userAccount) > 11){
			printf("\n�˺Ų����Ϲ淶��\n������������......\n");
			getch();
			system("cls");
			continue;
		}
		FILE *file = fopen("user.txt", "r");
    	if (file == NULL)
    	{
        	printf("\nError opening file!\n");
        	return 0;
    	}
    	// read first line to count
    	int count = 0;
    	fscanf(file, "%d", &count);
    	users.length = count;
    	if (count == 0)
    	{
        	printf("no users\n");
        	system("cls"); 
        	return 0;
    	}
    	int b = 0;   //��b=1ʱ��ʾ���˺Ŵ��� 
    	for (int i = 0; i < count; i++)
    	{
        	fscanf(file, "%s %s %s %d", users.elem[i].account, users.elem[i].accountNume,users.elem[i].role,&users.elem[i].lendNumber);
        	for(int j = 0; j < users.elem[i].lendNumber * 13;j = j + 13){
        		fscanf(file,"%s",&(users.elem[i].ISBNS[j]));
			}
        	if(strcmp(userAccount,users.elem[i].account) == 0){
        		b = 1;
				strcpy(user.account,users.elem[i].account);
				strcpy(user.accountNume,users.elem[i].accountNume);
				strcpy(user.role,users.elem[i].role);
				strcpy(user.ISBNS,users.elem[i].ISBNS);
				user.lendNumber = users.elem[i].lendNumber;
			}
			if(i == count - 1 && b == 0){
				printf("\n�����ڸ��˻���\n������������......\n");
				a = 0;
				getch();
				system("cls");
			}
    	}
    	fclose(file);
    	if(a == 0){
    		continue;
		}
		while(1){
			printf("\n��������������(11λ)��");
			scanf("%s",userAccountNume);
			if(strlen(userAccountNume) != 11){
				printf("\���벻���Ϲ淶��\n������������......\n");
				getch();
				system("cls");
				continue;
			}
			if(strcmp(userAccountNume,user.accountNume) == 0){
				if(strcmp(user.role,admin) == 0){
					return 1;
				}
				else {
					return 0;
				}
			}
			else{
				printf("�������");
				getch();
				system("cls");
				continue;
			}
		}
	}
}
//ע�ắ��															       Ŀǰ��Ҫд�ĺ���
int logist(SqListUser &users,User &user){
	char userAccount[2000],userAccountNume[2000],role[2000],admin[6] = "admin";
	user.lendNumber = 0;
	
	FILE *file = fopen("user.txt", "r");
    if (file == NULL)
    {
       	printf("\nError opening file!\n");
       	return 2;
    }
    // read first line to count
    int count = 0;
    fscanf(file, "%d", &count);
    users.length = count;
    if (count == 0)
    {
        printf("no users\n");
  	 	system("cls"); 
    	return 0;
    }
    for (int i = 0; i < count; i++)
    {
       	fscanf(file, "%s %s %s %d", users.elem[i].account, users.elem[i].accountNume,users.elem[i].role,&users.elem[i].lendNumber);
       	for(int j = 0; j < users.elem[i].lendNumber * MAX_ISBN;j = j + 13){
       		fscanf(file,"%s",&(users.elem[i].ISBNS[j]));
		}
    }
    while(1){
		printf("�����������˺�(<=11λ)��");
		scanf("%s",userAccount);
		if(strlen(userAccount) > 11){
			printf("\n�˺Ų����Ϲ淶��\n������������......\n");
			getch();
			system("cls");
			continue;
		}
		int c = 0;
		for(int i = 0;i < count;i++){
			if(strcmp(userAccount,users.elem[i].account) == 0){
				printf("\n�˺������ظ�\n������������......\n");
				getch();
				system("cls");
				c = 1;
				break;
			}
		}
		if(c==1)continue;
		strcpy(user.account,userAccount);
		break;
	}
	while(1){
		printf("\n��������������(11λ)��");
		scanf("%s",userAccountNume);
		if(strlen(userAccountNume) != 11){
			printf("\n���벻���Ϲ淶��\n������������......\n");
			getch();
			system("cls");
			continue;
		}
		strcpy(user.accountNume,userAccountNume);
		break;
	}
	while(1){
		printf("\n�������������(admin or student)��");
		scanf("%s",role) ;
		if(strcmp(role,"admin") != 0 && strcmp(role,"student") != 0){
			printf("������������ݣ�\n������������......\n");
			getch();
			system("cls");
			continue;
		}
		strcpy(user.role,role);
		break;
	}
   	fclose(file);
	strcpy(users.elem[count].account,user.account);
	strcpy(users.elem[count].accountNume,user.accountNume);
	strcpy(users.elem[count].role,user.role);
	users.elem[count].lendNumber = 0;
	users.length += 1;

	//�����˳����������������ļ� 
	if(strcmp("admin",role) == 0){
		
		return 1;
	}
	if(strcmp("student",role) == 0){
		return 0; 
	} 
}
 
//���ļ��ж����鼮��Ϣ
int readBooks(Book books[])
{
    FILE *file = fopen("books.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }
    // read first line to count
    int count = 0;
    fscanf(file, "%d", &count);
    if (count == 0)
    {
        printf("no books\n");
        return 0;
    }
    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%s %s %s %f %d", books[i].ISBN, books[i].name,books[i].auth, &books[i].price, &books[i].inventory);
    }
    fclose(file);
    return count;
}
//�����鼮���� 
void searchBooks(SqListBook &books){
	int a = 0;
	while(1){
		char choices;
		cout <<"(1)���չ��ʱ�׼�鼮�������\n\
(2)�����鼮���Ʋ����鼮\n\
(3)�����������Ʋ����鼮\n\
(4)�������˵�\n\ 
.......\n\
���������ѡ��(1-4):"<< endl;
		cin >> choices;
		char ch = getchar();
		if(ch == '\n'){
			switch(choices){
			case '1':
				char searchISBN[2000];
				while(1){
					int c = 0;
					printf("����������鼮��13λ�鼮��ţ�");
    				scanf("%s",searchISBN);
    				if(strlen(searchISBN)!=13){
    					printf("���벻�淶\n");
    					continue;
					}
					for(int j = 0;j < 13;j++){
						if(searchISBN[j] < '0' || searchISBN[j] > '9'){
							c = 1;
							break;
						}
					}
					if(c == 1){
						printf("���벻�淶\n");
    					continue;
					}
					break;
    			}
				for(int i = 0; i < books.length; i++){
					if(strcmp(searchISBN,books.elem[i].ISBN) == 0)
					{
						printf("\n�鼮���	����	����	�۸�		���\n");
    					printf("\n%s	%s	%s	%f	%d\n", books.elem[i].ISBN, books.elem[i].name,books.elem[i].auth, books.elem[i].price, books.elem[i].inventory);
						printf("������������......\n");
						getch();
						system("cls");
						break;
					}
					if(i == books.length - 1){
						printf("\nû������ҵ��鼮Ŷ!\n"); 
						printf("������������......\n");
						getch();
						system("cls");
					}
				}
				break;
			case '2':
				char searchname[2000];
				while(1){
					printf("����������鼮���鼮���ƣ�");
    				scanf("%s",searchname);
    				if(strlen(searchname) > 20){
    					printf("���벻�淶\n");
    					continue;
					}
					break;
    			}
				for(int i = 0; i < books.length; i++){
					if(strcmp(searchname,books.elem[i].name) == 0)
					{
						printf("\n�鼮���	����	����	�۸�		���\n");
    					printf("\n%s	%s	%s	%f	%d\n", books.elem[i].ISBN, books.elem[i].name,books.elem[i].auth, books.elem[i].price, books.elem[i].inventory);
						printf("������������......\n");
						getch();
						system("cls");
						break;
					}
					if(i == books.length - 1){
						printf("\nû������ҵ��鼮Ŷ!\n"); 
						printf("������������......\n");
						getch();
						system("cls");
					}
				}
				break;
			case '3':
				char searchauth[2000];
				while(1){
					printf("����������鼮���������ƣ�");
    				scanf("%s",searchauth);
    				if(strlen(searchauth) > 10){
    					printf("���벻�淶\n");
    					continue;
					}
					break;
    			}
				for(int i = 0; i < books.length; i++){
					if(strcmp(searchauth,books.elem[i].auth) == 0)
					{
						printf("\n�鼮���	����	����	�۸�		���\n");
    					printf("\n%s	%s	%s	%f	%d\n", books.elem[i].ISBN, books.elem[i].name,books.elem[i].auth, books.elem[i].price, books.elem[i].inventory);
						printf("������������......\n");
						getch();
						system("cls");
						break;
					}
					if(i == books.length - 1){
						printf("\nû������ҵ��鼮Ŷ!\n"); 
						printf("������������......\n");
						getch();
						system("cls");
					}
				}
				break;
			case '4':
				a = 1;
				break;
			default:
				printf("���벻���Ϲ淶�淶��\n������������\n");
				getch();
				system("cls");
				break;
			}
		}
		else
		{
			printf("���벻���Ϲ淶��\������������\n");
			getch();
			system("cls");
		}
		if(a == 1){
			break;
			system("cls");
		}
	}
}
//��������鼮��Ϣ 
void searchBook(SqListBook &books,char searchISBN[14]){
	for(int i = 0; i < books.length; i++){
		if(strcmp(searchISBN,books.elem[i].ISBN) == 0)
		{
    		printf("\n%s	%s	%s	%f\n", books.elem[i].ISBN, books.elem[i].name,books.elem[i].auth, books.elem[i].price);
			break;
		}
		if(i == books.length - 1){
			printf("\nû������ҵ��鼮Ŷ!\n");
		}
	}
}

void addBooks(SqListBook &books){
	//Ҫ��Ҫ�ж�ԭ����û����ͬ�鼮 ?
	int q = 1;
	while(q){
		char auth[100];//
		printf("\n������������(<=10)��");
		scanf("%s",auth);
		if(strlen(auth) > 10){
			printf("���벻���Ϲ淶��\n");
			getch();
			continue;
		}
		strcpy(books.elem[books.length].auth,auth);
		break;
	}
		
	while(q){ 
		int a = 0;
		char ISBN[100];
		printf("\n������13λ�����鼮��׼����:");
		scanf("%s",ISBN);
		if(strlen(ISBN) > 13){
			printf("���벻���Ϲ淶��\n");
			getch();
			continue;
		}
		for(int i = 0;i < 13;i++){
			if(ISBN[i] < '0' || ISBN[i] > '9'){
				a = 1;
				break;
			}
		}
		if(a==1){
			printf("���벻���Ϲ淶��\n");
			getch();
			continue;
		}
		strcpy(books.elem[books.length].ISBN,ISBN);
		break;
	}
	
	while(q){
		char name[100];
		printf("\n����������(<=20)��");
		scanf("%s",name);
		if(strlen(name) > 20){
			printf("���벻���Ϲ淶��\n");
			getch();
			continue;
		}
		strcpy(books.elem[books.length].name,name);
		break;
	}
	
	printf("\n������۸�");
	scanf("%f",&books.elem[books.length].price);
	
	while(q){
	    char inventory[10];
	    int b = 0;
		printf("\n�������棺");
		scanf("%s",inventory);
		for(int i = 0;i < strlen(inventory);i++){
			if(inventory[i] < '0' || inventory[i] > '9'){
				b = 1;
				break;
			}
		}
		if(b == 1){
			printf("���벻���Ϲ淶��\n");
			getch();
			continue;
		}
		books.elem[books.length].inventory = atoi(inventory);
		break;
	}
	books.length += 1;
	system("cls");
	
}

void Modifying_Book_Information(SqListBook &books)//�޸�ͼ����Ϣ�ĺ��� 
{
	printf("������Ҫ�޸���Ϣ���鼮��(<20):");
	char modifying_books[21];
	scanf("%s",modifying_books);
	int i;	//Ҫ�ĵ�����±�
	int count=0;//0�ҵ�1�Ҳ��� 
	for(i=0;i<books.length;i++) //�ҵ����飬���õ������ַ 
	{
		if(!strcmp(books.elem[i].name,modifying_books))break; 
		if(i==books.length-1)
		{
			printf("�Ҳ�������");
			getch(); 
			system("cls");
			count=1; 
		}
	}
	if(count==0) 
	{
		while(1)
    	{
    		system("cls");
      		cout<<"\n	1:��ISBN\n\
      		2����������\n\
      		3������������\n\
      		4���ļ۸�\n\
      		5���Ŀ�棻\n\
      		6���˳���\n\
      		�������ѡ��(1-6):"<<endl;
      		char q;
      		scanf("%c",&q);//�û������ѡ�� 
      		Book correct_books;//���������û��������Ϣ 
      		char c = getchar();
      		if(c == '\n'){
      			switch(q)
      			{
      				case '1':
      					printf("�����鼮��ISBN;");
						scanf("%s",correct_books.ISBN);
						if(sizeof(correct_books.ISBN)!=13)
						{
							break;
						}
						strcpy(books.elem[i].ISBN,correct_books.ISBN);
						break; 
	  				case '2':
	  					printf("�����鼮������;");
						scanf("%s",correct_books.name);
						strcpy(books.elem[i].name,correct_books.name);
						break;   
	  				case '3':
	  					printf("�����鼮��������;");
						scanf("%s",correct_books.auth);
						strcpy(books.elem[i].auth,correct_books.auth);
						break;  
	  				case '4':
	  					printf("�����鼮�ļ۸�;");
						scanf("%f",&correct_books.price);
						if(correct_books.price<0)
						{
							printf("�������"); 
							break;
						}
						books.elem[i].price=correct_books.price;
						break;    
	  				case '5': 
	  					printf("�����鼮�Ŀ��;");
						scanf("%d",&correct_books.inventory);
						if(correct_books.inventory<0)
						{
							printf("�������"); 
							break;
						}
						books.elem[i].inventory=correct_books.inventory;
						break;
					case '6':
						break;
					default :
						printf("�����������������룻");
						getch();
						break; 
				}
	   		if(q==6)break;//�˳�����ҳ�� 
	   		system("cls");	
		}
		else{
			printf("�����������������룻\n������������\n");
			getch();
			system("cls");
		}
		
	}
	system("cls");
      
	} 
}
//���麯��                                                                Ŀǰ��Ҫд�ĺ��� 
void lendBooks(User &user,SqListBook &books){
	if (user.lendNumber == 5) {
		cout << "���������ѴＫ�ޣ��޷��������飬���ȹ黹�ѽ��鼮������\n��������˳�����" << endl;
		getch();
		return;
	}
	char lendISBN[MAX_ISBN], ch;
	int choice, exit = 0;
	int length = books.length;
	while (1) {
		cout << "1������ISBN����\n2���˳�\n���������ѡ��" << endl;
		cin >> choice;
		ch = getchar();
		if (ch == '\n') {
			switch (choice)
			{
			case 1:    //�����鼮�������
				printf("�������鼮��13λ���룺");
				scanf("%s", lendISBN);
				if (strlen(lendISBN) != 13) {     //�ж�������鼮����λ�������
					printf("�鼮������󣡣���\n���������������\n");
					getch();
					system("cls");
					break;
				}
				for (int i = 0; i < length; i++) {      //�����鼮�����������ƥ���Ӧ�鼮
					if (strcmp(books.elem[i].ISBN, lendISBN) == 0) {
						if (books.elem[i].inventory == 0) { 
							cout << "���鼮���Ϊ0���޷����飬���黹����\n���������������\n" << endl; 
							break;
						}
						for (int m = 0; m < 13; m++) user.ISBNS[user.lendNumber * 13 + m] = lendISBN[m];
						++user.lendNumber;
						--books.elem[i].inventory;
						printf("\n�ɹ�����\n���������������\n");
						getch();
						system("cls");
						break;
					}
					if (i == length - 1) {     //û���ҵ���Ӧ�鼮
						printf("\n�����û��ָ��������鼮!\n���������������\n");
						getch();
						system("cls");
						break;
					}
				}
				break;
			case 2:
				exit = 1;
				break;
			default:    //��������
				printf("Invalid choice!\n");
				break;
			}
		}
		else {
			printf("���벻�淶��\n���������������\n");
			getch();
		}
		if (exit == 1) {
			break;
		}
	}
	system("cls");
} 
//���麯��															     Ŀǰ��Ҫд�ĺ���
void returnBooks(User &user,SqListBook &books) {
	if (user.lendNumber == 0) {
		cout << "��������Ϊ0�����軹�飡����\n��������˳�����" << endl;
		getch();
		return;
	}
	char returnISBN[MAX_ISBN], ch;
	int choice, exit = 0;
	int length = books.length;
	while (1) {
		cout << "1������ISBN����\n2���˳�\n���������ѡ��" << endl;
		cin >> choice;
		ch = getchar();
		if (ch == '\n') {
			switch (choice)
			{
			case 1:    //�����鼮���뻹��
				printf("�������鼮��13λ���룺");
				scanf("%s", returnISBN);
				if (strlen(returnISBN) != 13) {     //�ж�������鼮����λ�������
					printf("�鼮������󣡣���\n���������������\n");
					getch();
					system("cls");
					break;
				}
				for (int i = 0; i < length; i++) {      //�����鼮�����������ƥ���Ӧ�鼮
					if (strcmp(books.elem[i].ISBN, returnISBN) == 0) {
						--user.lendNumber;
						++books.elem[i].inventory;
						printf("\n�ɹ�����\n���������������\n");
						getch();
						system("cls");
						break;
					}
					if (i == length - 1) {     //û���ҵ���Ӧ�鼮
						printf("\n�����û��ָ��������鼮!\n���������������\n");
						getch();
						system("cls");
						break;
					}
				}
				break;
			case 2:
				exit = 1;
				break;
			default:    //��������
				printf("Invalid choice!\n");
				break;
			}
		}
		else {
			printf("���벻�淶��\n���������������\n");
			getch();
		}
		if (exit == 1) {
			break;
		}
	}
	system("cls");
}
void deleteBooks(SqListBook &books) {
    char deleteISBN[MAX_ISBN],ch;
    char deleteauth[MAX_AUTH_NAME];
    int choice,exit = 0;
    int length = books.length;
    while(1){
    	printf("1������ISBNɾ���鼮\n2����������ɾ���鼮\n3���������˵�\n���������ѡ��");
    	cin >> choice;
    	ch = getchar();
    	if(ch == '\n'){
    		switch (choice)
    		{
    		case 1:    //�����鼮����ɾ���鼮
        		printf("������ɾ���鼮��13λ�鼮���룺");
        		scanf("%s", deleteISBN);
        		if (strlen(deleteISBN) != 13) {     //�ж�������鼮����λ�������
            		printf("�鼮������󣡣���\n���������������\n");
            		getch();
            		system("cls");
            		break;
        		}
        		for (int i = 0; i < length; i++) {      //�����鼮�����������ƥ���Ӧ�鼮
            		if (strcmp(books.elem[i].ISBN, deleteISBN) == 0) {
                		if (i == length - 1) --books.length;
                		else {
                    		while (1) {    //ɾ����Ӧ�鼮����ǰ�ƶ�
                        		strcpy(books.elem[i].ISBN, books.elem[i + 1].ISBN);
                        		strcpy(books.elem[i].name, books.elem[i + 1].name);
                        		strcpy(books.elem[i].auth, books.elem[i + 1].auth);
                        		books.elem[i].price = books.elem[i + 1].price;
                        		books.elem[i].inventory = books.elem[i + 1].inventory;
                        		++i;
                        		if (i == books.length - 1) {
                            		--books.length;
                            		break;
                        		}
                    		}
                		}
                		printf("\n�ɹ�ɾ��ָ���鼮\n���������������\n");
                		getch();
                		system("cls");
                		break;
            		}
            		if (i == length - 1) {     //û���ҵ���Ӧ�鼮
                		printf("\n�����û��ָ��������鼮!\n���������������\n");
                		getch();
                		system("cls");
                		break;
            		}
        		}
        		break;
    		case 2:   //��������ɾ���鼮
        		printf("������ɾ���鼮������������");
        		scanf("%s", deleteauth);
        		for (int i = 0; i < length; i++) {      //�������ƥ����������
            		if (strcmp(books.elem[i].auth, deleteauth) == 0) {   //ƥ��ɹ�
                		if (i == length - 1) --books.length;
                		else {
                    		while (1) {    //ɾ����Ӧ�鼮
                        		strcpy(books.elem[i].ISBN, books.elem[i + 1].ISBN);
                        		strcpy(books.elem[i].name, books.elem[i + 1].name);
                        		strcpy(books.elem[i].auth, books.elem[i + 1].auth);
                        		books.elem[i].price = books.elem[i + 1].price;
                        		books.elem[i].inventory = books.elem[i + 1].inventory;
                        		++i;
                        		if (i == books.length - 1) {
                            		--books.length;
                            		break;
                        		}
                    		}
                		}
                		printf("\n�ɹ�ɾ��ָ���鼮\n���������������\n");
                		getch();
                		system("cls");
                		break;
            		}
            		if (i == length - 1) {
                		printf("\n�����û��ָ�����ߵ��鼮!\n���������������\n");
                		getch();
                		system("cls");
                		break;
            		}
        		}
        		break;
        	case 3:
        		exit = 1;
        		break;
    		default:    //��������
        		printf("Invalid choice!\n");
        		break;
    		}
		}
		else{
			printf("���벻�淶��\n���������������\n");
			getch(); 
		}
		if(exit == 1){
			break;
		}
	}
    system("cls");
}

void deduplication(SqListBook &books) {
        for (int i = 0; i < books.length; i++) {
            for (int j = i + 1; j < books.length; j++) {
                if (strcmp(books.elem[i].ISBN, books.elem[j].ISBN) == 0) {
                	books.elem[i].inventory += books.elem[j].inventory;
                    // �ҵ��ظ����鼮����������鼮��ǰ�ƶ������ظ���λ��
                    for (int k = j; k < books.length - 1; k++) {
                        books.elem[k] = books.elem[k + 1];
                    }
                    books.length--; // �����鼮����
                    j--; // �����ڵ�ǰλ�ü���Ƿ��������ظ����鼮
                }
            }
        }
        printf("ȥ���ɹ�\n\������������......\n");
        getch();
    
}
//�˳�����������user��users�ҽ�users������д���ļ��У����Բο�writeBooks����       Ŀǰ��Ҫд�ĺ���
void writeUsers(SqListUser &users,User &user) {	
	for(int i=0;i<users.length;i++)
	{
		if(!strcmp(user.account,users.elem[i].account))
		{
			users.elem[i].lendNumber=user.lendNumber;
			strcpy(users.elem[i].ISBNS,user.ISBNS);
			break;
		}
	}	
	FILE *file = fopen("user.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file,"%d\n",users.length);
	for(int i=0;i<users.length;i++) 
	{
		fprintf(file,"%s %s %s %d\n", users.elem[i].account, users.elem[i].accountNume,users.elem[i].role,users.elem[i].lendNumber);
		char ISBN[14];
		ISBN[13]='\0';
		int count=0;
		for(int j=0;j<users.elem[i].lendNumber;j++)
		{
			for(int b=0;b < 13;b++)
					{
							ISBN[b]=users.elem[i].ISBNS[b+13*j];
							count+=1;
				    }
			if(count==13)
			{
				fprintf(file,"%s \n",ISBN);
				count=0;
			}
		}
	}

    fclose(file);		

}
 //Function to write books to file  
void writeBooks(Book books[], int count)
{
    FILE *file = fopen("books.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s %s %s %.2f %d\n", books[i].ISBN, books[i].name,books[i].auth, books[i].price,books[i].inventory);
    }

    fclose(file);
}
//����Ա�˵� 
void displayAdminMenu(SqListBook &books,SqListUser &users,User user){
	 while (1)
        {
            printf("Welcome!\n");
            char choice;
            cout<<"(1) �����鼮��Ϣ��\n\
(2)����鼮��\n\
(3)ɾ�������鼮��\n\
(4)�޸�ָ���鼮��Ϣ��\n\
(5)ȥ���ظ���Ϣ��\n\
(6)�˳�ϵͳ��\n\ 
(7)�鿴������Ϣ\n\ 
.....\n\
���������ѡ��(1-6):"<<endl;
            printf("Enter your choice: ");
            cin >> choice;
            char ch = getchar();
            if(ch == '\n'){
            	switch (choice)
            	{
            	case '1':	            //�����鼮���� 
            		system("cls");
                	searchBooks(books);
					break;
            	case '2':            	//����鼮���� 
            		system("cls");
            		addBooks(books);
					break;
            	case '3':
            		system("cls");
            		deleteBooks(books);
            		
            	//ɾ���鼮���� 
            		break;
            	case '4':
            		system("cls");
            		Modifying_Book_Information(books); 
            	//�޸��鼮��Ϣ���� 
                	printf("Exiting...\n");
                	break;
            	case '5':
				//ȥ���ظ���Ϣ 
					deduplication(books); 
            		system("cls");
					break;
				case '6'://�˳� 
					writeUsers(users,user);
					writeBooks(books.elem,books.length);
			    	exit(0);	 
            	default:
                	printf("Invalid choice!\n");
                	getch();
                	break;
            	}
        	}
        	else{
        		printf("Invalid choice!\n");
        		printf("���һ�¼���......\n");
        		system("cls");
        		getch();
			}
        }
}
//ѧ���˵�                                                                ȱ��һЩ���� 
void displayStudentMenu(SqListUser &users,User &user,SqListBook &books){//ֻ��Ҫ�Զ���������һ���ṹ���Լ�ͼ�������������ʹ�ú������ƻ�users˳����� 
	
	int choice,count = 0;
	char searchISBN[14];
	searchISBN[13] = '\0'; 
	while(1){
		printf("�����鼮��Ϣ����:"); 
		printf("\n�鼮���	����		����	�۸�\n");
		for(int i = 0;i < user.lendNumber * 13;i++) {
			searchISBN[count] =  user.ISBNS[i];
			if(count == 12){
				searchBook(books,searchISBN);
				count = 0;
				continue; 
			}
			count++;
		}
		//��һЩ���룬�����������Ϣ 
		cout<<"(1)���飻\n\
(2)���飻\n\
(3)����\n\ 
(4)�˳�\n\ 
.....\n\
���������ѡ��(1-2):"<<endl;
		cin >> choice;
		char ch = getchar();
		if(ch == '\n'){
			switch(choice)
			{
			case 1:
				lendBooks(user,books);
				break;
			case 2:
				returnBooks(user,books);
				
				system("cls") ;
				break;
			case 3:
				//���麯������֮ǰ�Ѿ�д�ú������ɣ�������д�� 
				break;
			case 4:
				//�˳�������
				writeUsers(users,user); 
				exit(0);
				break;
			default:
				printf("���벻���Ϲ淶��\n������������\n");
				getch();
				system("cls");
				break;
			}
		} 
		else{
			printf("���벻���Ϲ淶��\n������������\n");
			getch();
			system("cls");
		}
	}
}


int main(){
	SqListBook books;
	SqListUser users;
	User user;
	initSqListUsers(users);
	initSqListBooks(books);
	char choice; 
    books.length = readBooks(books.elem);//�鼮��Ϣ����ṹ�� 
	while(1){
		int role = 2;
		cout<<"(1) ��¼��\n\
(2)ע�᣻\n\
(3)�˳�\n\ 
.....\n\
���������ѡ��(1-2):"<<endl;
		cin >> choice;
		char ch = getchar();
		if(ch == '\n'){
			switch(choice)
			{
			case '1':
				role = logOn(users,user);
				system("cls"); 
				//��¼�����������û������룬�˻����ж��Ƿ���ȷ���˺Ų�������������ͬʱͨ����ɫ��һ�����жϸý����ĸ����淵��1��admin����0��ѧ���� 
				break;
			case '2':
				role = logist(users,user);
				system("cls");
				break;
			case '3':
				//�˳��������� 
				 exit(0);
			default:
				printf("û���������ѡ��Ŷ��\n������������......\n") ;
				getch();
				system("cls");
				break;
			}
		} 
		if(role == 1) {
			displayAdminMenu(books,users,user); 
		}
		if(role == 0) {
			displayStudentMenu(users,user,books);
		}
	}
    
    return 0;
}




