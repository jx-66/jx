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
//二叉树的非递归实现需要用到栈 
//创建栈
typedef struct{
	BiTree data[N];
	int top;
}StackBiTree;
//初始化栈 
void InitStack(StackBiTree* &s)
{
	s=(StackBiTree*)malloc(sizeof(StackBiTree));
	s->top=-1;	 
}
//入栈 
int EnterStack(StackBiTree* &s,BiTree b)
{
	if(s->top >= N) return 0;	//栈已满 
	else{
		s->top++;
		s->data[s->top]=b;
	}
	return 1;
}
//出栈
int OutStack(StackBiTree* &s,BiTree &b)
{
	if(s->top == -1) return 0;	//栈已经为空
	else{
		b=s->data[s->top];
		s->top--;
	} 
	return 1;
} 
//得到栈顶元素
BiTree TopElemtype(StackBiTree* s)
{
	return s->data[s->top];
} 
//判断栈是否为空
bool StackEmpty(StackBiTree* s)
{
	if(s->top==-1) return true;	//如果栈为空，返回-1 
	else return false;
} 
//根据前序遍历，创建二叉树
int CreateBiTree(BiTree &b)
{
	char ch=str[index++];	//或者选择从键盘输入
	if(ch=='#') b=NULL;
	else{
		b=(BiTree)malloc(sizeof(BiTNode));
		b->data=ch;	//生成根节点 
		CreateBiTree(b->lchild);	//左子树 
		CreateBiTree(b->rchild);	//右子树 
	}
	return 1;
} 
//前序遍历非递归 
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
//中序遍历非递归 
BiTree GoForBiTree(BiTree b,StackBiTree* s)
{
	if(!b) return NULL;	//如果这个树为空，返回空
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
//后序遍历非递归 
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
	//输入前序遍历
	BiTree b;
	CreateBiTree(b);
	cout<<"递归遍历："<<endl;
	cout<<"先序遍历：";
	PreOrder_s(b);
	cout<<endl;
	cout<<"中序遍历：";
	MidOrder_s(b);
	cout<<endl;
	cout<<"后序遍历：";
	PostOrder_s(b);
	cout<<endl<<endl;
	
	return 0;
}