#include"myhead.h"

int main() {
	SqL L1;
	bool S;
	int l = -1, x;
	cout << "��ʼ��˳���L1:" << endl;
	InitList(L1);
	//cout << "��ʼ��˳���L2:" << endl;
	//InitList(L2);
	//Print(L1); Print(L2);
	//Reni(L)
	cout << "��������Ҫ���ҵ�ֵ ��";
	cin >> x;
	//DeletSameX(L,x);
	l = FindxHalf(L1,x);
	if (l != -1) cout << "��Ҫ���ҵ�ֵ��λ��Ϊ��"<< l;
	else cout << "˳���Ϊ��" << endl;
	//L3 = Order2SqL(L1, L2);


	//Print(L1);
}