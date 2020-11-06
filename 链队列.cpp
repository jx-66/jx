#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef char Elemtype;
typedef struct QNode{
	Elemtype data;
	struct QNode *next; 
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

int InitQueue(LinkQueue &q)
{
	q.front=q.rear=(QueuePtr)malloc(sizeof(QueuePtr));
	if(!q.front) return 0;
	q.front->next=NULL;
	return 1;
}
int DestroyQueue(LinkQueue &q)
{
	QueuePtr p;
	while(q.front){
		p=q.front->next;	//可以不用p,用q.rear
		free(q.front);
		q.front=p;
	}
	return 1;
}
int EnterQueue(LinkQueue &q,Elemtype e)
{
	//插入元素e为新的队尾元素
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(0); 
	p->data=e;
	p->next=NULL;
	q.rear->next=p;
	q.rear=p;
	return 1;
} 
int OutQueue(LinkQueue &q,Elemtype &e)
{
	QueuePtr p;
	if(q.front==q.rear) return 0;	//空队列
	p=q.front->next;
	e=p->data;
	q.front->next=p->next;
	if(q.rear==p)	//考虑删除的是最后一个结点的情况，
	{				//也需要修改q.rear,指向头结点
		q.rear=q.front;
	}				 
		
	free(p);
	return 1; 
}
int GetQueueHead(LinkQueue &q,Elemtype &e)
{
	if(q.front==q.rear) return 0;
	e=q.front->next->data;
}
int main()
{
	LinkQueue q;
	InitQueue(q);
	Elemtype t;
	for(int i=0;i<3;i++)
	{
		cin>>t;
		EnterQueue(q,t);
	}
	cout<<endl;
	for(int i=0;i<3;i++)
	{
		OutQueue(q,t);
		cout<<t<<endl;
	}
	return 0;
}