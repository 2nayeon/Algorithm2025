#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int call_number, m, r, k, ans1, ans2;

	printf("몇으로 나누어 떨어지는 놀이할까요? ");
	scanf("%d", &m);
	printf("Start: %d로 나누어지는 가장 가까운 수로 답하기\n", m);

	for (k = 0; k < 5; k++) {
		printf("\nCall Number = ");
		scanf("%d", &call_number);
		r = call_number % m;

		if ((m - r) > r) {// 이전 배수가 더 가까움
			ans1 = call_number - r;
			printf("The answer is %d\n", ans1);
		}
		else if ((m - r) < r) { // 다음 배수가 더 가까움
			ans2 = call_number + (m - r);
			printf("The answer is %d\n", ans2);
		}
		else { // 이전배수와 다음배수까지의 값 차이가 동일
			ans1 = call_number - r;
			ans2 = call_number + (m - r);
			printf("The answer is %d and %d\n", ans1, ans2);
		}
	}

	return 0;
}