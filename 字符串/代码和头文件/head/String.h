#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

typedef enum Status
{
    ERROR = 0,
	SUCCESS = 1
} Status;

//两个功能函数
char *fPalindrome(char *s);		//寻找最长回文串
char *zTransform(char *s, int num);	//Z字形变换

//初始化交互界面
void display();

#endif // STRING_H_INCLUDED
