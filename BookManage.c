#include "BookManage.h"

void ShowMainMenu()
{
	system("cls");/*清屏函数*/
	printf("	|----------------------欢迎进入---------------------------|\n");
	printf("	|                   图书馆管理系统                        |\n");
	printf("	|                       主菜单                            |\n");
	printf("	|                   1、图书管理                           |\n");
	printf("	|                   2、读者管理                           |\n");
	printf("	|                   3、借/还书登记                        |\n");
	printf("	|                   0、退出系统                           |\n");
	printf("	|---------------------------------------------------------|\n");
	printf("\n");
	printf("		请选择（0-3）：");
}

void ShowBookMenu()
{
	system("cls");
	printf("	|----------------------欢迎进入---------------------------|\n");
	printf("	|                    图书管理系统                         |\n");
	printf("	|                       子菜单                            |\n");
	printf("	|                  1、显示图书信息                        |\n");
	printf("	|                  2、新增图书信息                        |\n");
	printf("	|                  3、图书信息查询                        |\n");
	printf("	|                  4、图书信息删除                        |\n");
	printf("	|                  5、图书信息修改                        |\n");
	printf("	|                  0、返回主菜单                          |\n");
	printf("	|---------------------------------------------------------|\n");
	printf("\n");
	printf("		请选择（0-5）：");
}

void ShowReaderMenu()
{
	system("cls");
	printf("	|----------------------欢迎进入---------------------------|\n");
	printf("	|                    读者管理系统                         |\n");
	printf("	|                       子菜单                            |\n");
	printf("	|                  1、显示读者信息                        |\n");
	printf("	|                  2、新增读者信息                        |\n");
	printf("	|                  3、读者信息查询                        |\n");
	printf("	|                  4、读者信息删除                        |\n");
	printf("	|                  5、读者信息修改                        |\n");
	printf("	|                  0、返回主菜单                          |\n");
	printf("	|---------------------------------------------------------|\n");
	printf("\n");
	printf("		请选择（0-5）：");
}

void ShowBorrowReturnMenu()
{
	system("cls");
	printf("	|----------------------欢迎进入---------------------------|\n");
	printf("	|                    借/还书登记                          |\n");
	printf("	|                       子菜单                            |\n");
	printf("	|                    1、借书登记                          |\n");
	printf("	|                    2、还书登记                          |\n");
	printf("	|                   0、返回主菜单                         |\n");
	printf("	|---------------------------------------------------------|\n");
	printf("\n");
	printf("		请选择（0-2）：");
}

void ShowModifyBookMenu()
{
	printf("\n");
	printf("	|                  1、编号                        |\n");
	printf("	|                  2、书名                        |\n");
	printf("	|                  3、作者                        |\n");
	printf("	|                  4、出版社                      |\n");
	printf("	|                  5、库存                        |\n");
	printf("\n");
	printf("请输入所要修改的信息(键入相应的数字:1-5 ):");

}

void ShowModifyReaderMenu()
{
	printf("\n");
	printf("	|                  1、编号                        |\n");
	printf("	|                  2、名字                        |\n");
	printf("	|                  3、性别                        |\n");
	printf("	|                  4、最大可借书数                |\n");
	printf("\n");
	printf("请输入所要修改的信息(键入相应的数字:1-4 )\n");
}

/*==============================图书管理相关函数============================*/
/*分别读取图书和读者信息转存至astBook和astReader数组中*/
int ReadBookFile(char pcMode)
{
	int iBookRecord = 0;
	FILE* pfBook;   /*文件指针*/

	pfBook = fopen("book.txt", pcMode);
	if (pfBook == NULL)
		return -1;
	while (!feof(pfBook))
	{
		if (fread(&astBook[iBookRecord], LEN_BOOK, 1, pfBook)==1)
			iBookRecord++;
	}
	fclose(pfBook);
	return iBookRecord;
}

