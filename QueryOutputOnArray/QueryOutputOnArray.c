/*
Assumptions
Query1: right rotation
Query2: left rotation
Query3: sum to l...r (both inclusive)
*/

#include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int arr[], int start, int end) {
	int temp;
	while (start < end) {
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void findSum(int arr[], int query[], int sum) {
	int start = query[1];
	sum = 0;
	for (start; start < query[2] + 1; start++) {
		sum += arr[start];
	}
	printf("sum is %d\n", sum);
}

void leftRotation(int arr[], int n, int query[]) {
	int times = query[1];
	swap(arr, 0, times - 1);
	swap(arr, times, n - 1);
	swap(arr, 0, n - 1);
	printArr(arr, n);
}

void rightRotation(int arr[], int n, int query[]) {
	int times = query[1];
	swap(arr, 0, n - 1 - times);
	swap(arr, n - times, n - 1);
	swap(arr, 0, n - 1);
	printArr(arr, n);
}

void queryChecker(int arr[], int query[], int n, int sum) {
	if (query[0] == 1) {
		rightRotation(arr, n, query);
	}
	else if (query[0] == 2) {
		leftRotation(arr, n, query);
	}
	else {
		findSum(arr, query, sum);
	}
}

int main(void) {
	int sum = 0;
	int n = 5;
	int arr[] = { 1, 2, 3, 4, 5 };
	int q1[] = { 1, 3 };
	int q2[] = { 3, 0, 2 };
	int q3[] = { 2, 1 };
	int q4[] = { 3, 1, 4 };
	queryChecker(arr, q1, n, sum);
	queryChecker(arr, q2, n, sum);
	queryChecker(arr, q3, n, sum);
	queryChecker(arr, q4, n, sum);
	return 0;
}