#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int howmany(int ccahnge);

int main() {
	int cmoney;
	printf("거스름돈 얼마? ");
	scanf("%d", &cmoney);
	printf("거스름돈 전체 개수는 = %d", howmany(cmoney));
}

int howmany(int cchange) {
	int coin500, coin100, coin50, coin10;
	coin500 = coin100 = coin50 = coin10 = 0;

	while (cchange >= 500) { cchange -= 500; coin500++; }
	while (cchange >= 100) { cchange -= 100; coin100++; }
	while (cchange >= 50) { cchange -= 50; coin50++; }
	while (cchange >= 10) { cchange -= 10; coin10++; }

	printf("500원: %d, 100원: %d, 50원: %d, 10원: %d\n", coin500, coin100, coin50, coin10);
	return coin500 + coin100 + coin50 + coin10;
}