int ReadReaderFile(char pcMode)
{
	int iReaderRecord = 0;
	FILE* pfReader;
	pfReader = fopen("reader.txt", pcMode);
	if (pfReader == NULL)
		return -1;
	while (!feof(pfReader))
	{
		if (fread(&astReader[iReaderRecord], LEN_READER, 1, pfReader)==1)
			iReaderRecord++;
	}
	fclose(pfReader);
	return iReaderRecord;
}

void SaveBookFile(int iBookId)
{
	FILE* pfBook;
	/*读写方式打开文件，文件必须已经存在，指针指向文件首部，wb会删掉原有文件，ab指针指向文件尾部*/
	pfBook = fopen("book.txt", "rb+");
	if (pfBook != NULL)
	{
		fseek(pfBook, LEN_BOOK * iBookId, SEEK_SET);
		if (fwrite(&astBook[iBookId], LEN_BOOK, 1, pfBook) != 1)
			printf("无法保存该信息！\n");
	}
	fclose(pfBook);
}		

void SaveReaderFile(int iReaderId)
{
	FILE* pfReader;
	pfReader = fopen("reader.txt", "rb+");
	if (pfReader != NULL)
	{
		fseek(pfReader, LEN_READER * iReaderId, SEEK_SET);
		if (fwrite(&astReader[iReaderId], LEN_READER, 1, pfReader) != 1)
			printf("无法保存该信息！\n");
		fclose(pfReader);
	}	
	fclose(pfReader);
}


/*显示图书函数*/
void ShowBook()
{
	int i, iBookRecord;/*整型变量，i用以循环计数，iBookRecord用以计量图书的条数*/

	system("cls");

	iBookRecord = ReadBookFile("rb");
	if (iBookRecord == -1)
		printf("文件打开失败！请先新增加图书信息！\n");
	else if (iBookRecord == 0)
		printf("文件中没有图书信息！\n");
	else
	{
		printf("	|---------------------------------------------------------|\n");
		printf("	  %-6s%-16s%-10s%-20s%-4s\n", "编号", "书名", "作者", "出版社", "库存");
		for (i = 0; i < iBookRecord; i++)/*显示图书信息*/
			printf("	  %-6d%-16s%-10s%-20s%-4d\n", BOOK_DATA);
		printf("	|---------------------------------------------------------|\n");
	}
}

void AddBook()
{
	FILE* pfBook;/*文件指针*/
	int iBookRecord, iFlagExist, i;
	char cFlag;

	system("cls");

	iBookRecord = ReadBookFile("ab+");  /*ab+追加方式打开或新建二进制文件*/
	if (iBookRecord == -1)
	{
		printf("文件打开失败！\n");
		return;
	}
	else if (iBookRecord == 0)
		printf("没有图书记录！\n");
	else
		ShowBook();/*如果图书记录不为零则调用showBook显示所有图书*/

	/*以下代码为循环录入图书信息*/
	printf("请选择是否键入信息（y/n）：");
	cFlag = getchar();
	getchar();
	if (cFlag == 'n')
		return;
	/*键入'y'则开始进行写入，首先输入图书编号，遍历数组并判断是否已存在该图书，若存在提示用户重新输入*/
	pfBook = fopen("book.txt", "ab+");
	if (pfBook == NULL)
	{
		printf("文件打开失败！\n");
		return;
	}

	while (cFlag == 'y')
	{
		if (iBookRecord >= BOOK_NUM)/*若超过M容量范围则不能继续写入*/
		{
			printf("记录已满！");
			fclose(pfBook);
			return;
		}

		printf("请输入图书编号：");
		do {
			iFlagExist = 0;
			scanf("%d", &astBook[iBookRecord].iNum);
			getchar();
			for (i = 0; i < iBookRecord; i++)
			{
				if (astBook[i].iNum == astBook[iBookRecord].iNum)
				{
					iFlagExist = 1;
					printf("该图书编号已存在，请重新输入：");
					break;
				}
			}
		} while (iFlagExist == 1);

		/*新增图书的基本信息*/
		printf("请输入图书名称：");
		gets(astBook[iBookRecord].acName);
		printf("请输入图书作者：");
		gets(astBook[iBookRecord].acAuthor);
		printf("请输入图书出版社：");
		gets(astBook[iBookRecord].acPress);
		printf("请输入图书库存量：");
		scanf("%d", &astBook[iBookRecord].iAmount);
		getchar();
		/*将新增的图书信息写入文件中*/
		if (fwrite(&astBook[iBookRecord], LEN_BOOK, 1, pfBook) != 1)
		{
			printf("无法保存该信息！\n");
			return;
		}
		else
		{
			printf("%d号图书信息已保存！\n", astBook[iBookRecord].iNum);
			iBookRecord++;
		}
		printf("继续添加书籍信息吗（y/n）");
		cFlag = getchar();
		getchar();
	}
	fclose(pfBook);
	printf("添加图书执行完毕！\n");
}

