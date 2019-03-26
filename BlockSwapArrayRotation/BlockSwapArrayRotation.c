/*
Time Complexity:
Auxiliary Space: O(1)
*/

#include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void swap(int arr[], int d, int from, int to) {
	int temp;
	int i = 0;
	for (i; i < d; i++) {
		temp = arr[to + i];
		arr[to + i] = arr[from + i];
		arr[from + i] = temp;
	}
}

void recursiveSwap(int arr[], int n, int d, int s) {
	if (d == n - d) {
		swap(arr, d, s, s + n - d);
	}
	else if (d < n - d) {
		swap(arr, d, s, s + n - d);
		recursiveSwap(arr, n - d, d, s);
	}
	else {
		swap(arr, n - d, s, s + d);
		recursiveSwap(arr, d, 2 * d - n, n - d);
	}
}

int main(void) {
	int n = 15;
	int d = 9;
	int s = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	recursiveSwap(arr, n, d, s);
	printArr(arr, n);
	return 0;
}
