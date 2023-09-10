#include"StackQue.h"

//*************************************
/*ջ�ĳ�ʼ��*/
void InitStack(SqStack& S) {
	S.top = -1;
}

/*ջ���п�*/
bool StackEmpty(SqStack& S) {
	return (S.top == -1) ? true : false;
}

/*��ջ*/
bool PushStack(SqStack& S, ElemType x) {
	if (S.top == MAXSIZE - 1) return false;
	S.data[++S.top] = x;
	return true;
}

/*��ջ*/
bool PopStack(SqStack& S, ElemType& x) {
	if (!StackEmpty(S)) {
		x = S.data[S.top--];
		return true;
	}
	return false;
}

/*ɨ��ջ��Ԫ��*/
void StackPrint(SqStack& S) {
	int len=0 ;
	cout << "��ջ��Ԫ��Ϊ��ջ�� --> ջ������ ";
	while (len <= S.top) {
		cout << S.data[len++] << " ";
	}
	cout << endl;
}

/*��ȡջ��Ԫ��*/
ElemType ReadTop(SqStack& S) {
	if (StackEmpty(S)) exit(0);
	return S.data[S.top];
}

/*������ջ*/
void ContinePush(SqStack& S) {
	ElemType x;
	cout << "������ջԪ��" << endl;
	while (S.top != MAXSIZE - 1) {
		cin >> x;
		if (x != 9999) S.data[++S.top] = x;
		else break;
	}
	StackPrint(S);
}

/*������ջ*/
void ContinePop(SqStack& S, int len) {
	char op;
	int lenS = S.top;
	ElemType x;       //����һ����������ӡ��ջԪ��
	if (StackEmpty(S)) {    //�ж�ջ�Ƿ�Ϊ��
		cout << "��ջΪ��ջ" << endl;
		exit(0);
	}
	if ((len - 1) > S.top) {   //ջ��Ϊ�գ����ж������ջԪ�����Ƿ�Ϸ�
		cout << "�����ջԪ�ظ�������ʵ��ջ��Ԫ�أ�ջ���� "<< lenS + 1 <<"��Ԫ��..." << endl;
		cout << "�Ƿ����ִ�У�����ִ����ջ��գ���������������������y/n��:";   //���Ϸ�ѡ����һ������
		cin >> op;
		switch (op)
		{
		case 'y':    //�ڲ��Ϸ��������£�y: ������ջ�����������ջ
			for (int i = S.top; i >= 0 ; i--) {
				PopStack(S, x);
				cout << x << " ";
			}
			cout << endl;
			break;
		case 'n':     //ѡ�� n: ���������ջ��Ԫ�ظ���
			cout << "���������ջ��Ԫ�ظ�����";
			cin >> len;
			ContinePop(S, len);
			break;
		default:
			break;
		}
	}
	else {
		for (int i = len; i >0 ; i--) {  //����Ϸ���������ջ
			PopStack(S, x);
			cout << x << " ";
		}
		cout << endl;
	}
}

/*����ջ*/
bool ShareStackOp(ShareStack& Shs) {
	Shs.top_1 = 0;
	Shs.top_2 = MAXSIZE - 1;
	int StackNo = 0; // ʹ�ü���ջ��0��1
	int top1;
	ElemType x;

	while (Shs.top_2 >= Shs.top_1) {   //ջ���ж�
		cout << "**��������ֵȡ����ջ**ѡ��ջ��0/1��:";
		cin >> StackNo;
		cout << "[" << StackNo << "]Stack" << "��������ջԪ��:" << endl;
		
		if (StackNo == 0) {
			while (Shs.top_2 >= Shs.top_1) {
				top1 = Shs.top_1;
				cout << "0ջ��ջλ��" << top1+1 << ":";
				cin >> x;
				if (x != 9999) Shs.data[Shs.top_1++] = x; 
				else break;
			}
		}
		else if (StackNo == 1) {
			while (Shs.top_2 >= Shs.top_1) {
				cout << "1ջ��ջλ��" << MAXSIZE-Shs.top_2 << ":";
				cin >> x;
				if (x != 9999) Shs.data[Shs.top_2--] = x;
				else break;
			}
		}
		else break;           //��ѡ��0��1�����ջ�����˳�
	}

	cout << "ջ������" << endl;

	cout << "��ջ�����" << endl;
	//0��ջ
	cout << "0��ջ���ݣ�ջ��-->ջ����:";
	for (int i = 0; i <= Shs.top_1-1; i++) {
		cout << Shs.data[i] << " ";
	}
	cout << endl;

	//1��ջ
	cout << "1��ջ���ݣ�ջ��-->ջ����:";
	for (int i=MAXSIZE-1; i > Shs.top_2; i--) {
		cout << Shs.data[i] << " ";
	}
	cout << endl;
	return true;
}

