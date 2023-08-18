#pragma once
/*该头文件为线性表的链式表示相关声明*/
/*具体函数算法实现在Linkf(x)中*/
#include<stdlib.h>
#include<iostream>
#include<math.h>
#define MAXSIZE 10

typedef int ElemType;
using namespace std;

/*定义单向链表的基本数据节点*/
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;


//小函数
bool LInitList(LinkList& L);//创建第一个节点，选择带不带头结点
LinkList TailInsertList(LinkList& L);//尾插法建立单向链表
bool Input(LinkList& L);//向单链表中输入值
bool LPrint(LinkList& L);//打印链表


bool LDeletXn(LinkList& L, ElemType x);//递归删除链表中与x相等的值
bool ReniPrint(LinkList& L);//逆向打印链表
bool LDeletMin(LinkList& L);//删除链表最小值
bool ReniList(LinkList& L, LNode& p);//带头结点就地逆置