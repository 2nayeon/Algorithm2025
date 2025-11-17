#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n);

int main() {
	int n, i;

	printf("Input n: ");
	scanf("%d", &n);

	for (i = 0; i <= n; i++) {
		printf("After %d months: %d\n", i, fibo(i));
	}

	return 0;
}

int fibo(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return fibo(n - 2) + fibo(n - 1);
}