#include "../head/Calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*对于数据链栈的各种操作函数*/

//初始化栈
Status initLStack(LinkStack *s)
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));
	if(!s->top)
	{
		printf("初始化失败\n");
		return ERROR;
	}
	s->count=0;
	//printf("初始化成功\n");
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,double data)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));//新结点p
	p->data=data;
	p->next=s->top;		//当前的栈顶赋值给新的元素的后继(指针的指向)
	s->top=p;		//新节点赋值给栈顶指针（新元素成为栈顶元素）
	s->count++;
	//printf("入栈的元素为：%d",p->data);
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,double *data)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	if(s->count==0)
	{
		printf("栈为空\n");
		return ERROR;
	}
	LinkStackPtr p;		//临时节点

	*data =s->top->data;	//出栈的元素
	p=s->top;		//将栈顶指针交给p
	s->top=s->top->next;	//使得栈顶指针下移一位
	free(p);		//释放临时节点
	s->count--;
	//printf("出栈的元素为：%d\n",*data);
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	if(s->count==0)
	{
		//printf("栈为空\n");
		return SUCCESS;
	}
	//printf("栈不为空\n");
	return ERROR;
}

/*对于符号链栈的各种操作函数*/

//初始化栈
Status initLStackc(LinkStackc *s)
{
	s->top=(LinkStackcPtr)malloc(sizeof(StackNodec));
	if(!s->top)
	{
		printf("初始化失败\n");
		return ERROR;
	}
	s->count=0;
	//printf("初始化成功\n");
	return SUCCESS;
}

//入栈
Status pushLStackc(LinkStackc *s,char data)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	LinkStackcPtr p=(LinkStackcPtr)malloc(sizeof(StackNodec));//新结点p
	p->data=data;
	p->next=s->top;		//当前的栈顶赋值给新的元素的后继(指针的指向)
	s->top=p;		//新节点赋值给栈顶指针（新元素成为栈顶元素）
	s->count++;
	//printf("入栈的元素为：%d",p->data);
	return SUCCESS;
}

//出栈
Status popLStackc(LinkStackc *s,char *data)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	if(s->count==0)
	{
		printf("栈为空\n");
		return ERROR;
	}
	LinkStackcPtr p;		//临时节点

	*data =s->top->data;	//出栈的元素
	p=s->top;		//将栈顶指针交给p
	s->top=s->top->next;	//使得栈顶指针下移一位
	free(p);		//释放临时节点
	s->count--;
	//printf("出栈的元素为：%c\n",*data);
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStackc(LinkStackc *s)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	if(s->count==0)
	{
		//printf("栈为空\n");
		return SUCCESS;
	}
	//printf("栈不为空\n");
	return ERROR;
}

