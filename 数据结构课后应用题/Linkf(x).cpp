/*线性表的链表表示，相关算法具体实现*/
#include"Link.h"

/*初始化一个结点，建立一个结点*/
bool LInitList(LinkList& L) {
	char op;
	cout << "是否创建带头结点的单链表（y/n）:";
	cin >> op;
	switch (op)
	{
	case 'y':
		L = (LinkList)malloc(sizeof(LNode));
		if (L == NULL) {
			cout << "创建头结点失败！" << endl;
			return false;
		}
		cout << "创建头结点成功！" << endl;
		L->next = NULL;
		return true;
	case 'n':
		L = NULL;     //防止数据污染，初始化为NULL
		cout << "创建单链表成功！" << endl;
		return true;
	default:
		break;
	}
}

/*带头结点尾插法*/
bool TailInsertList(LinkList& L) {
	if (L == NULL) return false;
	LinkList p = L;
	int x, i=2;
	cout << "请输入链表值No.1：" ;
	cin >> x;
	while (x != 9999) {
		LinkList s = (LinkList)malloc(sizeof(LNode));
		if (s == NULL) return false;
		s->data = x;
		s->next = NULL;
		p->next = s;
		p = s;
		cout << "请输入链表值No." << i << "：";
		cin >> x;
		i++;
	}
	p->next = NULL;
	return true;
}

/*打印链表*/
bool LPrint(LinkList& L) {
	if (L == NULL) return false;
	LNode* p = L;
	cout << "该链表为：";
	while (p->next != NULL) {
		cout << p->next->data<<"  ";
		p=p->next;
	}
	return true;
}

/*01 递归删除不带头节点链表中x的值*/
bool LDeletX(LNode& L) {
	return false;
}