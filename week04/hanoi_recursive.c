#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, char from, char via, char to);
long count = 0;

int main() {
	int n;

	printf("Input the number of dist: ");
	scanf("%d", &n);

	if (n <= 0)
		printf("No dist!\n");
	else
		hanoi(n, 'A', 'B', 'C');
	printf("Moving count = %d\n", count);
}

void hanoi(int n, char from, char via, char to) {
	if (n == 1) {
		count++;
		printf("Move disk from %c to %c\n", from, to);
	}
	else {
		hanoi(n - 1, from, via, to); // n-1개 원판을 목표 기둥(to)이 아닌 다른기둥(via)으로 이동
		hanoi(1, from, to, via); // 맨 아래 남은 원판 1개를 이동
		hanoi(n - 1, via, to, from); // 아까 옮겨둔 n-1개의 원판을 보조기둥(via)에서 목표기둥(to)으로 이동
	}

}