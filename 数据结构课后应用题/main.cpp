#include"Link.h"

int main() {
	int x;
	LinkList L;
	LInitList(L);
	TailInsertList(L);
	LPrint(L);
	cout << "请输入想要删除的值：" << endl;
	cin >> x;
	LDeletX(L, x);
	LPrint(L);
}