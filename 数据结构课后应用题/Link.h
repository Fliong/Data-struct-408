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
LinkList TailInsertList(LinkList& L);//β�巨������������
bool Input(LinkList& L);//������������ֵ
bool LPrint(LinkList& L);//��ӡ����
int Length(LinkList& L); //��ȡ������

//�㷨��
bool LDeletXn(LinkList& L, ElemType x);//�ݹ�ɾ����������x��ȵ�ֵ
bool ReniPrint(LinkList& L);//�����ӡ����
bool LDeletMin(LinkList& L);//ɾ��������Сֵ
bool ReniList_1(LinkList& L);//��ͷ���͵�����
bool ReniList_2(LinkList& L);
bool UpList(LinkList& L); //������������
bool DeletRangeList(LinkList& L, ElemType min, ElemType max); //ɾ��������[min,max]��ֵ
LinkList FindSameNode(LinkList& L1, LinkList& L2); //Ѱ����������Ĺ����ڵ�
bool Print2Free(LinkList& head); //�����������ֵ�����ͷŶ�Ӧ�Ŀռ䣨��ͷ���)
LinkList DecomposeOE(LinkList& A);//�������е���ż���ֳ�A(����) B(ż��) ��������
bool LDeletSameX(LinkList& L); //����������ɾ����ͬԪ��(��ͷ���)
LinkList TwoUpL2OneDown(LinkList& L1, LinkList& L2); //�������������ϲ�Ϊ�ݼ�������