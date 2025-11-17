#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NUM 100

int bsearch_stock(long s[][2], long key, int left, int right);
long stocksum(long s[][2], int k);

int main(int argc, char *argv[]) {
	long stock[NUM][2], item_code;
	int k = 0, s;

	FILE* stockp;
	if (argc != 2) {
		printf("실행 인자를 잘못 주었습니다.");
		exit(1);
	}
	if ((stockp = fopen(argv[1], "r")) == NULL) {
		printf("실행파일을 열 수 없습니다.");
		exit(1);
	}

	while (fscanf(stockp, "%ld %ld", &stock[k][0], &stock[k][1]) != EOF) {
		printf("%d\n", stock[k][0]);
		k++;
	}

	printf("\n검색할 item번호를 입력하세요: ");
	scanf("%d", &item_code);
	s = bsearch_stock(stock, item_code, 0, k - 1);
	if (s == -1) printf("재고물품이 없습니다\n");
	else printf("%ld의 재고갯수 = %u\n", item_code, stock[s][1]);

	printf("전체 재고물품의 갯수 합 = %ld\n", stocksum(stock, k));
}

long bsearch_stock(long s[][2], long key, int left, int right) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key < s[mid][0])
			right = mid - 1;
		else if (key > s[mid][0])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

long stocksum(long s[][2], int k) {
	int total = 0;
	for (int i = 0; i < k; i++) {
		total += s[i][1];
	}
	return total;
}