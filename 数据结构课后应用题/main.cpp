#include"Link.h"

int main() {
	ElemType x;
	LinkList L;
	LNode* q;
	LInitList(L);
	q = TailInsertList(L);
	//ReniPrint(L);
	//cout << endl<< "请输入想要删除的值：" << endl;
	//cin >> x;
	//LDeletXn(L, x);

	//LDeletMin(L);

	ReniList(L, *q);
	LPrint(L);
}