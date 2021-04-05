#include "../head/Calculator.h"
#include <stdio.h>
#include <stdlib.h>

//����׺���ʽ����ת��Ϊ��׺���ʽ
//�õ�����Ѻ�׺���ʽ��β�巨��������

//��ͷ��㿪ʼ��ȡ�������еĺ�׺���ʽ
//��ջ�Զ�ȡ�����ĺ�׺���ʽ���м���

//��׺���ʽת��Ϊ��׺���ʽ����һ��ʹ�÷�����ջ��
Status formulaTransform(LinkedList *p,LinkStackc *s)
{
	//��׺ת��Ϊ��׺
	char c,e;
	char k='$';

	printf("��������׺���ʽ,��#��Ϊ������\n");
	scanf("%c",&c);
	printf("����׺���ʽת��Ϊ��׺���ʽΪ��\n");

	while(c!='#')
	{
		//��һ�����֣�double�����д�����棨��$��ʾһ����������
		while((c>='0'&&c<='9')||c=='.')
		{
			printf("%c",c);
			insertList(*p,c);
			scanf("%c",&c);
			if(c<'0'||c>'9')
			{
				if(c=='.')
				{
					continue;
				}
				printf(" ");
				insertList(*p,k);
				break;
			}
		}
		//�Բ�ͬ���ȼ�����������д���
		if(c==')')
		{
			popLStackc(&(*s),&e);
			while(e!='(')
			{
				printf("%c ",e);
				insertList(*p,e);
				insertList(*p,k);
				popLStackc(&(*s),&e);
			}
		}
		else if(c=='+'||c=='-')
		{
			if(isEmptyLStackc(&(*s)))
			{
				pushLStackc(&(*s),c);
			}
			else
			{
				do
				{
					popLStackc(&(*s),&e);
					if(e=='(')
					{
						pushLStackc(&(*s),e);
					}
					else
					{
						printf("%c ",e);
						insertList(*p,e);
						insertList(*p,k);
					}
				}while(!isEmptyLStackc(&(*s))&&e!='(');
				pushLStackc(&(*s),c);
			}
		}
		else if(c=='*'||c=='/'||c=='(')
		{
			pushLStackc(&(*s),c);
		}
		else if(c=='#')
		{
			getchar();	//�Ե�#������ڻ������Ļس�����ֹ�ڵڶ��μ���ʱ���������
			break;
		}
		else if(c=='\n')
		{
			break;
		}
		else
		{
			printf("�������\n");
			while(getchar()!='\n');	//�Ե������������ڻ������������ַ�
			return ERROR;
		}
		scanf("%c",&c);
	}
	while(!isEmptyLStackc(&(*s)))
	{
		popLStackc(&(*s),&e);
		printf("%c ",e);
		insertList(*p,e);
		insertList(*p,k);
	}
	//���û���������#������������ô���
	if(c!='#')
	{
		printf("\n������ı��ʽû�н�����#\n");
		destroyList(p);
		initList(p);
		return ERROR;
	}
	insertList(*p,c);	//�Ե�����д��#��ʾһ��ʽ�ӽ���
	printf("\n");
	return SUCCESS;
}

//�Ժ�׺���ʽ���м��㣨��һ��ʹ��������ջ��
Status formulaCalculation(LinkedList *p,LinkStack *s)
{
	char c;
	char str[20];
	double a,b,d;
	int i=0;

	//scanf("%c",&c);
	deleteList(*p,&c);

	while(c!='#')
	{
		//�Դ���õ�һ������������ת���������charת��Ϊһ��double��������ջ
		while((c>='0'&&c<='9')||c=='.')
		{
			str[i++]=c;
			str[i]='\0';
			if(i>=20)
			{
				printf("������������ݹ���\n");
				return ERROR;
			}
			//scanf("%c",&c);
			deleteList(*p,&c);
			if(c=='$')		//$��־��һ�������������
			{
				d=atof(str);
				pushLStack(&(*s),d);
				i=0;
				break;
			}
		}
		//��������д����˴�Ϊ�Ѿ�ת���õĺ�׺���ʽ�������迼�����ȼ���
		switch(c)
		{
			case '+': {
				popLStack(&(*s),&a);
				popLStack(&(*s),&b);
				pushLStack(&(*s),a+b);
				break;
			}
			case '-': {
				popLStack(&(*s),&a);
				popLStack(&(*s),&b);
				pushLStack(&(*s),b-a);
				break;
			}
			case '*': {
				popLStack(&(*s),&a);
				popLStack(&(*s),&b);
				pushLStack(&(*s),a*b);
				break;
			}
			case '/': {
				popLStack(&(*s),&a);
				popLStack(&(*s),&b);
				//�Գ���a�жϣ���������Ϊ0
				if(a!=0)
				{
					pushLStack(&(*s),b/a);
				}
				else
				{
					//���ò���
					printf("\n����Ϊ0����������\n");
					destroyList(p);
					initList(p);
					return ERROR;
				}
				break;
			}
		}
		//scanf("%c",&c);
		deleteList(*p,&c);
	}
	popLStack(&(*s),&d);		//ջ�����ʣһ������Ϊʽ�����ļ�����
	printf("������Ϊ��%.2f\n",d);
	getchar();	//�Ե����ڻ������Ļس��������ʽ��()ʱ��
	return SUCCESS;
}

//��ʼ����������
void display()
{
	printf("*****������*****\n");
	printf("* c���������  *\n");
	printf("* g���˳�����  *\n");
	printf("****************\n");
}