int SearchBook()
{
	int iBookNum, iBookRecord, iBookId, i;
	system("cls");

	iBookRecord = ReadBookFile("rb");/*以"rb"形式打开文件，如果失败则返回*/
	if (iBookRecord == -1)
	{
		printf("文件打开失败！\n");
		printf("| 按任意键返回子菜单 |");
		_getch();
		return -2;/*文件打开失败，返回-2*/
	}
	else if (iBookRecord == 0)
	{
		printf("没有图书记录！\n");
		printf("| 按任意键返回子菜单 |");
		_getch();
		return -3; /*没有记录，返回-3*/
	}

	/*以下进入查找程序*/
	printf("请输入图书编号：");
	scanf("%d", &iBookNum);
	getchar();
	for (i = 0; i < iBookRecord; i++)
	{
		if (iBookNum == astBook[i].iNum)
		{
			iBookId = i;/*找到记录，返回记录号*/
			printf("%d号图书信息如下：\n", iBookNum);
			printf("	|---------------------------------------------------------|\n");
			printf("	  %-6s%-16s%-10s%-20s%-4s\n", "编号", "书名", "作者", "出版社", "库存");
			printf("	  %-6d%-16s%-10s%-20s%-4d\n", BOOK_DATA);
			printf("	|---------------------------------------------------------|\n");
			break;
		}
	}
	if (i == iBookRecord)/*遍历循环，没有找到记录，提示用户*/
	{
		printf("找不到%d号图书信息！\n", iBookNum);
		iBookId = -1;/*找不到记录，返回-1*/
	}
	return iBookId;
}
void DeleteBook()
{
	FILE* pfBook;/*文件指针*/
	int iBookId, iBookRecord, i;
	char cFlag;/*字符型变量，用于选择*/

	system("cls");

	iBookId = SearchBook();

	if (iBookId == -1)
		return;

	iBookRecord = ReadBookFile("rb");
	printf("已找到该图书，是否删除？（y/n）");
	cFlag = getchar();
	getchar();

	if (cFlag == 'n')
		return;
	else if (cFlag == 'y')
	{
		for (i = iBookId; i < iBookRecord - 1; i++)
			astBook[i] = astBook[i + 1];/*数组依次前移*/
		iBookRecord--;
	}

	pfBook = fopen("book.txt", "wb");
	if (pfBook != NULL)
	{
		for (i = 0; i < iBookRecord; i++)/*将修改过的图书信息写入文件*/
		{
			if (fwrite(&astBook[i], LEN_BOOK, 1, pfBook) != 1)
			{
				printf("无法保存该信息！\n");
				return;
			}
		}

		fclose(pfBook);
		printf("%d号图书信息已删除！\n", astBook[iBookId].iNum);
	}
}

