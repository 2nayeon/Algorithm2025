#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct agent {
	char aid[10]; // 상담원의 ID(문자열)
	int apart; // 상담원이 속한 파트 번호
	int wn; // 상담원의 대기 고객 수
} agentTYPE;

agentTYPE max_waiting(agentTYPE a[], int n) {
	int k, maxi = 0;
	for (k = 0; k < n; k++) {
		if (a[k].wn > a[maxi].wn)
			maxi = k;
	}
	return a[maxi];
}

int main(int argc, char* argv[]) {
	agentTYPE atable[50], maxw;
	int i = 0, n, wsum = 0, wclass[5] = { 0 };

	FILE* agentp;
	if (argc != 2) {
		printf("실행인수를 잘못주었습니다.\n");
		exit(1);
	}
	if ((agentp = fopen(argv[1], "r")) == NULL) {
		printf("데이터 파일을 열 수 없습니다.\n");
		exit(1);
	}
	while (fscanf(agentp, "%s %d %d", atable[i].aid, &atable[i].apart, &atable[i].wn) != EOF) {
		wclass[(atable[i].apart) - 1] += atable[i].wn; // apart별 대기자수
		/*
		switch (atable[i].apart) {
			case 1: wclass[0] += atable[i].wn;
				break;
			case 2: wclass[1] += atable[i].wn;
				break;
			case 3: wclass[2] += atable[i].wn;
				break;
			case 4: wclass[3] += atable[i].wn;
				break;
			case 5: wclass[4] += atable[i].wn;
		}
		*/
		wsum += atable[i].wn; // 전체 대기자수
		i++;
	}

	n = i;
	printf("상담원의 수 = %d\n\n", n);
	for (i = 0; i < 5; i++) {
		printf("상담분야 %d의 대기자수 = %d\n", i + 1, wclass[i]);
	}
	printf("\n전체 %d명이 대기 중입니다.\n", wsum);
	maxw = max_waiting(atable, n);
	printf("최대 대기상담원: %s %d %d", maxw.aid, maxw.apart, maxw.wn);

	return 0;
}