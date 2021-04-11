#include "../head/LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//初始化队列
void InitLQueue(LQueue *Q)
{
	//申请头结点，头结点不存放数据
	Node *p=(Node*)malloc(sizeof(Node));
	if(p==NULL)
	{
		printf("初始化失败\n");
		return;
	}
	//头结点赋值
	p->next=NULL;
	Q->front=p;
	Q->rear=p;
	Q->length=0;
	printf("初始化成功\n");
}

//销毁队列
void DestoryLQueue(LQueue *Q)
{
	if(!Q->front)
	{
		printf("队列未初始化，请初始化\n");
		return;
	}
	//清空队列
	ClearLQueue(Q);
	//释放结点
	free(Q->front);
	free(Q->rear);
	Q->front=Q->rear=NULL;
	printf("销毁成功\n");
}

//判断队列是否为空
Status IsEmptyLQueue(const LQueue *Q)
{
	if(!Q->front)
	{
		printf("队列未初始化，请初始化\n");
		return FALSE;
	}
	if(Q->front==Q->rear)
	{
		printf("队列为空\n");
		return TRUE;
	}
	else
	{
		printf("队列不为空\n");
		return FALSE;
	}
}

//查看队头元素
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front==Q->rear)
	{
		printf("队列为空，无队头\n");
		e=NULL;
		return FALSE;
	}
	memcpy(e,Q->front->next->data,8);		//用memcpy函数复制字符
	return TRUE;
}

//获取队列长度
int LengthLQueue(LQueue *Q)
{
	if(!Q->front)
	{
		printf("队列未初始化，请初始化\n");
		return 0;
	}
	int length;
	Node *p=(Node*)malloc(sizeof(Node));
	p=Q->front;
	for(length=0;p!=Q->rear;length++)
		p = p->next;
	return length;
}

//入队
Status EnLQueue(LQueue *Q, void *data)
{
	//申请结点并赋值
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=(void*)malloc(8);
	memcpy(p->data,data,8);		//用memcpy函数复制字符
	p->next=NULL;
	//进行入队
	Q->rear->next=p;
	Q->rear=p;
	return TRUE;
}

//出队
Status DeLQueue(LQueue *Q)
{
	if(Q->front==Q->rear)
	{
		printf("队列为空，无法出队\n");
		return FALSE;
	}
	//临时结点p
	Node *p=(Node*)malloc(sizeof(Node));
	p=Q->front->next;
	Q->front->next=p->next;
	//队列只有队头一个元素时
	if(Q->front->next==NULL)
	{
		Q->rear=Q->front;
		datatype[1]=5;		//手动抹去数据标记
	}
	free(p);
        //对Q->length进行处理，（数据类型标记全体往队头前移）
	int i;
	for (i = 1; i < Q->length; i++)
		datatype[i] = datatype[i + 1];	//移动标记
	Q->length--;			//队列长度减一
	printf("出队成功\n");
	return TRUE;
}

//清空队列
void ClearLQueue(LQueue *Q)
{
	if(!Q->front)
	{
		printf("队列未初始化，请初始化\n");
		return;
	}
	if(Q->front==Q->rear)
	{
		printf("队列已为空，无需清空\n");
		return;
	}
	//定义p，q结点用于操作
	Node *p,*q;
	Q->rear=Q->front;
	p=Q->front->next;
	//结点逐个释放
	while (p!=NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	Q->length=0;	//手动队列长度写0
	datatype[1]=5;	//手动抹去数据标记
	printf("清空成功\n");
	return;
}

//遍历队列
void LPrint(void *q)
{
	//根据type确定数据类型，选择输出语句
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
		printf("队列未初始化，请初始化\n");
		return FALSE;
	}
	if(Q->front==Q->rear)
	{
		printf("队列为空，无法遍历\n");
		return FALSE;
	}
	//申请结点p为队头
	Node *p=(void*)malloc(8);
	p=Q->front->next;
	int i = 1;
	while(p != NULL)
	{
		//根据datatype[]对type赋值
		switch(datatype[i])
		{
			case 1:type=1;	break;
			case 2:type=2;	break;
			case 3:type=3;	break;
			case 4:type=4;	break;
		}
		foo(p->data);
		//遍历
		p = p->next;
		if (i < Q->length)
			i++;
	}
	printf("\n");
	return TRUE;
}

//交互界面初始化
void display()
{
	printf("***********************\n");
	printf("* i：初始化队列       *\n");
	printf("* r：销毁队列         *\n");
	printf("* e：判断队列是否为空 *\n");
	printf("* h：查看队头元素     *\n");
	printf("* l：确定队列长度     *\n");
	printf("* a：入队             *\n");
	printf("* d：出队             *\n");
	printf("* c：清空队列         *\n");
	printf("* p：遍历队列         *\n");
	printf("* g：退出程序         *\n");
	printf("***********************\n");
}
