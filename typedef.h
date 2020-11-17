#pragma once
#define maxSize 100

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