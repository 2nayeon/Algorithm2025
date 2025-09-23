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
	agentTYPE atable[100], maxw;
	int i = 0, n;

	FILE* agentp;
	if (argc != 2) { // 실행파일+인자=2
		printf("실행인수를 잘못주었습니다.\n");
		exit(1);
	}
	// 전달받은 파일명을 열고 읽기 모드 "r"로 파일 열기 -> 실패 시 오류메세지
	if((agentp=fopen(argv[1], "r"))==NULL){
		printf("데이터 파일을 열 수 없습니다.\n");
		exit(1);
	}
	// 파일의 끝(EOF)까지 한줄씩 읽어서 구조체배열 atable에 저장
	while (fscanf(agentp, "%s %d %d", atable[i].aid, &atable[i].apart, &atable[i].wn) != EOF) {
		i++;
	}

	n = i;
	printf("상담원의 수 = %d\n", n);
	maxw = max_waiting(atable, n);
	printf("최대 대기상담원: %s\t%d\t%d\n", maxw.aid, maxw.apart, maxw.wn);
	
	return 0;
}