#pragma once
/*��ͷ�ļ�Ϊ���Ա����ʽ��ʾ�������*/
/*���庯���㷨ʵ����Linkf(x)��*/
#include<stdlib.h>
#include<iostream>
#include<math.h>
#define MAXSIZE 10

typedef int ElemType;
using namespace std;

/*���嵥������Ļ������ݽڵ�*/
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;


//С����
bool LInitList(LinkList& L);//������һ���ڵ㣬ѡ�������ͷ���
bool TailInsertList(LinkList& L);//β�巨������������
bool Input(LinkList& L);//������������ֵ
bool LPrint(LinkList& L);//��ӡ����
bool LDeletX(LinkList& L, int x);//�ݹ�ɾ����������x��ȵ�ֵ