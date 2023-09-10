#pragma once
/*栈，队列和数组相关操作算法声明*/

#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#define MAXSIZE 10

typedef int ElemType;
using namespace std;

/*栈的数据结构*/

/*普通栈结构*/
typedef struct Stack {
	ElemType data[MAXSIZE];
	int top;
} SqStack;
/*链栈结构*/
typedef struct LStack {
	ElemType data;
	struct LStack *next;
} *LinkStack;
typedef struct {
	ElemType data[MAXSIZE];
	int top_1, top_2;
}ShareStack;

/*队的数据结构*/

/*普通队*/
typedef struct Queue {
	ElemType data[MAXSIZE];
	int front,rear;
	int tag;
} SqQueue;
/*链队结构*/
typedef struct  LQueue{
	ElemType data;
	struct LQueue *next;
} QueueNode;
typedef struct {
	QueueNode* front, * rear;
} *Linkptr;


/*栈操作函数*/
void InitStack(SqStack& S);
bool StackEmpty(SqStack& S);
bool PushStack(SqStack& S, ElemType x);
bool PopStack(SqStack& S, ElemType& x);
void StackPrint(SqStack& S);
ElemType ReadTop(SqStack& S); 

void ContinePush(SqStack& S);//连续入栈
void ContinePop(SqStack& S, int len);//连续出栈
bool ShareStackOp(ShareStack& Shs);//共享栈操作

bool IOStackLegality(char Arryop[]); //出入栈操作是否合法判断
bool CentralSym(LinkStack& L);//是否为中心对称字符

/*队列操作函数*/
void InitQueue(SqQueue& Q);
bool InQueue(SqQueue& Q, ElemType x);
bool OutQueue(SqQueue& Q, ElemType& x);
void PrintQueue(SqQueue& Q);


/*综合*/
bool QueueTbyStack(SqQueue& Q, SqStack& S);  //Page 082_02   利用栈将队列元素逆置