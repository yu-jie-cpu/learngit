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
	//��ʼ������
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
			case 'c': {//���㺯��
				formulaTransform(&L,&sign);
				//���ô�����жϼ������
				if(L->next==NULL)
				{
					break;
				}
				formulaCalculation(&L,&num);
				break;
			}
			default :printf("������������������\n");
		}
		system("pause");
		system("cls");
	}

	return 0;
}
