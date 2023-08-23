#include"Link.h"

int main() {
	ElemType x;
	LinkList L;
	LNode* q;
	LInitList(L);
	q = TailInsertList(L);
	//ReniPrint(L);
	//cout << endl<< "请输入想要删除的值："<<q->data << endl;
	//cout << L->next->data << endl;
	//cin >> x;
	//LDeletXn(L, x);

	//LDeletMin(L);

	//ReniList_1(L);

	//UpList(L);

	//DeletRangeList(L, 2, 5);

	//
	LPrint(L);
}