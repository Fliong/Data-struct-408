/*���Ա�������ʾ������㷨����ʵ��*/
#include"Link.h"

/*��ʼ��һ����㣬����һ�����*/
bool LInitList(LinkList& L) {
	char op;
	cout << "�Ƿ񴴽���ͷ���ĵ�����y/n��:";
	cin >> op;
	switch (op)
	{
	case 'y':
		L = (LinkList)malloc(sizeof(LNode));
		if (L == NULL) {
			cout << "����ͷ���ʧ�ܣ�" << endl;
			return false;
		}
		cout << "����ͷ���ɹ���" << endl;
		L->next = NULL;
		return true;
	case 'n':
		L = NULL;     //��ֹ������Ⱦ����ʼ��ΪNULL
		cout << "����������ɹ���" << endl;
		return true;
	default:
		break;
	}
	return true;
}

/*��ͷ���β�巨*/
LNode* TailInsertList(LinkList& L) {
	
	int x, i=2;
	cout << "����������ֵNo.1��" ;
	cin >> x;
	if (L == NULL) {
		LinkList t = (LinkList)malloc(sizeof(LNode));
		if (t == NULL) exit(0);
		t->data = x;
		t->next = NULL;
		L = t;
		cout << "����������ֵNo." << i++ << "��";
		cin >> x;
	}
	LinkList p = L;    //��ʼpָ������ͷ
	while (x != 9999) {
		LinkList s = (LinkList)malloc(sizeof(LNode));  //����һ���ڵ�
		if (s == NULL) exit(0);   //�������ʧ���˳�
		s->data = x;       //��xֵ����������ڵ��������
		s->next = NULL;
		p->next = s;      //���½ڵ�����������
		p = s;          //ָ��p��ָ�������ڵ�
		cout << "����������ֵNo." << i << "��";
		cin >> x;
		i++;
	}
	p->next = NULL;
	return p;
}

/*��ӡ����*/
bool LPrint(LinkList& L) {
	if (L == NULL) return false;
	LNode* p = L;
	cout << "������Ϊ��";
	while (p != NULL) {
	    if(abs(p->data)<9999) cout << p->data<<"  "; //�����ͷ��㣬����ӡͷ����ֵ
		p=p->next;
	}
	cout << endl;
	return true;
}
/*03�����ӡ����*/
bool ReniPrint(LinkList& L) {
	if (L->next != NULL) {
		ReniPrint(L->next);
		
	}
	if(L->data>0 && L->data<9999) cout << L->data << " ";
	return true;
}

/*ͳ��������*/
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


/*01,02�ݹ�ɾ�����������x��ֵ*/
bool LDeletXn(LinkList& L, ElemType x) {
	if (L == NULL) return false;
	LinkList p;
	if (L->data == x) {
		p = L;
		L = L->next;   //ͷ���Lһֱ����
		free(p);
		LDeletXn(L, x);
	}
	else {
		LDeletXn(L->next, x);
	}
	return true;
}

/*04ɾ����������Сֵ*/
bool LDeletMin(LinkList& L) {
	if (L == NULL) return false;
	LNode* p = L, * q = L->next;  //��ʼ��p,qָ�룬ָ����n ��n+1;
	while (q != NULL) {
		if (abs(p->data) > q->data) {
			p = q;
		}
		q = q->next;
	}
	LDeletXn(L, p->data);
	return true;
}

/*05��ͷ���͵�����*/
bool ReniList_1(LinkList& L) {
	if (L == NULL) return false;
	LNode* pre = L->next, * mid, * r;   //pre,mid,rΪ�������ڵĽڵ㣬��ʼΪ�ڵ�1��2��3
	mid = pre->next;
	r = mid->next;
	pre->next = NULL;  //����ǵ�һ�����ݽڵ㣬���øýڵ��nextָ��NULL
	while (r!=NULL) {
		mid->next = pre;      //mid��nextָ��ָ��pre,���������ڽڵ�ָ������
		pre = mid;
		mid = r;              //pre,mid,r����ָ�����
		r = r->next;
	}
	 mid->next = pre;    //ѭ������ʱ�� mid �� next ָ�� pre
	L->next = mid;      //ͷ���ָ�� r
	return true;
}

/*ͷ�巨*/
bool ReniList_2(LinkList& L) {
	if (L == NULL) return false;
	LNode *p = L->next, *r;
	L->next = NULL;
	while (p != NULL) {
		r = p->next;
		p->next = L->next;    //ÿһ�� p �ڵ�ʼ�ս��� L ��ͷָ��֮�󣩣�����ԭ���ڶ���λ��
		L->next = p;
		p = r;
	}
	return true;
}

