#pragma once
#include<stdlib.h>
#include<iostream>
#include<math.h>
#define MAXSIZE 10

using namespace std;
typedef int Elem;

typedef struct {
	Elem data[MAXSIZE];
	int len;
}SqL;

/*С����*/
void InitList(SqL& L);// ��ʼ��˳���
void Print(SqL& L);//��ӡ˳���
void Comp(SqL& L, int temp[], int j);//˳����п�ȱ��λ�ý��в���
int FindxHalf(SqL& L, int x);//�۰����

/*���������ⷽ���ࣩ*/
bool DeletX(SqL& L, int& min);//��˳�������һλ�滻˳�����Сֵ��λ��
void Reni(SqL& L, int a, int b);//��˳�������(���±�a��b)����ʱ�临�Ӷ�Ϊ O(1)
void DeletSameX(SqL& L, int x);//ɾ�����ݱ�����x��ȵ�ֵ
bool DeletRangeOrder(SqL& L, int s, int t);//ɾ������˳����У�ֵ�ڣ�s,t����Χ��ֵ��
bool DeletRangeOrder2(SqL& L, int s, int t);//ɾ������˳����У�ֵ��[s,t]��Χ��ֵ��
bool DeletSameOrder(SqL& L);//ɾ������˳������ظ���ֵ��ʹ˳����е�ֵ���в�ͬ��
SqL Order2SqL(SqL& L1, SqL& L2);//����������˳����ϲ�Ϊһ���µ�˳���
bool Amn2nm(SqL& A);//����A[m+n]���������Ա�����˳��ߵ