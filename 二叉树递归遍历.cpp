#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef char Elemtype;

typedef struct BiTNode{
	Elemtype data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

const char* str="ABE#L###DH##J#M##";
int index=0;

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

//前序遍历,根左右 
int PreOrder(BiTree b)
{
	if(b==NULL) return 0;	//空二叉树 
	else{
		cout<<b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	} 
	return 1;
}
//中序遍历,左根右 
int MidOrder(BiTree b)
{
	if(b==NULL) return 0;
	else{
		MidOrder(b->lchild);
		cout<<b->data;
		MidOrder(b->rchild);
	}
	return 1;	
} 
//后序遍历,左右根 
int PostOrder(BiTree b)
{
	if(b==NULL) return 0;
	else{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout<<b->data; 
	}
	return 1;
}

int main()
{
	//输入前序遍历
	BiTree b;
	CreateBiTree(b);
	cout<<"递归遍历："<<endl;
	cout<<"先序遍历：";
	PreOrder(b);
	cout<<endl;
	cout<<"中序遍历：";
	MidOrder(b);
	cout<<endl;
	cout<<"后序遍历：";
	PostOrder(b);
	cout<<endl<<endl;
	
	return 0;
}