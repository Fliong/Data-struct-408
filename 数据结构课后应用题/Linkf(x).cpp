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
}

/*��ͷ���β�巨*/
bool TailInsertList(LinkList& L) {
	if (L == NULL) return false;
	LinkList p = L;
	int x, i=2;
	cout << "����������ֵNo.1��" ;
	cin >> x;
	while (x != 9999) {
		LinkList s = (LinkList)malloc(sizeof(LNode));
		if (s == NULL) return false;
		s->data = x;
		s->next = NULL;
		p->next = s;
		p = s;
		cout << "����������ֵNo." << i << "��";
		cin >> x;
		i++;
	}
	p->next = NULL;
	return true;
}

/*��ӡ����*/
bool LPrint(LinkList& L) {
	if (L == NULL) return false;
	LNode* p = L;
	cout << "������Ϊ��";
	while (p->next != NULL) {
		cout << p->next->data<<"  ";
		p=p->next;
	}
	return true;
}

/*01 �ݹ�ɾ������ͷ�ڵ�������x��ֵ*/
bool LDeletX(LNode& L) {
	return false;
}