#pragma once
/*栈，队列和数组相关操作算法声明*/

#include<stdlib.h>
#include<iostream>
#include<math.h>
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

/*队的数据结构*/

/*普通队*/
typedef struct Queue {
	ElemType data[MAXSIZE];
	int front,rear;
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

void ContinePush(SqStack& S);//连续入栈
void ContinePop(SqStack& S, int len);//连续出栈