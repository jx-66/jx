/*
�����е���Ϊ��
		A
	B		D
  E   #   H   J
#  L # # # # # M 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define N 500
const int OK=1;

typedef char Elemtype;
//���������� 
typedef struct BiTNode{
	Elemtype data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

const char* str="ABE#L###DH##J#M##";
int index=0;

//����ջ
typedef struct{
	struct BiTNode* data[N];
	int top;
}StackBiTNode;
//��ʼ��ջ
void initStack(StackBiTNode* &s){
	s=(StackBiTNode*)malloc(sizeof(StackBiTNode));
	s->top=-1;
}
//��ջ
void Push(StackBiTNode* &s,BiTree t){
	if(s->top >= N)
		return;
	else{
		s->top++;
		s->data[s->top]=t;
	}
}
//��ջ
void Pop(StackBiTNode*& s, BiTree  &r){
	if(s->top == -1)
		return;
	else{
		r=s->data[s->top];
		s->top--;
	}
}
// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(StackBiTNode* s) {
	return(s->top == -1);
}
// ��ȡջ��Ԫ��
struct BiTNode* GetElemType(StackBiTNode* s) {
	return s->data[s->top];
}

//���������������ֵ�ķ�ʽ����������T 
int CreateBiTree(BiTree &T)
{
	//�����ַ�,������ʱʡ�ԣ�ֱ������str���� 
	//scanf(&ch);
	char ch=str[index++];	
	if(ch=='#')	//cΪ��������(��#)���Ա�ʾ���� 
		T=NULL; 
	else{
		T=(BiTNode*)malloc(sizeof(BiTNode));
		T->data=ch;//���ɸ��ڵ�
		CreateBiTree(T->lchild);//������
		CreateBiTree(T->rchild);//������ 
	} 
	return OK; 
} 

//������� 
int PreOrderTraverse(BiTree T)
{
	if(T==NULL) return OK;//�ն�����
	else{
		cout<<T->data; //visit(T->data);  ���ʸ��ڵ�
		PreOrderTraverse(T->lchild);	//�ݹ����������
		PreOrderTraverse(T->rchild);	//�ݹ���������� 
	} 
}
//������� 
 InOrderTraverse(BiTree T)
{
	if(T==NULL) return OK;	//�ն�����
	else{
		InOrderTraverse(T->lchild);//�ݹ����������
		cout<<T->data;//visit(T->data);���ʸ��ڵ�
		InOrderTraverse(T->rchild);//�ݹ���������� 
	} 
}
//�������
int PostOrderTraverse(BiTree T)
{
	if(T==NULL) return OK;	//�ն�����
	else{
		PostOrderTraverse(T->lchild);//�ݹ����������
		PostOrderTraverse(T->rchild);//�ݹ���������� 
		cout<<T->data;//visit(T->data);���ʸ��ڵ�
	} 
}

//��������ǵݹ�ʵ��
void PreOrderBiTNode1(BiTree B) {
	StackBiTNode* S;
	struct BiTNode* e;
	initStack(S);
	Push(S,B);
	while(!StackEmpty(S)){
		Pop(S,e);
		B=e;
		cout<<e->data;
		if(B->rchild){
			Push(S,B->rchild);
		}
		if(B->lchild){
			Push(S,B->lchild);
		}
	}
}
//��������ǵݹ�
BiTNode* GoForBiTNode(BiTree B, StackBiTNode* S) {
	if(!B)
		return NULL;
	while(B->lchild){
		Push(S,B);
		B=B->lchild;
	}
	return B;
}
void MidOrderBiTNode1(BiTree B) {
	StackBiTNode *S;
	initStack(S);
	struct BiTNode* e;
	BiTNode *t =GoForBiTNode(B,S);
	while(t){
		cout<<t->data;
		if(t->rchild){
			t=GoForBiTNode(t->rchild,S);
		}
		else if(!StackEmpty(S)){
			Pop(S,e);
			t=e;
		}
		else{
			t=NULL;
		}	
	}
}
//��������ǵݹ�ʵ��
void PostOrderBiTNode1(BiTNode* B) {
	StackBiTNode *S;
	struct BiTNode* e;
	initStack(S);
	bool flag;
	BiTNode*p,*r;
		p=B;
		do{
			while(p!=NULL){
				Push(S,p);
				p=p->lchild;
			}
			r=NULL;
			flag=true;
			while(!StackEmpty(S)&&flag){
				p=GetElemType(S);
				if(p->rchild==r){
					cout<<p->data;
					Pop(S,e);
					p=e;
					r=p;
				}
				else{
					p=p->rchild;
					flag=false;
				}
			}
		}while(!StackEmpty(S));
		cout<<endl;
}

//��α������������㷨(���ö���)
typedef struct{
	BiTNode* data[N];
	int front,rear;
}SqQueue;	//˳��ѭ������ 
//��ʼ������ 
void InitQueue(SqQueue* &q) {
	q=(SqQueue*)malloc(sizeof(SqQueue));	//����һ���ռ� 
	q->front=q->rear=0;				//��-1 
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue* &q) {
	if(q->front==q->rear)				//��ָ���βָ����ȣ�˵��Ϊ�� 
		return true;						//������ 
	else
		return false;						//���ؼ� 
}
//������
bool enQueue(SqQueue*& q, BiTNode* &B){
	if (q->rear==N-1){			//�ж϶����Ƿ����� 
		return false;						//���ؼ� 
	}
	q->rear++;								//ͷָ��� 1 
	q->data[q->rear]=B;					//��ֵ 
	return true;							//������ 
}
//������ 
bool deQueue(SqQueue* &q, BiTNode* &B) {
	if(q->front == q->rear) {				//�ж��Ƿ���� 
		return false;						//���ؼ� 
	}
	q->front++;								//βָ��� 1 
	B=q->data[q->front];					//ȡֵ 
	return true;							//������ 
}
//��α��� 
void LevelTraverse(BiTNode* &p)
{
	SqQueue *q;
	InitQueue(q);//��ʼ������
	if(p!=NULL)
		enQueue(q,p);//���ڵ�ָ�����
	while(QueueEmpty(q)!=true){
		deQueue(q,p);//���ӽ��p
		cout<<p->data; //visit(p->data)  ����p
		if(p->lchild)
			enQueue(q,p->lchild);//�ǿյ�����ָ�����
		if(p->rchild)
			enQueue(q,p->rchild);//�ǿյ��Һ���ָ�����
	}
} 

void preorder(BiTree T)//���������ʵ��
{
	if(T!=NULL)
	{
		printf("%d\t",T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	} 
}

//������������
int Depth(BiTree T)
{
	int h1,h2;
	if(T==NULL)
		return 0;//����ǿ�������0
	else{
		h1=Depth(T->lchild);
		h2=Depth(T->rchild);
		return h1>h2?h1+1:h2+1;
	} 
} 
//��������Ľ������
int NodeCount(BiTree T)
{
	if(T==NULL)
		return 0;//����ǿ�������0
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1; 
}
//�����������Ҷ������
int LeafCount(BiTree T)
{
	if(T==NULL)
		return 0;//����ǿ�������0
	if(T->lchild==NULL&&T->rchild==NULL)
		return 1;//�����Ҷ�ӽ�㷵��1
	else
		return LeafCount(T->lchild)+LeafCount(T->rchild); 
}


int main()
{
	StackBiTNode *s;
	BiTree b;
	initStack(s);
	CreateBiTree(b);
	
	cout<<"�ݹ������"<<endl;
	cout<<"���������";
	PreOrderTraverse(b);
	cout<<endl;
	cout<<"���������";
	InOrderTraverse(b);
	cout<<endl;
	cout<<"���������";
	PostOrderTraverse(b);
	cout<<endl<<endl; 
	
	cout<<"�ǵݹ������"<<endl; 
	cout<<"�������:";
	PreOrderBiTNode1(b);
	cout<<endl;
	cout<<"���������";
	MidOrderBiTNode1(b);
	cout<<endl;
	cout<<"���������:";
	PostOrderBiTNode1(b);
	cout<<endl<<endl;
	
	cout<<"��α�����";
	LevelTraverse(b);
	cout<<endl<<endl;
	 
	cout<<"�������Ϊ��"<<Depth(b)<<endl;
	cout<<"���нڵ�ĸ���Ϊ��"<<NodeCount(b)<<endl;
	cout<<"����Ҷ�ӽڵ�ĸ�����"<<LeafCount(b)<<endl;
	return 0;
} 