/*����ջ�����Ƿ�Ϸ��ж�*/
bool IOStackLegality(char Arryop[]) {
	char push = 'I', pop = 'O';  //���ò���
	int lenA = sizeof(Arryop), i = 0;  //��ȡ���鳤�� �ͱ�����λ
	int temp = 0;   //��ʼ������Ϊ0��ÿ����ջ +1�� ��ջ -1

	while (i<lenA) {     //�������������
		if (Arryop[i] == push) {
			temp++;
		}
		else {
			if (temp > 0) temp--;
			else return false;          //�ų�bug1 : ���� n �γ�ջ�������� n ����ջ ��temp=0
		}
		i++;
	}
	
	if (temp == 0)  cout << "�������Ϸ�";
	else cout << "�������Ƿ�";
	return (temp == 0) ? true : false;   //����temp��ֵ�жϲ����Ƿ�Ϸ�
}

/*�Ƿ�Ϊ���ĶԳ��ַ�*/
bool CentralSym(LinkStack& L) {

	LinkStack p = L;
	char s[MAXSIZE];
	int i = 0, j = 0, temp;

	while (p != NULL) {
		if (i > MAXSIZE - 1) break;
		s[i++] = p->data;
		p = p->next;
	}
	i--;

	temp = i % 2;
	while (j != temp+1) {
		if (s[j] == s[i]) { j++; i--; }
		else return false;
	}

	return true;    
}

//***************************
/*����*/

/*���г�ʼ��*/
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.tag = 0;
}

/*ɨ�����*/
void PrintQueue(SqQueue& Q) {
	int p1 = Q.front, p2 = Q.rear, temp=Q.tag;
	cout << "�ö���Ԫ�أ���β-->��ͷ��:";
	while (p1!= p2 || temp==1) {
		if (p2 - 1==0 && temp == 1) p2 = MAXSIZE - 1;
		cout << Q.data[--p2]<<" ";
		temp = 0;
	}
	cout << endl;
}

/*Page 082_01   ���*/
bool InQueue(SqQueue& Q, ElemType x) {
	if (Q.front == Q.rear && Q.tag == 1) return false;  //��������
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.tag = 1;
	return true;
}

/*Page 082_01   ����*/
bool OutQueue(SqQueue& Q, ElemType& x) {
	if (Q.front == Q.rear && Q.tag == 0) return false;   //����Ϊ��
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.tag = 0;
	return true;
}


/*Page 082_02   ����ջ������Ԫ������*/
bool QueueTbyStack(SqQueue& Q, SqStack& S) {
	ElemType x;

	while (Q.front != Q.rear || Q.tag == 1) {  //�ӿձ�־
		if (OutQueue(Q, x)) 
			if(!PushStack(S, x)) return false;   //�������ִ�гɹ��������Ԫ����ջ
	}
	StackPrint(S);           //ɨ��ջ�鿴Ԫ��
	while (S.top != -1) {                  //ջ�ձ�־
		if (PopStack(S, x)) 
			if(!InQueue(Q, x)) return false;   //�����ջ�ɹ������ջԪ�����
	}

	return true;
}