#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, x;
	long mult = 1; //곱하기->1로 초기화

	printf("Enter the number of data to be processed: ");
	scanf("%d", &n);

	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x != 0) {
			mult *= x;
		}
	}

	printf("The result = %d\n", mult);

	return 0;
}