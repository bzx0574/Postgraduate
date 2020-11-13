#include <iostream>
#define maxSize 100

using namespace std;

//结构体：二叉树
typedef struct BTNode {
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;
//结构体：顺序表
typedef struct SqList {
	int data[maxSize];
	int length;
}SqList;
//结构体：单链表
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;
//结构体：双链表
typedef struct DLNode {
	int data;
	struct DLNode* priot;
	struct DLNode* next;
}DLNode;
//结构体：顺序栈
typedef struct SqStack {
	int data[maxSize];
	int top;
}SqStack;
//结构体：顺序队列
typedef struct SqQueue {
	int data[maxSize];
	int front;
	int rear;
}SqQueue;
//结构体：链队
typedef struct LiQueue {
	LNode* front;
	LNode* rear;
}LiQueue;
//初始化顺序表
void CreateList(SqList& L, int a[], int n)
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
void CreateList(LNode*& c, int a[], int n) {
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

int main()
{
	int i;
	int a[] = { 1,3,5,7,2,4,6 };
	SortElem(a, 4, 3);
	for (i = 0; i < 7; ++i) {
		cout << a[i] << endl;
	}
	return 0;
}
