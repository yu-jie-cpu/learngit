#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

typedef enum Status
{
    ERROR = 0,
	SUCCESS = 1
} Status;

//�������ܺ���
char *fPalindrome(char *s);		//Ѱ������Ĵ�
char *zTransform(char *s, int num);	//Z���α任

//��ʼ����������
void display();

#endif // STRING_H_INCLUDED
