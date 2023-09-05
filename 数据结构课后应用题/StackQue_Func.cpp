#include"StackQue.h"

/*ջ�ĳ�ʼ��*/
void InitStack(SqStack& S) {
	S.top = -1;
}

/*ջ���п�*/
bool StackEmpty(SqStack& S) {
	return (S.top == -1) ? true : false;
}

/*��ջ*/
bool PushStack(SqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1) return false;
	S.data[++S.top] = x;
	return true;
}

/*��ջ*/
bool PopStack(SqStack& S, ElemType& x) {
	if (!StackEmpty(S)) {
		x = S.data[S.top--];
		return true;
	}
	return false;
}

/*ɨ��ջ��Ԫ��*/
void StackPrint(SqStack& S) {
	int len=0 ;
	cout << "��ջ��Ԫ��Ϊ��ջ�� --> ջ������ ";
	while (len <= S.top) {
		cout << S.data[len++] << " ";
	}
	cout << endl;
}

/*������ջ*/
void ContinePush(SqStack& S) {
	ElemType x;
	cout << "������ջԪ��" << endl;
	while (S.top != MAXSIZE - 1) {
		cin >> x;
		if (x != 9999) S.data[++S.top] = x;
		else break;
	}
	StackPrint(S);
}

/*������ջ*/
void ContinePop(SqStack& S, int len) {
	char op;
	ElemType x;
	if (StackEmpty(S)) {
		cout << "��ջΪ��ջ" << endl;
		exit(0);
	}
	if ((len - 1) > S.top) {
		cout << "�����ջԪ�ظ�������ʵ��ջ��Ԫ��..." << endl;
		cout << "�Ƿ����ִ�У�����ִ����ջ��գ���������������������y/n��:";
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