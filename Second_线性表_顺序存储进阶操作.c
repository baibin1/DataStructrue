#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

/*
*���Ա���ʽ�洢�ṹ��ʵ��
*������������ʼ�������١����ã���գ����ж��Ƿ�Ϊ�ա��ж��Ƿ�Ϊ�����õ�Ԫ�صĸ��������Ա�ĳ��ȣ�������ĳ��λ�õ�Ԫ�� 
*����ĳ��Ԫ�ص�λ����������ĳ��Ԫ�س��ֵĴ�������ֵ��ǰ������ֵ�ĺ�̡�λ�ò��롢ֵ���롢λ��ɾ����ֵɾ��
*��ӡ������
*/
 
typedef int ElemType;
#define LIST_INIT_SIZE 100	//���Ա�洢�ռ�ĳ�ʼ������
typedef struct ArrList{
	ElemType * elem;		//�洢�ռ��ַ 
	int length;				//��ǰ���� 
	int listsize;			//��ǰ����Ĵ洢�� ����sizeof(ElemType)Ϊ��λ 
}List, *SqList;

SqList InitList();					//��ʼ��������������
SqList CreatList(SqList Arr);		//���Ա�ֵ���� 
SqList DestoryList(SqList Arr);		//���ٲ�����������
void ClearList(SqList Arr);			//��գ����ã�������������
bool ListEmpty(SqList Arr);			//�ж��Ƿ�Ϊ�պ�������
bool ListFull(SqList Arr);			//�ж��Ƿ�Ϊ����������
int ListLength(SqList Arr);			// ���ر���Ԫ�ظ��������� 
SqList GetElem(SqList Arr);			//���ر��е�i��Ԫ�ص�ֵ 
int GetElems(SqList Arr);			//��ѯ��i��Ԫ�س����˼��� 
int GetElemPlos(SqList Arr);		//��ѯֵΪx��Ԫ�ص�λ�ú͸��� 
void GetPrior(SqList Arr);			//��ѯǰ��
void InsertList(SqList Arr);		//ֵ�Ĳ��� 
void SortList(SqList Arr);			//���� 

int main(){
	
//	SqList Arr = NULL;
//	Arr =InitList(Arr);
//	
//	Arr = CreatList(Arr);
	
//	SqList DestoryList();

//	ClearList(Arr);

//	ListEmpty(Arr);
//	if(ListEmpty(Arr)){
//		printf("Empty\n");
//	}else
//	{
//		printf("Not Empty\n");
//	}
	
//	if(ListFull(Arr)){
//		printf("Full\n");
//	}else
//	{
//		printf("NOT FULL\n");
//	}

//	printf("�����Ա�ĳ���Ϊ��%d\n",ListLength(Arr));
	
//	GetElem(Arr);

//	GetElems(Arr);

//	GetElemPlos(Arr);

//	GetPrior(Arr);
	
//	InsertList(Arr);

//	SortList(Arr); 

	return 0;
} 

SqList InitList(SqList Arr){
	Arr = (SqList)malloc(sizeof(List));
	if(NULL == Arr)
	{
		printf("Dynamic malloc failed.\n");	//��̬����ʧ�� 
		exit(-1); 
	}
	Arr->elem = (int *)malloc(sizeof(int)*LIST_INIT_SIZE);
	if(NULL == Arr)
	{
		printf("Dynamic malloc failed.\n");
		exit(-1);
	}
	Arr->length = 0;
	Arr->listsize = LIST_INIT_SIZE;
	return Arr;
} 

SqList CreatList(SqList Arr){
	int i,j,val;
	printf("��ֵԪ�صĸ���Ϊ��\n");
	scanf("%d",&i);
	Arr->length = i;
	for(j=0;j<Arr->length;j++)
	{
		printf("��%d��Ԫ�ص�ֵΪ��\n",j+1);
		scanf("%d",&val);
		Arr->elem[j] = val;
	}
	for(j=0;j<Arr->length;j++)
	{
		printf("%d ",Arr->elem[j]);
	}
	printf("\n");
	return Arr;
}

SqList DestoryList(SqList Arr){
	if(NULL == Arr)
	{
		printf("ArrΪNULL.\n");
		return NULL;
	}
	free(Arr->elem);
	Arr->elem = NULL;
	Arr->length = 0;
	Arr->listsize = 0;
	return NULL;
}

void ClearList(SqList Arr){
	if(NULL == Arr)
	{
		printf("ArrΪNULL.\n");
		return;
	}
	Arr->length = 0;
}

