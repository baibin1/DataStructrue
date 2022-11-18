/*
	Name: �ֿ����/����˳����� 
	Author: bjb 
	Date: 09/11/22 13:46
	Description:�����Ա���зֿ���� 
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
typedef struct List{
	int elem[MaxSize];
	int length;
}List; 
//����������
typedef struct indexElem{
	int key;
	int low,high;			//��¼ĳ���е�һ�������һ��Ԫ�ص�λ�� 
}indexElem;
indexElem index[MaxSize];	//���������� 

int CreateIndex();			//���������� 
//�����������keyֵ���ж��ֲ��� 
int Bsearch(indexElem index[],int key,int x);

int main(){
	List L;
	printf("������˳���ĳ��ȣ�\n");
	scanf("%d",&L.length);
	for(int i = 0; i < L.length; i++)
	{
		printf("�������%d��Ԫ�ص�ֵ��\n",i+1);
		int val; 
		scanf(" %d",&val);
		L.elem[i] = val;
	}
	for(int i = 0; i < L.length; i++)
	{
		printf("��%d��Ԫ�ص�ֵ%d��\n",i+1,L.elem[i]);
	}
	
	int x;
	x = CreateIndex();
	int res;
	int key;
	printf("��������Ҫ���ҵ�keyֵ��\n");
	scanf("%d",&key);
	res = Bsearch(index,key,x);
	if(res == -1)
		printf("����ʧ�ܣ�\n");
	else
	{	
		int v;
		for( v = 0; v < x; v++)
		{
			if(index[v].key == res)
				break;
		}
		index[v].high--;
		index[v].low--;
		for(index[v].low ; index[v].low <= index[v].high ; index[v].low++)
			if(L.elem[index[v].low] == key ) 
			{
				printf("���ҳɹ���%d\n",L.elem[index[v].low]);
				return 0;
			}
		
	}
	printf("����ʧ�ܣ�\n");
	return 0;
}

int CreateIndex(){
	int x;					//Ҫ�����������������
	printf("��������Ҫ�������������������\n");
	scanf("%d",&x);
	for(int i = 0; i < x; i++)
	{
		printf("�������%d���������keyֵ����һ��Ԫ��λ�á����һ��Ԫ��λ�ã�\n",i+1);
		scanf("%d%d%d",&index[i].key,&index[i].low,&index[i].high);
	} 
	return x;
} 

int  Bsearch(indexElem index[],int key,int x){
	int low = 0,high = x-1,mid;
	if(index[0].key > key)
		return index[0].key;
	else if(index[x-1].key < key)
		return -1;
	else
	{
		while(low <= high)
		{
			mid = (low + high)/2;
			if(index[mid].key >= key && index[mid-1].key < key)
				return index[mid].key;
			else if(index[mid].key > key)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return -1;	
	}
	
}
