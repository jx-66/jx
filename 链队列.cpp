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
		p=q.front->next;	//���Բ���p,��q.rear
		free(q.front);
		q.front=p;
	}
	return 1;
}
int EnterQueue(LinkQueue &q,Elemtype e)
{
	//����Ԫ��eΪ�µĶ�βԪ��
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
	if(q.front==q.rear) return 0;	//�ն���
	p=q.front->next;
	e=p->data;
	q.front->next=p->next;
	if(q.rear==p)	//����ɾ���������һ�����������
	{				//Ҳ��Ҫ�޸�q.rear,ָ��ͷ���
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