#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 20
typedef int KeyType;
typedef struct RedType {
	KeyType key;
	char otherinfo;
}RedType;
typedef struct SqList {
	RedType r[MaxSize + 1];		//r0闲置或用作哨兵单元、
	int length;
}SqList;
typedef struct out{
	SqList L;
	int k; 
}out;

SqList CreateStr(SqList L);						//创建一组待排序的记录存放在连续的存储单元上 
void vist(SqList L);							//将L中的记录打印出来 
SqList InsertSort(SqList L);					//直接插入法 
SqList BInsertSort(SqList L);					//折半插入排序 
SqList ShellInsert(SqList L,int dk);			//希尔插入排序
SqList ShellSort(SqList L,int dlta[],int t);	//希尔排序 
SqList BubbleSort(SqList L);					//起泡排序 
SqList SelectSort(SqList L);					//简单选择排序 
out Partition(SqList L,int low,int high);		//将线性表L分为两部分
SqList QSort(SqList L,int low,int high);		//快速排序，Quick Sort 
SqList HeapAdjust(SqList L,int s,int m);		//对线性表进行调整，调整为一个大顶堆
SqList HeapSort(SqList L);						//堆排序 
//将有序的L.r[]和有序的T.r[]并为有序的T.r[] 
SqList Merge(SqList L,SqList T,int i,int m,int n);
//将L.r归并排序为T1 
SqList MSort(SqList L,SqList T1,int s,int t);
//对顺序表L作归并排序
SqList MergeSort(SqList L); 

int main() {
	
	SqList L;
	L = CreateStr(L);
	vist(L);
//	L = InsertSort(L);
//	vist(L);
//	L = BInsertSort(L);
//	vist(L);
//	int dlta[3] = {5,3,1},t =4;
//	L = ShellSort(L,dlta,t);
//	vist(L); 
//	L = BubbleSort(L);
//	L = SelectSort(L); 
//	int low = 1,high = L.length;
//	L = QSort(L,low,high);
//	L = HeapSort(L);
	L = MergeSort(L);
	vist(L);
	return 0;
}

SqList CreateStr(SqList L){
	L.length = 10;
	L.r[1].key = 10;
	L.r[2].key = 30;
	L.r[3].key = 0;
	L.r[4].key = 20;
	L.r[5].key = 50;
	L.r[6].key = 40;
	L.r[7].key = 70;
	L.r[8].key = 60;
	L.r[9].key = 90;
	L.r[10].key = 80;
	return L;		
} 

void vist(SqList L){
	if(L.length == 0)
		printf("L is Empty!\n");
	else
		for(int i = 1; i <= L.length; i++)
			printf("%d ",L.r[i].key);
	printf("\n");
} 

SqList InsertSort(SqList L){
	//对顺序表L作直接插入排序
	L.length++;
	int j;
	printf("请输入你要插入的值：\n");
	scanf(" %d",&L.r[L.length].key);
	for(int i = 2; i <= L.length ; i++)
		if(L.r[i].key < L.r[i-1].key)
		{
			L.r[0] = L.r[i]; 
			L.r[i] = L.r[i-1];
			for( j = i-2; L.r[0].key < L.r[j].key; j--)
				L.r[j+1] = L.r[j];
			L.r[j+1] = L.r[0];
		}
	return L;
}

SqList BInsertSort(SqList L){
	//对顺序表作折半插入排序 
	L.length++; 
	printf("请输入你要插入的值：\n");
	scanf(" %d",&L.r[L.length].key);
	for(int i = 2;i <= L.length; i++){
		L.r[0] = L.r[i];
		int low = 1,high = i-1;
		while(low <= high){
			int m = (low+high)/2;
			if(L.r[0].key < L.r[m].key)
				high = m-1;
			else
				low = m+1;
		}
		for(int j = i-1; j >= high+1 ; j--)
			L.r[j+1] = L.r[j];
		L.r[high+1] = L.r[0];
	}
	return L;
} 

