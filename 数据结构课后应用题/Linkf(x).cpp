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
	int len;
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