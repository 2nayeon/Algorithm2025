#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int call_number, m, r, k, ans;

	printf("몇으로 나누어 떨어지는 놀이할까요? ");
	scanf("%d", &m);
	printf("Start: %d로 나누어지는 가장 가까운 수로 답하기\n", m);

	for (k = 0; k < 5; k++) {
		printf("\nCall Number = ");
		scanf("%d", &call_number);
		r = call_number % m;

		if ((m - r) < r) // 다음 배수가 더 가까움
			ans = call_number + (m - r);
		else // 이전 배수가 더 가까움
			ans = call_number - r;

		printf("The answer is %d\n", ans);
	}

	return 0;
}