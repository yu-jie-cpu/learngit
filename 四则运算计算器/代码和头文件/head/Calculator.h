#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED


typedef enum Status
{
    ERROR = 0,
	SUCCESS = 1
} Status;

//数据链栈
typedef  struct StackNode
{
	double data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;	//栈顶指针
	int	count;		//栈中元素个数
}LinkStack;

//符号链栈
typedef  struct StackNodec
{
	char data;
	struct StackNode *next;
}StackNodec, *LinkStackcPtr;

typedef  struct  LinkStackc
{
	LinkStackcPtr top;	//栈顶指针
	int	count;		//栈中元素个数
}LinkStackc;

//单链表
typedef struct LNode
{
	char sign;
  	struct LNode *next;
} LNode, *LinkedList;

//数据链栈操作函数
Status initLStack(LinkStack *s);		//初始化栈
Status pushLStack(LinkStack *s,double data);	//入栈
Status popLStack(LinkStack *s,double *data);	//出栈
Status isEmptyLStack(LinkStack *s);		//判断栈是否为空

//符号链栈操作函数
Status initLStackc(LinkStackc *s);		//初始化栈
Status pushLStackc(LinkStackc *s,char data);	//入栈
Status popLStackc(LinkStackc *s,char *data);	//出栈
Status isEmptyLStackc(LinkStackc *s);		//判断栈是否为空

//单链表操作函数
Status initList(LinkedList *L);			//初始化单链表
Status insertList(LNode *p, char sign);		//在结点p后插入结点q
Status deleteList(LNode *p, char *sign);	//删除结点p之后的第一个结点
void destroyList(LinkedList *L);		//销毁单链表

//计算器操作函数
Status formulaTransform(LinkedList *p,LinkStackc *s);		//中缀表达式转换为后缀表达式
Status formulaCalculation(LinkedList *p,LinkStack *s);		//对后缀表达式进行计算
void display();							//初始化交互界面
#endif // CALCULATOR_H_INCLUDED
