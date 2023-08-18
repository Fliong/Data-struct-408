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
	return true;
}

/*带头结点尾插法*/
LNode* TailInsertList(LinkList& L) {
	
	int x, i=2;
	cout << "请输入链表值No.1：" ;
	cin >> x;
	if (L == NULL) {
		LinkList t = (LinkList)malloc(sizeof(LNode));
		if (t == NULL) exit(0);
		t->data = x;
		t->next = NULL;
		L = t;
		cout << "请输入链表值No." << i++ << "：";
		cin >> x;
	}
	LinkList p = L;    //初始p指向链表头
	while (x != 9999) {
		LinkList s = (LinkList)malloc(sizeof(LNode));  //申请一个节点
		if (s == NULL) exit(0);   //如果申请失败退出
		s->data = x;       //将x值赋给新申请节点的数据域
		s->next = NULL;
		p->next = s;      //将新节点连接至链表
		p = s;          //指针p，指向新增节点
		cout << "请输入链表值No." << i << "：";
		cin >> x;
		i++;
	}
	p->next = NULL;
	return p;
}

/*打印链表*/
bool LPrint(LinkList& L) {
	if (L == NULL) return false;
	LNode* p = L;
	cout << "该链表为：";
	while (p != NULL) {
	    if(abs(p->data)<9999) cout << p->data<<"  "; //如果有头结点，不打印头结点的值
		p=p->next;
	}
	cout << endl;
	return true;
}
/*03反向打印链表*/
bool ReniPrint(LinkList& L) {
	if (L->next != NULL) {
		ReniPrint(L->next);
		
	}
	if(L->data>0 && L->data<9999) cout << L->data << " ";
	return true;
}


/*01,02递归删除结点链表中x的值*/
bool LDeletXn(LinkList& L, ElemType x) {
	if (L == NULL) return false;
	LinkList p;
	if (L->data == x) {
		p = L;
		L = L->next;   //头结点L一直不变
		free(p);
		LDeletXn(L, x);
	}
	else {
		LDeletXn(L->next, x);
	}
	return true;
}

/*04删除链表中最小值*/
bool LDeletMin(LinkList& L) {
	if (L == NULL) return false;
	LNode* p = L, * q = L->next;  //初始化p,q指针，指向最n 和n+1;
	while (q != NULL) {
		if (abs(p->data) > q->data) {
			p = q;
		}
		q = q->next;
	}
	LDeletXn(L, p->data);
	return true;
}

/*05带头结点就地逆置*/
bool ReniList(LinkList& L,LNode& p) {
	LNode* q = L;
	ElemType temp;
	while (q->data != p.data) {
		temp = q->data;
		q->data = p.data;
		p.data = temp;
		
	}
	return true;
}