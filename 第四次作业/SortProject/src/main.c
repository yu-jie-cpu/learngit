#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//load();
	char ch;
	while(1)
	{
		display();
		ch=getch();
		if(ch=='0')
			break;
		switch(ch)
		{
			case '1':sort1w();	break;
			case '2':sort5w();	break;
			case '3':sort20w();	break;
			case '4':sort0();	break;
			case '5':appsort();	break;
			case '6':{
				system("cls");
				load();
				break;
			}
			default :printf("输入有误，请重新输入\n");
		}
		system("pause");
		system("cls");
	}

	return 0;
}
