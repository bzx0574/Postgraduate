#include <iostream>
#include "typedef.h"

using namespace std;

/*
* ����˼·��
* �ѵ�m��Ԫ�ش���temp,Ȼ���temp��ǰһ��Ԫ�ضԱȣ����Ѹ�Ԫ�غ���һλ��
* ���temp������ڸ�Ԫ�غ���
*/
void InsertElem(int a[], int m, int n) {
	//int i, j, temp;
	//for (i = m; i < m + n; ++i) {
	//	temp = a[i];
	//	for (j = i - 1; j >= 0; --j) {
	//		if (temp < a[j]) {
	//			a[j + 1] = a[j];
	//		}
	//	}
	//	a[j + 1] = temp;
	//}
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
void PrintArray(int a[], int length) {
	int i;
	cout << "��ʼ��ӡ" << endl;
	for (i = 0; i < length; ++i) {
		cout << a[i] << endl;
	}
}
int main() {
	int m, n;
	m = 5;
	n = 4;
	int a[] = { 1,3,5,7,9,2,4,6,8 };
	PrintArray(a, 9);
	InsertElem(a, 5, 4);
	PrintArray(a, 9);

	return 0;
}