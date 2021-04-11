#include "../head/AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	AQueue *Q=(AQueue*)malloc(sizeof(AQueue));
	Q->data[0]=NULL;
	int t,flag=0;
        char ch;
        while(1)
	{
		display();
		ch=getch();
		if(ch=='g')
			break;
		switch(ch)
		{
			case 'i':InitAQueue(Q);			break;
			case 'r':DestoryAQueue(Q);		break;
			case 'f':{
				if(IsFullAQueue(Q))
					printf("队列已满\n");
				else
					printf("队列未满\n");
				break;
			}
			case 'e':{
				if(IsEmptyAQueue(Q))
					printf("队列为空\n");
				else
					printf("队列不为空\n");
				break;
			}
			case 'h':{
				if(Q->data[0] == NULL)
				{
					printf("队列未初始化，请初始化\n");
					break;
				}
				switch(datatype[Q->front])
				{
					case 1:{
						int e;
						GetHeadAQueue(Q,&e);
						printf("队头为：%d\n",e);
						break;
					}
					case 2:{
						char e;
						GetHeadAQueue(Q,&e);
						printf("队头为：%c\n",e);
						break;
					}
					case 3:{
						double e;
						GetHeadAQueue(Q,&e);
						printf("队头为：%lf\n",e);
						break;
					}
					case 4:{
						char e[10];
						GetHeadAQueue(Q,e);
						printf("队头为：%s\n",e);
						break;
					}
					default:printf("队列为空，无队头\n");
				}
				break;
			}
			case 'l':{
				printf("队列长度为：%d\n",LengthAQueue(Q));
				break;
			}
			case 'a':{
				if(Q->data[0] == NULL)
				{
					printf("队列未初始化，请初始化\n");
					break;
				}
				printf("选择想入队的数据类型：\n");
				printf("1.int  2.char  3.double  4.char*\n");
				flag=scanf("%d",&t);
				//错误输入判断
				if(!flag)
				{
					printf("输入有误，请重新输入\n");
					while(getchar()!='\n');		//吃掉非回车字符
					break;
				}
				switch(t)
				{
					case 1:{
						int a;
						printf("输入入队的数据 :");
						flag=scanf("%d",&a);
						//错误输入判断
						if(!flag)
						{
							printf("输入有误，请重新输入\n");
							while(getchar()!='\n');		//吃掉非回车字符
							break;
						}
						datatype[Q->rear]=t;	//对数据类型进行标记
						EnAQueue(Q,&a);
						break;
					}
					case 2: {
						char a;
						getchar();		//吃掉回车
						printf("输入入队的数据 :");
						scanf("%c",&a);
						while(getchar()!='\n');	//吃掉多余的非回车字符（用户输入字符超出时）
						datatype[Q->rear]=t;	//对数据类型进行标记
						EnAQueue(Q,&a);
						break;
					}
					case 3:{
						double a ;
						printf("输入入队的数据 :");
						flag=scanf("%lf",&a);
						//错误输入判断
						if(!flag)
						{
							printf("输入有误，请重新输入\n");
							while(getchar()!='\n');		//吃掉非回车字符
							break;
						}
						datatype[Q->rear]=t;	//对数据类型进行标记
						EnAQueue(Q,&a);
						break;
					}
					case 4:{
						char a[10];
						printf("输入入队的数据（最大长度为10）:");
						getchar();		//吃掉回车
						gets(a);
						datatype[Q->rear]=t;	//对数据类型进行标记
						EnAQueue(Q,a);
						break;
					}
					default:printf("输入有误，请重新输入\n");
				}
				break;
			}
			case 'd':DeAQueue(Q);			break;
			case 'c':ClearAQueue(Q);		break;
			case 'p':TraverseAQueue(Q,APrint);	break;
			default :printf("输入有误，请重新输入\n");
		}
		system("pause");
		system("cls");
	}

	return 0;
}
