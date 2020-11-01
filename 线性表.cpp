#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define N 20
typedef char Elemtype;
typedef struct{
	Elemtype *elem;
	int length;
}Sqlist;

int InitList(Sqlist &l)
{
	l.elem=(Elemtype*)malloc(sizeof(Elemtype));
	if(!l.elem) return 0;	//如果空间分配失败 
	
	l.length=0; 
}
void DestroyList(Sqlist &l)
{
	free(l.elem);
}
void ClearList(Sqlist &l)
{
	l.length=0;
}
bool ListEmpty(Sqlist &l)
{
	if(l.length==0) return true;
	else return false;
}
int ListLength(Sqlist &l)
{
	return l.length;
} 
int GetElemtype(Sqlist &l,int i,Elemtype &e)
{
	if(i<1||i>l.length) return 0;
	e=l.elem[i-1];
	return 1;
}
int Compare(Elemtype t1,Elemtype t2)
{
	if(t1==t2) return 1;
	else return 0;
}
int LocateElemtype(Sqlist &l,Elemtype e)
{
	for(int i=0;i<l.length;i++)
	{
		if(Compare(e,l.elem[i])==1) return i;
	}
	return -1;
}
int NextElemtype(Sqlist &l,int current_elem,Elemtype &e)
{
	if(current_elem<0||current_elem>l.length-1) return 0;
	e=l.elem[current_elem+1];
	return 1;
}
void TailInsert(Sqlist &l,Elemtype e)
{
	l.elem[l.length]=e;
	l.length++;
}
int ListInsert(Sqlist &l,int i,Elemtype e)
{
	if(i<0||i>l.length) return 0;
	for(int j=l.length;j>i;j--)
	{
		l.elem[j]=l.elem[j-1];
	}
	l.elem[i]=e;
	l.length+=1;
	return l.length;
} 
int ListDelete(Sqlist &l,int i)
{
	if(i<0||i>l.length-1) return 0;
	for(int j=i;j<l.length-1;j++)
		l.elem[j]=l.elem[j+1];
		
	l.length-=1;
	return l.length;
}
void ShowList(Sqlist &l)
{
	for(int i=0;i<l.length;i++)
	{
		cout<<l.elem[i];
	}
	cout<<endl;
	cout<<"线性表的长度为："<<l.length<<endl;
}
int main()
{
	Sqlist l;
	InitList(l);
	for(int i=0;i<3;i++)
	{
		Elemtype e;
		cin>>e;
		TailInsert(l,e);
	}
	Elemtype tmp='y';
	ListInsert(l,2,tmp);
	ShowList(l);
	
	cout<<endl; 
	cout<<"判断线性表是否为空；"<<ListEmpty(l)<<endl; 
	
	Elemtype tmp1;
	cout<<endl;
	if(NextElemtype(l,1,tmp1)) cout<<tmp1<<endl;
	else cout<<"No NextElem!"<<endl;
	
	cout<<endl;
	int location=LocateElemtype(l,tmp);
	if(location==-1) cout<<"No this Elem."<<endl;
	else cout<<location<<endl;
	
	printf("\n");
	ListDelete(l,2);
	ShowList(l);
	
	cout<<endl;
	ClearList(l);
	printf("%d\n",ListLength(l));
	
	DestroyList(l);
	return 0;
} 