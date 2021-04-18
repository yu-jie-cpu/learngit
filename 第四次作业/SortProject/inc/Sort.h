#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#define SIZE1  10000
#define SIZE5  50000
#define SIZE20 200000
#define SIZE0  100
#define SIZE3  30

//用来实现快排非递归版
typedef struct Peer
{
 	unsigned int start;
 	unsigned int end;
}Peer;

typedef struct Stack
{
 	Peer *data;
 	int   top;
}Stack;

//用来实现一次初始化100组数组
typedef struct Array
{
	int arr[SIZE0];
}Array;

//Sort.c
void InsertionSort(int *arr, int size);				//插入排序
void MergeSort(int *arr, int start, int end,int size);		//归并排序
void Merge(int *arr, int start, int mid, int end,int size);
void CountSort(int *arr, int size);				//计数排序
void RadixSort(int *arr, int size, int dec, int order);		//基数计数排序
int  get_index(int num, int dec, int order);
void QuickSort(int *arr, int left, int right);			//快排递归版
void QuickSortNoR(int *arr, int len);				//快排非递归版
int Quick(int *arr, int start, int end);

//application.c
void ColorsSort(int* arr, int size);	//应用一：彩虹排序
void swap(int* nums, int i, int j);
void FindKth(int* a, int szie);		//应用二：找第K大
int  QuickSort0(int *arr, int left, int right);

//array.c
int* get_rand_arr(int *arr, int size, int min, int max);	//生成随机数组
void Print(int *arr,int size);					//打印数组

//file.c
void load();	//从文件中读取数据并打印
void save();	//保存数据到文件

//display.c
void sort1w();		//1w数据排序
void sort5w();		//5w数据排序
void sort20w();		//20w数据排序
void sort0();		//100*100数据排序
void appsort();		//2道应用题
void display();		//初始化交互界面

#endif // SORT_H_INCLUDED
