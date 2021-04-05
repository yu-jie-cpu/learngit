#include "../head/Calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//��ʼ��������
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

//�ڽ��p�������q
Status insertList(LNode *p,char sign)
{
	if (!p)
	{
		printf("�������ڣ����ʼ��\n");
		return ERROR;
	}
	//Ϊ���q��ֵsign
	LinkedList q=(LinkedList)malloc(sizeof(LNode));
	q->sign=sign;
	q->next = NULL;
	//������β������
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	//printf("���������Ϊ��%c\n",q->sign);
	return SUCCESS;
}

//ɾ�����p֮��ĵ�һ�����
Status deleteList(LNode *p,char *sign)
{
	if (!p)
	{
		printf("�������ڣ����ʼ��\n");
		return ERROR;
	}
	if (p->next == NULL)
	{
		printf("�ý����޽���ɾ��\n");
		return SUCCESS;
	}
	//����q��ֵ��*sign
	LNode* q = p->next;
	*sign=q->sign;
	p->next = q->next;
	q->next = NULL;
	free(q);
	//printf("ɾ��������Ϊ��%c\n",*sign);
	return SUCCESS;
}

//���ٵ�����
void destroyList(LinkedList *L)
{
	if (!*L)
	{
		printf("�������ڣ����ʼ��\n");
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
