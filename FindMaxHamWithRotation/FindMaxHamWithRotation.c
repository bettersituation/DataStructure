/*
Time Complexity: O(n*n)
Auxiliary Space: O(n)
*/

#include <stdio.h>

int calcHam(int fixed_arr[], int window_arr[], int n, int start) {
	int d = 0;
	int j = 0;
	for (j; j < n; j++) {
		if (fixed_arr[j] != window_arr[start + j]) {
			d++;
		}
	}
	return d;
}

int main(void) {
	int maxham = 0;
	int ham = 0;
	int n = 6;
	int arr[] = { 2, 2, 5, 6, 2, 3 };
	int window_arr[12];
	int i = 0;
	for (i; i < n; i++) {
		window_arr[i] = arr[i];
		window_arr[n + i] = arr[i];
	}
	i = 0;

	for (i; i < n; i++) {
		ham = calcHam(arr, window_arr, n, i);
		if (maxham < ham) {
			maxham = ham;
		}
	}
	i = 0;

	printf("maximum hamming distance is %d", maxham);
}
