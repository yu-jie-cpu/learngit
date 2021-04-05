#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/*����˳��ջ�ĸ��ֲ�������*/

//��ʼ��ջ
Status initStack(SqStack* s, int sizes)
{
	printf("��������Ҫ������ջ�Ĵ�С��");
	int flag=scanf("%d", &sizes);
	int ch;
	if(!flag)
	{
		printf("�����ʽ�����˳�\n");
		while((ch=getchar())!='\n');
		return ERROR;
	}
	while((ch=getchar())!='\n');
	s->elem = (int*)malloc(sizeof(int) * sizes);
	s->top = -1;
	s->size = sizes;
	if (!s->elem)		//s->elem=NULL
	{
		printf("��ʼ��ʧ��\n");
		return ERROR;
	}
	else
	{
		printf("��ʼ���ɹ�\n");
		return SUCCESS;
	}
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack* s)
{
	if (!s->elem)
	{
		printf("ջδ��ʼ��\n");
		return ERROR;
	}
	if (s->top == -1)
	{
		printf("ջ����\n");
		return SUCCESS;
	}
	printf("ջ��Ϊ��\n");
	return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e)
{
	if (!s->elem)
	{
		printf("ջδ��ʼ��\n");
		return ERROR;
	}
	if(s->top==-1)
	{
		printf("ջ����\n");
		return SUCCESS;
	}
	*e = s->elem[s->top];
	printf("ջ��Ԫ���ǣ�%d\n", *e);
	return SUCCESS;
}

//���ջ
Status clearStack(SqStack *s)
{
	if (!s->elem)
	{
		printf("ջδ��ʼ��\n");
		return ERROR;
	}
	s->top=-1;
	printf("��ճɹ�\n");
	return SUCCESS;
}

//����ջ
Status destroyStack(SqStack *s)
{
	if (!s->elem)
	{
		printf("ջδ��ʼ��\n");
		return ERROR;
	}
	free(s->elem);
	s->elem=NULL;
	if (!(s->elem))	//s->elem=NULL
	{
		printf("���ٳɹ�\n");
		return SUCCESS;
	}
	return ERROR;
}

//���ջ����
Status stackLength(SqStack *s,int *length)
{
	if (!s->elem)
	{
		printf("ջδ��ʼ��\n");
		return ERROR;
	}
	if (s->top == -1)
	{
		printf("ջ����\n");
		return SUCCESS;
	}
	*length=(s->top+1);
	printf("ջ�ĳ���Ϊ��%d\n", *length);
	return SUCCESS;
}

//��ջ
Status pushStack(SqStack *s,ElemType data)
{
	if (!s->elem)
	{
		printf("ջδ��ʼ��\n");
		return ERROR;
	}
	if((s->top+1)>=s->size)
	{
		printf("ջ����\n");
		return ERROR;
	}
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
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

//��ջ
Status popStack(SqStack *s,ElemType *data)
{
	if (!s->elem)
	{
		printf("ջδ��ʼ��\n");
		return ERROR;
	}
	if(s->top==-1)
	{
		printf("ջ����\n");
		return SUCCESS;
	}
	*data=s->elem[s->top];
	s->top--;
	printf("��ջ��Ԫ���ǣ�%d\n", *data);
	return SUCCESS;
}

//��ӡջ
Status printStack(SqStack *s)
{
	if (!s->elem)
	{
		printf("ջδ��ʼ��\n");
		return ERROR;
	}
	int cnt=s->top;		//��ʼ��������������s->top��ֵ
	while(cnt!=-1)
	{
		printf("%d ",s->elem[cnt]);
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
