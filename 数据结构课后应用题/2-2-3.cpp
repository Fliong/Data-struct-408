#include"myhead.h"

int main() {
	SqL L1;
	bool S;
	int l = -1, x;
	cout << "初始化顺序表L1:" << endl;
	InitList(L1);
	//cout << "初始化顺序表L2:" << endl;
	//InitList(L2);
	//Print(L1); Print(L2);
	//Reni(L)
	cout << "请输入你要查找的值 ：";
	cin >> x;
	//DeletSameX(L,x);
	l = FindxHalf(L1,x);
	if (l != -1) cout << "你要查找的值的位置为："<< l;
	else cout << "顺序表为空" << endl;
	//L3 = Order2SqL(L1, L2);


	//Print(L1);
}