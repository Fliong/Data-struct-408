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
	char op;
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

	cout << endl << "是否建立为循环单链表(y/n):";
	cin >> op;
	switch (op) {
	case 'y': p->next = L; break;
	case 'n': p->next = NULL; break;
	default: p->next = NULL;
	}

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
		if (p == L) break;  //如果为循环链表的话，防止死循环
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
	int len = 0;
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
			if (q->next == L) break;   //防止循环链表死循环
			q = q->next;
		}
		if (p->next == q) break;     //同上
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

/*09递增输出链表值，并释放对应的空间（带头结点）*/
bool Print2Free(LinkList& head) {
	if (head == NULL) return false;
	LNode* pre, * q;
	bool stence;      //定义bool 的变量用来接收 UpList 处理链表返回的结果（true/false）
	stence = UpList(head);
	if (stence) {     
		pre = head->next;   //结构体指针指向处理后链表的第一个数据节点
		cout << "链表递增输出为：";
		while (pre != NULL) {
			cout << pre->data << " ";   //依次打印增序链表的值
			q = pre;                  //将释放的节点用q 指向
			head->next = pre->next;    //链表头指针跳过第一个元素，指向下一个元素
			pre = pre->next;          //pre 后移
			if (pre == head) {        //防止指针冲突
				free(pre);           //释放头结点
				break;         //跳出循环，防止死循环
			}
			free(q);
		}
		cout << endl;
		return true;
	}
	return false;
}

/*10 将链表中的奇偶数分成A(奇数) B(偶数) 两个链表*/
LinkList DecomposeOE(LinkList& A) {
	LNode* pA_1, *pA_0, * pB_1; //初始化结构体指针 pA_1,  pB_1,  qA_1（指向即将释放的节点）
	if (A == NULL) return NULL;
	LinkList B = (LinkList)malloc(sizeof(LNode));   //申请偶数头结点B
	//C++里也可以用 LinkList B = new LNode;
	if (B == NULL) return NULL;
	B->next = NULL;
	
	pA_0 = A; pA_1 = A->next; pB_1 = B;
	while (pA_1 != NULL) {
		if (pA_1->data % 2 == 0) {   //判断奇偶性，若为偶数
			pB_1->next = pA_1;        //pB_1的next指向该节点
			pA_0->next = pA_1->next;   //而链表A中的pA_1指向的前一个节点指向其后节点
			pB_1 = pB_1->next;      //pB_1指针后移
		}
		else {
			pA_0 = pA_1;      //如果不为偶数，pA_0 后移，pA_0 一直为 pA_1 的前节点
		}
		pA_1 = pA_1->next;    //pA_1 后移
	}
	pB_1->next = NULL;   //此时pB_1指向链为 赋值为 NULL
	return B;
}

/*12增序链表中删除相同元素(带头结点)*/
bool LDeletSameX(LinkList& L) {
	if (L == NULL) return false;
	LNode* pre, * p, * q = NULL;
	pre = L->next;  //因带头结点，pre 指向链表的第一个元素

	while (pre->next != NULL) {    //外层循环
		p = pre->next;     //pre 是 p 的前驱
		while (pre->data == p->data) {   //如果pre 和 p 指向的元素相等
			q = p;               //q 指向将要释放的元素
			pre->next = p->next;     //pre 指针跳过 p 指向 p 的下一个元素
			p = p->next;         //p 指针后移
			free(q);      //释放q
		}
		pre = pre->next;
	}
	return true;
}

/*13两个增序单链表，合并为递减单链表*/
LinkList TwoUpL2OneDown(LinkList& L1, LinkList& L2) {
	LNode* p = L1;
	bool s1, s2;
	while ( p->next != NULL) {     //利用循环令 p 指向 L1 最后一个节点
		p = p->next; 
	}
	p->next = L2->next;   //让最后一个节点的指针域指向 L2 的第一个元素域，即将 L1 和 L2 串起来
	free(L2);    //释放L2 的头结点
	s1 = UpList(L1);   //重新增序排列 L1
	s2 = ReniList_2(L1);   //链表逆置
	if (s1 && s2) return L1;
	else return NULL;
}

/*14创建一个新链表，包含两个链表的共同元素*/
LinkList TwoLSameX2newlist(LinkList& L1, LinkList& L2) {
	if (L1 == NULL || L2 == NULL) return NULL;
	LinkList C = new LNode; C->next = NULL;    //新链表的头结点
	LNode* pL1 = L1->next;   //初始化，pL1指向 链表 L1 的第一个数据元素
	LNode* pL2 = L2->next;          //pL2指向 链表 L2 的第一个数据元素
	LNode* pC = C;        //pC 指向 新链表的头结点

	while ((pL1 != NULL) && (pL2 != NULL)) {     //跳出循环的条件
		if (pL1->data > pL2->data) pL2 = pL2->next;    // 对比 pL1 和 pL2 的值，pL1 大，则 pL2 后移
		else if (pL1->data < pL2->data) pL1 = pL1->next;  //若 pL2 大 ，则 pL1 后移
		else {                                    // 若两个值相等
			LinkList add = new LNode;        //创建新节点
			add->data = pL1->data;           //将两个链表相等的值 赋值给 新节点的数据域 
			add->next = NULL;             //新节点的指针域为 NULL
			pC->next = add;              //将新节点 连接上 新链表的头结点
			pC = pC->next;               //指针 pC 一直指向 新链表的最后

			pL2 = pL2->next;            //pL1、pL2 都进行后移
			pL1 = pL1->next;
		}
	}
	return C;         //返回新链表的头结点
}

/*18将两个循环单链表合并为一个循环单链表*/
bool TwoCycleConnect(LinkList& h1,LNode* p1, LinkList& h2, LNode* p2) {
	if (h1 == NULL || h2 == NULL) return false;
	
	if (abs(h2->data) >= 9999) p1->next = h2->next;   //判断是否含有头结点
	else p1->next = h2;
	p2->next = h1;

	return true;
}