#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*������ջ�ĸ��ֲ�������*/

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
	printf("��ʼ���ɹ�\n");
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
		printf("ջΪ��\n");
		return SUCCESS;
	}
	printf("ջ��Ϊ��\n");
	return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
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
	*e=s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	LinkStackPtr p,q;
        p=s->top;
        while(s->count)	//��ÿһ���ڵ�����ͷ�
        {
                q=p;
                p=p->next;
                free(q);
                s->count--;
        }
        printf("��ճɹ�\n");
        return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	free(s->top);
	s->top=NULL;
	printf("���ٳɹ�\n");
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	*length=s->count;
	printf("ջ�ĳ���Ϊ��%d\n",*length);
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	if(!s->top)
	{
		printf("ջδ��ʼ�������ʼ��\n");
		return ERROR;
	}
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));
	printf("��������Ҫ��ջ��Ԫ�أ�");
	int flag=scanf("%d", &data);
	int ch;
	if(!flag)
	{
		printf("�����ʽ�����˳�\n");
		while((ch=getchar())!='\n');
		return ERROR;
	}
	while((ch=getchar())!='\n');
	p->data=data;
	p->next=s->top;		//��ǰ��ջ����ֵ���µ�Ԫ�صĺ��(ָ���ָ��)
	s->top=p;		//�½ڵ㸳ֵ��ջ��ָ�루��Ԫ�س�Ϊջ��Ԫ�أ�
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data)
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
	printf("��ջ��Ԫ��Ϊ��%d\n",*data);
	return SUCCESS;
}

//��ӡջ
Status printLStack(LinkStack *s)
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
	LinkStackPtr p;
	int cnt=s->count;	//��ʼ��������cnt������s->count��ֵ�����޸�
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

//��ʼ����������
void display()
{
	printf("****����ѡ�����****\n");
	printf("*   i����ʼ��ջ    *\n");
	printf("*   a����ջ        *\n");
	printf("*   d����ջ        *\n");
	printf("*   e��ջ�Ƿ�Ϊ��  *\n");
	printf("*   t��ջ��Ԫ��    *\n");
	printf("*   c�����ջ      *\n");
	printf("*   r������ջ      *\n");
	printf("*   l����ջ����    *\n");
	printf("*   p����ӡջ      *\n");
	printf("*   g���˳�����    *\n");
	printf("********************\n");
}
