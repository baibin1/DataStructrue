#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>

typedef struct ArrList{
	int data;
}List,*SqList;
/*
命名一个新的类型名 List ，*SqList 代替结构体
List 相当于 struct ArrList
SqList 相当于 struct ArrList *
*/

SqList creat_list(int len);

void TraverseList(SqList Arr , int len);

SqList	FreeList(SqList Arr);

int main(){
	int len = 0;
	printf("请输入你想要构建的元素个数:");
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
		printf("为第%d个元素赋值:",i+1);
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

