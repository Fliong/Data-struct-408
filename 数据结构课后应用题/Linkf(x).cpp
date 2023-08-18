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