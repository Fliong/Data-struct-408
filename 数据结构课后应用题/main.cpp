#include"Link.h"

int main() {
	int x;
	LinkList L;
	LInitList(L);
	TailInsertList(L);
	LPrint(L);
	cout << "��������Ҫɾ����ֵ��" << endl;
	cin >> x;
	LDeletX(L, x);
	LPrint(L);
}