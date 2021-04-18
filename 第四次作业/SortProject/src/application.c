#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>

//Ӧ��һ���ʺ�����
void swap(int* arr, int i, int j)
{
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void ColorsSort(int* arr, int size)
{
	int i = 0, j = 0, k = size - 1, left = 0, right = size - 1;
	while(left < right)
	{
		for(i = left; i <= right; i++)
		{
			if(arr[i] == 2)
			{
				swap(arr, i, k);
				k--;
				break;
			}
			else if(arr[i] == 0 && i > j)
			{
				swap(arr, i, j);
				j++;
				break;
			}
		}
		left = i;

		for(i = right; i >= left; i--)
		{
			if(arr[i] == 0)
			{
				swap(arr, i, j);
				j++;
				break;
			}
			else if(arr[i] == 2 && i < k)
			{
				swap(arr, i, k);
				k--;
				break;
			}
		}
		right = i;
	}
}

//Ӧ�ö����ҵ�K��
// �Կ����㷨�򵥸��죬���ر��εĻ�׼ֵ�±�
int QuickSort0(int *arr, int left, int right)
{
	if (arr==NULL)
		return -1;
	if (left>right)
		return -1;

	int low = left;
	int high = right;
	// ѡ���׼��
	int temp = arr[left];
	int t;
	while (low<high)
	{
		while (low<high && arr[high]>=temp)
			high--;
		while (low<high && arr[low] <= temp)
			low++;
		if (low<high)
		{
			t = arr[low];
			arr[low] = arr[high];
			arr[high] = t;
		}
	}
	//������˵��low==high, ������׼�����������λ��
	arr[left] = arr[low];
	arr[low] = temp;
	return low;
}

void FindKth(int *arr, int size)
{
	//����Ҫ���ҵĵ�Kλ�������������ж�
	int k;
	printf("��������Ҫ�ҵĵ�K��");
	int flag=scanf("%d",&k);
	while(!flag||k<1||k>size)
	{
		printf("����������������������\n");
		while(getchar()!='\n');
		scanf("%d",&k);
	}

	int mid = QuickSort0(arr, 0, size-1);
	while (mid!=size-k)
	{
		if (mid>size-k)
			mid = QuickSort0(arr, 0, mid-1);
		if (mid<size-k)
			mid = QuickSort0(arr, mid+1, size-1);
	}
	printf("��%d�����Ϊ��%d\n",k,arr[mid]);
}
