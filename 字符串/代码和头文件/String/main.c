#include "../head/String.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<ctype.h>
#include <string.h>

int main()
{
	char s[1000];
	char *c;
	int num=0;
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
			case 'f':{
				printf("�������ַ�����");
				gets(s);
				c=fPalindrome(s);
				printf("%s\n",c);
				break;
			}
			case 'z':{
				printf("�������ַ�����");
				gets(s);
				printf("���������е�������");
				scanf("%d",&num);
				c=zTransform(s,num);
				printf("%s\n",c);
				break;
			}
			default :printf("����������������\n");
		}
		system("pause");
		system("cls");
	}
	return 0;
}
