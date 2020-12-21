﻿#include <iostream>
#include "typedef.h"
using namespace std;

//初始化顺序表
void CreateSqList(SqList& L, int a[], int n)
{
	int i;
	L.length = n;
	for (i = 0; i < n; i++)
	{
		L.data[i] = a[i];
	}
}
//输出顺序表
void PrintList(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++) {
		cout << L.data[i] << endl;
	}
}
//在顺序表中查某值的位置
int FindElem(SqList l, int x) {
	int i;
	for (i = 0; i < l.length; ++i) {
		if (x < l.data[i]) {
			return i;
		}
	}
	return i;
}
//在顺序表中安大小插入值
void InsertElem(SqList& l, int x) {
	int  i;
	int p = FindElem(l, x);
	for (i = l.length - 1; i >= p; --i) {
		l.data[i + 1] = l.data[i];
	}
	l.data[p] = x;
	++(l.length);
}
//删除顺序表某元素
void DeleteElem(SqList& l, int p) {
	int i;
	if (p<0 || p>l.length - 1) {
		return;
	}
	for (i = p; i < l.length - 1; ++i) {
		l.data[i] = l.data[i + 1];
	}
	--l.length;
}
//合并两个单链表
void Merge(LNode* a, LNode* b, LNode*& c) {
	LNode* pa = a->next;
	LNode* pb = b->next;
	LNode* r;
	c = a;
	c->next = NULL;
	free(b);
	r = c;
	while (pa != NULL && pb != NULL) {
		if (pa->data <= pb->data) {
			r->next = pa;
			pa = pa->next;
			r = r->next;
		}
		else {
			r->next = pb;
			pb = pb->next;
			r = r->next;
		}
	}
	r->next = NULL;
	if (pa != NULL) {
		r->next = pa;
	}
	if (pb != NULL) {
		r->next = pb;
	}
}
//用尾插法创建单链表
void CreateLNodeList(LNode*& c, int a[], int n) {
	LNode* s, * r;
	int i;
	c = (LNode*)malloc(sizeof(LNode));
	c->next = NULL;
	r = c;
	for (i = 0; i < n; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
//遍历单链表
void ScanList(LNode* c)
{
	while (c != NULL)
	{
		cout << c->data << endl;
		c = c->next;		//temp指向下一个的地址 即实现++操作
	}

}
//在数组中整理数字
void SortElem(int a[], int m, int n) {
	int i, j;
	int temp;
	for (i = m; i < m + n; ++i) {
		temp = a[i];
		for (j = i - 1; j >= 0 && temp < a[j]; --j) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}
//删除不同的数字
void DeleteDifference(LNode* a, LNode* b) {
	LNode* pa = a->next, * pb = b->next;
	LNode* pre = a;
	LNode* r;
	while (pa != NULL && pb != NULL) {
		if (pa->data < pb->data) {
			pre = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data) {
			pb = pb->next;
		}
		else {
			pre->next = pa->next;
			r = pa;
			pa = pa->next;
			free(r);
		}
	}
}
/*
在单链表中找到倒数k个节点
并返回该节点的值
*/
int FindElemLNode(LNode* head, int k) {
	LNode* p1 = head->next;
	LNode* p = head;
	int i;
	i = 1;
	while (p1 != NULL)
	{
		p1 = p1->next;
		++i;
		if (i > k) {
			p = p->next;
		}
	}
	if (p == head)
	{
		return 0;
	}
	else
	{
		cout << p->data << endl;
		return 1;
	}
}
//初始化栈
void InitStack(SqStack& st) {
	st.top = -1;
}
//判断栈空
int IsEmptyStack(SqStack st) {
	if (st.top == -1) {
		return -1;
	}
	else {
		return 0;
	}
}
//进栈
int PushStack(SqStack& st, int x) {
	if (st.top == maxSize - 1) {
		return 0;
	}
	++(st.top);
	st.data[st.top] = x;
	return 1;
}
//出栈
int PopStack(SqStack& st, int& x) {
	if (st.top == -1) {
		return 0;
	}
	x = st.data[st.top];
	--(st.top);
	return 1;
}
//初始化链队
void initQueue(LiQueue*& lqu) {
	lqu = (LiQueue*)malloc(sizeof(LiQueue));
	lqu->front = lqu->rear = NULL;
}
//判断队空
int isQueueEmpty(LiQueue* lqu) {
	if (lqu->rear == NULL || lqu->front == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
/*
* 一个算术表达式中的括号只有小括号。判断这个表达式是不是正确匹配
*/
int match(char exp[], int n) {
	char stack[maxSize];
	int top = -1;
	int i;
	for (i = 0; i < n; ++i) {
		if (exp[i] == '(') {
			stack[++top] = '(';
		}
		if (exp[i] == ')') {
			if (top == -1) {
				return 0;
			}
			else {
				--top;
			}
		}
	}
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}


int main()
{
	LNode* l;
	l = (LNode*)malloc(sizeof(LNode));
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	CreateLNodeList(l, a, 9);
	FindElemLNode(l, 3);
	return 0;
}
