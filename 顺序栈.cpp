#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define N 50

typedef char Elemtype;

typedef struct SqStack{
	Elemtype *base;	//ջ��
	Elemtype *top;	//ջ��
	int StackSize;
}SqStack;

//��ʼ��ջ
int InitStack(SqStack &s)
{
	s.base=(Elemtype*)malloc(sizeof(Elemtype));
	if(!s.base) return 0;	//����ʧ��
	s.top=s.base;
	s.StackSize=N;
}
//����ջ
int DestroyStack(SqStack &s)
{

}
//���һ��ջ
void ClearStack(SqStack &s)
{
	s.base=s.top;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack s)
{
	if(s.base==s.top) return true;
	else return false;
}
//ջ��Ԫ�صĸ���
int StackLength(SqStack s)
{
	return s.top-s.base;
}
//��Ԫ��ѹ��ջ
int Push(SqStack &s,Elemtype e)
{
	if(s.top-s.base>=N) return 0;//ջ����
	*(s.top)=e;
	s.top++;	//*(s.top++)=e;
	return 1;
}
//ɾ��ջ��Ԫ��
int Pop(SqStack &s,Elemtype &e)
{
	if(s.top-s.base==0) return 0;//ջ��Ϊ��
	--s.top;
	e=*(s.top);//e=*(--s.top);
	return 1;
}
int main()
{
	SqStack s;
	InitStack(s);
	cout<<"������5��Ԫ�أ�"; 
	for(int i=0;i<5;i++)
	{
		char ch;
		cin>>ch;
		Elemtype tmp=ch;
		Push(s,tmp);
	}
	cout<<"ջ��Ԫ�ظ�����"<<StackLength(s)<<endl;
	cout<<"ջ��Ԫ�أ�";
	for(int i=0;i<4;i++)
	{
		Elemtype e;
		Pop(s,e);
		cout<<e;
	}
	cout<<endl;
	cout<<"ջ�Ƿ�Ϊ�գ�"<<StackEmpty(s)<<endl;
	
	ClearStack(s);
	cout<<"ջ�Ƿ�Ϊ�գ�"<<StackEmpty(s)<<endl;
	return 0;
}