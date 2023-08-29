#include"Link.h"

int main() {
	ElemType x;
	LinkList L, B, N;
	LNode* q, *s;

	LInitList(L);
	q = TailInsertList(L);

	//LInitList(B);
	//s = TailInsertList(B);

	LPrint(L);
	//LPrint(B);

	//ReniPrint(L);
	//cout << endl<< "请输入想要删除的值："<<q->data << endl;
	//cout << L->next->data << endl;
	//cin >> x;
	//LDeletXn(L, x);

	//LDeletMin(L);

	//ReniList_1(L);

	//UpList(L);

	//DeletRangeList(L, 2, 5);

	Print2Free(L);
	//B = DecomposeOE(L);

	//LDeletSameX(L);
	//TwoCycleConnect(L,q, B,s);
	LPrint(L);
	//LPrint(B);
}