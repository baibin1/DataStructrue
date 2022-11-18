#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

/*
*线性表链式存储结构的实现
*操作包括：初始化、销毁、重置（清空）、判断是否为空、判断是否为满、得到元素的个数（线性表的长度）、查找某个位置的元素 
*查找某个元素的位置数、查找某个元素出现的次数、找值的前驱、找值的后继、位置插入、值插入、位置删除、值删除
*打印、排序
*/
 
typedef int ElemType;
#define LIST_INIT_SIZE 100	//线性表存储空间的初始分配量
typedef struct ArrList{
	ElemType * elem;		//存储空间基址 
	int length;				//当前长度 
	int listsize;			//当前分配的存储量 ，以sizeof(ElemType)为单位 
}List, *SqList;

SqList InitList();					//初始化操作函数声明
SqList CreatList(SqList Arr);		//线性表赋值操作 
SqList DestoryList(SqList Arr);		//销毁操作函数声明
void ClearList(SqList Arr);			//清空（重置）操作函数声明
bool ListEmpty(SqList Arr);			//判断是否为空函数声明
bool ListFull(SqList Arr);			//判断是否为满函数声明
int ListLength(SqList Arr);			// 返回表中元素个数（表长） 
SqList GetElem(SqList Arr);			//返回表中第i个元素的值 
int GetElems(SqList Arr);			//查询第i个元素出现了几次 
int GetElemPlos(SqList Arr);		//查询值为x的元素的位置和个数 
void GetPrior(SqList Arr);			//查询前驱
void InsertList(SqList Arr);		//值的插入 
void SortList(SqList Arr);			//排序 

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

//	printf("该线性表的长度为：%d\n",ListLength(Arr));
	
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
		printf("Dynamic malloc failed.\n");	//动态分配失败 
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
	printf("赋值元素的个数为：\n");
	scanf("%d",&i);
	Arr->length = i;
	for(j=0;j<Arr->length;j++)
	{
		printf("第%d个元素的值为：\n",j+1);
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
		printf("Arr为NULL.\n");
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
		printf("Arr为NULL.\n");
		return;
	}
	Arr->length = 0;
}

bool ListEmpty(SqList Arr){
	if(NULL == Arr)
	{
		printf("Arr为NULL.\n");
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
		printf("Arr为NULL.\n");
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
		printf("Arr为NULL.\n");
	}
	int z;
	printf("请输出您想要查找的位置：\n");
	scanf("%d",&z);
	if(z<1 || z>Arr->length)
	{
		printf("位置输入错误!\n");
	}
	else
	{
		printf("第%d个位置的元素为：%d!\n",z,Arr->elem[z-1]);
	}	
}

int GetElems(SqList Arr){
	if(NULL == Arr)
	{
		printf("Arr为NULL.\n");
		return 0;
	}
	int i;
	int times = 0;
	printf("要查询的数据的位置为：");
	scanf("%d",&i);
	printf("与第%d个元素值%d相同的元素(不包括该元素)为",i,Arr->elem[i-1]); 
	if(i<1||i>Arr->length)
	{
		printf("输入错误！");
	}
	for(int j=0;j<Arr->length;j++)
	{
		if(Arr->elem[j] == Arr->elem[i-1])
		{
			times++;
			if(i!=j){
				printf("第%d个 ",j+1);
			}
		}	
	} 
	printf(",共有%d个",times-1);
	return 0;
}

int GetElemPlos(SqList Arr){
	if(NULL == Arr)
	{
		printf("Arr为NULL.\n");
		return 0;
	}
	printf("输入要查询的值：");
	int value,times = 0;
	scanf("%d",&value);
	printf("与该相同的元素的位置为："); 
	for(int i=0;i<Arr->length;i++)
	{
		if(Arr->elem[i] == value)
		{
			printf("%d ",i+1);
			times++;
		}
	}
	printf(",共出现了%d次！",times);
	return 0;
} 

void GetPrior(SqList Arr){
	if(NULL == Arr)
	{
		printf("Arr为NULL.\n");
		return; 
	}
	int pos;
	printf("1.求位置前驱。2.求值前驱。\n请输入你的选择：\n");
	scanf("%d",&pos);
	if(1 == pos)
	{
		int option;
		printf("请输入你要查找前驱的位置：");
		scanf("%d",&option);
		if(option<2||option>Arr->length)
		{
			printf("无前驱.\n");
		 } 
		 else
		 {
		 	printf("第%d个位置的前驱为：%d\n",option,Arr->elem[option-2]);
		 }
	}
	else if(2 == pos)
	{
		int value,times=0;
		printf("请输入你要求前驱的值：");
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
		printf("输入错误！\n");
	}	
} 

void InsertList(SqList Arr){
	int postion,value;
	printf("请输入你要插入的值的位置：\n");
	scanf("%d",&postion);
	if(postion<1||postion>Arr->length+1)
	{
		printf("输入位置错误！\n");
	}
	else
	{	
		Arr->length++;
		printf("请输入要插入的值：\n");
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
