#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define N 50
typedef char Elemtype;
typedef struct StackNode{
	Elemtype data;
	struct StackNode* next;
}StackNode,*LinkStack;

void InitStack(LinkStack &s)
{
	s=NULL;	//栈顶指针置空 
}
int Push(LinkStack &s,Elemtype e)
{
	LinkStack p;
	p=(StackNode*)malloc(N*sizeof(StackNode));
	p->data=e;
	p->next=s;
	s=p;
	return 1;
} 
int StackEmpty(LinkStack s)
{
	if(s==NULL) return 0;
	else return 1;
} 
int StackLength(LinkStack s)
{
	int len=0;
	while(s!=NULL){
		LinkStack p;
		p=s;
		s=s->next;
		len++; 
	} 
	return len;
}
int Pop(LinkStack &s,Elemtype &e)
{
	LinkStack p;
	if(s==NULL) return 0;
	e=s->data;
	p=s;
	s=s->next;
	free(p);
	return 1;
}
int main()
{
	LinkStack s;
	InitStack(s);
	for(int i=0;i<3;i++)
	{
		Elemtype p;
		cin>>p;
		Push(s,p); 
	}
	cout<<"栈的长度："<<StackLength(s)<<endl;
	Elemtype e;
	while(StackEmpty(s)){
		Pop(s,e);
		cout<<e;
	} 
	cout<<endl<<endl; 
	return 0;
} 