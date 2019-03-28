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

void findMaxIsum(int arr[], int n) {
	int maxisum;
	int maxi = 0;
	int isum = 0;
	int base = 0;
	int i = 0;
	for (i; i < n; i++) {
		base += arr[i];
	}
	i = 0;
	for (i; i < n; i++) {
		isum += i * arr[i];
	}
	maxisum = isum;
	i = 0;
	for (i; i < n-1; i++) {
		isum = isum - base + n * arr[i];
		if (isum > maxisum) {
			maxisum = isum;
			maxi = i + 1;
		}
	}
	i = 0;

	printf("max sum of i*arr[i] is %d\n", maxisum);
	printf("rotate to left %d times\n", maxi);

	printf("given array is { ");
	for (i; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	printf("}\n");
	i = 0;

	printf("rotated array is { ");
	for (i; i < n; i++) {
		printf("%d, ", arr[(maxi + i) % n]);
	}
	printf("}\n");
}

int main(void) {
	int n = 4;
	int arr[] = { 1, 20, 2, 10 };
	findMaxIsum(arr, n);
}