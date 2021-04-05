#include "../head/String.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//寻找最长回文串
char *fPalindrome(char *s)
{

	char *p=s;
	int len=strlen(s);	//字符串长度
	int i,j,k;
	int count=0,start=0;	//头尾
	char *s1;		//最终回文串
	//字符串无字符或只有一个字符
	if(len<=1)
	{
		return s;
	}
	//寻找回文串
	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(p[i]==p[j])			//找出所有头尾元素相等的子串
			{
				for(k=0;k<=j-i;k++)	//判断子串是否为回文报文
				{
					if(!(p[i+k]==p[j-k]))
					{
						k=0;   	//防止k长度大于正确的回文子串长度
						break;
					}

				}
				if(k==len)		//若子串长度等于字符串长度，直接返回字符串（整个字符串为回文串）
				{
					return s;
				}
				if(count<k)           	//最大值赋给count
				{
					count=k;
					start=i;
				}
			}
		}
	}
	if(0==count) 		//若没有回文子串，返回s的第一个字符
	{
		*(s+1)='\0';
		return s;
	}
	//对s1进行最终结果赋值（给予头地址和手动写上'\0'）
	s1=&s[start];
	s1[count]='\0';
	return s1;
}

//Z字形变换
char *zTransform(char *s,int num)
{
	//按一行排列，不需要改变
	if(num==1)
	{
		return s;
	}

	int i,j,k=0,flag,index;
	int len=strlen(s);	//字符串长度
	char *s1;		//最终Z字形字符串
	s1=(char*)malloc(sizeof(char)*(len+1));
	for(i=1;i<=num;i++)
	{
		flag=1,index=1;
		for(j=0;j<len;j++)
		{
			if(index==i)
			{
				//printf("%c ",s[j]);
				s1[k]=s[j];
				k++;
			}
			if(index==1)
			{
				flag=1;
			}
			else if(index==num)
			{
				flag=-1;
			}
			index=index+flag;
		}
	}
	s1[k]='\0';	//手动写'\0'
	return s1;
}

//初始化交互界面
void display()
{
	printf("******主界面*****\n");
	printf("* f：最长回文串 *\n");
	printf("* z：Z字形排列  *\n");
	printf("* g：退出程序   *\n");
	printf("*****************\n");
}
