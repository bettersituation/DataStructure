/*
Assume Clock-wise rotation
Time Complexity: O(log n)
Auxiliary Space: O(1)
*/

#include <stdio.h>

int findRotationCount(int arr[], int n) {
	int start = 0;
	int end = n - 1;
	int mid = (start + end) / 2;

	if (arr[start] < arr[end]) {
		return -1;
	}
	while (1) {
		if (arr[mid] > arr[mid + 1]) {
			return mid;
		}
		if (arr[start] > arr[mid]) {
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else {
			start = mid + 1;
			mid = (start + end) / 2;
		}
	}
}

int main(void) {
	int n = 6;
	int arr[] = { 15, 18, 2, 3, 6, 12 };
	int k = findRotationCount(arr, n);
	printf("%d", (k + 1) % n);
}