#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�����������
int* get_rand_arr(int *arr, int size, int min, int max)
{
	srand((unsigned)time(NULL));
	int i;
	for (i= 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;//����max��min�������
	}
	return arr;
}

//��ӡ����
void Print(int *arr,int size)
{
	int i;
	//printf("�����Ľ���ǣ�\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
