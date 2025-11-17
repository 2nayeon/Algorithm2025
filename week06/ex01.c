#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 오름차순으로 정렬된 데이터를 이진탐색으로 구현
int bsearch(int a[], int n, int key) {
	int left = 0, right = n - 1;
	int mid;
	while (left<=right) {
		mid = (left + right) / 2;
		if (key > a[mid])
			left = mid + 1;
		else if (key < a[mid])
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}

// 오름차순으로 정렬된 데이터를 재귀함수로 구현
int rbsearch(int a[], int n, int key) {
	int left = 0, right = n - 1;
	int mid;
	while (left <= n - 1) {
		mid = (left + right) / 2;
		if (key > a[mid])
			return rbsearch(a, mid + 1, right, key);
		else if (key < a[mid])
			return rbsearch(a, left, mid - 1, key);
		else
			return mid;
	}
	return -1;
}
