/*
Assume All elements are distinct
Time Complexity: O(log n)
Auxiliary Space: O(1)
*/

# include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void recursiveFind(int arr[], int value, int start, int end) {
	if (start == end) {
		if (arr[start] == value) {
			printf("value %d found at index %d\n", value, start);
			return;
		}
		else {
			printf("value %d not found\n", value);
			return;
		}
	}
	else if (arr[(start + end) / 2] == value) {
		printf("value %d found at index %d\n", value, (start + end) / 2);
		return;
	}
	else if (arr[(start + end) / 2] < value) {
		if ((arr[start] > arr[(start + end) / 2]) && (arr[start] <= value)) {
			recursiveFind(arr, value, start, (start + end) / 2 - 1);
		}
		else if ((arr[start] > arr[(start + end) / 2]) && (arr[start] > value)) {
			recursiveFind(arr, value, (start + end) / 2 + 1, end);
		}
		else {
			recursiveFind(arr, value, (start + end) / 2 + 1, end);
		}
	}
	else {
		if ((arr[end] < arr[(start + end) / 2]) && (arr[end] >= value)) {
			recursiveFind(arr, value, (start + end) / 2 + 1, end);
		}
		else if ((arr[end] < arr[(start + end) / 2]) && (arr[end] < value)) {
			recursiveFind(arr, value, start, (start + end) / 2 - 1);
		}
		else {
			recursiveFind(arr, value, start, (start + end) / 2 - 1);
		}
	}
}


int main(void) {
	int n = 9;
	int start = 0;
	int end = n - 1;
	int arr[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
	int value = 8;

	recursiveFind(arr, value, start, end);
	printArr(arr, n);
	return 0;
}