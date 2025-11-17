#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_data(int a[], int n);
void selection_sort(int a[], int n);
void selection_sort2(int a[], int n);

int main() {
	int list[] = { 45, 100, 38, 90, 17, 75, 56 };
	int n = sizeof(list) / sizeof(int);

	printf("== 정렬 전 리스트 데이터 ==\n");
	print_data(list, n);
	selection_sort(list, n);

	printf("\n\n== 오름차순 정렬 후 리스트 데이터 ==\n");
	print_data(list, n);
	
	selection_sort2(list, n);
	printf("\n\n== 내림차순 정렬 후 리스트 데이터 ==\n");
	print_data(list, n);
	
	return 0;
}

void print_data(int a[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

// 오름차순 정렬
void selection_sort(int a[], int n) {
	int s, m, temp;
	for (s = 0; s < n - 1; s++) {
		m = s;
		for (int i = s + 1; i < n; i++) {
			// m과 비교하여 작은 값을 앞으로 보내기 때문에, 오름차수 정렬이 된다.
			if (a[i] < a[m]) 
				m = i;
		}
		temp = a[s];
		a[s] = a[m];
		a[m] = temp;
	}
}

// 내림차순 정렬
void selection_sort2(int a[], int n) {
	int s, m, temp;
	for (s = 0; s < n - 1; s++) {
		m = s;
		for (int i = s + 1; i < n; i++) {
			// m과 비교하여 큰 값을 앞으로 보내기 때문에, 내림차순 정렬이 된다.
			if (a[i] > a[m]) 
				m = i;
		}
		temp = a[s];
		a[s] = a[m];
		a[m] = temp;
	}
}