/*06������������*/
bool UpList(LinkList& L) {
	if (L == NULL) return false;
	LNode* p = L->next, *q;
	ElemType data;   //�����ݴ潻��������
	//temp = p->next;
	while (p != NULL) {
		q = p->next;   //q ָ�� p ��һ������
		while (q != NULL) {
			if (p->data > q->data) {  //��� p (ǰ��)���� q ���ߣ��򽻻�
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

/*07ɾ��������Χ�ڵ�ֵ*/
bool DeletRangeList(LinkList& L, ElemType min, ElemType max){
	if ((L == NULL) && (min > max)) return false;
	LNode *pre = L, *p=NULL, *q; //pre p ���ڣ�q ����ָ��ɾ����ֵ
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

/*08Ѱ����������Ĺ����ڵ�*/
LinkList FindSameNode(LinkList& L1, LinkList& L2) {
	int dist;
	int len1, len2;
	LinkList longlist, shortlist;  //����ṹ��ָ�룬һ��ָ�򳤣�һ��ָ���
	len1 = Length(L1);   //��ȡ������
	len2 = Length(L2);
	if (len1 > len2) { longlist = L1; shortlist = L2;}
	else { longlist = L2; shortlist = L1; }
	dist = abs(len1 - len2);   //�õ�������������ĳ��Ȳ�
	
	while (dist--) {      //��������������Ľڵ㣬Ϊ����ͬ����׼��
		longlist = longlist->next;
	}

	while (longlist != NULL) {
		if (longlist->next == shortlist->next) {   //�ж��Ƿ�Ϊͬ�ڵ�
			return shortlist;
		}
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return NULL;   //��������û���ҵ���ͬ�ڵ㣬 ���� NULL ֵ
}

/*09�����������ֵ�����ͷŶ�Ӧ�Ŀռ䣨��ͷ��㣩*/
bool Print2Free(LinkList& head) {
	if (head == NULL) return false;
	LNode* pre, * q;
	bool stence;      //����bool �ı����������� UpList ���������صĽ����true/false��
	stence = UpList(head);
	if (stence) {     
		pre = head->next;   //�ṹ��ָ��ָ���������ĵ�һ�����ݽڵ�
		cout << "����������Ϊ��";
		while (pre != NULL) {
			cout << pre->data << " ";   //���δ�ӡ���������ֵ
			q = pre;                  //���ͷŵĽڵ���q ָ��
			head->next = pre->next;    //����ͷָ��������һ��Ԫ�أ�ָ����һ��Ԫ��
			pre = pre->next;          //pre ����
			free(q);
		}
		cout << endl;
		return true;
	}
	return false;
}

/*10 �������е���ż���ֳ�A(����) B(ż��) ��������*/
LinkList DecomposeOE(LinkList& A) {
	LNode* pA_1, *pA_0, * pB_1, * qA_1; //��ʼ���ṹ��ָ�� pA_1,  pB_1,  qA_1��ָ�򼴽��ͷŵĽڵ㣩
	if (A == NULL) return NULL;
	LinkList B = (LinkList)malloc(sizeof(LNode));   //����ż��ͷ���B
	//C++��Ҳ������ LinkList B = new LNode;
	if (B == NULL) return NULL;
	B->next = NULL;
	
	pA_0 = A; pA_1 = A->next; pB_1 = B;
	while (pA_1 != NULL) {
		if (pA_1->data % 2 == 0) {   //�ж���ż�ԣ���Ϊż��
			pB_1->next = pA_1;        //pB_1��nextָ��ýڵ�
			pA_0->next = pA_1->next;   //������A�е�pA_1ָ���ǰһ���ڵ�ָ�����ڵ�
			pB_1 = pB_1->next;      //pB_1ָ�����
		}
		else {
			pA_0 = pA_1;      //�����Ϊż����pA_0 ���ƣ�pA_0 һֱΪ pA_1 ��ǰ�ڵ�
		}
		pA_1 = pA_1->next;    //pA_1 ����
	}
	pB_1->next = NULL;   //��ʱpB_1ָ����Ϊ ��ֵΪ NULL
	return B;
}

/*12����������ɾ����ͬԪ��(��ͷ���)*/
bool LDeletSameX(LinkList& L) {
	if (L == NULL) return false;
	LNode* pre, * p, * q = NULL;
	pre = L->next;  //���ͷ��㣬pre ָ������ĵ�һ��Ԫ��

	while (pre->next != NULL) {    //���ѭ��
		p = pre->next;     //pre �� p ��ǰ��
		while (pre->data == p->data) {   //���pre �� p ָ���Ԫ�����
			q = p;               //q ָ��Ҫ�ͷŵ�Ԫ��
			pre->next = p->next;     //pre ָ������ p ָ�� p ����һ��Ԫ��
			p = p->next;         //p ָ�����
			free(q);      //�ͷ�q
		}
		pre = pre->next;
	}

}

/*13�������������ϲ�Ϊ�ݼ�������*/
LinkList TwoUpL2OneDown(LinkList& L1, LinkList& L2) {
	LNode* p = L1;
	bool s1, s2;
	while ( p->next != NULL) {     //����ѭ���� p ָ�� L1 ���һ���ڵ�
		p = p->next; 
	}
	p->next = L2->next;   //�����һ���ڵ��ָ����ָ�� L2 �ĵ�һ��Ԫ���򣬼��� L1 �� L2 ������
	free(L2);    //�ͷ�L2 ��ͷ���
	s1 = UpList(L1);   //������������ L1
	s2 = ReniList_2(L1);   //��������
	if (s1 && s2) return L1;
	else return NULL;
}