#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_data(int a[], int n);
void descending_selection_sort(int a[], int n);
int descending_bsearch(int a[], int n, int key);

int main() {
	int list[] = { 82, 120, 30, 40, 5, 90, 77, 25, 45, 100, 10, 79, 31, 55, 87 };
	int n = sizeof(list) / sizeof(int);
	int key, i;
	char sorted;

	printf("Is your data set sorted(y/n)? ");
	scanf("%c", &sorted);

	printf("\nThe data set:\n");
	if (sorted == 'n') {
		descending_selection_sort(list, n);
		print_data(list, n);
	}
	else
		print_data(list, n);

	printf("\n\nEnter a Key: ");
	scanf("%d", &key);
	i = descending_bsearch(list, n, key);
	if (i != -1)
		printf("\n%d exist at [%d]", key, i + 1);
	else
		printf("\n%d does not exist", key);
}

void print_data(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%4d", a[i]);
		if ((i + 1) % 7 == 0)
			printf("\n");
	}
}

void descending_selection_sort(int a[], int n) {
	int s, m, temp;
	for (s = 0; s < n - 1; s++) {
		m = s;
		for (int i = s + 1; i < n; i++) {
			if (a[i] > a[m])
				m = i;
		}
		temp = a[s];
		a[s] = a[m];
		a[m] = temp;
	}
}


int descending_bsearch(int a[], int n, int key) {
	int mid;
	int left = 0, right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key < a[mid]) 
			left = mid + 1;
		else if (key > a[mid])
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}