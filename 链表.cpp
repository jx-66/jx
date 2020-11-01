#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef char Elemtype; 
typedef struct Node
{
	Elemtype data;	//������ 
	struct Node *next;	//ָ���� 
}Node,*LinkList; 	//����Node,ͬʱ����һ��Node���͵�ָ�� 

//����һ�������� 
void InitList(LinkList &L)
{
	L=(LinkList)malloc(sizeof(Node));
	L->next=NULL;	//ͷ�ڵ�ָ����Ϊ�գ�������Ϊ�� 
	//return 1;
}
//�ж������Ƿ�Ϊ��
bool ListEmpty(LinkList L)
{
	if(L->next==NULL) return true;
	else return false;
} 
//����һ��������
int DestroyList(LinkList &L)
{
	Node *p;	//����LinkList p; 
	while(L){
		p=L;
		L=L->next;
		free(p);
	}
	return 1;
} 
//��յ�����
int ClearList(LinkList &L)
{
	Node *p,*q;	//�ȼ���LinkList p,q; 
	p=L->next;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return 1;
} 
//����������Ԫ�صĸ���
int ListLength(LinkList L)
{
	int n=0;
	LinkList p;
	p=L->next;	//pָ���һ���ڵ㡢 
	while(p){
		n++;
		p=p->next;
	}
	return n;
} 
//���ص�i��Ԫ�ص�ֵ
int getElem(LinkList L,int i,Elemtype &e)
{
	int j=1;
	Node *p;
	p=L->next;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i) return 0;	//�����i��Ԫ�ز����ڣ�����pΪ�ջ������� 
	e=p->data;
	return 1;
}
//ɾ����i��Ԫ�أ���������ֵe
int ListDelete(LinkList &L,int i,Elemtype &e)
{
	int j=0;
	LinkList p,q;
	p=L;
	while(p->next&&j<i-1){	//Ѱ�ҵ�i-1����㣬����pָ��Ҫɾ���Ľ���ǰ�� 
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
//�ڵ�i��λ��֮ǰ����Ԫ��e 
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
//���µ����ݲ��뵽��ͷ
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
//�����ݲ��뵽ԭ������β�� 
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
//���µ����ݲ��뵽�½�������ĩβ,�ܹ�n��Ԫ�� 
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
//��������
void Show(LinkList &L)
{
	printf("\nShow:\n");
	LinkList p;
	p=L->next;	//pָ����Ԫ��� 
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