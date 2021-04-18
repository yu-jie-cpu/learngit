#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#define SIZE1  10000
#define SIZE5  50000
#define SIZE20 200000
#define SIZE0  100
#define SIZE3  30

//����ʵ�ֿ��ŷǵݹ��
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

//����ʵ��һ�γ�ʼ��100������
typedef struct Array
{
	int arr[SIZE0];
}Array;

//Sort.c
void InsertionSort(int *arr, int size);				//��������
void MergeSort(int *arr, int start, int end,int size);		//�鲢����
void Merge(int *arr, int start, int mid, int end,int size);
void CountSort(int *arr, int size);				//��������
void RadixSort(int *arr, int size, int dec, int order);		//������������
int  get_index(int num, int dec, int order);
void QuickSort(int *arr, int left, int right);			//���ŵݹ��
void QuickSortNoR(int *arr, int len);				//���ŷǵݹ��
int Quick(int *arr, int start, int end);

//application.c
void ColorsSort(int* arr, int size);	//Ӧ��һ���ʺ�����
void swap(int* nums, int i, int j);
void FindKth(int* a, int szie);		//Ӧ�ö����ҵ�K��
int  QuickSort0(int *arr, int left, int right);

//array.c
int* get_rand_arr(int *arr, int size, int min, int max);	//�����������
void Print(int *arr,int size);					//��ӡ����

//file.c
void load();	//���ļ��ж�ȡ���ݲ���ӡ
void save();	//�������ݵ��ļ�

//display.c
void sort1w();		//1w��������
void sort5w();		//5w��������
void sort20w();		//20w��������
void sort0();		//100*100��������
void appsort();		//2��Ӧ����
void display();		//��ʼ����������

#endif // SORT_H_INCLUDED
