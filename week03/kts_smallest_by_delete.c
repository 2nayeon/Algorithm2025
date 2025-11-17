#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define DNUM 100

int find_min_delete(int a[], int n);

int main() {
	int data[DNUM], k, n, i, fdata;

	printf("데이터의 갯수와 몇번째 데이터를 찾을지 입력: ");
	scanf("%d %d", &n, &k);
	printf("Enter %d data: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &data[i]);
	
	for (i = 0; i < k; i++)
		fdata = find_min_delete(data, n - i);

	printf("%d번째로 작은 데이터 = %d", k,fdata);
	return 0;
}

// 배열에서 최소값을 찾아서 삭제하고, 그 값을 리턴
// 삭제된 값자리에는 뒤에 값들을 당기기
int find_min_delete(int a[], int n) {
	int i, min, min_index = 0;

	for (i = 1; i < n; i++) {
		if (a[i] < a[min_index])
			min_index = i;
	}
	min = a[min_index]; // 반환할 최소값 저장

	i = min_index + 1;
	while (i < n) { // 삭제를 위해 배열 당기기
		a[i - 1] = a[i];
		i++;
	}

	return min;
}