void ModifyBook()
{
	int iBookId, iBookRecord, iFlagExist, iItem, iNum, i;

	system("cls");

	iBookId = SearchBook();  /*调用查找图书函数获得图书记录号*/

	if (iBookId == -1) /*未找到该序号的图书，直接返回*/
		return;

	/*找到该序号的图书，可以进行修改操作*/
	iBookRecord = ReadBookFile("rb");
	ShowModifyBookMenu();   /*显示修改选项的菜单*/

	scanf("%d", &iItem);
	getchar();
	switch (iItem)
	{
	case 1:
		printf("请输入图书编号：");
		do {
			iFlagExist = 0;
			scanf("%d", &iNum);
			getchar();
			for (i = 0; i < iBookRecord; i++)
			{
				if (iNum == astBook[i].iNum && i != iBookId)
				{
					iFlagExist = 1;
					printf("错误，该图书编号已存在，请重新输入：");
					break;
				}
			}
		} while (iFlagExist == 1);
		astBook[iBookId].iNum = iNum;
		break;
	case 2:
		printf("请输入图书名称：");
		gets(astBook[iBookId].acName);
		break;
	case 3:
		printf("请输入图书作者：");
		gets(astBook[iBookId].acAuthor);
		break;
	case 4:
		printf("请输入图书出版社：");
		gets(astBook[iBookId].acPress);
		break;
	case 5:
		printf("请输入图书库存量：");
		scanf("%d", &astBook[iBookId].iAmount);
		getchar();
		break;
	}
	/*调用SaveBookFile函数将修改记录存入文件*/
	SaveBookFile(iBookId);
	printf("图书信息修改成功！\n");
}
void ManageBook()
{
	int iItem;

	ShowBookMenu();	/*显示子菜单*/
	scanf("%d", &iItem);
	getchar();
	/*用while循环和switch语句进行选择*/
	while (iItem)
	{
		switch (iItem)
		{
		case 1:
			ShowBook();/*显示图书信息*/
			break;
		case 2:
			AddBook();/*新增图书信息*/
			break;
		case 3:
			SearchBook();/*查找图书*/
			break;
		case 4:
			DeleteBook();/*删除图书*/
			break;
		case 5:
			ModifyBook();/*修改图书信息*/
			break;
		default:
			printf("		请输入正确的数字！\n		");
		}
		printf("| 按任意键返回子菜单 |");
		_getch();   /*接收用户输入任意字符*/

		ShowBookMenu();
		scanf("%d", &iItem);
		getchar();
	}
}



/*==============================读者管理相关函数============================*/

 ///*显示读者信息函数*/
void ShowReader()
{
	int i, iReaderRecord;
	system("cls");

	iReaderRecord = ReadReaderFile("rb");
	if (iReaderRecord == -1)
		printf("文件打开失败！请先添加读者信息！\n");
	else if (iReaderRecord == 0)
		printf("文件中没有读者信息\n");
	else
	{
		printf("	|---------------------------------------------------------|\n");
		printf("	  %-8s%-12s%-6s%-16s%-16s%-8d\n", "编号", "姓名", "性别", "当前可借书数量", "最大可借书数量");
		for (i = 0; i < iReaderRecord; i++)
			printf("	  %-8d%-12s%-6s%-16d%-16d%-8d\n", READER_DATA);
		printf("	|---------------------------------------------------------|\n");
	}
}

