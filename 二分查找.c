/*
	Name: 二分查找 
	Author: bjb 
	Date: 08/11/22 15:28
	Description: 对有序表进行二分查找 
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int elem[20];
	int length;
}SeqList;

int Binary_Search(SeqList L,int key);

int main(){
	
	SeqList L;
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
	int res;
	int x = 15;
	res = Binary_Search(L,x);
	printf("\n");
	printf("%d %d",res,L.elem[res]);
	
	return 0;
} 

int Binary_Search(SeqList L,int key){
	int low = 0,high = L.length - 1,mid;
	while(low <= high)
	{
		mid = (low + high)/2;			//取中间位置
		printf("%d ", mid);
		if(L.elem[mid] == key)
			return mid;
		else if(L.elem[mid] > key)
			high= mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
