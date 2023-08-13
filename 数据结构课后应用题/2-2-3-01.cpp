#include"myhead.h"

int main() {
	SqL L;
	int e;
	InitList(L);
	DeletX(L, e);
	cout << "要删除的最小值为:" << e << endl;
	Print(L);
	return 0;
}