/*添加读者信息函数*/
void AddReader()
{
	FILE* pfReader;
	int iFlagExist, iReaderRecord, i;
	char cFlag;

	system("cls");

	iReaderRecord = ReadReaderFile("ab+"); /*ab+追加方式打开或新建二进制文件*/
	if (iReaderRecord == -1)
	{
		printf("文件打开失败！\n");
		return;
	}
	else if (iReaderRecord == 0)
		printf("没有读者记录！\n");
	else
		ShowReader();

	/*以下代码为循环录入读者信息*/
	printf("请选择是否键入信息（y/n）：");
	cFlag = getchar();
	getchar();
	if (cFlag == 'n')
		return;

	pfReader = fopen("reader.txt", "ab+");
	if (pfReader == NULL)
	{
		printf("文件打开失败！\\n");
		return;
	}

	while (cFlag == 'y')
	{
		if (iReaderRecord >= READER_NUM)
		{
			printf("记录已满！");
			fclose(pfReader);
			return;
		}
		printf("请输入读者编号：");
		do
		{
			iFlagExist = 0;
			scanf("%d", &astReader[iReaderRecord].iNum);
			getchar();

			for (i = 0; i < iReaderRecord; i++)
			{
				if (astReader[i].iNum == astReader[iReaderRecord].iNum)
				{
					iFlagExist = 1;
					printf("该读者编号已存在！请重新输入:");
				}
			}
		} while (iFlagExist == 1);

		printf("请输入读者姓名：");
		gets(astReader[iReaderRecord].acName);
		printf("请输入读者性别：F/M:");
		while (gets(astReader[iReaderRecord].acSex) != NULL)
		{
			if (strcmp(astReader[iReaderRecord].acSex, "F") == 0 || strcmp(astReader[iReaderRecord].acSex, "M") == 0)
				break;
			printf("错误，只能输入'F'或者'M',请重新输入\n");
		}
		printf("请输入读者最大可借书数：(范围为5-10):");
		while (scanf("%d", &astReader[iReaderRecord].iMax) == 1)
		{
			getchar();
			if (astReader[iReaderRecord].iMax >= 5 && astReader[iReaderRecord].iMax <= 10)
				break;
			printf("错误，读者最大借阅数范围为5-10,请重新输入\n");
		}
		astReader[iReaderRecord].iAmount = astReader[iReaderRecord].iMax;

		for (i = 0; i < astReader[iReaderRecord].iMax; i++)//数组初始化为0，表示该读者一本书也没有借;
			astReader[iReaderRecord].aiBookId[i] = 0;


		if (fwrite(&astReader[iReaderRecord], LEN_READER, 1, pfReader) != 1)
		{
			printf("无法保存该信息！\n");
		}
		else
		{
			printf("%d号读者信息已保存！\n", astReader[iReaderRecord].iNum);
			iReaderRecord++;
		}
		printf("继续输入信息吗（y/n）");
		cFlag = getchar();
		getchar();
	}
	fclose(pfReader);
	printf("添加读者执行完毕！\n");
}

void DeleteReader()
{
	FILE* pfReader;
	int iReaderId, iReaderRecord, i;
	char cFlag;

	system("cls");

	iReaderId = SearchReader();
	if (iReaderId == -1)
		return;

	iReaderRecord = ReadReaderFile("rb");
	printf("已找到该读者，是否删除？（y/n）");
	cFlag = getchar();
	getchar();

	if (cFlag == 'n')
		return;
	else if (cFlag == 'y')
	{
		for (i = iReaderId; i < iReaderRecord - 1; i++)
			astReader[i] = astReader[i + 1];
		iReaderRecord--;
	}

	pfReader = fopen("reader.txt", "wb");
	if (pfReader != NULL)
	{
		for (i = 0; i < iReaderRecord; i++)
		{
			if (fwrite(&astReader[i], LEN_READER, 1, pfReader) != 1)
			{
				printf("无法保存该信息！\n");
				return;
			}
		}
		fclose(pfReader);
		printf("%d号读者信息已删除！\n", astReader[iReaderId].iNum);
	}
}

