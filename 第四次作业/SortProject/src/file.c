#include "../head/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void load()
{
	FILE *fp=fopen("data.txt","r");
	int i,arr[6];
	char str[30];
	setvbuf(fp, NULL, _IONBF, 0);//���û���ģʽΪ�޻���

	while(!feof(fp))	//�ļ�δ��ĩβ
	{
		fgets(str,30,fp);
		if(feof(fp))	//��ֹ���һ���ظ���ӡ
			break;
		printf("%s",str);
	}
	fclose(fp);
}

void save(int *arr,int cnt)
{
	FILE *fp = fopen("data.txt","a+");
	int i;
	char str1[]="����1w��������Ĳ������ݣ�\n";
	char str5[]="����5w��������Ĳ������ݣ�\n";
	char str20[]="����20w��������Ĳ������ݣ�\n";
	char str100[]="����100*100��������Ĳ������ݣ�\n";

	setvbuf(fp, NULL, _IONBF, 0);//���û���ģʽΪ�޻���

	switch(cnt)
	{
		case 1:fprintf(fp ,"%s",str1);		break;
		case 5:fprintf(fp ,"%s",str5);		break;
		case 20:fprintf(fp ,"%s",str20);	break;
		case 100:fprintf(fp ,"%s",str100);	break;
		default :printf("�����cnt�����⣡����\n");
	}

	for(i = 0; i < 6; i++)
	{	//д������
		fprintf(fp ,"%d  ", arr[i]);
	}
	fprintf(fp ,"\n");
	fclose(fp);
}

