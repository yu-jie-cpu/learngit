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
				printf("请输入字符串：");
				gets(s);
				c=fPalindrome(s);
				printf("%s\n",c);
				break;
			}
			case 'z':{
				printf("请输入字符串：");
				gets(s);
				printf("请输入排列的行数：");
				scanf("%d",&num);
				c=zTransform(s,num);
				printf("%s\n",c);
				break;
			}
			default :printf("输入有误，重新输入\n");
		}
		system("pause");
		system("cls");
	}
	return 0;
}
