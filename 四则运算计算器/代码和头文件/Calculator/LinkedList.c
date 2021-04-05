#include "../head/Calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//初始化单链表
Status initList(LinkedList *L)
{
	*L = (LinkedList)malloc(sizeof(LNode));
	if (*L)
	{
		(*L)->next = NULL;
		//printf("success\n");
		return SUCCESS;
	}
	printf("error\n");
	return ERROR;
}

//在结点p后插入结点q
Status insertList(LNode *p,char sign)
{
	if (!p)
	{
		printf("链表不存在，请初始化\n");
		return ERROR;
	}
	//为结点q赋值sign
	LinkedList q=(LinkedList)malloc(sizeof(LNode));
	q->sign=sign;
	q->next = NULL;
	//遍历到尾结点插入
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	//printf("插入的数据为：%c\n",q->sign);
	return SUCCESS;
}

//删除结点p之后的第一个结点
Status deleteList(LNode *p,char *sign)
{
	if (!p)
	{
		printf("链表不存在，请初始化\n");
		return ERROR;
	}
	if (p->next == NULL)
	{
		printf("该结点后无结点可删除\n");
		return SUCCESS;
	}
	//保存q的值到*sign
	LNode* q = p->next;
	*sign=q->sign;
	p->next = q->next;
	q->next = NULL;
	free(q);
	//printf("删除的数据为：%c\n",*sign);
	return SUCCESS;
}

//销毁单链表
void destroyList(LinkedList *L)
{
	if (!*L)
	{
		printf("链表不存在，请初始化\n");
		return;
	}
	LinkedList p;
	while (*L)
	{
		p = (*L)->next;
		free(*L);
		*L = p;
	}
	//printf("success\n");
}
