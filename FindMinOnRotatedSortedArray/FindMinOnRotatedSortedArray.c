/*
Time Complexity: O(log n)
Auxiliary Space: O(1)
*/

#include <stdio.h>

int findPivot(int arr[], int n) {
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
		else if (arr[start] > arr[mid]) {
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
	int arr[] = { 11, 13, 15, 19, -4, 2, 3, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int pivot = findPivot(arr, n);
	printf("minimum value is %d", arr[(pivot + 1) % n]);
	return 0;
}