#include"BookManage.h"
int main()
{
	int iItem;
	ShowMainMenu();/*调用ShowMainMenu函数绘制界面*/
	scanf("%d", &iItem);/*提示用户输入数字*/
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
			printf("		请输入正确的数字！\\n		程序将于3秒后跳转到主菜单");
			Sleep(3000);
		}
		ShowMainMenu();
		scanf("%d", &iItem);
		getchar();
	}
	return 0;

}