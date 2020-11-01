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

//ǰ�����,������ 
int PreOrder(BiTree b)
{
	if(b==NULL) return 0;	//�ն����� 
	else{
		cout<<b->data;
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	} 
	return 1;
}
//�������,����� 
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
//�������,���Ҹ� 
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
	//����ǰ�����
	BiTree b;
	CreateBiTree(b);
	cout<<"�ݹ������"<<endl;
	cout<<"���������";
	PreOrder(b);
	cout<<endl;
	cout<<"���������";
	MidOrder(b);
	cout<<endl;
	cout<<"���������";
	PostOrder(b);
	cout<<endl<<endl;
	
	return 0;
}