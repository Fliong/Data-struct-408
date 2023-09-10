#pragma once
/*ջ�����к�������ز����㷨����*/

#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
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
typedef struct {
	ElemType data[MAXSIZE];
	int top_1, top_2;
}ShareStack;

/*�ӵ����ݽṹ*/

/*��ͨ��*/
typedef struct Queue {
	ElemType data[MAXSIZE];
	int front,rear;
	int tag;
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
ElemType ReadTop(SqStack& S); 

void ContinePush(SqStack& S);//������ջ
void ContinePop(SqStack& S, int len);//������ջ
bool ShareStackOp(ShareStack& Shs);//����ջ����

bool IOStackLegality(char Arryop[]); //����ջ�����Ƿ�Ϸ��ж�
bool CentralSym(LinkStack& L);//�Ƿ�Ϊ���ĶԳ��ַ�

/*���в�������*/
void InitQueue(SqQueue& Q);
bool InQueue(SqQueue& Q, ElemType x);
bool OutQueue(SqQueue& Q, ElemType& x);
void PrintQueue(SqQueue& Q);


/*�ۺ�*/
bool QueueTbyStack(SqQueue& Q, SqStack& S);  //Page 082_02   ����ջ������Ԫ������