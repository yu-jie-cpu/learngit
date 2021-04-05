#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*对于链栈的各种操作函数*/

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
	printf("初始化成功\n");
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
		printf("栈为空\n");
		return SUCCESS;
	}
	printf("栈不为空\n");
	return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e)
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
	*e=s->top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	LinkStackPtr p,q;
        p=s->top;
        while(s->count)	//对每一个节点进行释放
        {
                q=p;
                p=p->next;
                free(q);
                s->count--;
        }
        printf("清空成功\n");
        return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	free(s->top);
	s->top=NULL;
	printf("销毁成功\n");
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	*length=s->count;
	printf("栈的长度为：%d\n",*length);
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data)
{
	if(!s->top)
	{
		printf("栈未初始化，请初始化\n");
		return ERROR;
	}
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
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
	p->data=data;
	p->next=s->top;		//当前的栈顶赋值给新的元素的后继(指针的指向)
	s->top=p;		//新节点赋值给栈顶指针（新元素成为栈顶元素）
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data)
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
	printf("出栈的元素为：%d\n",*data);
	return SUCCESS;
}

//打印栈
Status printLStack(LinkStack *s)
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
	LinkStackPtr p;
	int cnt=s->count;	//初始化计数器cnt，保护s->count的值不被修改
	p=s->top;
	while(cnt)
	{
		printf("%d ",p->data);
		p=p->next;
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
