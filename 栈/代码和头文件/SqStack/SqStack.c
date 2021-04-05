#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*对于顺序栈的各种操作函数*/

//初始化栈
Status initStack(SqStack* s, int sizes)
{
	printf("请输入你要创建的栈的大小：");
	int flag=scanf("%d", &sizes);
	int ch;
	if(!flag)
	{
		printf("输入格式有误，退出\n");
		while((ch=getchar())!='\n');
		return ERROR;
	}
	while((ch=getchar())!='\n');
	s->elem = (int*)malloc(sizeof(int) * sizes);
	s->top = -1;
	s->size = sizes;
	if (!s->elem)		//s->elem=NULL
	{
		printf("初始化失败\n");
		return ERROR;
	}
	else
	{
		printf("初始化成功\n");
		return SUCCESS;
	}
}

//判断栈是否为空
Status isEmptyStack(SqStack* s)
{
	if (!s->elem)
	{
		printf("栈未初始化\n");
		return ERROR;
	}
	if (s->top == -1)
	{
		printf("栈空了\n");
		return SUCCESS;
	}
	printf("栈不为空\n");
	return ERROR;
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e)
{
	if (!s->elem)
	{
		printf("栈未初始化\n");
		return ERROR;
	}
	if(s->top==-1)
	{
		printf("栈空了\n");
		return SUCCESS;
	}
	*e = s->elem[s->top];
	printf("栈顶元素是：%d\n", *e);
	return SUCCESS;
}

//清空栈
Status clearStack(SqStack *s)
{
	if (!s->elem)
	{
		printf("栈未初始化\n");
		return ERROR;
	}
	s->top=-1;
	printf("清空成功\n");
	return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack *s)
{
	if (!s->elem)
	{
		printf("栈未初始化\n");
		return ERROR;
	}
	free(s->elem);
	s->elem=NULL;
	if (!(s->elem))	//s->elem=NULL
	{
		printf("销毁成功\n");
		return SUCCESS;
	}
	return ERROR;
}

//检测栈长度
Status stackLength(SqStack *s,int *length)
{
	if (!s->elem)
	{
		printf("栈未初始化\n");
		return ERROR;
	}
	if (s->top == -1)
	{
		printf("栈空了\n");
		return SUCCESS;
	}
	*length=(s->top+1);
	printf("栈的长度为：%d\n", *length);
	return SUCCESS;
}

//入栈
Status pushStack(SqStack *s,ElemType data)
{
	if (!s->elem)
	{
		printf("栈未初始化\n");
		return ERROR;
	}
	if((s->top+1)>=s->size)
	{
		printf("栈满了\n");
		return ERROR;
	}
	printf("请输入你要进栈的元素：");
	int flag=scanf("%d", &data);
	int ch;
	if(!flag)
	{
		printf("输入格式有误，退出\n");
		while((ch=getchar())!='\n');
		return ERROR;
	}
	while((ch=getchar())!='\n');
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

//出栈
Status popStack(SqStack *s,ElemType *data)
{
	if (!s->elem)
	{
		printf("栈未初始化\n");
		return ERROR;
	}
	if(s->top==-1)
	{
		printf("栈空了\n");
		return SUCCESS;
	}
	*data=s->elem[s->top];
	s->top--;
	printf("出栈的元素是：%d\n", *data);
	return SUCCESS;
}

//打印栈
Status printStack(SqStack *s)
{
	if (!s->elem)
	{
		printf("栈未初始化\n");
		return ERROR;
	}
	int cnt=s->top;		//初始化计数器，保护s->top的值
	while(cnt!=-1)
	{
		printf("%d ",s->elem[cnt]);
		cnt--;
	}
	printf("\n");
	return SUCCESS;
}

//初始化交互界面
void display()
{
	printf("****进入选择界面****\n");
	printf("*   i：初始化栈    *\n");
	printf("*   a：进栈        *\n");
	printf("*   d：出栈        *\n");
	printf("*   e：栈是否为空  *\n");
	printf("*   t：栈顶元素    *\n");
	printf("*   c：清空栈      *\n");
	printf("*   r：销毁栈      *\n");
	printf("*   l：测栈长度    *\n");
	printf("*   p：打印栈      *\n");
	printf("*   g：退出程序    *\n");
	printf("********************\n");
}
