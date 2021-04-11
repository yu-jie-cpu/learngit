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
					printf("����δ��ʼ�������ʼ��\n");
					break;
				}
				switch(datatype[1])
				{//���ݱ�ǵ��������ͣ���ʼ����Ӧ�ı���
					case 1:{
						int e;
						GetHeadLQueue(&Q,&e);
						printf("��ͷΪ��%d\n",e);
						break;
					}
					case 2:{
						char e;
						GetHeadLQueue(&Q,&e);
						printf("��ͷΪ��%c\n",e);
						break;
					}
					case 3:{
						double e;
						GetHeadLQueue(&Q,&e);
						printf("��ͷΪ��%lf\n",e);
						break;
					}
					case 4:{
						char e[10];
						GetHeadLQueue(&Q,e);
						printf("��ͷΪ��%s\n",e);
						break;
					}
					default:printf("����Ϊ�գ��޶�ͷ\n");
				}
				break;
			}
			case 'l':printf("���еĳ���Ϊ��%d\n",LengthLQueue(&Q));	break;
			case 'a':{
				if(!Q.front)
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
					while(getchar()!='\n');
					break;
				}
				switch(t)
				{//�����û�ѡ��ĵ��������ͣ���ʼ����Ӧ�ı���
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
						Q.length++;		//��Q.length���д�������Ԫ�ؼ�һ��
						datatype[Q.length]=t;	//���������ͽ��б��
						EnLQueue(&Q,&a);
						break;
					}
					case 2: {
						char a;
						getchar();		//�Ե��س�
						printf("������ӵ����� :");
						scanf("%c",&a);
						while(getchar()!='\n');	//�Ե�����ķǻس��ַ����û������ַ�����ʱ��
						Q.length++;		//��Q.length���д�������Ԫ�ؼ�һ��
						datatype[Q.length]=t;	//���������ͽ��б��
						EnLQueue(&Q,&a);
						break;
					}
					case 3:{
						double a;
						printf("������ӵ����� :");
						flag=scanf("%lf",&a);
						//���������ж�
						if(!flag)
						{
							printf("������������������\n");
							while(getchar()!='\n');		//�Ե��ǻس��ַ�
							break;
						}
						Q.length++;		//��Q.length���д�������Ԫ�ؼ�һ��
						datatype[Q.length]=t;	//���������ͽ��б��
						EnLQueue(&Q,&a);
						break;
					}
					case 4:{
						char a[10];
						printf("������ӵ����ݣ���󳤶�Ϊ10��:");
						getchar();		//�Ե��س�
						gets(a);
						Q.length++;		//��Q.length���д�������Ԫ�ؼ�һ��
						datatype[Q.length]=t;	//���������ͽ��б��
						EnLQueue(&Q,a);
						break;
					}
					default:printf("������������������\n");
				}
				break;
			}
			case 'd':DeLQueue(&Q);			break;
			case 'c':ClearLQueue(&Q);		break;
			case 'p':TraverseLQueue(&Q,LPrint);	break;
			default :printf("������������������\n");
		}
		system("pause");
		system("cls");
	}

	return 0;
}
