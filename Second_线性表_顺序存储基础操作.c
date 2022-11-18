#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>

typedef struct ArrList{
	int data;
}List,*SqList;
/*
����һ���µ������� List ��*SqList ����ṹ��
List �൱�� struct ArrList
SqList �൱�� struct ArrList *
*/

SqList creat_list(int len);

void TraverseList(SqList Arr , int len);

SqList	FreeList(SqList Arr);

int main(){
	int len = 0;
	printf("����������Ҫ������Ԫ�ظ���:");
	scanf("%d",&len);
	SqList Arr = creat_list(len);
	TraverseList(Arr,len);
	Arr = FreeList(Arr);
	
	return 0;
	
}

SqList creat_list(int len){
	int val = 0;
	SqList Arr = (SqList)malloc(sizeof(List)*len);
	if (NULL == Arr)
	{
		exit(-1);
	}
	for(int i=0;i<len;i++)
	{
		printf("Ϊ��%d��Ԫ�ظ�ֵ:",i+1);
		scanf("%d",&val);
		Arr[i].data = val;
	}
	return Arr;
}
void TraverseList(SqList Arr,int len){
	for(int i=0;i<len;i++)
	{
		printf("%d ",Arr[i].data);
	}
	printf("\n");
}
SqList FreeList(SqList Arr){
	free(Arr);
	return NULL;
}

