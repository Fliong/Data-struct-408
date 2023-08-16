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
		cout << "数据初始化，请输入:data[" << i << "] = ";
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
	cout << "顺序表逆置后为：";
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
		temp[i + 1]=temp[i+1] - i - 1;//删除一个数后，temp[1]及其以后记录的下标应 -1
	}
}

void DeletSameX(SqL& L, int x) {
	int temp[MAXSIZE] = { -1 },j=0;
	for (int i = 0; i < L.len; i++) {
		if (L.data[i] == x) {
			temp[j] = i;   //将顺序表中与x值相等的下标存放在数组temp[]中
			j++;
		}
	}
	Comp(L, temp, j);
}

int FindxHalf(SqL& L, int x) {
	if (L.len == 0) return -1;  
	int left = 0, right = L.len - 1;
	while (left <= right) {
		int half = left + (right - left) / 2; //half 记录一般的位置，这里为初始值
		if (L.data[half] == x) {
			cout << "你要查找的值的位置为：" << half<< endl ;
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
		if (L.data[i] >= x) {     //在递增线性表中找到第一个大于x的值的下标
			for (int j = 0; j < L.len - i; j++) {      //在合适的位置插入x
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
			temp[j] = i;   //将顺序表中在（s,t）范围内值的下标存放在数组temp[]中
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
			temp[j] = i;   //将顺序表中在（s,t）范围内值的下标存放在数组temp[]中
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
	//通过两个顺序数列的对比，将新的顺序填入L3中
	while (k<=L3.len) {
		if (L1.data[i] > L2.data[j]) {
			L3.data[k] = L2.data[j];
			if (j == L2.len - 1) {       //比值到最后，下标不用再加一
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
	cout << "请输入第一个线性表的长度 m=";
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
	int e = -1, temp; //用e接收折半查找返回的下标,temp负责暂存后继元素
	if (L.len == 0) return false;
	e = FindxHalf(L, x);
	if (e != -1) {    //e!=-1时，说明在该线性表中找到x，然后和后继元素交换
		temp = L.data[e];
		L.data[e] = L.data[e + 1];
		L.data[e + 1] = temp;
		cout << "交换后继元素成功！！" << endl;
		Print(L);
		return true;
	}
	//如果找不到x值，则将其插入线性表，且保持递增
	setance = InsertXup(L, x);
	if (setance) {
		cout << "插入成功！！" << endl;
		Print(L);
		return true;
	}
	else {

	}
	return false;
}