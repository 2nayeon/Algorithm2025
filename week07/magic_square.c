#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15

int main() {
	int n, i, j, sum = 0;
	int count, row, col;
	int table[MAX_SIZE][MAX_SIZE];

	printf("Enter a number: ");
	scanf("%d", &n);

	if ((n < 1) || (n > MAX_SIZE)) {
		printf("Error! Size is out of range.\n");
		exit(1);
	}
	if (!(n % 2)) { // n%2==0
		printf("Error! Size is even.\n");
		exit(1);
	}

	// 2차원배열을 0으로 초기화 -> 이 프로그램에서 다른 숫자가 이미 들어가있는지 알기 위해
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			table[i][j] = 0;
	}

	// i, j -> 방금 숫자가 들어간 자리를 나타내는 변수
	i = 0;
	j = (n - 1) / 2;
	table[i][j] = 1;

	// row, col -> 다음 숫자가 들어갈 자리를 나타내는 변수
	for (count = 2; count <= n*n; count++) {
		row = (i - 1 < 0) ? n - 1 : i - 1;
		col = (j - 1 < 0) ? n - 1: j - 1;
		if (table[row][col] != 0)
			i++;
		else {
			i = row;
			j = col;
		}
		table[i][j] = count;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%d\t", table[i][j]);
		printf("\n");
	}

	for (j = 0; j < n; j++)
		sum += table[0][j];
	printf("Row/Column/Diagonal Sum = %d", sum);
}