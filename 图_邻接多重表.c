/*
*-----------����ͼ���ڽӶ��ر�洢��ʾ-----------
*����ͼ����һ����ʽ�洢�ṹ
*������2022��11��2��21��56��
*Author��bjb 
*/ 
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20
typedef enum {unvisted,visted} VisitIf;
typedef struct EBox{
	VisitIf mark;				//���ʱ��
	int ivex,jvex;				//�ñ����������������λ��
	struct EBox *ilink,*jlink; 	//�ֱ�ָ�������������������һ����
	char *info;					//�ñ���Ϣָ�� 
}EBox;
typedef struct VexBox{
	int data;
	EBox *firstedge;			//ָ���һ�������ö���ı� 
}VexBox;
typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum,edgenum;			//����ͼ�ĵ�ǰ�������ͱ��� 
}AMLGraph;

int main(){
	return 0;
} 
 
