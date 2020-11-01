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

int InitQueue(SqQueue &Q){
	Q.base=(Elemtype*)malloc(N*sizeof(Elemtype));
	if(!Q.base) exit(0);
	Q.front=Q.rear=0;
	return 1;
} 
//入队
int EnterQueue(SqQueue &Q,Elemtype e)
{
	if((Q.rear+1)%N==Q.front) return 0;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%N;
	return 1; 
} 
//出队
int OutQueue(SqQueue &Q,Elemtype &e)
{
	if(Q.rear==Q.front) return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%N;
	return 1;
} 
//取循环队列的队头元素
Elemtype GetQueueFront(SqQueue &Q,Elemtype &e)
{
	if(Q.front!=Q.rear)
		return Q.base[Q.front];
} 
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+N)%N;
}
int main()
{
	SqQueue q;
	InitQueue(q);
	
	Elemtype t;
	for(int i=0;i<3;i++)
	{
		cin>>t;
		EnterQueue(q,t);
	}
	cout<<"队列的长度为："<<QueueLength(q)<<endl;
	for(int i=0;i<3;i++)
	{
		OutQueue(q,t);
		cout<<t;
	}
	cout<<endl;
	cout<<"新的队列的长度为："<<QueueLength(q)<<endl;
	return 0;
}