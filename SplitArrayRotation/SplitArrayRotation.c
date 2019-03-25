/*
Time Complexity: O(n) because of loop1(d) + loop2(n-d) + loop(d) and d < n
Auxiliary Space: O(d) because of saving int temp[]
*/

#include <stdio.h>

int main(void) {
	int n = 8;
	int d = 3;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int tmp[3];
	int i = 0;

	for (i; i < d; i++) {
		tmp[i] = arr[i];
	}

	i = 0;
	for (i; i < n - d; i++) {
		arr[i] = arr[i + d];
	}

	i = 0;
	for (i; i < d; i++) {
		arr[n - d + i] = tmp[i];
	}

	i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}