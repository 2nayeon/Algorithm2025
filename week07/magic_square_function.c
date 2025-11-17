#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15

void display(int table[][MAX_SIZE], int n);
void make_msquare(int table[][MAX_SIZE], int n);

int main() {
	int n, i, j, sum = 0;
	int count, row, col;
	int table[MAX_SIZE][MAX_SIZE];

	printf("Enter a number: ");
	scanf("%d", &n);

	if ((n < 1) || (n > MAX_SIZE)) {
		printf("Error! Size is out of range.\n");
		exit(0);
	}
	if (!(n % 2)) { // n%2 == 0
		printf("Error! Size is even.\n");
		exit(0);
	}

	// 2차원배열을 0으로 초기화
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			table[i][j] = 0;
	}

	make_msquare(table, n);
	display(table, n);

	for (j = 0; j < n; j++)
		sum += table[0][j];
	printf("Row/Column/Diagonal Sum = %d\n", sum);
}

void display(int table[][MAX_SIZE], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", table[i][j]);
		}
		printf("\n");
	}
}

void make_msquare(int table[][MAX_SIZE], int n)
{
	int i, j, count, row, col;

	i = 0; 
	j = (n - 1) / 2;
	table[i][j] = 1;

	for (count = 2; count <= n*n; count++) {
		row = i - 1; 
		col = j - 1;

		if (row < 0) row = n - 1;
		if (col < 0) col = n - 1;
		if (table[row][col]) i++;
		else {
			i = row; j = col;
		}
		table[i][j] = count;
	}
}

