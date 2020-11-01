#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define N 50

typedef char Elemtype;

typedef struct SqStack{
	Elemtype *base;	//栈底
	Elemtype *top;	//栈顶
	int StackSize;
}SqStack;

//初始化栈
int InitStack(SqStack &s)
{
	s.base=(Elemtype*)malloc(sizeof(Elemtype));
	if(!s.base) return 0;	//分配失败
	s.top=s.base;
	s.StackSize=N;
}
//销毁栈
int DestroyStack(SqStack &s)
{

}
//清空一个栈
void ClearStack(SqStack &s)
{
	s.base=s.top;
}
//判断栈是否为空
bool StackEmpty(SqStack s)
{
	if(s.base==s.top) return true;
	else return false;
}
//栈中元素的个数
int StackLength(SqStack s)
{
	return s.top-s.base;
}
//将元素压入栈
int Push(SqStack &s,Elemtype e)
{
	if(s.top-s.base>=N) return 0;//栈已满
	*(s.top)=e;
	s.top++;	//*(s.top++)=e;
	return 1;
}
//删除栈顶元素
int Pop(SqStack &s,Elemtype &e)
{
	if(s.top-s.base==0) return 0;//栈已为空
	--s.top;
	e=*(s.top);//e=*(--s.top);
	return 1;
}
int main()
{
	SqStack s;
	InitStack(s);
	cout<<"请输入5个元素："; 
	for(int i=0;i<5;i++)
	{
		char ch;
		cin>>ch;
		Elemtype tmp=ch;
		Push(s,tmp);
	}
	cout<<"栈中元素个数："<<StackLength(s)<<endl;
	cout<<"栈中元素：";
	for(int i=0;i<4;i++)
	{
		Elemtype e;
		Pop(s,e);
		cout<<e;
	}
	cout<<endl;
	cout<<"栈是否为空？"<<StackEmpty(s)<<endl;
	
	ClearStack(s);
	cout<<"栈是否为空？"<<StackEmpty(s)<<endl;
	return 0;
}