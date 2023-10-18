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
    int inventory; // 库存数量
} Book;
typedef struct {
    Book *elem;             //存储空间基址
    int length;             //当前顺序表中实际元素的个数
    int listsize;               //当前分配的存储容量
} SqListBook;
typedef struct
{
    char account[Max_ACCOUNT + 1];
    char accountNume[Max_ACCOUNT_NUME + 1];
    char role[MAX_ROLE + 1];
    int lendNumber; // 借书数量 （一个人最多借五本书）
    char ISBNS[66];
} User;
typedef struct
{
	User *elem;             //存储空间基址
    int length;             //当前顺序表中实际元素的个数
    int listsize;
}SqListUser;
//顺序表初始化 
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
//登陆函数
int logOn(SqListUser &users,User &user){
	while(1){
		int a = 1;
		char userAccount[2000],userAccountNume[2000],admin[6] = "admin";
		printf("请输入您的账号(<=11位)：");
		scanf("%s",userAccount);
		if(strlen(userAccount) > 11){
			printf("\n账号不符合规范！\n点击任意键继续......\n");
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
    	int b = 0;   //当b=1时表示该账号存在 
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
				printf("\n不存在该账户！\n点击任意键继续......\n");
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
			printf("\n请输入您的密码(11位)：");
			scanf("%s",userAccountNume);
			if(strlen(userAccountNume) != 11){
				printf("\密码不符合规范！\n点击任意键继续......\n");
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
				printf("密码错误！");
				getch();
				system("cls");
				continue;
			}
		}
	}
}
//注册函数															       目前需要写的函数
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
		printf("请输入您的账号(<=11位)：");
		scanf("%s",userAccount);
		if(strlen(userAccount) > 11){
			printf("\n账号不符合规范！\n点击任意键继续......\n");
			getch();
			system("cls");
			continue;
		}
		int c = 0;
		for(int i = 0;i < count;i++){
			if(strcmp(userAccount,users.elem[i].account) == 0){
				printf("\n账号名已重复\n点击任意键继续......\n");
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
		printf("\n请输入您的密码(11位)：");
		scanf("%s",userAccountNume);
		if(strlen(userAccountNume) != 11){
			printf("\n密码不符合规范！\n点击任意键继续......\n");
			getch();
			system("cls");
			continue;
		}
		strcpy(user.accountNume,userAccountNume);
		break;
	}
	while(1){
		printf("\n请输入您的身份(admin or student)：");
		scanf("%s",role) ;
		if(strcmp(role,"admin") != 0 && strcmp(role,"student") != 0){
			printf("请输入合理的身份！\n点击任意键继续......\n");
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

	//调用退出函数将代数据入文件 
	if(strcmp("admin",role) == 0){
		
		return 1;
	}
	if(strcmp("student",role) == 0){
		return 0; 
	} 
}
 
//从文件中读入书籍信息
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
//查找书籍函数 
void searchBooks(SqListBook &books){
	int a = 0;
	while(1){
		char choices;
		cout <<"(1)按照国际标准书籍编码查书\n\
(2)按照书籍名称查找书籍\n\
(3)按照作者名称查找书籍\n\
(4)返回主菜单\n\ 
.......\n\
请输入你的选择(1-4):"<< endl;
		cin >> choices;
		char ch = getchar();
		if(ch == '\n'){
			switch(choices){
			case '1':
				char searchISBN[2000];
				while(1){
					int c = 0;
					printf("请输入查找书籍的13位书籍编号：");
    				scanf("%s",searchISBN);
    				if(strlen(searchISBN)!=13){
    					printf("输入不规范\n");
    					continue;
					}
					for(int j = 0;j < 13;j++){
						if(searchISBN[j] < '0' || searchISBN[j] > '9'){
							c = 1;
							break;
						}
					}
					if(c == 1){
						printf("输入不规范\n");
    					continue;
					}
					break;
    			}
				for(int i = 0; i < books.length; i++){
					if(strcmp(searchISBN,books.elem[i].ISBN) == 0)
					{
						printf("\n书籍编号	书名	作者	价格		库存\n");
    					printf("\n%s	%s	%s	%f	%d\n", books.elem[i].ISBN, books.elem[i].name,books.elem[i].auth, books.elem[i].price, books.elem[i].inventory);
						printf("点击任意键继续......\n");
						getch();
						system("cls");
						break;
					}
					if(i == books.length - 1){
						printf("\n没有你查找的书籍哦!\n"); 
						printf("点击任意键继续......\n");
						getch();
						system("cls");
					}
				}
				break;
			case '2':
				char searchname[2000];
				while(1){
					printf("请输入查找书籍的书籍名称：");
    				scanf("%s",searchname);
    				if(strlen(searchname) > 20){
    					printf("输入不规范\n");
    					continue;
					}
					break;
    			}
				for(int i = 0; i < books.length; i++){
					if(strcmp(searchname,books.elem[i].name) == 0)
					{
						printf("\n书籍编号	书名	作者	价格		库存\n");
    					printf("\n%s	%s	%s	%f	%d\n", books.elem[i].ISBN, books.elem[i].name,books.elem[i].auth, books.elem[i].price, books.elem[i].inventory);
						printf("点击任意键继续......\n");
						getch();
						system("cls");
						break;
					}
					if(i == books.length - 1){
						printf("\n没有你查找的书籍哦!\n"); 
						printf("点击任意键继续......\n");
						getch();
						system("cls");
					}
				}
				break;
			case '3':
				char searchauth[2000];
				while(1){
					printf("请输入查找书籍的作者名称：");
    				scanf("%s",searchauth);
    				if(strlen(searchauth) > 10){
    					printf("输入不规范\n");
    					continue;
					}
					break;
    			}
				for(int i = 0; i < books.length; i++){
					if(strcmp(searchauth,books.elem[i].auth) == 0)
					{
						printf("\n书籍编号	书名	作者	价格		库存\n");
    					printf("\n%s	%s	%s	%f	%d\n", books.elem[i].ISBN, books.elem[i].name,books.elem[i].auth, books.elem[i].price, books.elem[i].inventory);
						printf("点击任意键继续......\n");
						getch();
						system("cls");
						break;
					}
					if(i == books.length - 1){
						printf("\n没有你查找的书籍哦!\n"); 
						printf("点击任意键继续......\n");
						getch();
						system("cls");
					}
				}
				break;
			case '4':
				a = 1;
				break;
			default:
				printf("输入不符合规范规范！\n点击任意键继续\n");
				getch();
				system("cls");
				break;
			}
		}
		else
		{
			printf("输入不符合规范！\点击任意键继续\n");
			getch();
			system("cls");
		}
		if(a == 1){
			break;
			system("cls");
		}
	}
}
//输出借用书籍信息 
void searchBook(SqListBook &books,char searchISBN[14]){
	for(int i = 0; i < books.length; i++){
		if(strcmp(searchISBN,books.elem[i].ISBN) == 0)
		{
    		printf("\n%s	%s	%s	%f\n", books.elem[i].ISBN, books.elem[i].name,books.elem[i].auth, books.elem[i].price);
			break;
		}
		if(i == books.length - 1){
			printf("\n没有你查找的书籍哦!\n");
		}
	}
}

void addBooks(SqListBook &books){
	//要不要判断原来有没有相同书籍 ?
	int q = 1;
	while(q){
		char auth[100];//
		printf("\n请输入作者名(<=10)：");
		scanf("%s",auth);
		if(strlen(auth) > 10){
			printf("输入不符合规范！\n");
			getch();
			continue;
		}
		strcpy(books.elem[books.length].auth,auth);
		break;
	}
		
	while(q){ 
		int a = 0;
		char ISBN[100];
		printf("\n请输入13位国际书籍标准编码:");
		scanf("%s",ISBN);
		if(strlen(ISBN) > 13){
			printf("输入不符合规范！\n");
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
			printf("输入不符合规范！\n");
			getch();
			continue;
		}
		strcpy(books.elem[books.length].ISBN,ISBN);
		break;
	}
	
	while(q){
		char name[100];
		printf("\n请输入书名(<=20)：");
		scanf("%s",name);
		if(strlen(name) > 20){
			printf("输入不符合规范！\n");
			getch();
			continue;
		}
		strcpy(books.elem[books.length].name,name);
		break;
	}
	
	printf("\n请输入价格：");
	scanf("%f",&books.elem[books.length].price);
	
	while(q){
	    char inventory[10];
	    int b = 0;
		printf("\n请输入库存：");
		scanf("%s",inventory);
		for(int i = 0;i < strlen(inventory);i++){
			if(inventory[i] < '0' || inventory[i] > '9'){
				b = 1;
				break;
			}
		}
		if(b == 1){
			printf("输入不符合规范！\n");
			getch();
			continue;
		}
		books.elem[books.length].inventory = atoi(inventory);
		break;
	}
	books.length += 1;
	system("cls");
	
}

void Modifying_Book_Information(SqListBook &books)//修改图书信息的函数 
{
	printf("请输入要修改信息的书籍名(<20):");
	char modifying_books[21];
	scanf("%s",modifying_books);
	int i;	//要改的书的下标
	int count=0;//0找到1找不到 
	for(i=0;i<books.length;i++) //找到该书，并得到该书地址 
	{
		if(!strcmp(books.elem[i].name,modifying_books))break; 
		if(i==books.length-1)
		{
			printf("找不到该书");
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
      		cout<<"\n	1:改ISBN\n\
      		2：改书名；\n\
      		3：改作者名；\n\
      		4：改价格；\n\
      		5：改库存；\n\
      		6：退出；\n\
      		输入你的选择(1-6):"<<endl;
      		char q;
      		scanf("%c",&q);//用户输入的选择 
      		Book correct_books;//用来储存用户输入的信息 
      		char c = getchar();
      		if(c == '\n'){
      			switch(q)
      			{
      				case '1':
      					printf("输入书籍的ISBN;");
						scanf("%s",correct_books.ISBN);
						if(sizeof(correct_books.ISBN)!=13)
						{
							break;
						}
						strcpy(books.elem[i].ISBN,correct_books.ISBN);
						break; 
	  				case '2':
	  					printf("输入书籍的书名;");
						scanf("%s",correct_books.name);
						strcpy(books.elem[i].name,correct_books.name);
						break;   
	  				case '3':
	  					printf("输入书籍的作者名;");
						scanf("%s",correct_books.auth);
						strcpy(books.elem[i].auth,correct_books.auth);
						break;  
	  				case '4':
	  					printf("输入书籍的价格;");
						scanf("%f",&correct_books.price);
						if(correct_books.price<0)
						{
							printf("输入错误"); 
							break;
						}
						books.elem[i].price=correct_books.price;
						break;    
	  				case '5': 
	  					printf("输入书籍的库存;");
						scanf("%d",&correct_books.inventory);
						if(correct_books.inventory<0)
						{
							printf("输入错误"); 
							break;
						}
						books.elem[i].inventory=correct_books.inventory;
						break;
					case '6':
						break;
					default :
						printf("输入有误，请重新输入；");
						getch();
						break; 
				}
	   		if(q==6)break;//退出到主页面 
	   		system("cls");	
		}
		else{
			printf("输入有误，请重新输入；\n点击任意键继续\n");
			getch();
			system("cls");
		}
		
	}
	system("cls");
      
	} 
}
//借书函数                                                                目前需要写的函数 
void lendBooks(User &user,SqListBook &books){
	if (user.lendNumber == 5) {
		cout << "借书数量已达极限，无法继续借书，请先归还已借书籍！！！\n按任意键退出……" << endl;
		getch();
		return;
	}
	char lendISBN[MAX_ISBN], ch;
	int choice, exit = 0;
	int length = books.length;
	while (1) {
		cout << "1、输入ISBN借书\n2、退出\n请输入你的选择：" << endl;
		cin >> choice;
		ch = getchar();
		if (ch == '\n') {
			switch (choice)
			{
			case 1:    //根据书籍编码借书
				printf("请输入书籍的13位编码：");
				scanf("%s", lendISBN);
				if (strlen(lendISBN) != 13) {     //判断输入的书籍编码位数多或少
					printf("书籍编码错误！！！\n按任意键继续……\n");
					getch();
					system("cls");
					break;
				}
				for (int i = 0; i < length; i++) {      //根据书籍编码在书库中匹配对应书籍
					if (strcmp(books.elem[i].ISBN, lendISBN) == 0) {
						if (books.elem[i].inventory == 0) { 
							cout << "该书籍库存为0，无法借书，待归还……\n按任意键继续……\n" << endl; 
							break;
						}
						for (int m = 0; m < 13; m++) user.ISBNS[user.lendNumber * 13 + m] = lendISBN[m];
						++user.lendNumber;
						--books.elem[i].inventory;
						printf("\n成功借书\n按任意键继续……\n");
						getch();
						system("cls");
						break;
					}
					if (i == length - 1) {     //没有找到对应书籍
						printf("\n书库中没有指定编码的书籍!\n按任意键继续……\n");
						getch();
						system("cls");
						break;
					}
				}
				break;
			case 2:
				exit = 1;
				break;
			default:    //错误输入
				printf("Invalid choice!\n");
				break;
			}
		}
		else {
			printf("输入不规范！\n按任意键继续……\n");
			getch();
		}
		if (exit == 1) {
			break;
		}
	}
	system("cls");
} 
//还书函数															     目前需要写的函数
void returnBooks(User &user,SqListBook &books) {
	if (user.lendNumber == 0) {
		cout << "借书数量为0，无需还书！！！\n按任意键退出……" << endl;
		getch();
		return;
	}
	char returnISBN[MAX_ISBN], ch;
	int choice, exit = 0;
	int length = books.length;
	while (1) {
		cout << "1、输入ISBN还书\n2、退出\n请输入你的选择：" << endl;
		cin >> choice;
		ch = getchar();
		if (ch == '\n') {
			switch (choice)
			{
			case 1:    //根据书籍编码还书
				printf("请输入书籍的13位编码：");
				scanf("%s", returnISBN);
				if (strlen(returnISBN) != 13) {     //判断输入的书籍编码位数多或少
					printf("书籍编码错误！！！\n按任意键继续……\n");
					getch();
					system("cls");
					break;
				}
				for (int i = 0; i < length; i++) {      //根据书籍编码在书库中匹配对应书籍
					if (strcmp(books.elem[i].ISBN, returnISBN) == 0) {
						--user.lendNumber;
						++books.elem[i].inventory;
						printf("\n成功还书\n按任意键继续……\n");
						getch();
						system("cls");
						break;
					}
					if (i == length - 1) {     //没有找到对应书籍
						printf("\n书库中没有指定编码的书籍!\n按任意键继续……\n");
						getch();
						system("cls");
						break;
					}
				}
				break;
			case 2:
				exit = 1;
				break;
			default:    //错误输入
				printf("Invalid choice!\n");
				break;
			}
		}
		else {
			printf("输入不规范！\n按任意键继续……\n");
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
    	printf("1、根据ISBN删除书籍\n2、根据作者删除书籍\n3、返回主菜单\n请输入你的选择：");
    	cin >> choice;
    	ch = getchar();
    	if(ch == '\n'){
    		switch (choice)
    		{
    		case 1:    //根据书籍编码删除书籍
        		printf("请输入删除书籍的13位书籍编码：");
        		scanf("%s", deleteISBN);
        		if (strlen(deleteISBN) != 13) {     //判断输入的书籍编码位数多或少
            		printf("书籍编码错误！！！\n按任意键继续……\n");
            		getch();
            		system("cls");
            		break;
        		}
        		for (int i = 0; i < length; i++) {      //根据书籍编码在书库中匹配对应书籍
            		if (strcmp(books.elem[i].ISBN, deleteISBN) == 0) {
                		if (i == length - 1) --books.length;
                		else {
                    		while (1) {    //删除对应书籍，向前移动
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
                		printf("\n成功删除指定书籍\n按任意键继续……\n");
                		getch();
                		system("cls");
                		break;
            		}
            		if (i == length - 1) {     //没有找到对应书籍
                		printf("\n书库中没有指定编码的书籍!\n按任意键继续……\n");
                		getch();
                		system("cls");
                		break;
            		}
        		}
        		break;
    		case 2:   //根据作者删除书籍
        		printf("请输入删除书籍的作者姓名：");
        		scanf("%s", deleteauth);
        		for (int i = 0; i < length; i++) {      //在书库中匹配作者姓名
            		if (strcmp(books.elem[i].auth, deleteauth) == 0) {   //匹配成功
                		if (i == length - 1) --books.length;
                		else {
                    		while (1) {    //删除对应书籍
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
                		printf("\n成功删除指定书籍\n按任意键继续……\n");
                		getch();
                		system("cls");
                		break;
            		}
            		if (i == length - 1) {
                		printf("\n书库中没有指定作者的书籍!\n按任意键继续……\n");
                		getch();
                		system("cls");
                		break;
            		}
        		}
        		break;
        	case 3:
        		exit = 1;
        		break;
    		default:    //错误输入
        		printf("Invalid choice!\n");
        		break;
    		}
		}
		else{
			printf("输入不规范！\n按任意键继续……\n");
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
                    // 找到重复的书籍，将后面的书籍向前移动覆盖重复的位置
                    for (int k = j; k < books.length - 1; k++) {
                        books.elem[k] = books.elem[k + 1];
                    }
                    books.length--; // 更新书籍数量
                    j--; // 继续在当前位置检查是否还有其他重复的书籍
                }
            }
        }
        printf("去除成功\n\点击任意键继续......\n");
        getch();
    
}
//退出函数：复制user到users且将users中数据写道文件中，可以参考writeBooks函数       目前需要写的函数
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
//管理员菜单 
void displayAdminMenu(SqListBook &books,SqListUser &users,User user){
	 while (1)
        {
            printf("Welcome!\n");
            char choice;
            cout<<"(1) 查找书籍信息；\n\
(2)添加书籍；\n\
(3)删除部分书籍；\n\
(4)修改指定书籍信息；\n\
(5)去除重复信息；\n\
(6)退出系统；\n\ 
(7)查看借书信息\n\ 
.....\n\
请输入你的选择(1-6):"<<endl;
            printf("Enter your choice: ");
            cin >> choice;
            char ch = getchar();
            if(ch == '\n'){
            	switch (choice)
            	{
            	case '1':	            //查找书籍函数 
            		system("cls");
                	searchBooks(books);
					break;
            	case '2':            	//添加书籍函数 
            		system("cls");
            		addBooks(books);
					break;
            	case '3':
            		system("cls");
            		deleteBooks(books);
            		
            	//删除书籍函数 
            		break;
            	case '4':
            		system("cls");
            		Modifying_Book_Information(books); 
            	//修改书籍信息函数 
                	printf("Exiting...\n");
                	break;
            	case '5':
				//去除重复信息 
					deduplication(books); 
            		system("cls");
					break;
				case '6'://退出 
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
        		printf("点击一下继续......\n");
        		system("cls");
        		getch();
			}
        }
}
//学生菜单                                                                缺少一些函数 
void displayStudentMenu(SqListUser &users,User &user,SqListBook &books){//只需要对独立出来的一个结构体以及图书操作，后续会使用函数复制回users顺序表中 
	
	int choice,count = 0;
	char searchISBN[14];
	searchISBN[13] = '\0'; 
	while(1){
		printf("借用书籍信息如下:"); 
		printf("\n书籍编号	书名		作者	价格\n");
		for(int i = 0;i < user.lendNumber * 13;i++) {
			searchISBN[count] =  user.ISBNS[i];
			if(count == 12){
				searchBook(books,searchISBN);
				count = 0;
				continue; 
			}
			count++;
		}
		//差一些代码，，输出借书信息 
		cout<<"(1)借书；\n\
(2)还书；\n\
(3)查书\n\ 
(4)退出\n\ 
.....\n\
请输入你的选择(1-2):"<<endl;
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
				//查书函数，用之前已经写得函数即可，不用再写； 
				break;
			case 4:
				//退出函数：
				writeUsers(users,user); 
				exit(0);
				break;
			default:
				printf("输入不符合规范！\n点击任意键继续\n");
				getch();
				system("cls");
				break;
			}
		} 
		else{
			printf("输入不符合规范！\n点击任意键继续\n");
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
    books.length = readBooks(books.elem);//书籍信息读入结构体 
	while(1){
		int role = 2;
		cout<<"(1) 登录；\n\
(2)注册；\n\
(3)退出\n\ 
.....\n\
请输入你的选择(1-2):"<<endl;
		cin >> choice;
		char ch = getchar();
		if(ch == '\n'){
			switch(choice)
			{
			case '1':
				role = logOn(users,user);
				system("cls"); 
				//登录函数：接收用户的密码，账户并判断是否正确（账号不允许重名），同时通过角色这一属性判断该进入哪个界面返回1（admin），0（学生） 
				break;
			case '2':
				role = logist(users,user);
				system("cls");
				break;
			case '3':
				//退出，无作用 
				 exit(0);
			default:
				printf("没有您输入的选择哦！\n点击任意键继续......\n") ;
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




