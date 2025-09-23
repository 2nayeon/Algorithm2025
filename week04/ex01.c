#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char* argv[]) {
	int i;
	printf("프로그램 명령 인수의 갯수는 %d\n", argc);
	for (i = 0; i < argc; i++) {
		printf("%d: %s\n", i, argv[i]);
	}
	return 0;
}