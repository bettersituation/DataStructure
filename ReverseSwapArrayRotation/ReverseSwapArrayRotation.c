/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void reverseSwap(int arr[], int start, int end) {
	int i = start;
	int j = end;
	int temp;
	while (1) {
		if (i >= j) {
			break;
		}
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

int main(void) {
	int n = 15;
	int d = 6;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	reverseSwap(arr, 0, d - 1);
	reverseSwap(arr, d, n - 1);
	reverseSwap(arr, 0, n - 1);
	printArr(arr, n);
	return 0;
}