bool ListEmpty(SqList Arr){
	if(NULL == Arr)
	{
		printf("ArrΪNULL.\n");
		return NULL;
	}
	if(0 == Arr->length)
	{
		return true;
	}
	else
	{
		return false; 
	}
}

bool ListFull(SqList Arr){
	if(NULL == Arr)
	{
		printf("ArrΪNULL.\n");
		return NULL;
	}
	if(Arr->length == Arr->listsize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ListLength(SqList Arr){
	return Arr->length;
} 

SqList  GetElem(SqList Arr){
	if(NULL == Arr)
	{
		printf("ArrΪNULL.\n");
	}
	int z;
	printf("���������Ҫ���ҵ�λ�ã�\n");
	scanf("%d",&z);
	if(z<1 || z>Arr->length)
	{
		printf("λ���������!\n");
	}
	else
	{
		printf("��%d��λ�õ�Ԫ��Ϊ��%d!\n",z,Arr->elem[z-1]);
	}	
}

int GetElems(SqList Arr){
	if(NULL == Arr)
	{
		printf("ArrΪNULL.\n");
		return 0;
	}
	int i;
	int times = 0;
	printf("Ҫ��ѯ�����ݵ�λ��Ϊ��");
	scanf("%d",&i);
	printf("���%d��Ԫ��ֵ%d��ͬ��Ԫ��(��������Ԫ��)Ϊ",i,Arr->elem[i-1]); 
	if(i<1||i>Arr->length)
	{
		printf("�������");
	}
	for(int j=0;j<Arr->length;j++)
	{
		if(Arr->elem[j] == Arr->elem[i-1])
		{
			times++;
			if(i!=j){
				printf("��%d�� ",j+1);
			}
		}	
	} 
	printf(",����%d��",times-1);
	return 0;
}

int GetElemPlos(SqList Arr){
	if(NULL == Arr)
	{
		printf("ArrΪNULL.\n");
		return 0;
	}
	printf("����Ҫ��ѯ��ֵ��");
	int value,times = 0;
	scanf("%d",&value);
	printf("�����ͬ��Ԫ�ص�λ��Ϊ��"); 
	for(int i=0;i<Arr->length;i++)
	{
		if(Arr->elem[i] == value)
		{
			printf("%d ",i+1);
			times++;
		}
	}
	printf(",��������%d�Σ�",times);
	return 0;
} 

void GetPrior(SqList Arr){
	if(NULL == Arr)
	{
		printf("ArrΪNULL.\n");
		return; 
	}
	int pos;
	printf("1.��λ��ǰ����2.��ֵǰ����\n���������ѡ��\n");
	scanf("%d",&pos);
	if(1 == pos)
	{
		int option;
		printf("��������Ҫ����ǰ����λ�ã�");
		scanf("%d",&option);
		if(option<2||option>Arr->length)
		{
			printf("��ǰ��.\n");
		 } 
		 else
		 {
		 	printf("��%d��λ�õ�ǰ��Ϊ��%d\n",option,Arr->elem[option-2]);
		 }
	}
	else if(2 == pos)
	{
		int value,times=0;
		printf("��������Ҫ��ǰ����ֵ��");
		scanf("%d",&value);
		for(int i = 0;i<Arr->length;i++)
		{
			if(Arr->elem[i] == value)
			{
				printf("%d" ,Arr->elem[i-1]);
				times++;
			}
		 } 
		 if(times == 0)
		 {
		 	printf("None.\n");
		 }
	}
	else
	{
		printf("�������\n");
	}	
} 

void InsertList(SqList Arr){
	int postion,value;
	printf("��������Ҫ�����ֵ��λ�ã�\n");
	scanf("%d",&postion);
	if(postion<1||postion>Arr->length+1)
	{
		printf("����λ�ô���\n");
	}
	else
	{	
		Arr->length++;
		printf("������Ҫ�����ֵ��\n");
		scanf("%d",&value);
		for(int i=Arr->length;i>=postion;i--)
		{
			Arr->elem[i] = Arr->elem[i-1]; 
		}
		Arr->elem[postion-1] = value;
		for(int j=0;j<Arr->length;j++)
		{
			printf("%d ",Arr->elem[j]);
		}
	}
} 

void SortList(SqList Arr){
	int item;
	for(int i=0;i<Arr->length-1;i++)
		for(int j=0;j<Arr->length-1-i;j++)
			if(Arr->elem[j]>Arr->elem[j+1])
				{
					item = Arr->elem[j];
					Arr->elem[j] = Arr->elem[j+1];
					Arr->elem[j+1] = item;
				}
	for(int z=0;z<Arr->length;z++)
	{
		printf("%d ",Arr->elem[z]);
	}
	printf("\n");
}
