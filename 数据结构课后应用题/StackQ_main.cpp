#include"StackQue.h"

int main() {
	SqStack S;
	ElemType x;
	int len;
	InitStack(S);
	ContinePush(S);
	cin >> len;
	ContinePop(S, len);
	StackPrint(S);
}