#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define N 50

typedef char Elemtype;
typedef struct{
	Elemtype *base;	//初始化动态分配存储空间 
	int front;//指向队列头元素 
	int rear;//指向队列尾元素的下一个位置 
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
	cout<<"队列的长度："<<QueueLength(q)<<endl;
	
	for(int i=0;i<3;i++)
	{
		Elemtype t;
		DelQueue(q,t);
		cout<<t; 
	}
	cout<<endl;
	cout<<"判断队列是否为空："<<QueueEmpty(q)<<endl; 
	return 0;
}