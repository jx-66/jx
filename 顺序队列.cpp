#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define N 50

typedef char Elemtype;
typedef struct{
	Elemtype *base;	//��ʼ����̬����洢�ռ� 
	int front;//ָ�����ͷԪ�� 
	int rear;//ָ�����βԪ�ص���һ��λ�� 
}SqQueue;

int InitQueue(SqQueue &q)
{
	q.base=(Elemtype*)malloc(N*sizeof(Elemtype));
	if(!q.base) return 0;
	q.front=0;
	q.rear=0;
	return 1;
}
//DestroyQueue(&q)
//ClearQueue(&q)

bool QueueEmpty(SqQueue q)
{
	if(q.front==q.rear) return true;
	else return false;
} 
int QueueLength(SqQueue q)
{
	return q.rear-q.front; 
}
int EnterQueue(SqQueue &q,Elemtype e)
{
	q.base[q.rear]=e;
	q.rear++;
}
int DelQueue(SqQueue &q,Elemtype &e)
{
	e=q.base[q.front];
	q.front++;
}
//QueueTraverse(s,visit())
int main()
{
	SqQueue q;
	InitQueue(q); 
	for(int i=0;i<3;i++)
	{
		Elemtype t;
		cin>>t;
		EnterQueue(q,t);
	} 
	cout<<"���еĳ��ȣ�"<<QueueLength(q)<<endl;
	
	for(int i=0;i<3;i++)
	{
		Elemtype t;
		DelQueue(q,t);
		cout<<t; 
	}
	cout<<endl;
	cout<<"�ж϶����Ƿ�Ϊ�գ�"<<QueueEmpty(q)<<endl; 
	return 0;
}