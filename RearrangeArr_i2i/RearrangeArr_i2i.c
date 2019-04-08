#include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void globalRearrangeArr(int arr[], int n) {
	int i = 0;
	int at;
	int tmp;
	int val;

	for (i; i < n; i++) {
		at = i;
		val = arr[at];
		while (1) {
			if ((at == val) || (val == -1)) {
				break;
			}
			at = val;
			tmp = arr[val];
			arr[val] = val;
			val = tmp;
		}
		if (arr[i] != i) {
			arr[i] = -1;
		}
	}
}

int main(void) {
	int arr[] = { 19, 7, 0, 3, 18, 15, 12, 6, 1, -1, 11, 10, 9, 5, 13, 16, 2, 14, 17, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printArr(arr, n);
	globalRearrangeArr(arr, n);
	printArr(arr, n);
}