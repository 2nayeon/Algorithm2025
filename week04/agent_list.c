#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct agent* aList;
struct agent {
	char aid[10]; // 상담원id
	int apart; // 상담분야
	int wn; // 대기고객수
	aList next; 
};
aList head = NULL;

void make_list(aList inode);
aList max_waiting(aList ptr);

int main(int argc, char *argv[]) {
	aList inode, maxwp;
	int i = 0, n, wsum = 0, wclass[5] = {0};

	FILE* agentp;
	if (argc != 2) {
		printf("실행인수를 잘못 주었습니다.");
		exit(1);
	}
	if ((agentp = fopen(argv[1], "r")) == NULL) {
		printf("데이터 파일을 열 수 없습니다.");
		exit(1);
	}
	
	inode = (aList)malloc(sizeof(struct agent));
	while (fscanf(agentp, "%s %d %d", inode->aid, &(inode->apart), &(inode->wn))!= EOF){
		make_list(inode);
		wclass[(inode->apart) - 1] += inode->wn;
		wsum += inode->wn;
		i++;
		inode = (aList)malloc(sizeof(struct agent));
	}

	n = i;
	printf("상담원의 수 = %d\n\n", n);
	for (i = 0; i < 5; i++) {
		printf("상담분야 %d의 대기자수 = %d\n", i + 1, wclass[i]);
	}
	printf("\n전체 %d명이 대기 중입니다.\n", wsum);
	maxwp = max_waiting(head);
	printf("\n최대 대기 상담원: %s\t%d\t%d\n", maxwp->aid, maxwp->apart, maxwp->wn);

}

void make_list(aList inode) {
	aList before = NULL, ptr = NULL;
	if (!head) {
		head = inode;
	}
	else {
		ptr = head;
		while (ptr != NULL) {
			before = ptr;
			ptr = ptr->next;
		}
		before->next = inode;
	}
	inode->next = NULL;
}

aList max_waiting(aList ptr) {
	aList maxp = ptr;
	while (ptr->next != NULL) {
		ptr = ptr->next;
		if (ptr->wn > maxp->wn)
			maxp = ptr;
	}
	return maxp;
}

