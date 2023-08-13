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

/*小函数*/
void InitList(SqL& L);// 初始化顺序表
void Print(SqL& L);//打印顺序表
void Comp(SqL& L, int temp[], int j);//顺序表中空缺的位置进行补齐
int FindxHalf(SqL& L, int x);//折半查找

/*大函数（解题方法类）*/
bool DeletX(SqL& L, int& min);//将顺序表的最后一位替换顺序表最小值的位置
void Reni(SqL& L, int a, int b);//将顺序表逆置(从下标a到b)，且时间复杂度为 O(1)
void DeletSameX(SqL& L, int x);//删除数据表中与x相等的值
bool DeletRangeOrder(SqL& L, int s, int t);//删除有序顺序表中，值在（s,t）范围的值。
bool DeletRangeOrder2(SqL& L, int s, int t);//删除有序顺序表中，值在[s,t]范围的值。
bool DeletSameOrder(SqL& L);//删除有序顺序表中重复得值，使顺序表中的值均有不同。
SqL Order2SqL(SqL& L1, SqL& L2);//将两个有序顺序表，合并为一个新的顺序表
bool Amn2nm(SqL& A);//数组A[m+n]中两个线性表，进行顺序颠倒