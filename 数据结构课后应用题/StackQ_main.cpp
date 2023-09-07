#include"StackQue.h"

int main() {
	SqStack S;
	ShareStack M;
	ElemType x;
	int len;

	ShareStackOp(M);
	exit(0);

	InitStack(S);
	ContinePush(S);
	cout << ReadTop(S) << endl;
	cin >> len;
	ContinePop(S, len);
	StackPrint(S);
	cout << ReadTop(S) << endl;
}