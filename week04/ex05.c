#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo(int n);

int main() {
	int n, k;
	printf("Input n: ");
	scanf("%d", &n);
	for (k = 0; k <= n; k++) {
		printf("After %d months: %d\n", k, fibo(k));
	}
}

int fibo(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return (fibo(n - 2) + fibo(n - 1));
}