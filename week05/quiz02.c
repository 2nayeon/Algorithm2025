#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test(int* a, float b);

int main() {
	int num1 = 100, num2;
	float ratio = 0.5;

	num2 = test(&num1, ratio);
	printf("num1: %d, num2: %d, ratio: %.1f\n", num1, num2, ratio);
}

int test(int* a, float b) {
	int c;
	c = (*a) * b;
	*a = (*a) * 2;
	b = b + 0.1;

	return c;
}