#pragma once
/*ջ�����к�������ز����㷨����*/

#include<stdlib.h>
#include<iostream>
#include<math.h>
#define MAXSIZE 10

typedef int ElemType;
using namespace std;

/*ջ�����ݽṹ*/

/*��ͨջ�ṹ*/
typedef struct Stack {
	ElemType data[MAXSIZE];
	int top;
} SqStack;
/*��ջ�ṹ*/
typedef struct LStack {
	ElemType data;
	struct LStack *next;
} *LinkStack;

/*�ӵ����ݽṹ*/

/*��ͨ��*/
typedef struct Queue {
	ElemType data[MAXSIZE];
	int front,rear;
} SqQueue;
/*���ӽṹ*/
typedef struct  LQueue{
	ElemType data;
	struct LQueue *next;
} QueueNode;
typedef struct {
	QueueNode* front, * rear;
} *Linkptr;


/*ջ��������*/
void InitStack(SqStack& S);
bool StackEmpty(SqStack& S);
bool PushStack(SqStack& S, ElemType x);
bool PopStack(SqStack& S, ElemType& x);
void StackPrint(SqStack& S);

void ContinePush(SqStack& S);//������ջ
void ContinePop(SqStack& S, int len);//������ջ