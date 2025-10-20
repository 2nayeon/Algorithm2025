#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int k, dap, score = 0, try, ok;

	for (k = 10; k < 15; k++) {
		ok = 0, try = 0;
		while (try < 2 && !ok) {
			printf("%d * %d = ", k + 10, k + 2);
			scanf("%d", &dap);
			if (dap == (k + 10) * (k + 2)) {
				printf("Correct!!\n");
				ok = 1;
				score += (20 - try * 10);
			}
			else {
				if (try != 1)
					printf("Try Again!\n");
				else
					printf("Answer = %d\n", (k + 10) * (k + 2));
			}
			try++;
		}
	}

	printf("당신의 성적은? %d\n", score);

	return 0;
}