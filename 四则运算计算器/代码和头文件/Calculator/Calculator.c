#include "../head/Calculator.h"
#include <stdio.h>
#include <stdlib.h>

//对中缀表达式处理转换为后缀表达式
//用单链表把后缀表达式以尾插法储存起来

//从头结点开始读取单链表中的后缀表达式
//用栈对读取出来的后缀表达式进行计算

//中缀表达式转换为后缀表达式（这一步使用符号链栈）
Status formulaTransform(LinkedList *p,LinkStackc *s)
{
	//中缀转化为后缀
	char c,e;
	char k='$';

	printf("请输入中缀表达式,以#作为结束符\n");
	scanf("%c",&c);
	printf("该中缀表达式转换为后缀表达式为：\n");

	while(c!='#')
	{
		//对一个数字（double）进行打包储存（用$表示一个数结束）
		while((c>='0'&&c<='9')||c=='.')
		{
			printf("%c",c);
			insertList(*p,c);
			scanf("%c",&c);
			if(c<'0'||c>'9')
			{
				if(c=='.')
				{
					continue;
				}
				printf(" ");
				insertList(*p,k);
				break;
			}
		}
		//对不同优先级别运算符进行处理
		if(c==')')
		{
			popLStackc(&(*s),&e);
			while(e!='(')
			{
				printf("%c ",e);
				insertList(*p,e);
				insertList(*p,k);
				popLStackc(&(*s),&e);
			}
		}
		else if(c=='+'||c=='-')
		{
			if(isEmptyLStackc(&(*s)))
			{
				pushLStackc(&(*s),c);
			}
			else
			{
				do
				{
					popLStackc(&(*s),&e);
					if(e=='(')
					{
						pushLStackc(&(*s),e);
					}
					else
					{
						printf("%c ",e);
						insertList(*p,e);
						insertList(*p,k);
					}
				}while(!isEmptyLStackc(&(*s))&&e!='(');
				pushLStackc(&(*s),c);
			}
		}
		else if(c=='*'||c=='/'||c=='(')
		{
			pushLStackc(&(*s),c);
		}
		else if(c=='#')
		{
			getchar();	//吃掉#后边留在缓冲区的回车，防止在第二次计算时造成误输入
			break;
		}
		else if(c=='\n')
		{
			break;
		}
		else
		{
			printf("输入错误\n");
			while(getchar()!='\n');	//吃掉错误输入留在缓冲区的所有字符
			return ERROR;
		}
		scanf("%c",&c);
	}
	while(!isEmptyLStackc(&(*s)))
	{
		popLStackc(&(*s),&e);
		printf("%c ",e);
		insertList(*p,e);
		insertList(*p,k);
	}
	//对用户忘记输入#的情况进行重置处理
	if(c!='#')
	{
		printf("\n你输入的表达式没有结束符#\n");
		destroyList(p);
		initList(p);
		return ERROR;
	}
	insertList(*p,c);	//对单链表写入#表示一个式子结束
	printf("\n");
	return SUCCESS;
}

//对后缀表达式进行计算（这一步使用数据链栈）
Status formulaCalculation(LinkedList *p,LinkStack *s)
{
	char c;
	char str[20];
	double a,b,d;
	int i=0;

	//scanf("%c",&c);
	deleteList(*p,&c);

	while(c!='#')
	{
		//对打包好的一个数进行类型转换处理（多个char转换为一个double），并入栈
		while((c>='0'&&c<='9')||c=='.')
		{
			str[i++]=c;
			str[i]='\0';
			if(i>=20)
			{
				printf("出错，输入的数据过多\n");
				return ERROR;
			}
			//scanf("%c",&c);
			deleteList(*p,&c);
			if(c=='$')		//$标志着一个打包的数结束
			{
				d=atof(str);
				pushLStack(&(*s),d);
				i=0;
				break;
			}
		}
		//运算符进行处理（此处为已经转换好的后缀表达式，故无需考虑优先级）
		switch(c)
		{
			case '+': {
				popLStack(&(*s),&a);
				popLStack(&(*s),&b);
				pushLStack(&(*s),a+b);
				break;
			}
			case '-': {
				popLStack(&(*s),&a);
				popLStack(&(*s),&b);
				pushLStack(&(*s),b-a);
				break;
			}
			case '*': {
				popLStack(&(*s),&a);
				popLStack(&(*s),&b);
				pushLStack(&(*s),a*b);
				break;
			}
			case '/': {
				popLStack(&(*s),&a);
				popLStack(&(*s),&b);
				//对除数a判断，除数不能为0
				if(a!=0)
				{
					pushLStack(&(*s),b/a);
				}
				else
				{
					//重置操作
					printf("\n除数为0，输入有误\n");
					destroyList(p);
					initList(p);
					return ERROR;
				}
				break;
			}
		}
		//scanf("%c",&c);
		deleteList(*p,&c);
	}
	popLStack(&(*s),&d);		//栈中最后剩一个数据为式子最后的计算结果
	printf("计算结果为：%.2f\n",d);
	getchar();	//吃掉留在缓冲区的回车（当表达式带()时）
	return SUCCESS;
}

//初始化交互界面
void display()
{
	printf("*****主界面*****\n");
	printf("* c：进入计算  *\n");
	printf("* g：退出程序  *\n");
	printf("****************\n");
}
