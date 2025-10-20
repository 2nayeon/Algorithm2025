#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, data, large, count;

	printf("Input the number of data: ");
	scanf("%d", &n);

	printf("Input %d data: \n", n);
	scanf("%d", &data);

	large = data;

	for (count = 1; count < n; count++) {
		scanf("%d", &data);
		if (data > large)
			large = data;
	}

	printf("The largest data = %d\n", large);

	return 0;
}