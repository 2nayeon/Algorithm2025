#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct agent {
	char aid[10]; // 상담원id
	int apart; // 상담분야
	int wn; // 대기고객수
} agentTYPE;

agentTYPE max_waiting(agentTYPE a[], int n);

int main(int argc, char* argv[]) {
	agentTYPE atable[100], maxw;
	int i = 0, n;
	
	FILE* agentp;
	if (argc != 2) {
		printf("실행인수를 잘못 주었습니다.\n");
		exit(1);
	}
	if ((agentp = fopen(argv[1], "r")) == NULL) {
		printf("데이터 파일을 열 수 없습니다.\n");
		exit(1);
	}
	while (fscanf(agentp, "%s %d %d", atable[i].aid, &atable[i].apart, &atable[i].wn) != EOF) {
		i++;
	}
	
	n = i;
	printf("상담원의 수 = %d\n", n);
	maxw = max_waiting(atable, n);
	printf("최대 대기 상담원: %s\t%d\t%d\n", maxw.aid, maxw.apart, maxw.wn);
}

agentTYPE max_waiting(agentTYPE a[], int n) {
	int i, maxi = 0;
	for(i=1; i<n; i++){
		if (a[i].wn > a[maxi].wn)
			maxi = i;
	}
	return a[maxi];
}

