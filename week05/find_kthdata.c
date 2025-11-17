#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_data(int a[], int n);
int find_kthdata(int a[], int n, int k);

int main() {
	int list[] = { 45, 100, 38, 90, 17, 75, 56 };
	int n = sizeof(list) / sizeof(int);
	int k;

	printf("== 정렬 전 리스트 데이터 ==\n");
	print_data(list, n);

	printf("\n\n몇번째 데이터를 선택할까요? ");
	scanf("%d", &k);

	printf("\n%d번째 데이터: %d\n", k, find_kthdata(list, n, k));
	printf("\n== 오름차순으로 정렬 후 리스트 데이터 ==\n");
	print_data(list, n);
}

void print_data(int a[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int find_kthdata(int a[], int n, int k) {
	int s, m, temp;
	for (s = 0; s < n - 1; s++) {
		m = s;
		for (int i = s + 1; i < n; i++) {
			if (a[i] < a[m])
				m = i;
		}
		temp = a[s];
		a[s] = a[m];
		a[m] = temp;
	}
	return a[k-1];
}