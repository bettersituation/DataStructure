# include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void rightBy1Rotate(int arr[], int n) {
	int temp = arr[n - 1];
	int i = 0;
	for (i; i < n - 1; i++) {
		arr[n - 1 - i] = arr[n - i - 2];
	}
	arr[0] = temp;
}

int main(void) {
	int n = 15;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	rightBy1Rotate(arr, n);
	printArr(arr, n);
	return 0;
}