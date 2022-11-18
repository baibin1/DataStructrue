/*
	Name: 树型查找 
	Author: bjb 
	Date: 09/11/22 16:34
	Description:二叉排序树插入、删除 
*/
#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>

typedef struct BTNode{
	char key;
	struct BTNode *lchild,*rchild;
}BTNode,*BTree;

void CreateTree(BTree *T);
void inorder(BTree T);
//查找关键字 
BTree BSTSearch(BTree bt,char key);
//插入关键字
void BSTInsert(BTree *bt,char key);
//构造二叉排序树
void Creat_BST(BTree *bt,char str[],int n); 
//删除结点
void DeleteBST(BTree *T,char key);
void Delete(BTree* p); 

int main(){
	
	BTree T = (BTree)malloc(sizeof(BTNode));
	CreateTree(&T);
	inorder(T);
	printf("\n");
	char key;
//	printf("请输入要查找的key值：\n");
//	scanf(" %c",&key);
//	BTree p;
//	p = BSTSearch(T,key);
//	if(p == NULL)
//		printf("查找失败！\n");
//	else
//		printf("%c\n",p->key);
	// printf("请输入要插入的值：\n");
	// scanf(" %c",&key);
	// BSTInsert(&T,key);
	// inorder(T);
	// printf("\n");
	// int n =5;
	// char str[5] = {'1','3','5','7','9'};
	// Creat_BST(&T,str,n);
	// inorder(T);
	// printf("\n");
	printf("请输入要删除的值：\n");
	scanf(" %c",&key);
	DeleteBST(&T,key);
	inorder(T); 
	printf("\n");
	printf("请输入要删除的值：\n");
	scanf(" %c",&key);
	DeleteBST(&T,key);
	inorder(T); 
	
	return 0;
} 

void CreateTree(BTree *T){
	char ch;
	scanf("%c",&ch);
	if(ch == '#') *T = NULL;
	else
	{
		*T = (BTree)malloc(sizeof(BTNode));
		(*T)->key = ch;
		CreateTree(&((*T)->lchild));
		CreateTree(&((*T)->rchild));
	}
}

void inorder(BTree T){
	if(T)
	{
		inorder(T->lchild);
		printf("%c ",T->key);
		inorder(T->rchild);
	}
}

BTree BSTSearch(BTree bt,char key){
	if(bt == NULL)
		return NULL;
	else
	{
		if(bt->key == key)
			return bt;
		else if(key < bt->key)
			return BSTSearch(bt->lchild,key);
		else
			return BSTSearch(bt->rchild,key);
	}
} 

void BSTInsert(BTree *bt,char key){
	if((*bt) == NULL)
	{
		*bt = (BTree)malloc(sizeof(BTNode));
		(*bt)->lchild = (*bt)->rchild = NULL;
		(*bt)->key = key;
	} 
	else
	{	
		if(key == (*bt)->key)
			printf("该关键字已存在！\n");
		else if(key < (*bt)->key)
			return BSTInsert(&((*bt)->lchild),key);
		else
			return BSTInsert(&((*bt)->rchild),key);
	}
}

void Creat_BST(BTree *bt,char str[],int n){
	*bt = NULL;
	for(int i = 0; i < n;i++)
		BSTInsert(&(*bt),str[i]);
}

void DeleteBST(BTree *T,char key){
	if(*T == NULL) 
		printf("Empty!删除失败！\n");
	else
	{
		BTree* p;
		*p = BSTSearch(*T,key);
		if(*p == NULL)
			printf("找不到该key值，删除失败！\n");
		else
		{	
			Delete(p);
		}
	}
}

void Delete(BTree *p){
	BTree *s,*q;
	q = (BTree*)malloc(sizeof(BTree));
	s = (BTree*)malloc(sizeof(BTree));
	if((*p)->lchild == NULL)
		{
		(*p)->lchild = NULL;
		printf("p->lchild为NULL!\n");
		}
	else
		printf("%x %c\n",(*p)->lchild,(*p)->lchild->key);
	if((*p)->rchild == NULL)
	{	
		(*p)->rchild = NULL;
		printf("p->rchild为NULL!\n");
	}
	else
		printf("%x %c\n",(*p)->rchild,(*p)->rchild->key);

	if((*p)->rchild == NULL)
	{
		*q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if((*p)->lchild == NULL)
	{
		*q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{
		*q = (*p);
		*s = (*p)->lchild;
		while((*s)->rchild)
		{
			*q = *s;
			*s = (*s)->rchild;
		}
		(*p)->key = (*s)->key;
		if((*q)!=(*p))
			(*q)->rchild = (*s)->lchild;
		else
			(*q)->lchild = (*s)->lchild;
		free(s); 
	}
}
