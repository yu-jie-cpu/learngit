#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <assert.h>

//��������
void InsertionSort(int *arr, int size)
{
	int i, j, temp;

	for(i = 1; i < size; i++)
	{	//�ӵڶ�������ʼ
		if(arr[i] < arr[i-1])	//�����������ǰ�����С
		{
			temp = arr[i];	//��¼��С��ֵtemp
			for(j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j+1] = arr[j];
			}
			arr[j+1] = temp;
		}
	}
}

//�鲢����
void Merge(int *arr, int start, int mid, int end, int size)
{
	//int temp[size];		//��źϲ����кõ���ʱ����
	int *temp=(int*)malloc(sizeof(int)*size);
	int k = 0;		//temp�������
	int i = start;		//������
	int j = mid + 1;	//�ұ����

	while (i <= mid && j <= end)	//���Ҿ�δ����ĩ�ˣ�������һ������ĩ���˳�ѭ��
	{	//�����������ֺϲ����е�temp������	//��һ�߶��ˣ�ʵ���Լ�
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	if (i == mid + 1)		//��ߵ���ĩ��
	{
		while(j <= end)		//���ұ߽��в���
			temp[k++] = arr[j++];
	}
	if (j == end + 1)		//�ұߵ���ĩ��
	{
		while (i <= mid)	//����߽��в���
			temp[k++] = arr[i++];
	}
	for (j = 0, i = start ; j < k; i++, j++)
		arr[i] = temp[j];	//�����кõ�temp���鸳ֵ��arr����

	free(temp);
}

void MergeSort(int *arr, int start, int end, int size)
{
	if(start >= end)
		return;
	int mid = (start + end) / 2;
	MergeSort(arr,start,mid,size);	//��߻���
	MergeSort(arr,mid+1,end,size);	//�ұ߻���
	Merge(arr,start,mid,end,size);	//�������߽�������ϲ�
}

//��������
void CountSort(int *arr, int size)
{
	//ͨ��max��min�������ʱ��������Ҫ���ٵĿռ��С
	int max = arr[0], min = arr[0];
	int i=0,j=0;
	for(i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	//ʹ��calloc�����鶼��ʼ��Ϊ0
	int range = max - min + 1;
	int *temp = (int *)calloc(range, sizeof(int));
	//ʹ����ʱ�����¼ԭʼ������ÿ�����ĸ���
	for (i = 0; i < size; i++)
		temp[arr[i] - min] += 1;	//�ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�Ų������Խ������
	//��arr����������ĸ�ֵ
	for (i = 0; i < range; i++)
	{
		while (temp[i]--)
		{
			arr[j++] = i + min;	//��i��ֵ����min���ܻ�ԭ��ԭʼ����
		}
	}

	free(temp);
	temp = NULL;
}

//������������
int get_index(int num, int dec, int order)
{
	int i, j, n;
	int index;
	int div;
	//����λ������ȥ����Ҫ�ĸ�λ����
	for (i=dec; i>order; i--)
	{
		n = 1;
		for (j=0; j<dec-1; j++)
			n *= 10;
		div = num/n;
		num -= div * n;
		dec--;
	}
	//��ö�Ӧλ��������
	n = 1;
	for (i=0; i<order-1; i++)
		n *= 10;

	//��ȡindex
	index = num / n;
	return index;
}

void RadixSort(int *arr, int size, int dec, int order)
{
	int i, j;
	int index;		//��������
	//int temp[size];		//��ʱ���飬���������������м���
	int *temp=(int*)malloc(sizeof(int)*size);
	int num[10];		//��������ֵ������
	memset(num, 0, 10*sizeof(int));		//�����ʼ����
	memset(temp, 0, size*sizeof(int));	//�����ʼ����

	if (dec < order)	//�����λ�������
		return;

	for (i=0; i<size; i++)
	{
		index = get_index(arr[i], dec, order);	//��ȡ����ֵ
		num[index]++;					//��Ӧλ��һ
	}
	//������������
	for (i=1; i<10; i++)
		num[i] += num[i-1];

	for (i=size-1; i>=0; i--)
	{
		index = get_index(arr[i], dec, order);  	//������β��ʼ���λ�ø������ֵ�����
		j = --num[index]; 			 	//������������������ڰ�λ����֮���������е�λ��
		temp[j] = arr[i]; 				//���ַ�����ʱ����
	}
	//����ʱ���鸴�Ƶ�ԭ����
	for (i=0; i<size; i++)
		arr[i] = temp[i];
	//��������һλ�����ִ�С��������
	RadixSort(arr, size, dec, order+1);
}

//���ŵݹ��
void QuickSort(int *arr, int left, int right)
{
	int l = left, r = right;
	int temp, refer;
	refer = arr[(left + right) / 2];
	while (l <= r)
	{
		while (arr[l] < refer)
			l++;
		while (arr[r] > refer)
			r--;
		if (l <= r)
		{
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
		}
	}
	if (left < l)
		QuickSort(arr, left, r);
	if (r < right)
		QuickSort(arr, l, right);
}

//���ŷǵݹ��
int Quick(int *arr, int start, int end)
{
 	int temp = arr[start];
 	// ��ѭ����������������ȫ������һ��
 	while (start < end)
 	{
  		//Сѭ���� �Ӻ���ǰ�ҵ�һ���Ȼ�׼С�����ݣ��洢��startλ��
  		while (start < end)
  		{
   			if (arr[end] < temp)
				break;
			end--;
  		}
  		arr[start] = arr[end];
  		//Сѭ���� ��ǰ����ҵ�һ���Ȼ�׼������ݣ��洢��endλ��
  		while (start < end)
  		{
   			if (arr[start] > temp)
				break;
			start++;
  		}
  		arr[end] = arr[start];
 	}
 	arr[start] = temp;
 	return start;
}

void QuickSortNoR(int *arr, int len)
{
 	Stack *st=(Stack*)malloc(sizeof(Stack));
 	st->data = (Peer *)malloc(sizeof(Peer) * len/4);
 	assert(st->data != NULL);
 	st->top = 0;

 	Peer peer;
 	peer.start = 0;
 	peer.end = len - 1;
 	st->data[st->top++] = peer;

	Peer new_peer;
 	while (st->top != 0)
 	{
  		peer = st->data[--st->top];
  		int mod = Quick(arr, peer.start, peer.end);

  		if (peer.end - mod > 1)
  		{
   			new_peer.start =  mod + 1;
   			new_peer.end =  peer.end;
   			st->data[st->top++] = new_peer;
  		}
  		if (mod - peer.start > 1)
  		{
   			new_peer.start = peer.start;
   			new_peer.end = mod - 1;
   			st->data[st->top++] = new_peer;
  		}
 	}

 	free(st->data);
	free(st);
}

