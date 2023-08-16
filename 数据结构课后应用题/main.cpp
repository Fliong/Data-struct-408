#include"Link.h"

int main() {
	LinkList L;
	LInitList(L);
	TailInsertList(L);
	LPrint(L);
	cout << endl << L->next->data;
}