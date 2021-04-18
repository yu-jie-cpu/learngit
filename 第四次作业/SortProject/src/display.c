#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1w���ݵ�����
void sort1w()
{
	int *arr1=(int*)malloc(sizeof(int)*SIZE1);
	int dec=3,order=1;
	clock_t start,diff[6];

	get_rand_arr(arr1,SIZE1,100,999);	//��ʼ������
	start=clock();
	InsertionSort(arr1,SIZE1);		//��������
	diff[0]=clock()-start;			//��������ʱ��
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[0]);

	get_rand_arr(arr1,SIZE1,100,999);
	start=clock();
	MergeSort(arr1,0,SIZE1-1,SIZE1);
	diff[1]=clock()-start;
	printf("�鲢��������ʱ��Ϊ��%dms\n",(int)diff[1]);

	get_rand_arr(arr1,SIZE1,100,999);
	start=clock();
	CountSort(arr1,SIZE1);
	diff[2]=clock()-start;
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[2]);

	get_rand_arr(arr1,SIZE1,100,999);
	start=clock();
	RadixSort(arr1,SIZE1,dec,order);
	diff[3]=clock()-start;
	printf("����������������ʱ��Ϊ��%dms\n",(int)diff[3]);

	get_rand_arr(arr1,SIZE1,100,999);
	start=clock();
	QuickSort(arr1,0,SIZE1-1);
	diff[4]=clock()-start;
	printf("���ŵݹ������ʱ��Ϊ��%dms\n",(int)diff[4]);

	get_rand_arr(arr1,SIZE1,100,999);
	start=clock();
	QuickSortNoR(arr1,SIZE1);
	diff[5]=clock()-start;
	printf("���ŷǵݹ������ʱ��Ϊ��%dms\n",(int)diff[5]);

	save(diff,1);
}

//5w���ݵ�����
void sort5w()
{
	int *arr5=(int*)malloc(sizeof(int)*SIZE5);
	int dec=3,order=1;
	clock_t start,diff[6];

	get_rand_arr(arr5,SIZE5,100,999);
	start=clock();
	InsertionSort(arr5,SIZE5);
	diff[0]=clock()-start;
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[0]);

	get_rand_arr(arr5,SIZE5,100,999);
	start=clock();
	MergeSort(arr5,0,SIZE5-1,SIZE5);
	diff[1]=clock()-start;
	printf("�鲢��������ʱ��Ϊ��%dms\n",(int)diff[1]);

	get_rand_arr(arr5,SIZE5,100,999);
	start=clock();
	CountSort(arr5,SIZE5);
	diff[2]=clock()-start;
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[2]);

	get_rand_arr(arr5,SIZE5,100,999);
	start=clock();
	RadixSort(arr5,SIZE5,dec,order);
	diff[3]=clock()-start;
	printf("����������������ʱ��Ϊ��%dms\n",(int)diff[3]);

	get_rand_arr(arr5,SIZE5,100,999);
	start=clock();
	QuickSort(arr5,0,SIZE5-1);
	diff[4]=clock()-start;
	printf("���ŵݹ������ʱ��Ϊ��%dms\n",(int)diff[4]);

	get_rand_arr(arr5,SIZE5,100,999);
	start=clock();
	QuickSortNoR(arr5,SIZE5);
	diff[5]=clock()-start;
	printf("���ŷǵݹ������ʱ��Ϊ��%dms\n",(int)diff[5]);

	save(diff,5);
}

//20w���ݵ�����
void sort20w()
{
	int *arr20=(int*)malloc(sizeof(int)*SIZE20);
	int dec=3,order=1;
	clock_t start,diff[6];

	get_rand_arr(arr20,SIZE20,100,999);
	start=clock();
	InsertionSort(arr20,SIZE20);
	diff[0]=clock()-start;
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[0]);

	get_rand_arr(arr20,SIZE20,100,999);
	start=clock();
	MergeSort(arr20,0,SIZE20-1,SIZE20);
	diff[1]=clock()-start;
	printf("�鲢��������ʱ��Ϊ��%dms\n",(int)diff[1]);

	get_rand_arr(arr20,SIZE20,100,999);
	start=clock();
	CountSort(arr20,SIZE20);
	diff[2]=clock()-start;
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[2]);

	get_rand_arr(arr20,SIZE20,100,999);
	start=clock();
	RadixSort(arr20,SIZE20,dec,order);
	diff[3]=clock()-start;
	printf("����������������ʱ��Ϊ��%dms\n",(int)diff[3]);

	get_rand_arr(arr20,SIZE20,100,999);
	start=clock();
	QuickSort(arr20,0,SIZE20-1);
	diff[4]=clock()-start;
	printf("���ŵݹ������ʱ��Ϊ��%dms\n",(int)diff[4]);

	get_rand_arr(arr20,SIZE20,100,999);
	start=clock();
	QuickSortNoR(arr20,SIZE20);
	diff[5]=clock()-start;
	printf("���ŷǵݹ������ʱ��Ϊ��%dms\n",(int)diff[5]);

	save(diff,20);
}

