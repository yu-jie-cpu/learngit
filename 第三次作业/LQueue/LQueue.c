#include "../head/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//��ʼ������
void InitLQueue(LQueue *Q)
{
	//����ͷ��㣬ͷ��㲻�������
	Node *p=(Node*)malloc(sizeof(Node));
	if(p==NULL)
	{
		printf("��ʼ��ʧ��\n");
		return;
	}
	//ͷ��㸳ֵ
	p->next=NULL;
	Q->front=p;
	Q->rear=p;
	Q->length=0;
	printf("��ʼ���ɹ�\n");
}

//���ٶ���
void DestoryLQueue(LQueue *Q)
{
	if(!Q->front)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return;
	}
	//��ն���
	ClearLQueue(Q);
	//�ͷŽ��
	free(Q->front);
	free(Q->rear);
	Q->front=Q->rear=NULL;
	printf("���ٳɹ�\n");
}

//�ж϶����Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue *Q)
{
	if(!Q->front)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return FALSE;
	}
	if(Q->front==Q->rear)
	{
		printf("����Ϊ��\n");
		return TRUE;
	}
	else
	{
		printf("���в�Ϊ��\n");
		return FALSE;
	}
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front==Q->rear)
	{
		printf("����Ϊ�գ��޶�ͷ\n");
		e=NULL;
		return FALSE;
	}
	memcpy(e,Q->front->next->data,8);		//��memcpy���������ַ�
	return TRUE;
}

//��ȡ���г���
int LengthLQueue(LQueue *Q)
{
	if(!Q->front)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return 0;
	}
	int length;
	Node *p=(Node*)malloc(sizeof(Node));
	p=Q->front;
	for(length=0;p!=Q->rear;length++)
		p = p->next;
	return length;
}

//���
Status EnLQueue(LQueue *Q, void *data)
{
	//�����㲢��ֵ
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=(void*)malloc(8);
	memcpy(p->data,data,8);		//��memcpy���������ַ�
	p->next=NULL;
	//�������
	Q->rear->next=p;
	Q->rear=p;
	return TRUE;
}

//����
Status DeLQueue(LQueue *Q)
{
	if(Q->front==Q->rear)
	{
		printf("����Ϊ�գ��޷�����\n");
		return FALSE;
	}
	//��ʱ���p
	Node *p=(Node*)malloc(sizeof(Node));
	p=Q->front->next;
	Q->front->next=p->next;
	//����ֻ�ж�ͷһ��Ԫ��ʱ
	if(Q->front->next==NULL)
	{
		Q->rear=Q->front;
		datatype[1]=5;		//�ֶ�Ĩȥ���ݱ��
	}
	free(p);
        //��Q->length���д������������ͱ��ȫ������ͷǰ�ƣ�
	int i;
	for (i = 1; i < Q->length; i++)
		datatype[i] = datatype[i + 1];	//�ƶ����
	Q->length--;			//���г��ȼ�һ
	printf("���ӳɹ�\n");
	return TRUE;
}

//��ն���
void ClearLQueue(LQueue *Q)
{
	if(!Q->front)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return;
	}
	if(Q->front==Q->rear)
	{
		printf("������Ϊ�գ��������\n");
		return;
	}
	//����p��q������ڲ���
	Node *p,*q;
	Q->rear=Q->front;
	p=Q->front->next;
	//�������ͷ�
	while (p!=NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	Q->length=0;	//�ֶ����г���д0
	datatype[1]=5;	//�ֶ�Ĩȥ���ݱ��
	printf("��ճɹ�\n");
	return;
}

//��������
void LPrint(void *q)
{
	//����typeȷ���������ͣ�ѡ��������
	switch(type)
	{
		case 1:printf("%d -> ", *(int*)q);		break;
		case 2:printf("%c -> ", *(char*)q);		break;
		case 3:printf("%lf -> ", *(double*)q);		break;
		case 4:printf("%s -> ", (char*)q);		break;
	}
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(!Q->front)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return FALSE;
	}
	if(Q->front==Q->rear)
	{
		printf("����Ϊ�գ��޷�����\n");
		return FALSE;
	}
	//������pΪ��ͷ
	Node *p=(void*)malloc(8);
	p=Q->front->next;
	int i = 1;
	while(p != NULL)
	{
		//����datatype[]��type��ֵ
		switch(datatype[i])
		{
			case 1:type=1;	break;
			case 2:type=2;	break;
			case 3:type=3;	break;
			case 4:type=4;	break;
		}
		foo(p->data);
		//����
		p = p->next;
		if (i < Q->length)
			i++;
	}
	printf("\n");
	return TRUE;
}

//���������ʼ��
void display()
{
	printf("***********************\n");
	printf("* i����ʼ������       *\n");
	printf("* r�����ٶ���         *\n");
	printf("* e���ж϶����Ƿ�Ϊ�� *\n");
	printf("* h���鿴��ͷԪ��     *\n");
	printf("* l��ȷ�����г���     *\n");
	printf("* a�����             *\n");
	printf("* d������             *\n");
	printf("* c����ն���         *\n");
	printf("* p����������         *\n");
	printf("* g���˳�����         *\n");
	printf("***********************\n");
}