void ModifyReader()
{
	int iReaderId, iReaderRecord, iBorrow, iItem, iNum, iMax, iFlagExist, i;

	system("cls");
	iReaderId = SearchReader();
	if (iReaderId == -1)
		return;

	/*能查询到该读者，则可以进行修改操作*/
	iReaderRecord = ReadReaderFile("rb");/*以"rb"形式打开文件，如果失败则返回*/
	ShowModifyReaderMenu();
	scanf("%d", &iItem);
	getchar();

	switch (iItem)
	{
	case 1:
		printf("请输入读者编号：");
		do {
			iFlagExist = 0;
			scanf("%d", &iNum);
			getchar();
			for (i = 0; i < iReaderRecord; i++)
				if (iNum == astReader[i].iNum && i != iReaderId)
				{
					iFlagExist = 1;
					printf("错误，该读者编号已存在，请重新输入：\n");
					break;
				}
		} while (iFlagExist == 1);
		astReader[iReaderId].iNum = iNum;
		break;
	case 2:
		printf("请输入读者名字：");
		gets(astReader[iReaderId].acName);
		break;
	case 3:
		printf("请输入读者性别：F/M:");
		while (gets(astReader[iReaderId].acSex) != NULL)
		{
			if (strcmp(astReader[iReaderId].acSex, "F") == 0 || strcmp(astReader[iReaderId].acSex, "M") == 0)
				break;
			printf("错误，只能输入'F'或者'M',请重新输入\n");
		}
		break;
	case 4:
		iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
		printf("请输入读者最大可借书数：(范围为5-10):");
		while (scanf("%d", &iMax) == 1)
		{
			getchar();
			if (iMax >= 5 && iMax <= 10)
			{
				if (iBorrow > iMax)
				{
					printf("该读者目前借阅图书数量大于该数目，需要先还书后修改！\n");
					return;
				}
				else
				{
					astReader[iReaderId].iMax = iMax;
					astReader[iReaderId].iAmount = iMax - iBorrow;
					for (i = iBorrow; i < iMax; i++)
						astReader[iReaderId].aiBookId[i] = 0;
					break;
				}
			}
			printf("错误，读者最大借阅数范围为5-10,请重新输入\n");
		}
		break;
	}/*switch 结束*/

	SaveReaderFile(iReaderId);
	printf("读者信息修改成功！\n");
}

int SearchReader()
{
	int iReaderNum, iReaderRecord, iReaderId, i;
	system("cls");

	iReaderRecord = ReadReaderFile("rb");
	if (iReaderRecord == -1)
	{
		printf("文件打开失败！\n");
		return -2; /*文件打开失败，返回-2*/
	}
	else if (iReaderRecord == 0)
	{
		printf("没有读者记录！\n");
		return -3; /*没有记录，返回-3*/
	}

	printf("请输入读者编号：");
	scanf("%d", &iReaderNum);
	getchar();
	for (i = 0; i < iReaderRecord; i++)
	{
		if (iReaderNum == astReader[i].iNum)
		{
			iReaderId = i; /*找到记录，返回记录号*/
			printf("%d号读者信息如下：\\n", iReaderNum);
			printf("	|---------------------------------------------------------|\n");
			printf("	  %-8s%-12s%-6s%-16s%-16s\\n", "编号", "姓名", "性别", "当前可借书数量", "最大可借书数量");
			printf("	  %-8d%-12s%-6s%-16d%-16d\\n", READER_DATA);
			printf("	|---------------------------------------------------------|\n");
			printf("\n");
			break;
		}
	}
	if (i == iReaderRecord)/*遍历循环，没有找到记录，提示用户*/
	{
		printf("找不到%d号读者信息！\n", iReaderNum);
		iReaderId = -1;/*找不到记录，返回-1*/
	}
	return iReaderId;
}



