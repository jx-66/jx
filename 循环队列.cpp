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

int InitQueue(SqQueue &Q){
	Q.base=(Elemtype*)malloc(N*sizeof(Elemtype));
	if(!Q.base) exit(0);
	Q.front=Q.rear=0;
	return 1;
} 
//���
int EnterQueue(SqQueue &Q,Elemtype e)
{
	if((Q.rear+1)%N==Q.front) return 0;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%N;
	return 1; 
} 
//����
int OutQueue(SqQueue &Q,Elemtype &e)
{
	if(Q.rear==Q.front) return 0;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%N;
	return 1;
} 
//ȡѭ�����еĶ�ͷԪ��
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
	cout<<"���еĳ���Ϊ��"<<QueueLength(q)<<endl;
	for(int i=0;i<3;i++)
	{
		OutQueue(q,t);
		cout<<t;
	}
	cout<<endl;
	cout<<"�µĶ��еĳ���Ϊ��"<<QueueLength(q)<<endl;
	return 0;
}