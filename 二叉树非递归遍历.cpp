#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define N 50
typedef char Elemtype;
typedef struct BiTNode{
	Elemtype data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

const char* str="ABE#L###DH##J#M##";
int index=0;
//�������ķǵݹ�ʵ����Ҫ�õ�ջ 
//����ջ
typedef struct{
	BiTree data[N];
	int top;
}StackBiTree;
//��ʼ��ջ 
void InitStack(StackBiTree* &s)
{
	s=(StackBiTree*)malloc(sizeof(StackBiTree));
	s->top=-1;	 
}
//��ջ 
int EnterStack(StackBiTree* &s,BiTree b)
{
	if(s->top >= N) return 0;	//ջ���� 
	else{
		s->top++;
		s->data[s->top]=b;
	}
	return 1;
}
//��ջ
int OutStack(StackBiTree* &s,BiTree &b)
{
	if(s->top == -1) return 0;	//ջ�Ѿ�Ϊ��
	else{
		b=s->data[s->top];
		s->top--;
	} 
	return 1;
} 
//�õ�ջ��Ԫ��
BiTree TopElemtype(StackBiTree* s)
{
	return s->data[s->top];
} 
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(StackBiTree* s)
{
	if(s->top==-1) return true;	//���ջΪ�գ�����-1 
	else return false;
} 
//����ǰ�����������������
int CreateBiTree(BiTree &b)
{
	char ch=str[index++];	//����ѡ��Ӽ�������
	if(ch=='#') b=NULL;
	else{
		b=(BiTree)malloc(sizeof(BiTNode));
		b->data=ch;	//���ɸ��ڵ� 
		CreateBiTree(b->lchild);	//������ 
		CreateBiTree(b->rchild);	//������ 
	}
	return 1;
} 
//ǰ������ǵݹ� 
int PreOrder_s(BiTree b)
{
	StackBiTree* s;
	BiTree e;
	InitStack(s);
	EnterStack(s,b);
	while(!StackEmpty(s)){
		OutStack(s,e);
		b=e;
		cout<<e->data;
		if(b->rchild) EnterStack(s,b->rchild);
		if(b->lchild) EnterStack(s,b->lchild);
	}
	return 1;
}
//��������ǵݹ� 
BiTree GoForBiTree(BiTree b,StackBiTree* s)
{
	if(!b) return NULL;	//��������Ϊ�գ����ؿ�
	while(b->lchild){
		EnterStack(s,b);
		b=b->lchild;
	}
	return b;
}
int MidOrder_s(BiTree b)
{
	StackBiTree* s;
	InitStack(s);
	BiTree e;
	BiTree t=GoForBiTree(b,s);
	while(t){
		cout<<t->data;
		if(t->rchild){
			t=GoForBiTree(t->rchild,s);
		}
		else if(!StackEmpty(s)){
			OutStack(s,e);
			t=e;
		}
		else t=NULL;
	}
	return 1;
} 
//��������ǵݹ� 
void PostOrder_s(BiTree b)
{
	StackBiTree* s;
	BiTree e;
	InitStack(s);
	bool flag;
	BiTree p,r;
	p=b;
	do{
		while(p!=NULL){
			EnterStack(s,p);
			p=p->lchild;
		}	
		r=NULL;
		flag=true;
		while(!StackEmpty(s)&&flag){
			p=TopElemtype(s);
			if(p->rchild==r){
				cout<<p->data;
				OutStack(s,e);
				p=e;
				r=p;
			}
			else{
				p=p->rchild;
				flag=false;
			}
		} 
	}while(!StackEmpty(s));
	cout<<endl;
} 
int main()
{
	//����ǰ�����
	BiTree b;
	CreateBiTree(b);
	cout<<"�ݹ������"<<endl;
	cout<<"���������";
	PreOrder_s(b);
	cout<<endl;
	cout<<"���������";
	MidOrder_s(b);
	cout<<endl;
	cout<<"���������";
	PostOrder_s(b);
	cout<<endl<<endl;
	
	return 0;
}