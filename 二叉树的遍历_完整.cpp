/*
本例中的树为：
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
//创建二叉树 
typedef struct BiTNode{
	Elemtype data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

const char* str="ABE#L###DH##J#M##";
int index=0;

//创建栈
typedef struct{
	struct BiTNode* data[N];
	int top;
}StackBiTNode;
//初始化栈
void initStack(StackBiTNode* &s){
	s=(StackBiTNode*)malloc(sizeof(StackBiTNode));
	s->top=-1;
}
//入栈
void Push(StackBiTNode* &s,BiTree t){
	if(s->top >= N)
		return;
	else{
		s->top++;
		s->data[s->top]=t;
	}
}
//出栈
void Pop(StackBiTNode*& s, BiTree  &r){
	if(s->top == -1)
		return;
	else{
		r=s->data[s->top];
		s->top--;
	}
}
// 判断栈是否为空
bool StackEmpty(StackBiTNode* s) {
	return(s->top == -1);
}
// 获取栈顶元素
struct BiTNode* GetElemType(StackBiTNode* s) {
	return s->data[s->top];
}

//按先序次序输入结点值的方式建立二叉树T 
int CreateBiTree(BiTree &T)
{
	//输入字符,这里暂时省略，直接利用str函数 
	//scanf(&ch);
	char ch=str[index++];	
	if(ch=='#')	//c为特殊数据(如#)用以表示空树 
		T=NULL; 
	else{
		T=(BiTNode*)malloc(sizeof(BiTNode));
		T->data=ch;//生成根节点
		CreateBiTree(T->lchild);//左子树
		CreateBiTree(T->rchild);//右子树 
	} 
	return OK; 
} 

//先序遍历 
int PreOrderTraverse(BiTree T)
{
	if(T==NULL) return OK;//空二叉树
	else{
		cout<<T->data; //visit(T->data);  访问根节点
		PreOrderTraverse(T->lchild);	//递归遍历左子树
		PreOrderTraverse(T->rchild);	//递归遍历右子树 
	} 
}
//中序遍历 
 InOrderTraverse(BiTree T)
{
	if(T==NULL) return OK;	//空二叉树
	else{
		InOrderTraverse(T->lchild);//递归遍历左子树
		cout<<T->data;//visit(T->data);访问根节点
		InOrderTraverse(T->rchild);//递归遍历右子树 
	} 
}
//后序遍历
int PostOrderTraverse(BiTree T)
{
	if(T==NULL) return OK;	//空二叉树
	else{
		PostOrderTraverse(T->lchild);//递归遍历左子树
		PostOrderTraverse(T->rchild);//递归遍历右子树 
		cout<<T->data;//visit(T->data);访问根节点
	} 
}

//先序遍历非递归实现
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
//中序遍历非递归
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
//后序遍历非递归实现
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

//层次遍历二叉树的算法(利用队列)
typedef struct{
	BiTNode* data[N];
	int front,rear;
}SqQueue;	//顺序循环队列 
//初始化队列 
void InitQueue(SqQueue* &q) {
	q=(SqQueue*)malloc(sizeof(SqQueue));	//分配一个空间 
	q->front=q->rear=0;				//置-1 
}
//判断队列是否为空
bool QueueEmpty(SqQueue* &q) {
	if(q->front==q->rear)				//首指针和尾指针相等，说明为空 
		return true;						//返回真 
	else
		return false;						//返回假 
}
//进队列
bool enQueue(SqQueue*& q, BiTNode* &B){
	if (q->rear==N-1){			//判断队列是否满了 
		return false;						//返回假 
	}
	q->rear++;								//头指针加 1 
	q->data[q->rear]=B;					//传值 
	return true;							//返回真 
}
//出队列 
bool deQueue(SqQueue* &q, BiTNode* &B) {
	if(q->front == q->rear) {				//判断是否空了 
		return false;						//返回假 
	}
	q->front++;								//尾指针加 1 
	B=q->data[q->front];					//取值 
	return true;							//返回真 
}
//层次遍历 
void LevelTraverse(BiTNode* &p)
{
	SqQueue *q;
	InitQueue(q);//初始化队列
	if(p!=NULL)
		enQueue(q,p);//根节点指针进队
	while(QueueEmpty(q)!=true){
		deQueue(q,p);//出队结点p
		cout<<p->data; //visit(p->data)  访问p
		if(p->lchild)
			enQueue(q,p->lchild);//非空的左孩子指针进队
		if(p->rchild)
			enQueue(q,p->rchild);//非空的右孩子指针进队
	}
} 

void preorder(BiTree T)//二叉链表的实现
{
	if(T!=NULL)
	{
		printf("%d\t",T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	} 
}

//求二叉树的深度
int Depth(BiTree T)
{
	int h1,h2;
	if(T==NULL)
		return 0;//如果是空树返回0
	else{
		h1=Depth(T->lchild);
		h2=Depth(T->rchild);
		return h1>h2?h1+1:h2+1;
	} 
} 
//求二叉树的结点总数
int NodeCount(BiTree T)
{
	if(T==NULL)
		return 0;//如果是空树返回0
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1; 
}
//计算二叉树的叶子总数
int LeafCount(BiTree T)
{
	if(T==NULL)
		return 0;//如果是空树返回0
	if(T->lchild==NULL&&T->rchild==NULL)
		return 1;//如果是叶子结点返回1
	else
		return LeafCount(T->lchild)+LeafCount(T->rchild); 
}


int main()
{
	StackBiTNode *s;
	BiTree b;
	initStack(s);
	CreateBiTree(b);
	
	cout<<"递归遍历："<<endl;
	cout<<"先序遍历：";
	PreOrderTraverse(b);
	cout<<endl;
	cout<<"中序遍历：";
	InOrderTraverse(b);
	cout<<endl;
	cout<<"后序遍历：";
	PostOrderTraverse(b);
	cout<<endl<<endl; 
	
	cout<<"非递归遍历："<<endl; 
	cout<<"先序遍历:";
	PreOrderBiTNode1(b);
	cout<<endl;
	cout<<"中序遍历：";
	MidOrderBiTNode1(b);
	cout<<endl;
	cout<<"后序序遍历:";
	PostOrderBiTNode1(b);
	cout<<endl<<endl;
	
	cout<<"层次遍历：";
	LevelTraverse(b);
	cout<<endl<<endl;
	 
	cout<<"树的深度为："<<Depth(b)<<endl;
	cout<<"树中节点的个数为："<<NodeCount(b)<<endl;
	cout<<"树中叶子节点的个数："<<LeafCount(b)<<endl;
	return 0;
} 