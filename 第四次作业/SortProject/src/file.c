#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void load()
{
	FILE *fp=fopen("data.txt","r");
	int i,arr[6];
	char str[30];
	setvbuf(fp, NULL, _IONBF, 0);//设置缓冲模式为无缓冲

	while(!feof(fp))	//文件未到末尾
	{
		fgets(str,30,fp);
		if(feof(fp))	//防止最后一行重复打印
			break;
		printf("%s",str);
	}
	fclose(fp);
}

void save(int *arr,int cnt)
{
	FILE *fp = fopen("data.txt","a+");
	int i;
	char str1[]="这是1w数据排序的测试数据：\n";
	char str5[]="这是5w数据排序的测试数据：\n";
	char str20[]="这是20w数据排序的测试数据：\n";
	char str100[]="这是100*100数据排序的测试数据：\n";

	setvbuf(fp, NULL, _IONBF, 0);//设置缓冲模式为无缓冲

	switch(cnt)
	{
		case 1:fprintf(fp ,"%s",str1);		break;
		case 5:fprintf(fp ,"%s",str5);		break;
		case 20:fprintf(fp ,"%s",str20);	break;
		case 100:fprintf(fp ,"%s",str100);	break;
		default :printf("输入的cnt有问题！！！\n");
	}

	for(i = 0; i < 6; i++)
	{	//写入数据
		fprintf(fp ,"%d  ", arr[i]);
	}
	fprintf(fp ,"\n");
	fclose(fp);
}