void ManageReader()
{
	int iItem = 0;
	ShowReaderMenu();

	scanf("%d", &iItem);
	getchar();

	while (iItem)
	{
		switch (iItem)
		{
		case 1:
			ShowReader();
			break;
		case 2:
			AddReader();
			break;
		case 3:
			SearchReader();
			break;
		case 4:
			DeleteReader();
			break;
		case 5:
			ModifyReader();
			break;
		default:
			printf("		请输入正确的数字！\n		");
		}

		printf("| 按任意键返回子菜单 |");
		_getch();   /*接收用户输入任意字符*/
		ShowReaderMenu();
		scanf("%d", &iItem);
		getchar();
	}
}
/*==============================借还书管理相关函数============================*/
void BorrowBook()
{
	system("cls");
	int iBookId, iReaderId, iBorrow, i;

	/*输入要借书的读者编号，判断编号是否存在，显示该读者已借图书的信息*/
	iReaderId = SearchReader();
	if (iReaderId == -1)
		return;
	iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
	if (iBorrow == 0)
		printf("该读者目前没有借任何书\n");
	else
	{
		printf("	该读者当前所借图书为:");
		for (i = 0; i < iBorrow; i++)
			printf("%d ", astReader[iReaderId].aiBookId[i]);
		printf("\\n\\n");
	}

	/*若读者可借书数量为0，不允许再借书，退出*/
	if (astReader[iReaderId].iAmount == 0)
	{
		printf("该读者可借书量为零，不能继续借书！\n");
		return;
	}

	/*输入要借的书号，查找书号是否存在，判断该书库存是否为0*/
	printf("\n按任意键输入要借阅的图书信息\n");
	_getch();

	iBookId = SearchBook();
	if (iBookId == -1)
		return;
	if (astBook[iBookId].iAmount == 0)
	{
		printf("该图书库存量为零！图书不可借\n");
		return;
	}
	astReader[iReaderId].aiBookId[iBorrow] = astBook[iBookId].iNum;/*图书库存不为0时，允许借书*/
	astBook[iBookId].iAmount--;     /*该图书的库存量减1*/
	astReader[iReaderId].iAmount--; /*该读者的可借书的数量减1*/

	SaveBookFile(iBookId);	     /*保存该条图书信息到文件*/
	SaveReaderFile(iReaderId);   /*保存该条读者信息到文件*/

	printf("借书成功！\\n");
}

void ReturnBook()
{
	int iBookId, iReaderId, iBorrow, i, j;

	system("cls");
	iReaderId = SearchReader();
	if (iReaderId == -1)
		return;
	iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;

	if (iBorrow == 0)
	{
		printf("	该读者没有借任何书，无需归还\n");
		return;
	}
	else
	{
		printf("	该读者当前所借图书为:");
		for (i = 0; i < iBorrow; i++)
			printf("%d ", astReader[iReaderId].aiBookId[i]);
		printf("\n\n");
	}

	printf("按任意键输入要归还的图书信息\\n");
	_getch();

	iBookId = SearchBook();
	if (iBookId == -1)
		return;
	for (i = 0; i < iBorrow; i++)
		if (astReader[iReaderId].aiBookId[i] == astBook[iBookId].iNum)
		{
			for (j = i; j < iBorrow - 1; j++)
				astReader[iReaderId].aiBookId[j] = astReader[iReaderId].aiBookId[j + 1];
			astReader[iReaderId].aiBookId[iBorrow] = 0;

			astBook[iBookId].iAmount++;      /*该书的库存数加1*/
			astReader[iReaderId].iAmount++;  /*该读者的最大可借阅数加1*/
			break;
		}

	if (i == iBorrow)/*遍历循环，未找到该书*/
	{
		printf("该读者没有借这本书，无需归还\n");
		return;
	}

	SaveBookFile(iBookId);      /*保存该条图书信息到文件*/
	SaveReaderFile(iReaderId);	/*保存该条读者信息到文件*/

	printf("还书成功！\n");
}

void BorrowReturnManage()
{
	int iItem = 0;
	ShowBorrowReturnMenu();

	scanf("%d", &iItem);
	getchar();

	while (iItem)
	{
		switch (iItem)
		{
		case 1:
			BorrowBook();
			break;
		case 2:
			ReturnBook();
			break;
		default:
			printf("		请输入正确的数字！\n		");
		}
		printf("| 按任意键返回子菜单 |");
		_getch();
		ShowBorrowReturnMenu();
		scanf("%d", &iItem);
		getchar();
	}
}
