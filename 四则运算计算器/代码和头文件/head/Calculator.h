#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED


typedef enum Status
{
    ERROR = 0,
	SUCCESS = 1
} Status;

//������ջ
typedef  struct StackNode
{
	double data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;	//ջ��ָ��
	int	count;		//ջ��Ԫ�ظ���
}LinkStack;

//������ջ
typedef  struct StackNodec
{
	char data;
	struct StackNode *next;
}StackNodec, *LinkStackcPtr;

typedef  struct  LinkStackc
{
	LinkStackcPtr top;	//ջ��ָ��
	int	count;		//ջ��Ԫ�ظ���
}LinkStackc;

//������
typedef struct LNode
{
	char sign;
  	struct LNode *next;
} LNode, *LinkedList;

//������ջ��������
Status initLStack(LinkStack *s);		//��ʼ��ջ
Status pushLStack(LinkStack *s,double data);	//��ջ
Status popLStack(LinkStack *s,double *data);	//��ջ
Status isEmptyLStack(LinkStack *s);		//�ж�ջ�Ƿ�Ϊ��

//������ջ��������
Status initLStackc(LinkStackc *s);		//��ʼ��ջ
Status pushLStackc(LinkStackc *s,char data);	//��ջ
Status popLStackc(LinkStackc *s,char *data);	//��ջ
Status isEmptyLStackc(LinkStackc *s);		//�ж�ջ�Ƿ�Ϊ��

//�������������
Status initList(LinkedList *L);			//��ʼ��������
Status insertList(LNode *p, char sign);		//�ڽ��p�������q
Status deleteList(LNode *p, char *sign);	//ɾ�����p֮��ĵ�һ�����
void destroyList(LinkedList *L);		//���ٵ�����

//��������������
Status formulaTransform(LinkedList *p,LinkStackc *s);		//��׺���ʽת��Ϊ��׺���ʽ
Status formulaCalculation(LinkedList *p,LinkStack *s);		//�Ժ�׺���ʽ���м���
void display();							//��ʼ����������
#endif // CALCULATOR_H_INCLUDED
