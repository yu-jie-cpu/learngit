#include "../head/String.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Ѱ������Ĵ�
char *fPalindrome(char *s)
{

	char *p=s;
	int len=strlen(s);	//�ַ�������
	int i,j,k;
	int count=0,start=0;	//ͷβ
	char *s1;		//���ջ��Ĵ�
	//�ַ������ַ���ֻ��һ���ַ�
	if(len<=1)
	{
		return s;
	}
	//Ѱ�һ��Ĵ�
	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(p[i]==p[j])			//�ҳ�����ͷβԪ����ȵ��Ӵ�
			{
				for(k=0;k<=j-i;k++)	//�ж��Ӵ��Ƿ�Ϊ���ı���
				{
					if(!(p[i+k]==p[j-k]))
					{
						k=0;   	//��ֹk���ȴ�����ȷ�Ļ����Ӵ�����
						break;
					}

				}
				if(k==len)		//���Ӵ����ȵ����ַ������ȣ�ֱ�ӷ����ַ����������ַ���Ϊ���Ĵ���
				{
					return s;
				}
				if(count<k)           	//���ֵ����count
				{
					count=k;
					start=i;
				}
			}
		}
	}
	if(0==count) 		//��û�л����Ӵ�������s�ĵ�һ���ַ�
	{
		*(s+1)='\0';
		return s;
	}
	//��s1�������ս����ֵ������ͷ��ַ���ֶ�д��'\0'��
	s1=&s[start];
	s1[count]='\0';
	return s1;
}

//Z���α任
char *zTransform(char *s,int num)
{
	//��һ�����У�����Ҫ�ı�
	if(num==1)
	{
		return s;
	}

	int i,j,k=0,flag,index;
	int len=strlen(s);	//�ַ�������
	char *s1;		//����Z�����ַ���
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
	s1[k]='\0';	//�ֶ�д'\0'
	return s1;
}

//��ʼ����������
void display()
{
	printf("******������*****\n");
	printf("* f������Ĵ� *\n");
	printf("* z��Z��������  *\n");
	printf("* g���˳�����   *\n");
	printf("*****************\n");
}
