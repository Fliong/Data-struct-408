#include"Link.h"

int main() {
	ElemType x;
	LinkList L;
	LNode* q;
	LInitList(L);
	q = TailInsertList(L);
	//ReniPrint(L);
	//cout << endl<< "��������Ҫɾ����ֵ��" << endl;
	//cin >> x;
	//LDeletXn(L, x);

	//LDeletMin(L);

	ReniList(L, *q);
	LPrint(L);
}