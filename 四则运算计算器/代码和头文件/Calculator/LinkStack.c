#include "../head/Calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*����������ջ�ĸ��ֲ�������*/

//��ʼ��ջ
Status initLStack(LinkStack *s)
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));
	if(!s->top)
	{
		printf("��ʼ��ʧ��\n");
		return ERROR;
	}
	s->count=0;
	//printf("��ʼ���ɹ�\n");
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,double data)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));//�½��p
	p->data=data;
	p->next=s->top;		//��ǰ��ջ����ֵ���µ�Ԫ�صĺ��(ָ���ָ��)
	s->top=p;		//�½ڵ㸳ֵ��ջ��ָ�루��Ԫ�س�Ϊջ��Ԫ�أ�
	s->count++;
	//printf("��ջ��Ԫ��Ϊ��%d",p->data);
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,double *data)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	if(s->count==0)
	{
		printf("ջΪ��\n");
		return ERROR;
	}
	LinkStackPtr p;		//��ʱ�ڵ�

	*data =s->top->data;	//��ջ��Ԫ��
	p=s->top;		//��ջ��ָ�뽻��p
	s->top=s->top->next;	//ʹ��ջ��ָ������һλ
	free(p);		//�ͷ���ʱ�ڵ�
	s->count--;
	//printf("��ջ��Ԫ��Ϊ��%d\n",*data);
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	if(s->count==0)
	{
		//printf("ջΪ��\n");
		return SUCCESS;
	}
	//printf("ջ��Ϊ��\n");
	return ERROR;
}

/*���ڷ�����ջ�ĸ��ֲ�������*/

//��ʼ��ջ
Status initLStackc(LinkStackc *s)
{
	s->top=(LinkStackcPtr)malloc(sizeof(StackNodec));
	if(!s->top)
	{
		printf("��ʼ��ʧ��\n");
		return ERROR;
	}
	s->count=0;
	//printf("��ʼ���ɹ�\n");
	return SUCCESS;
}

//��ջ
Status pushLStackc(LinkStackc *s,char data)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	LinkStackcPtr p=(LinkStackcPtr)malloc(sizeof(StackNodec));//�½��p
	p->data=data;
	p->next=s->top;		//��ǰ��ջ����ֵ���µ�Ԫ�صĺ��(ָ���ָ��)
	s->top=p;		//�½ڵ㸳ֵ��ջ��ָ�루��Ԫ�س�Ϊջ��Ԫ�أ�
	s->count++;
	//printf("��ջ��Ԫ��Ϊ��%d",p->data);
	return SUCCESS;
}

//��ջ
Status popLStackc(LinkStackc *s,char *data)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	if(s->count==0)
	{
		printf("ջΪ��\n");
		return ERROR;
	}
	LinkStackcPtr p;		//��ʱ�ڵ�

	*data =s->top->data;	//��ջ��Ԫ��
	p=s->top;		//��ջ��ָ�뽻��p
	s->top=s->top->next;	//ʹ��ջ��ָ������һλ
	free(p);		//�ͷ���ʱ�ڵ�
	s->count--;
	//printf("��ջ��Ԫ��Ϊ��%c\n",*data);
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStackc(LinkStackc *s)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	if(s->count==0)
	{
		//printf("ջΪ��\n");
		return SUCCESS;
	}
	//printf("ջ��Ϊ��\n");
	return ERROR;
}

