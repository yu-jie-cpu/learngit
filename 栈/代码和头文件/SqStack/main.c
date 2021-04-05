#include "../head/SqStack.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main()
{
	SqStack s;
	s.elem=NULL;
	int sizes=0, dataa=0, datad=0, top=0, length=0;
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
			case 'i': initStack(&s,sizes);		break;
			case 'a':
				{
					printf("当前栈：");
					printStack(&s);
					pushStack(&s,dataa);
					break;
				}
			case 'd':
				{
					printf("当前栈：");
					printStack(&s);
					popStack(&s,&datad);
					break;
				}
			case 'e': isEmptyStack(&s);		break;
			case 't': getTopStack(&s,&top);		break;
			case 'l': stackLength(&s,&length);	break;
			case 'c': clearStack(&s);		break;
			case 'r': destroyStack(&s);		break;
			case 'p': printStack(&s);		break;
			default : printf("输入有误，请重新输入\n");
		}
		system("pause");
		system("cls");
	}
	return 0;
}
