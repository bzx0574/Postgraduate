#pragma once
#define maxSize 100

//�ṹ�壺������
typedef struct BTNode {
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;
//�ṹ�壺˳���
typedef struct SqList {
	int data[maxSize];
	int length;
}SqList;
//�ṹ�壺������
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;
//�ṹ�壺˫����
typedef struct DLNode {
	int data;
	struct DLNode* priot;
	struct DLNode* next;
}DLNode;
//�ṹ�壺˳��ջ
typedef struct SqStack {
	int data[maxSize];
	int top;
}SqStack;
//�ṹ�壺˳�����
typedef struct SqQueue {
	int data[maxSize];
	int front;
	int rear;
}SqQueue;
//�ṹ�壺����
typedef struct LiQueue {
	LNode* front;
	LNode* rear;
}LiQueue;