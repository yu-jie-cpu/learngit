#include "../head/AQueue.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//��ʼ������
void InitAQueue(AQueue *Q)
{
	int i;
	Q->length = MAXQUEUE;
	for(i = 0; i < MAXQUEUE; i++)
	{
		//��֪���û��������������ͣ�����10��̫����int��char������⣩
		Q->data[i] = (void *)malloc(11);
	}
	Q->front = Q->rear = 0;
	printf("��ʼ���ɹ�\n");
}

//���ٶ���
void DestoryAQueue(AQueue *Q)
{

	if(Q->data[0] == NULL)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return;
	}
	//���free
	for(int i = 0; i < MAXQUEUE; i++)
	free(Q->data[i]);
	Q->data[0] = NULL;
	printf("���ٳɹ�\n");
}

//�������Ƿ�����
Status IsFullAQueue(const AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear)					//����Ϊ��
		return FALSE;
	if(Q->rear-Q->front+Q->length%Q->length == MAXQUEUE-1)	//��������
		return TRUE;
	else							//����δ��
		return FALSE;
}

//�������Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

//�鿴��ͷԪ��
Status GetHeadAQueue(AQueue *Q,void *e)
{
	memcpy(e,Q->data[Q->front],10);		//��memcpy���������ַ�
	return TRUE;
}

//ȷ�����г���
int LengthAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return FALSE;
	}
	int len;
	len=Q->rear-Q->front+Q->length;
	return len%Q->length;
}

//���
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("�����������޷����\n");
		return FALSE;
	}
	//����Ϊ�յ����
	if (Q->front==Q->rear)
	{
		memcpy(Q->data[Q->front],data,20);
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		return TRUE;
	}
	//���в�Ϊ�յ����
	memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	return TRUE;
}

//����
Status DeAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return FALSE;
	}
    	if (Q->front==Q->rear)
    	{
    		printf("����Ϊ�գ��޷�����\n");
    		return FALSE;
    	}
    	//�ƶ���ͷ
        Q->front = (Q->front+1) % MAXQUEUE;
        printf("���ӳɹ�\n");
        return TRUE;
}

//��ն���
void ClearAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("����δ��ʼ�������ʼ��\n");
		return;
	}
	if (Q->front==Q->rear)
	{
		printf("������Ϊ�գ��������\n");
		return;
	}
	//ֱ�����ö�ͷ����β
	Q->front = Q->rear = 0;
}

//��������
void APrint(void *q)
{
	//����typeȷ���������ͣ�ѡ��ͬ��������
	switch(type)
	{
		case 1 : printf("%d ->", *(int*)q);		break;
		case 2 : printf("%c ->", *(char*)q);		break;
		case 3 : printf("%lf ->", *(double*)q);	break;
		case 4 : printf("%s ->", (char*)q);		break;
	}
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
        if(Q->data[0] == NULL)
        {
		printf("����δ��ʼ�������ʼ��\n");
		return FALSE;
        }
    	if (Q->front == Q->rear)
    	{
    		printf("����Ϊ�գ��޷�����\n");
    		return FALSE;
    	}
    	//�������в���
    	int i = 0;
    	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE)
	{
		//���ݲ�ͬ�������ͣ�Ϊȫ�ֱ���type��ֵ
		switch(datatype[Q->front+i])
		{
			case 1:type=1;		break;
			case 2:type=2;		break;
			case 3:type=3;		break;
			case 4:type=4;		break;
		}
    		foo(Q->data[Q->front+i]);
    		i = (i+1) % MAXQUEUE;
    	}
    	printf("\n");
        return TRUE;
}

//��ʼ����������
void display()
{
	printf("***********************\n");
	printf("* i����ʼ������       *\n");
	printf("* r�����ٶ���         *\n");
	printf("* f���ж϶����Ƿ����� *\n");
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
