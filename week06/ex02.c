#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bsearch(int a[], int n, int key);
void selection_sort(int a[], int n);

int  main()
{
    int list[] = { 82, 120, 30, 40, 5, 90, 77, 25, 45, 100, 10, 79, 31, 55, 87 };
    int n = sizeof(list) / sizeof(int);
    int key, i;
    char sorted;

    printf("Is your data set sorted(y/n)?");
    scanf("%c", &sorted);

    if (sorted == 'n') selection_sort(list, n);

    printf("The data set : \n");
    for (i = 0; i < n; i++) {
        printf("%5d", list[i]);
        if ((i + 1) % 7 == 0) printf("\n");
    }

    printf("\nEnter a key: ");
    scanf("%d", &key);

    if ((i = bsearch(list, n, key)) != -1)
        printf("%d exist at [%d]\n", key, i + 1);
    else
        printf("%d does not exist\n", key);
}

// 오름차순 정렬
int bsearch(int a[], int n, int key) {
	int left = 0, right = n - 1;
	int mid;
	while (left <= n - 1) {
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

// 오름차순 정렬
void selection_sort(int list[], int n) {
	int s, m, j, temp;
	for (s = 0; s < n - 1; s++) {
		m = s;
		for (j = s + 1; j < n; j++)
			if (list[j] < list[m]) m = j;
		temp = list[s];
		list[s] = list[m];
		list[m] = temp;
	}
}

