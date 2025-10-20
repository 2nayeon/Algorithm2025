#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 10

int main() {
	int i, scores[NUM][2], sid, jumsu, rank, n;
	printf("Enter n: ");
	scanf("%d", &n);

	printf("Input id and score: \n");
	for (i = 0; i < n; i++) {
		scanf("%d %d", &scores[i][0], &scores[i][1]);
	}
	printf("Input student id to be search: ");
	scanf("%d", &sid);
	for (i = 0; i < n; i++) {
		if (sid == scores[i][0]) {
		if (sid == scores[i][0]) {
			jumsu = scores[i][1];
			break;
		}
	}

	rank = 0;
	for (i = 0; i < n; i++) {
		if (scores[i][1] > jumsu)
			rank = rank + 1;
	}

	printf("%d번의 점수: %d\n", sid, jumsu);
	printf("%d번의 등수: %d\n", sid, rank + 1);
}