SqList ShellInsert(SqList L,int dk){
	//对顺序表L作一次希尔插入排序
	for(int i = dk+1; i <= L.length; i++)
		if(L.r[i].key < L.r[i-dk].key)
		{
			L.r[0] = L.r[i];
			int j;
			for(j = i-dk; j>0&&L.r[0].key < L.r[j].key; j = j-dk)
				L.r[j+dk] = L.r[j];
			L.r[j+dk] =L.r[0];
		} 
	return L;
}

SqList ShellSort(SqList L,int dlta[],int t){
	for(int k = 0; k < t; k++)
		L = ShellInsert(L,dlta[k]);
	return L;
} 

SqList BubbleSort(SqList L){
	for(int i = 1; i < L.length; i++)
	{
		bool flag = false;
		for(int j = L.length; j > i; j--)
			if(L.r[j-1].key > L.r[j].key)
			{
				int t;
				t = L.r[j].key;
				L.r[j].key = L.r[j-1].key;
				L.r[j-1].key = t; 
				flag = true;
			}
	if(flag == false)
		return L;
	}
} 

SqList SelectSort(SqList L){
	for(int i = 1; i < L.length; i++){			//选择第i小的记录，并交换到位 
		int min = i;
		for(int j = i; j < L.length+1; j++)		//在L.r[i....L.length]中选择最小的 
			if(L.r[j].key < L.r[min].key)
				min = j;
		if(min!=i)
		{
			RedType t;
			t = L.r[i];
			L.r[i] = L.r[min];
			L.r[min] = t;
		}
	}
	return L;
}

out Partition(SqList L,int low,int high){
	//用表中的第一个记录作枢轴记录，交换位置，在他之前记录不大于他 
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while(low < high){
		while(low<high && L.r[high].key >= pivotkey)
			--high;
		L.r[low] = L.r[high];
		while(low<high && L.r[low].key <= pivotkey)
			++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	out T;
	T.k = low;
	T.L = L;
	return T;
}

SqList QSort(SqList L,int low,int high){
	//快速排序
	if(low<high){
		out T = Partition(L,low,high);
		int pivotloc = T.k;
		L = T.L;
//		vist(L);
		printf("%d\n",pivotloc);
		L = QSort(L,low,pivotloc-1);
		L = QSort(L,pivotloc+1,high);
	} 
	return L;
}

SqList HeapAdjust(SqList L,int s,int m){
	RedType rc;
	rc = L.r[s];
	for(int j = 2*s;j <= m;j*=2){
		if(j<m && L.r[j].key < L.r[j+1].key) ++j;
		if(rc.key >= L.r[j].key)	break;
		L.r[s] = L.r[j];
		s = j;
	}
	L.r[s] = rc;
	return L;
}

SqList HeapSort(SqList L){
	//堆排序
	for(int i = L.length/2; i>0; --i)
		L = HeapAdjust(L,i,L.length); 
	for(int i = L.length; i>1; --i){
		RedType T;
		T = L.r[1];
		L.r[1] = L.r[i];
		L.r[i] = T;
		L = HeapAdjust(L,1,i-1);
	} 
	return L;
}

//将有序的L.r[]和有序的T.r[]并为有序的T.r[] 
SqList Merge(SqList L,SqList T,int i,int m,int n){
	int k,j;
	for( j = m+1, k = i; i<=m && j<=n; ++k){
		if(L.r[i].key <= L.r[j].key)
			T.r[k] = L.r[i++];
		else
			T.r[k] = L.r[j++];
	} 
	while(i <= m) T.r[k++] = L.r[i++];
	while(j <= n) T.r[k++] = L.r[j++];
	return T;
}
//将L.r归并排序为T1 
SqList MSort(SqList L,SqList T,int s,int t){
	SqList T1;
	T1 = T;
	if(s==t) T1.r[s] = L.r[s];
	else
	{
		int m = (s+t)/2;
		T1 = MSort(L,T1,s,m);
		T1 = MSort(L,T1,m+1,t);
		T = Merge(T1,T,s,m,t);
	}
	return T;
}
//对顺序表L作归并排序
SqList MergeSort(SqList L){
	L = MSort(L,L,1,L.length);
	return L;
}
