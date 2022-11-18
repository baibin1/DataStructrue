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
	RedType r[MaxSize + 1];		//r0���û������ڱ���Ԫ��
	int length;
}SqList;
typedef struct out{
	SqList L;
	int k; 
}out;

SqList CreateStr(SqList L);						//����һ�������ļ�¼����������Ĵ洢��Ԫ�� 
void vist(SqList L);							//��L�еļ�¼��ӡ���� 
SqList InsertSort(SqList L);					//ֱ�Ӳ��뷨 
SqList BInsertSort(SqList L);					//�۰�������� 
SqList ShellInsert(SqList L,int dk);			//ϣ����������
SqList ShellSort(SqList L,int dlta[],int t);	//ϣ������ 
SqList BubbleSort(SqList L);					//�������� 
SqList SelectSort(SqList L);					//��ѡ������ 
out Partition(SqList L,int low,int high);		//�����Ա�L��Ϊ������
SqList QSort(SqList L,int low,int high);		//��������Quick Sort 
SqList HeapAdjust(SqList L,int s,int m);		//�����Ա���е���������Ϊһ���󶥶�
SqList HeapSort(SqList L);						//������ 
//�������L.r[]�������T.r[]��Ϊ�����T.r[] 
SqList Merge(SqList L,SqList T,int i,int m,int n);
//��L.r�鲢����ΪT1 
SqList MSort(SqList L,SqList T1,int s,int t);
//��˳���L���鲢����
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
	//��˳���L��ֱ�Ӳ�������
	L.length++;
	int j;
	printf("��������Ҫ�����ֵ��\n");
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
	//��˳������۰�������� 
	L.length++; 
	printf("��������Ҫ�����ֵ��\n");
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
	//��˳���L��һ��ϣ����������
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
	for(int i = 1; i < L.length; i++){			//ѡ���iС�ļ�¼����������λ 
		int min = i;
		for(int j = i; j < L.length+1; j++)		//��L.r[i....L.length]��ѡ����С�� 
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
	//�ñ��еĵ�һ����¼�������¼������λ�ã�����֮ǰ��¼�������� 
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
	//��������
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
	//������
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

//�������L.r[]�������T.r[]��Ϊ�����T.r[] 
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
//��L.r�鲢����ΪT1 
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
//��˳���L���鲢����
SqList MergeSort(SqList L){
	L = MSort(L,L,1,L.length);
	return L;
}
