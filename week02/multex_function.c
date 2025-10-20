#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DNUM 100

long multex(int a[], int n);

int main()
{
	int data[DNUM], k, n;
	printf("The number of data : ");
	scanf("%d", &n);
	printf("Enter %d data\n", n);
	for (k = 0; k < n; k++)
		scanf("%d", &data[k]);
	printf("The multipilication of data : %d\n", multex(data, n));
}

long multex(int a[], int n) {
	int i, x, allzero = 1;
	long mult = 1;

	for (i = 0; i < n; i++) {
		if (a[i] != 0) {
			mult *= a[i];
			allzero = 0;
		}
	}
	if (allzero)
		mult = 0;

	return mult;
}