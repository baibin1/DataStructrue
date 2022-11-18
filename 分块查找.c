/*
	Name: 分块查找/索引顺序查找 
	Author: bjb 
	Date: 09/11/22 13:46
	Description:对线性表进行分块查找 
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
typedef struct List{
	int elem[MaxSize];
	int length;
}List; 
//定义索引表
typedef struct indexElem{
	int key;
	int low,high;			//记录某块中第一个和最后一个元素的位置 
}indexElem;
indexElem index[MaxSize];	//定义索引表 

int CreateIndex();			//创建索引表 
//对所索引表的key值进行二分查找 
int Bsearch(indexElem index[],int key,int x);

int main(){
	List L;
	printf("请输入顺序表的长度：\n");
	scanf("%d",&L.length);
	for(int i = 0; i < L.length; i++)
	{
		printf("请输入第%d个元素的值：\n",i+1);
		int val; 
		scanf(" %d",&val);
		L.elem[i] = val;
	}
	for(int i = 0; i < L.length; i++)
	{
		printf("第%d个元素的值%d：\n",i+1,L.elem[i]);
	}
	
	int x;
	x = CreateIndex();
	int res;
	int key;
	printf("请输入你要查找的key值：\n");
	scanf("%d",&key);
	res = Bsearch(index,key,x);
	if(res == -1)
		printf("查找失败！\n");
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
				printf("查找成功：%d\n",L.elem[index[v].low]);
				return 0;
			}
		
	}
	printf("查找失败！\n");
	return 0;
}

int CreateIndex(){
	int x;					//要创建的索引表的数量
	printf("请输入你要创建的索引表的数量：\n");
	scanf("%d",&x);
	for(int i = 0; i < x; i++)
	{
		printf("请输入第%d个索引表的key值、第一个元素位置、最后一个元素位置：\n",i+1);
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
