#include "../head/Calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

int main()
{
	LinkStack num;
	LinkStackc sign;
	LinkedList L=NULL;
	//初始化函数
	initList(&L);
	initLStack(&num);
	initLStackc(&sign);

	char ch;
	while(1)
	{
		display();
		ch=getch();
		if(ch=='g')
		{
			break;
		}
		switch(ch)
		{
			case 'c': {//计算函数
				formulaTransform(&L,&sign);
				//重置处理后中断计算过程
				if(L->next==NULL)
				{
					break;
				}
				formulaCalculation(&L,&num);
				break;
			}
			default :printf("输入有误，请重新输入\n");
		}
		system("pause");
		system("cls");
	}

	return 0;
}
