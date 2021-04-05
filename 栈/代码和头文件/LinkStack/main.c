#include "../head/LinkStack.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main()
{
	LinkStack s;
	s.top=NULL;
	int dataa=0, datad=0, top=0, length=0;
	char ch;
	while(1)
	{
		display();
		ch=getch();
		if(ch=='g')
		{
			system("pause");
			break;
		}
		switch(ch)
		{
			case 'i': initLStack(&s);		break;
			case 'a':
			{
				printf("��ǰջ��");
				printLStack(&s);
				pushLStack(&s,dataa);
				break;
			}
			case 'd':
			{
				printf("��ǰջ��");
				printLStack(&s);
				popLStack(&s,&datad);
				break;
			}
			case 'e': isEmptyLStack(&s);		break;
			case 't': getTopLStack(&s,&top);	break;
			case 'l': LStackLength(&s,&length);	break;
			case 'c': clearLStack(&s);		break;
			case 'r': destroyLStack(&s);		break;
			case 'p': printLStack(&s);		break;
			default : printf("������������������\n");
		}
		system("pause");
		system("cls");
	}
	return 0;
}
