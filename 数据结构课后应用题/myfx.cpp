#include"myhead.h"

bool DeletX(SqL& L, int& min) {
	if (L.len == 0)
		return false;
	int* p = L.data;
	int* q = L.data;
	for (int i = 0; i < L.len - 1; i++) {
		if (*p > *q) {
			p = q;
		}
		q++;
	}
	min = *p;
	*p = *q;
	L.len--;
	return true;
}

void InitList(SqL& L) {
	L.len = 0;
	for (int i = 0; i < MAXSIZE; i++) {
		cout << "���ݳ�ʼ����������:data[" << i << "] = ";
		cin >> L.data[i];
		if (L.data[i] == -1) {
			break;
		}
		L.len++;
	}
}

void Reni(SqL& L, int a, int b) {
	int temp = 0, k = b, len = b - a;
	if (len <= 0) exit(0);
	cout << "˳������ú�Ϊ��";
	for (int i = 0; i<= len/2; i++) {
		temp = L.data[i+a];
		L.data[i+a] = L.data[k];
		L.data[k] = temp;
		k--;
	}
}

void Print(SqL& L) {
	for (int i = 0; i < L.len; i++) {
		cout << L.data[i] << "  ";
	}
	cout << endl;
}

void Comp(SqL& L, int temp[],int j) {
	for (int i = 0; i < j; i++) {
		for (int k = temp[i]; k < L.len; k++) {
			L.data[k] = L.data[k + 1];
		}
		L.len--;
		temp[i + 1]=temp[i+1] - i - 1;//ɾ��һ������temp[1]�����Ժ��¼���±�Ӧ -1
	}
}

void DeletSameX(SqL& L, int x) {
	int temp[MAXSIZE] = { -1 },j=0;
	for (int i = 0; i < L.len; i++) {
		if (L.data[i] == x) {
			temp[j] = i;   //��˳�������xֵ��ȵ��±���������temp[]��
			j++;
		}
	}
	Comp(L, temp, j);
}

int FindxHalf(SqL& L, int x) {
	if (L.len == 0) return -1;  
	int left = 0, right = L.len - 1;
	while (left <= right) {
		int half = left + (right - left) / 2; //half ��¼һ���λ�ã�����Ϊ��ʼֵ
		if (L.data[half] == x) {
			cout << "��Ҫ���ҵ�ֵ��λ��Ϊ��" << half<< endl ;
			return half;
		}
		else if (L.data[half] > x) {
			right = half - 1;
		}
		else if (L.data[half] < x) {
			left = half + 1;
		}
	}

}

bool InsertXup(SqL& L, int x) {
	if (L.len == 0) return false;
	for (int i = 0; i < L.len; i++) {
		if (L.data[i] >= x) {     //�ڵ������Ա����ҵ���һ������x��ֵ���±�
			for (int j = 0; j < L.len - i; j++) {      //�ں��ʵ�λ�ò���x
				L.data[L.len - j] = L.data[L.len - j - 1];
			}
			L.data[i] = x;
			L.len++;
			return true;
		}
	}
	return false;
}

//04
bool DeletRangeOrder(SqL& L, int s, int t) {
	if (s >= t || L.len == 0) return false;
	int temp[MAXSIZE] = { -1 }, j = 0;
	for (int i = 0; i < L.len; i++) {
		if (L.data[i] > s && L.data[i] < t) {
			temp[j] = i;   //��˳������ڣ�s,t����Χ��ֵ���±���������temp[]��
			j++;
		}
	}
	Comp(L, temp, j);
}

//05
bool DeletRangeOrder2(SqL& L, int s, int t) {
	if (s >= t || L.len == 0) return false;
	int temp[MAXSIZE] = { -1 }, j = 0;
	for (int i = 0; i < L.len; i++) {
		if (L.data[i] >= s && L.data[i] <= t) {
			temp[j] = i;   //��˳������ڣ�s,t����Χ��ֵ���±���������temp[]��
			j++;
		}
	}
	Comp(L, temp, j);
	return true;
}

//06
bool DeletSameOrder(SqL& L) {
	int temp[MAXSIZE] = { -1 },j = 0,i = 0;
	if (L.len == 0) return false;
	while(i<L.len) {
		if (L.data[i] == L.data[i + 1]) {
			temp[j] = i + 1;
			j++;
			i++;
		}
		else {
			i = i + 1;
		}
	}
	Comp(L, temp, j);
	return true;
}

//07
SqL Order2SqL(SqL& L1, SqL& L2) {
	SqL L3;
	int i = 0, j = 0, k = 0;
	L3.len = L1.len + L2.len;
	L3.data[L3.len-1] = {0};
	if (L1.len == 0 || L2.len == 0) return L3;
	//ͨ������˳�����еĶԱȣ����µ�˳������L3��
	while (k<=L3.len) {
		if (L1.data[i] > L2.data[j]) {
			L3.data[k] = L2.data[j];
			if (j == L2.len - 1) {       //��ֵ������±겻���ټ�һ
				L3.data[k + 1] = L1.data[i];
				break;
			}
			j++;
		}
		else {
			L3.data[k] = L1.data[i];
			if (i == L1.len - 1) {
				L3.data[k + 1] = L2.data[j];
				break;
			}
			i++;
		}
		k++;
	}
	return L3;
}

//08
bool Amn2nm(SqL& A) {
	if (A.len == 0||A.len == 1) return false;
	int m;
	cout << "�������һ�����Ա�ĳ��� m=";
	cin >> m;
	int n = A.len - m;
	Reni(A, 0, m + n - 1);
	Reni(A,0,n-1);
	Reni(A, n, m + n - 1);
	return true;
}

//09
bool ChangeXprev(SqL& L, Elem x) {
	bool setance;
	int e = -1, temp; //��e�����۰���ҷ��ص��±�,temp�����ݴ���Ԫ��
	if (L.len == 0) return false;
	e = FindxHalf(L, x);
	if (e != -1) {    //e!=-1ʱ��˵���ڸ����Ա����ҵ�x��Ȼ��ͺ��Ԫ�ؽ���
		temp = L.data[e];
		L.data[e] = L.data[e + 1];
		L.data[e + 1] = temp;
		cout << "�������Ԫ�سɹ�����" << endl;
		Print(L);
		return true;
	}
	//����Ҳ���xֵ������������Ա��ұ��ֵ���
	setance = InsertXup(L, x);
	if (setance) {
		cout << "����ɹ�����" << endl;
		Print(L);
		return true;
	}
	else {

	}
	return false;
}