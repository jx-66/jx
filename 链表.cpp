#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef char Elemtype; 
typedef struct Node
{
	Elemtype data;	//数据域 
	struct Node *next;	//指针域 
}Node,*LinkList; 	//更新Node,同时创建一个Node类型的指针 

//创建一个空链表 
void InitList(LinkList &L)
{
	L=(LinkList)malloc(sizeof(Node));
	L->next=NULL;	//头节点指针域为空，该链表为空 
	//return 1;
}
//判断链表是否为空
bool ListEmpty(LinkList L)
{
	if(L->next==NULL) return true;
	else return false;
} 
//销毁一个单链表
int DestroyList(LinkList &L)
{
	Node *p;	//或者LinkList p; 
	while(L){
		p=L;
		L=L->next;
		free(p);
	}
	return 1;
} 
//清空单链表
int ClearList(LinkList &L)
{
	Node *p,*q;	//等价于LinkList p,q; 
	p=L->next;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return 1;
} 
//返回链表中元素的个数
int ListLength(LinkList L)
{
	int n=0;
	LinkList p;
	p=L->next;	//p指向第一个节点、 
	while(p){
		n++;
		p=p->next;
	}
	return n;
} 
//返回第i个元素的值
int getElem(LinkList L,int i,Elemtype &e)
{
	int j=1;
	Node *p;
	p=L->next;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i) return 0;	//如果第i个元素不存在，或者p为空还不存在 
	e=p->data;
	return 1;
}
//删除第i个元素，并返回其值e
int ListDelete(LinkList &L,int i,Elemtype &e)
{
	int j=0;
	LinkList p,q;
	p=L;
	while(p->next&&j<i-1){	//寻找第i-1个结点，并令p指向要删除的结点的前驱 
		p=p->next;
		++j;
	}
	if(!p->next||j>i-1) return 0;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return 1;
}
//在第i个位置之前插入元素e 
int ListInsert(LinkList &L,int i,Elemtype e)
{
	int j=0;
	Node *p=L;
	while(!p&&j<i-1){
		p=p->next;
		++j;
	}
	if(!p||j>i-1) return 0;
	
	Node *s;
	s=(Node*) malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1; 
}
//将新的数据插入到表头
void ListInsertHead(LinkList &L,int n,Elemtype e)
{
	L=(Node*)malloc(sizeof(Node));
	L->next=NULL;
	LinkList p;
	for(int i=n;i>0;--i)
	{
		p=(Node*)malloc(sizeof(Node));
		p->data=e;
		p->next=L->next;
		L->next=p;
	}
} 
//将数据插入到原有链表尾部 
void ListInsertTail_OldList(LinkList &L,Elemtype e)
{
	LinkList p;
	p=L->next;
	while(p->next!=NULL){
		p=p->next;
	}
	Node *q;
	q=(Node*)malloc(sizeof(Node));
	q->data=e;
	q->next=p->next; 
	p->next=q;
}
//将新的数据插入到新建的链表末尾,总共n个元素 
void ListInsertTail(LinkList &L,int n)
{
	L=(Node*)malloc(sizeof(Node));
	L->next=NULL;
	
	LinkList r,p;
	r=L;
	for(int i=0;i<n;++i)
	{
		p=(Node*)malloc(sizeof(Node));
		Elemtype tmp;
		cin>>tmp;
		p->data=tmp;
		r->next=p;
		r=p;
	} 
} 
//遍历链表
void Show(LinkList &L)
{
	printf("\nShow:\n");
	LinkList p;
	p=L->next;	//p指向首元结点 
	while(p->next){
		cout<<p->data;
		p=p->next;
	}
	cout<<p->data<<endl;
} 

int main()
{
	LinkList l;
	InitList(l);
	
	ListInsert(l,1,'a');
	ListInsert(l,1,'b');
	ListInsert(l,1,'c');
	
	Show(l);
	
	for(int i=0;i<3;i++)
	{
		Elemtype t;
		cin>>t;
		ListInsertTail_OldList(l,t);
	}
	Show(l);
	
	Elemtype tmp;
	cin>>tmp;
	ListInsertTail_OldList(l,tmp);
	Show(l);
	
	cin>>tmp;
	ListInsertTail_OldList(l,tmp);
	Show(l);
	
	int n=ListLength(l);
	printf("%d\n",n);
	
	Elemtype elem;
	getElem(l,6,elem);
	cout<<elem<<endl;
	
	ListDelete(l,3,elem);
	Show(l);
	printf("%d\n",ListLength(l));
	
	
	ClearList(l);
	printf("%d\n",ListLength(l));
	
	return 0;
} 