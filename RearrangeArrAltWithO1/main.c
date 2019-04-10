/*
Rearrange Array +/- alternatively with O(1) space
but it may cause O(n^2) time complexity
*/

#include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void pushArr(int arr[], int to_idx, int from_idx) {
	int tmp = arr[from_idx];
	int i = from_idx;
	for (i; i > to_idx; i--) {
		arr[i] = arr[i - 1];
	}
	arr[to_idx] = tmp;
}

void altArr(int arr[], int n) {
	int i = 0;
	int j;
	
	if (arr[i] > 0) {
		j = i;
		while (j < n) {
			if (arr[j] < 0) {
				pushArr(arr, i, j);
				break;
			}
			j++;
		}
		if (j == n) {
			return;
		}
	}

	i++;

	for (i; i < n; i++) {
		if (arr[i] * arr[i - 1] > 0) {
			j = i;
			while (j < n) {
				if (arr[i] * arr[j] < 0) {
					pushArr(arr, i, j);
					break;
				}
				j++;
			}
			if (j == n) {
				return;
			}
		}
	}
}

int main(void) {
	int arr[] = { -5, -2, 5, 2, 4, 7, 1, 8, 0, -8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	altArr(arr, n);
	printArr(arr, n);
	return 0;
}