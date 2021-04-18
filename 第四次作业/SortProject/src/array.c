#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//生成随机数组
int* get_rand_arr(int *arr, int size, int min, int max)
{
	srand((unsigned)time(NULL));
	int i;
	for (i= 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;//产生max到min的随机数
	}
	return arr;
}

//打印数组
void Print(int *arr,int size)
{
	int i;
	//printf("排序后的结果是：\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
