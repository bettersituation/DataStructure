/*
Time Complexity: O(n*d) because move 'n' items 'd' times
Auxiliary Space: O(1)
*/

#include <stdio.h>

void pushOneByOne(int arr[], int n) {
	int temp = arr[0];
	int i = 0;
	for (i; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;
}

void pushOneByOneDtimes(int arr[], int n, int d) {
	int i = 0;
	for (i; i < d; i++) {
		pushOneByOne(arr, n);
	}
}

int main(void) {
	int n = 8;
	int d = 3;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i = 0;
	pushOneByOneDtimes(arr, n, d);
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}