#include"BookManage.h"
int main()
{
	int iItem;
	ShowMainMenu();/*����ShowMainMenu�������ƽ���*/
	scanf("%d", &iItem);/*��ʾ�û���������*/
	getchar();
	while (iItem)
	{
		switch (iItem)
		{
		case 1:
			ManageBook();
			break;
		case 2:
			ManageReader();
			break;
		case 3:
			BorrowReturnManage();
			break;
		default:
			printf("		��������ȷ�����֣�\\n		������3�����ת�����˵�");
			Sleep(3000);
		}
		ShowMainMenu();
		scanf("%d", &iItem);
		getchar();
	}
	return 0;

}