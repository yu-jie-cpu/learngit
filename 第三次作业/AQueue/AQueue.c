#include "../head/AQueue.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//初始化队列
void InitAQueue(AQueue *Q)
{
	int i;
	Q->length = MAXQUEUE;
	for(i = 0; i < MAXQUEUE; i++)
	{
		//不知道用户想放入的数据类型，给个10（太多了int和char会出问题）
		Q->data[i] = (void *)malloc(11);
	}
	Q->front = Q->rear = 0;
	printf("初始化成功\n");
}

//销毁队列
void DestoryAQueue(AQueue *Q)
{

	if(Q->data[0] == NULL)
	{
		printf("队列未初始化，请初始化\n");
		return;
	}
	//逐个free
	for(int i = 0; i < MAXQUEUE; i++)
	free(Q->data[i]);
	Q->data[0] = NULL;
	printf("销毁成功\n");
}

//检查队列是否已满
Status IsFullAQueue(const AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("队列未初始化，请初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear)					//队列为空
		return FALSE;
	if(Q->rear-Q->front+Q->length%Q->length == MAXQUEUE-1)	//队列满了
		return TRUE;
	else							//队列未满
		return FALSE;
}

//检查队列是否为空
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("队列未初始化，请初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

//查看队头元素
Status GetHeadAQueue(AQueue *Q,void *e)
{
	memcpy(e,Q->data[Q->front],10);		//用memcpy函数复制字符
	return TRUE;
}

//确定队列长度
int LengthAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("队列未初始化，请初始化\n");
		return FALSE;
	}
	int len;
	len=Q->rear-Q->front+Q->length;
	return len%Q->length;
}

//入队
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		printf("队列已满，无法入队\n");
		return FALSE;
	}
	//队列为空的情况
	if (Q->front==Q->rear)
	{
		memcpy(Q->data[Q->front],data,20);
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		return TRUE;
	}
	//队列不为空的情况
	memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	return TRUE;
}

//出队
Status DeAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("队列未初始化，请初始化\n");
		return FALSE;
	}
    	if (Q->front==Q->rear)
    	{
    		printf("队列为空，无法出队\n");
    		return FALSE;
    	}
    	//移动队头
        Q->front = (Q->front+1) % MAXQUEUE;
        printf("出队成功\n");
        return TRUE;
}

//清空队列
void ClearAQueue(AQueue *Q)
{
	if(Q->data[0] == NULL)
	{
		printf("队列未初始化，请初始化\n");
		return;
	}
	if (Q->front==Q->rear)
	{
		printf("队列已为空，无需清空\n");
		return;
	}
	//直接重置队头、队尾
	Q->front = Q->rear = 0;
}

//遍历队列
void APrint(void *q)
{
	//根据type确定数据类型，选择不同的输出语句
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
		printf("队列未初始化，请初始化\n");
		return FALSE;
        }
    	if (Q->front == Q->rear)
    	{
    		printf("队列为空，无法遍历\n");
    		return FALSE;
    	}
    	//遍历队列操作
    	int i = 0;
    	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE)
	{
		//根据不同数据类型，为全局变量type赋值
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

//初始化交互界面
void display()
{
	printf("***********************\n");
	printf("* i：初始化队列       *\n");
	printf("* r：销毁队列         *\n");
	printf("* f：判断队列是否以满 *\n");
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