//100*100��������
void sort0()
{
	Array *Arr=(Array*)malloc(sizeof(Array)*SIZE0);//SIZE0���СΪSIZE0������
	int dec=3,order=1;
	int i;
	clock_t start,diff[6];

	for(i=0;i<SIZE0;i++)	//��ʼ��100������
		get_rand_arr(Arr[i].arr,SIZE0,100,999);
	start=clock();
	for(i=0;i<SIZE0;i++)	//����100������
		InsertionSort(Arr[i].arr,SIZE0);
	diff[0]=clock()-start;	//��������ʱ��
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[0]);

	for(i=0;i<SIZE0;i++)
		get_rand_arr(Arr[i].arr,SIZE0,100,999);
	start=clock();
	for(i=0;i<SIZE0;i++)
		MergeSort(Arr[i].arr,0,SIZE0-1,SIZE0);
	diff[1]=clock()-start;
	printf("�鲢��������ʱ��Ϊ��%dms\n",(int)diff[1]);

	for(i=0;i<SIZE0;i++)
		get_rand_arr(Arr[i].arr,SIZE0,100,999);
	start=clock();
	for(i=0;i<SIZE0;i++)
		CountSort(Arr[i].arr,SIZE0);
	diff[2]=clock()-start;
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[2]);

	for(i=0;i<SIZE0;i++)
		get_rand_arr(Arr[i].arr,SIZE0,100,999);
	start=clock();
	for(i=0;i<SIZE0;i++)
		RadixSort(Arr[i].arr,SIZE0,dec,order);
	diff[3]=clock()-start;
	printf("����������������ʱ��Ϊ��%dms\n",(int)diff[3]);

	for(i=0;i<SIZE0;i++)
		get_rand_arr(Arr[i].arr,SIZE0,100,999);
	start=clock();
	for(i=0;i<SIZE0;i++)
		QuickSort(Arr[i].arr,0,SIZE0-1);
	diff[4]=clock()-start;
	printf("���ŵݹ������ʱ��Ϊ��%dms\n",(int)diff[4]);

	for(i=0;i<SIZE0;i++)
		get_rand_arr(Arr[i].arr,SIZE0,100,999);
	start=clock();
	for(i=0;i<SIZE0;i++)
		QuickSortNoR(Arr[i].arr,SIZE0);
	diff[5]=clock()-start;
	printf("������������ʱ��Ϊ��%dms\n",(int)diff[5]);

	save(diff,100);
}

//2��Ӧ����
void appsort()
{
	int *arr3=(int*)malloc(sizeof(int)*SIZE3);
	get_rand_arr(arr3,SIZE3,0,2);

	system("cls");
	printf("**********************************************************\n");
	printf("Ӧ����һ��ʵ�ֲʺ�����\n");
	printf("����ǰ��");
	Print(arr3,SIZE3);
	ColorsSort(arr3,SIZE3);	//��������
	printf("�����");
	Print(arr3,SIZE3);
	printf("\n");

	get_rand_arr(arr3,SIZE3,0,100);
	printf("**********************************************************\n");
	printf("Ӧ��������ҵ���K�����\n");
	printf("�ڴ�����������Ѱ�ң�0-100����\n");
	Print(arr3,SIZE3);
	FindKth(arr3,SIZE3);	//����Ѱ��
}

//��ʼ����������
void display()
{
	printf("************************\n");
	printf("*  1��1w��������       *\n");
	printf("*  2��5w��������       *\n");
	printf("*  3��20w��������      *\n");
	printf("*  4��100*100��������  *\n");
	printf("*  5��2��Ӧ����        *\n");
	printf("*  6����ӡ�ļ��е����� *\n");
	printf("*  0���˳�����         *\n");
	printf("************************\n");
}
