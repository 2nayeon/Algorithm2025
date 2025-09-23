#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcc(int x, int y);

int main() {
	int gvalue;
	int a, b, again = 1;
	while (again) {
		printf("최대공약수를 구할 두 수를 입력 하세요.");
		scanf("%d %d", &a, &b);
		gvalue = gcc(a, b);
		
		printf("gcd(%d, %d) = %d\n", a, b, gvalue);
		printf("계속하실래요?(1/0)");
		scanf("%d", &again);
	}
}

int gcc(int x, int y) {
	if (y == 0)
		return x;
	else
		gcc(y, x % y);
}

/*
int gcc(int x, int y) {
	int tmp;
	while (y != 0) {
		tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;
}
*/