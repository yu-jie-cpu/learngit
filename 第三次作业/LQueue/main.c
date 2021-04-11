#include "../head/LQueue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	LQueue Q;
	Q.front=Q.rear=NULL;
	char ch;
	int i,t,flag=0;

	while(1)
	{
		display();
		ch=getch();
		if(ch=='g')
			break;
		switch(ch)
		{
			case 'i':InitLQueue(&Q);	break;
			case 'r':DestoryLQueue(&Q);	break;
			case 'e':IsEmptyLQueue(&Q);	break;
			case 'h':{
				if(!Q.front)
				{
					printf("队列未初始化，请初始化\n");
					break;
				}
				switch(datatype[1])
				{//根据标记的数据类型，初始化对应的变量
					case 1:{
						int e;
						GetHeadLQueue(&Q,&e);
						printf("队头为：%d\n",e);
						break;
					}
					case 2:{
						char e;
						GetHeadLQueue(&Q,&e);
						printf("队头为：%c\n",e);
						break;
					}
					case 3:{
						double e;
						GetHeadLQueue(&Q,&e);
						printf("队头为：%lf\n",e);
						break;
					}
					case 4:{
						char e[10];
						GetHeadLQueue(&Q,e);
						printf("队头为：%s\n",e);
						break;
					}
					default:printf("队列为空，无队头\n");
				}
				break;
			}
			case 'l':printf("队列的长度为：%d\n",LengthLQueue(&Q));	break;
			case 'a':{
				if(!Q.front)
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
					while(getchar()!='\n');
					break;
				}
				switch(t)
				{//根据用户选择的的数据类型，初始化对应的变量
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
						Q.length++;		//对Q.length进行处理（插入元素加一）
						datatype[Q.length]=t;	//对数据类型进行标记
						EnLQueue(&Q,&a);
						break;
					}
					case 2: {
						char a;
						getchar();		//吃掉回车
						printf("输入入队的数据 :");
						scanf("%c",&a);
						while(getchar()!='\n');	//吃掉多余的非回车字符（用户输入字符超出时）
						Q.length++;		//对Q.length进行处理（插入元素加一）
						datatype[Q.length]=t;	//对数据类型进行标记
						EnLQueue(&Q,&a);
						break;
					}
					case 3:{
						double a;
						printf("输入入队的数据 :");
						flag=scanf("%lf",&a);
						//错误输入判断
						if(!flag)
						{
							printf("输入有误，请重新输入\n");
							while(getchar()!='\n');		//吃掉非回车字符
							break;
						}
						Q.length++;		//对Q.length进行处理（插入元素加一）
						datatype[Q.length]=t;	//对数据类型进行标记
						EnLQueue(&Q,&a);
						break;
					}
					case 4:{
						char a[10];
						printf("输入入队的数据（最大长度为10）:");
						getchar();		//吃掉回车
						gets(a);
						Q.length++;		//对Q.length进行处理（插入元素加一）
						datatype[Q.length]=t;	//对数据类型进行标记
						EnLQueue(&Q,a);
						break;
					}
					default:printf("输入有误，请重新输入\n");
				}
				break;
			}
			case 'd':DeLQueue(&Q);			break;
			case 'c':ClearLQueue(&Q);		break;
			case 'p':TraverseLQueue(&Q,LPrint);	break;
			default :printf("输入有误，请重新输入\n");
		}
		system("pause");
		system("cls");
	}

	return 0;
}
