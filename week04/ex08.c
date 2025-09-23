#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);

int main(int argc, char* argv[]) {
	int a, b, result, answer;
	int correct = 0, i = 0;

	FILE* infile, *out;
	if (argc != 4) {
		printf("실행인수를 잘못 주었습니다.");
		exit(1);
	}
	if ((infile = fopen(argv[2], "r")) == NULL) {
		printf("입력 파일을 열 수 없습니다.\n");
		exit(1);
	}
	if ((out = fopen(argv[3], "w")) == NULL) {
		printf("출력파일을 열 수 없습니다.\n");
		exit(1);
	}

	while (fscanf(infile, "%d %d", &a, &b) != EOF) {
		printf("%d: gcd(%d, %d) = ", i + 1, a, b);
		scanf("%d", &answer);
		result = gcd(a, b);
		if (answer != result) {
			fprintf(out, "%d %d\n", a, b);
			printf("Answer: gcd(%d, %d) = %d\n", a, b, result);
		}
		else {
			printf("Correct...\n");
			correct++;
		}
		i++;
	}
	printf("%d문제 중에 %d문제 통과하셨습니다.", i, correct);
}

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		gcd(y, x % y);
}