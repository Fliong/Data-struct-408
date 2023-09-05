#include"StackQue.h"

/*栈的初始化*/
void InitStack(SqStack& S) {
	S.top = -1;
}

/*栈的判空*/
bool StackEmpty(SqStack& S) {
	return (S.top == -1) ? true : false;
}

/*入栈*/
bool PushStack(SqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1) return false;
	S.data[++S.top] = x;
	return true;
}

/*出栈*/
bool PopStack(SqStack& S, ElemType& x) {
	if (!StackEmpty(S)) {
		x = S.data[S.top--];
		return true;
	}
	return false;
}

/*扫描栈内元素*/
void StackPrint(SqStack& S) {
	int len=0 ;
	cout << "该栈内元素为（栈低 --> 栈顶）： ";
	while (len <= S.top) {
		cout << S.data[len++] << " ";
	}
	cout << endl;
}

/*连续入栈*/
void ContinePush(SqStack& S) {
	ElemType x;
	cout << "请输入栈元素" << endl;
	while (S.top != MAXSIZE - 1) {
		cin >> x;
		if (x != 9999) S.data[++S.top] = x;
		else break;
	}
	StackPrint(S);
}

/*连续出栈*/
void ContinePop(SqStack& S, int len) {
	char op;
	ElemType x;
	if (StackEmpty(S)) {
		cout << "该栈为空栈" << endl;
		exit(0);
	}
	if ((len - 1) > S.top) {
		cout << "请求出栈元素个数大于实际栈内元素..." << endl;
		cout << "是否继续执行，继续执行则将栈清空，否则重新输入请求数（y/n）:";
		cin >> op;
		switch (op)
		{
		case 'y': 
			for (int i = S.top; i >= 0 ; i--) {
				PopStack(S, x);
				cout << x << " ";
			}
			cout << endl;
			break;
		case 'n':
			cin >> len;
			ContinePop(S, len);
			break;
		default:
			break;
		}
	}
	else {
		for (int i = len; i >0 ; i--) {
			PopStack(S, x);
			cout << x << " ";
		}
		cout << endl;
	}
}