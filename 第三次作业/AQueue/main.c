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
					printf("��������\n");
				else
					printf("����δ��\n");
				break;
			}
			case 'e':{
				if(IsEmptyAQueue(Q))
					printf("����Ϊ��\n");
				else
					printf("���в�Ϊ��\n");
				break;
			}
			case 'h':{
				if(Q->data[0] == NULL)
				{
					printf("����δ��ʼ�������ʼ��\n");
					break;
				}
				switch(datatype[Q->front])
				{
					case 1:{
						int e;
						GetHeadAQueue(Q,&e);
						printf("��ͷΪ��%d\n",e);
						break;
					}
					case 2:{
						char e;
						GetHeadAQueue(Q,&e);
						printf("��ͷΪ��%c\n",e);
						break;
					}
					case 3:{
						double e;
						GetHeadAQueue(Q,&e);
						printf("��ͷΪ��%lf\n",e);
						break;
					}
					case 4:{
						char e[10];
						GetHeadAQueue(Q,e);
						printf("��ͷΪ��%s\n",e);
						break;
					}
					default:printf("����Ϊ�գ��޶�ͷ\n");
				}
				break;
			}
			case 'l':{
				printf("���г���Ϊ��%d\n",LengthAQueue(Q));
				break;
			}
			case 'a':{
				if(Q->data[0] == NULL)
				{
					printf("����δ��ʼ�������ʼ��\n");
					break;
				}
				printf("ѡ������ӵ��������ͣ�\n");
				printf("1.int  2.char  3.double  4.char*\n");
				flag=scanf("%d",&t);
				//���������ж�
				if(!flag)
				{
					printf("������������������\n");
					while(getchar()!='\n');		//�Ե��ǻس��ַ�
					break;
				}
				switch(t)
				{
					case 1:{
						int a;
						printf("������ӵ����� :");
						flag=scanf("%d",&a);
						//���������ж�
						if(!flag)
						{
							printf("������������������\n");
							while(getchar()!='\n');		//�Ե��ǻس��ַ�
							break;
						}
						datatype[Q->rear]=t;	//���������ͽ��б��
						EnAQueue(Q,&a);
						break;
					}
					case 2: {
						char a;
						getchar();		//�Ե��س�
						printf("������ӵ����� :");
						scanf("%c",&a);
						while(getchar()!='\n');	//�Ե�����ķǻس��ַ����û������ַ�����ʱ��
						datatype[Q->rear]=t;	//���������ͽ��б��
						EnAQueue(Q,&a);
						break;
					}
					case 3:{
						double a ;
						printf("������ӵ����� :");
						flag=scanf("%lf",&a);
						//���������ж�
						if(!flag)
						{
							printf("������������������\n");
							while(getchar()!='\n');		//�Ե��ǻس��ַ�
							break;
						}
						datatype[Q->rear]=t;	//���������ͽ��б��
						EnAQueue(Q,&a);
						break;
					}
					case 4:{
						char a[10];
						printf("������ӵ����ݣ���󳤶�Ϊ10��:");
						getchar();		//�Ե��س�
						gets(a);
						datatype[Q->rear]=t;	//���������ͽ��б��
						EnAQueue(Q,a);
						break;
					}
					default:printf("������������������\n");
				}
				break;
			}
			case 'd':DeAQueue(Q);			break;
			case 'c':ClearAQueue(Q);		break;
			case 'p':TraverseAQueue(Q,APrint);	break;
			default :printf("������������������\n");
		}
		system("pause");
		system("cls");
	}

	return 0;
}
