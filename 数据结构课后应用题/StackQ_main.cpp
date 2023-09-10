#include"StackQue.h"

int main() {
	SqStack S;
	SqQueue Q;
	ShareStack M;
	ElemType x;
	int len;

	InitStack(S);
	InitQueue(Q);

	cin >> x;
	while (x != 9999) {
		if (InQueue(Q, x)) cin >> x;
		else break;
	}
	PrintQueue(Q);
	QueueTbyStack(Q, S);
	PrintQueue(Q);
	StackPrint(S);
}