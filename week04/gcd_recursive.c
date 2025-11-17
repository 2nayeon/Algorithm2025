// 파일명: gcd_recursive.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y);

int main() {
	int gvalue;
	int a, b, again = 1;

	while (again) {
		printf("최대공약수를 구할 두 수를 입력하세요.");
		scanf("%d %d", &a, &b);
		gvalue = gcd(a, b);
		printf("gcd(%d, %d) = %d\n\n", a, b, gvalue);
		printf("계속하실래요? (1/0)");
		scanf("%d", &again);
	}

	return 0;
}

// 재귀적 정의를 이용한 유틀리드 알고리즘
int gcd(int x, int y) {
	if (y == 0) //종료조건
		return x;
	else
		return gcd(y, x % y);
}


/*
// 반복을 이용한 유틀리드 알고리즘
int gcd(int x, int y) {
	int tmp;
	while (y != 0) {
		tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;
}
*/