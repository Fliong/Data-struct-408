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

/*统计链表长度*/
int Length(LinkList& L) {
	int len;
	LNode* p = L;
	if (abs(L->data) > 9999) p = p->next;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	return len;
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
bool ReniList_1(LinkList& L) {
	if (L == NULL) return false;
	LNode* pre = L->next, * mid, * r;   //pre,mid,r为三个相邻的节点，初始为节点1，2，3
	mid = pre->next;
	r = mid->next;
	pre->next = NULL;  //如果是第一个数据节点，则让该节点的next指向NULL
	while (r!=NULL) {
		mid->next = pre;      //mid的next指针指向pre,即两个相邻节点指针逆置
		pre = mid;
		mid = r;              //pre,mid,r三个指针后移
		r = r->next;
	}
	 mid->next = pre;    //循环结束时让 mid 的 next 指向 pre
	L->next = mid;      //头结点指向 r
	return true;
}

/*头插法*/
bool ReniList_2(LinkList& L) {
	if (L == NULL) return false;
	LNode *p = L->next, *r;
	L->next = NULL;
	while (p != NULL) {
		r = p->next;
		p->next = L->next;    //每一个 p 节点始终紧随 L （头指针之后），代替原本第二的位置
		L->next = p;
		p = r;
	}
	return true;
}

/*06递增排序链表*/
bool UpList(LinkList& L) {
	if (L == NULL) return false;
	LNode* p = L->next, *q;
	ElemType data;   //用于暂存交换的数据
	//temp = p->next;
	while (p != NULL) {
		q = p->next;   //q 指向 p 下一个数据
		while (q != NULL) {
			if (p->data > q->data) {  //如果 p (前者)大于 q 后者，则交换
				data = p->data;
				p->data = q->data;
				q->data = data;
			}
			q = q->next;
		}
		p = p->next;
	}
	return true;
}

/*07删除给定范围内的值*/
bool DeletRangeList(LinkList& L, ElemType min, ElemType max){
	if ((L == NULL) && (min > max)) return false;
	LNode *pre = L, *p=NULL, *q; //pre p 相邻，q 用来指向删除的值
	p = pre->next;
	while (p != NULL) {
		if ((p->data >= min) && (p->data <= max)) {
			pre->next = p->next;
			q = p;
			p = p->next;
			free(q);
		}
		else {
			pre = p;
			p = p->next;
		}
	}
	return false;
}

/*08寻找两个链表的公共节点*/
LinkList FindSameNode(LinkList& L1, LinkList& L2) {
	int dist;
	int len1, len2;
	LinkList longlist, shortlist;  //定义结构体指针，一个指向长，一个指向短
	len1 = Length(L1);   //获取链表长度
	len2 = Length(L2);
	if (len1 > len2) { longlist = L1; shortlist = L2;}
	else { longlist = L2; shortlist = L1; }
	dist = abs(len1 - len2);   //得到两个两个链表的长度差
	
	while (dist--) {      //长链表，遍历多出的节点，为后续同步做准备
		longlist = longlist->next;
	}

	while (longlist != NULL) {
		if (longlist->next == shortlist->next) {   //判断是否为同节点
			return shortlist;
		}
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return NULL;   //如果到最后没有找到共同节点， 返回 NULL 值
}