/*
Assume All elements are distinct
Time Complexity: O(n) = find pivot point(O(log n)) + find pair(O(n))
Auxiliary Space: O(1)
*/

#include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	} 
}

void findPair(int arr[], int n, int sum) {
	int pivot = findPivotPoint(arr, n);
	int end = pivot;
	int start = (pivot + 1) % n;
	int yn = 0;

	while (1) {
		if (start == end) {
			if (yn == 0) {
				printf("there does not exist pair which sum is equal to %d", sum);
			}
			return;
		}
		else if (arr[start] + arr[end] == sum) {
			printf("a pair of indices (%d, %d), which values are (%d, %d), makes sum to equal to %d\n", start, end, arr[start], arr[end], sum);
			start = (start + 1) % n;
			yn = 1;
		}
		else if (arr[start] + arr[end] < sum) {
			start = (start + 1) % n;
		}
		else {
			end = (end - 1) % n;
		}
	}
}

int findPivotPoint(int arr[], int n) {
	int start = 0;
	int end = n - 1;
	int mid = (start + end) / 2;

	if (arr[0] < arr[n - 1]) {
		return -1;
	}
	
	while (1) {
		if (arr[start] < arr[mid]) {
			if (arr[mid] > arr[mid + 1]) {
				return mid;
			}
			else {
				start = mid + 1;
				mid = (start + end) / 2;
			}
		}
		else {
			if (arr[start] > arr[start + 1]) {
				return start;
			}
			else {
				end = mid - 1;
				mid = (start + end) / 2;
			}
		}
	}
}


int main(void) {
	int n = 8;
	int arr[] = { 1, 2, 3, 5, 6, 7, -5, -2 };
	int sum = 3;
	findPair(arr, n, sum);
	return 0;
}