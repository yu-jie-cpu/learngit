#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
#include <assert.h>

//插入排序
void InsertionSort(int *arr, int size)
{
	int i, j, temp;

	for(i = 1; i < size; i++)
	{	//从第二个数开始
		if(arr[i] < arr[i-1])	//如果该数比他前面的数小
		{
			temp = arr[i];	//记录下小的值temp
			for(j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j+1] = arr[j];
			}
			arr[j+1] = temp;
		}
	}
}

//归并排序
void Merge(int *arr, int start, int mid, int end, int size)
{
	//int temp[size];		//存放合并排列好的临时数组
	int *temp=(int*)malloc(sizeof(int)*size);
	int k = 0;		//temp数组起点
	int i = start;		//左边起点
	int j = mid + 1;	//右边起点

	while (i <= mid && j <= end)	//左右均未到达末端，其中有一个到了末端退出循环
	{	//把左右两部分合并排列到temp数组中	//哪一边动了，实行自加
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	if (i == mid + 1)		//左边到了末端
	{
		while(j <= end)		//对右边进行操作
			temp[k++] = arr[j++];
	}
	if (j == end + 1)		//右边到了末端
	{
		while (i <= mid)	//对左边进行操作
			temp[k++] = arr[i++];
	}
	for (j = 0, i = start ; j < k; i++, j++)
		arr[i] = temp[j];	//把排列好的temp数组赋值回arr数组

	free(temp);
}

void MergeSort(int *arr, int start, int end, int size)
{
	if(start >= end)
		return;
	int mid = (start + end) / 2;
	MergeSort(arr,start,mid,size);	//左边划分
	MergeSort(arr,mid+1,end,size);	//右边划分
	Merge(arr,start,mid,end,size);	//左右两边进行排序合并
}

//计数排序
void CountSort(int *arr, int size)
{
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max = arr[0], min = arr[0];
	int i=0,j=0;
	for(i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	//使用calloc将数组都初始化为0
	int range = max - min + 1;
	int *temp = (int *)calloc(range, sizeof(int));
	//使用临时数组记录原始数组中每个数的个数
	for (i = 0; i < size; i++)
		temp[arr[i] - min] += 1;	//在存储上要在原始数组数值上减去min才不会出现越界问题
	//对arr数组进行最后的赋值
	for (i = 0; i < range; i++)
	{
		while (temp[i]--)
		{
			arr[j++] = i + min;	//将i的值加上min才能还原到原始数据
		}
	}

	free(temp);
	temp = NULL;
}

//基数计数排序
int get_index(int num, int dec, int order)
{
	int i, j, n;
	int index;
	int div;
	//根据位数，减去不需要的高位数字
	for (i=dec; i>order; i--)
	{
		n = 1;
		for (j=0; j<dec-1; j++)
			n *= 10;
		div = num/n;
		num -= div * n;
		dec--;
	}
	//获得对应位数的整数
	n = 1;
	for (i=0; i<order-1; i++)
		n *= 10;

	//获取index
	index = num / n;
	return index;
}

void RadixSort(int *arr, int size, int dec, int order)
{
	int i, j;
	int index;		//排序索引
	//int temp[size];		//临时数组，用来保存待排序的中间结果
	int *temp=(int*)malloc(sizeof(int)*size);
	int num[10];		//保存索引值的数组
	memset(num, 0, 10*sizeof(int));		//数组初始清零
	memset(temp, 0, size*sizeof(int));	//数组初始清零

	if (dec < order)	//到最高位排序完成
		return;

	for (i=0; i<size; i++)
	{
		index = get_index(arr[i], dec, order);	//获取索引值
		num[index]++;					//对应位加一
	}
	//调整索引数组
	for (i=1; i<10; i++)
		num[i] += num[i-1];

	for (i=size-1; i>=0; i--)
	{
		index = get_index(arr[i], dec, order);  	//从数组尾开始依次获得各个数字的索引
		j = --num[index]; 			 	//根据索引计算该数字在按位排序之后在数组中的位置
		temp[j] = arr[i]; 				//数字放入临时数组
	}
	//从临时数组复制到原数组
	for (i=0; i<size; i++)
		arr[i] = temp[i];
	//继续按高一位的数字大小进行排序
	RadixSort(arr, size, dec, order+1);
}

//快排递归版
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

//快排非递归版
int Quick(int *arr, int start, int end)
{
 	int temp = arr[start];
 	// 大循环，将待排序序列全部访问一遍
 	while (start < end)
 	{
  		//小循环， 从后向前找第一个比基准小的数据，存储到start位置
  		while (start < end)
  		{
   			if (arr[end] < temp)
				break;
			end--;
  		}
  		arr[start] = arr[end];
  		//小循环， 从前向后找第一个比基准大的数据，存储到end位置
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

