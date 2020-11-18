#include <iostream>
#include "typedef.h"

using namespace std;

/*
* 解题思路：
* 把第m个元素存入temp,然后把temp与前一个元素对比，并把该元素后移一位，
* 如果temp大则查在该元素后面
*/
void InsertElem(int a[], int m, int n) {
	int i, j, temp;
	for (i = m; i < m + n; ++i) {
		temp = a[i];
		for (j = i - 1; j >= 0; --j) {
			if (temp > a[j]) {
				break;
			}
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}
void PrintArray(int a[], int length) {
	int i;
	cout << "开始打印" << endl;
	for (i = 0; i < length; ++i) {
		cout << a[i] << endl;
	}
}
int main() {
	int m, n;
	m = 5;
	n = 2;
	int a[] = { 1,3,5,7,9,2,4};
	PrintArray(a, 9);
	InsertElem(a, 5, 2);
	PrintArray(a, 9);
	return 0;
}