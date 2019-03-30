/*
Assume clock-wise rotation
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <stdio.h>

int main(void) {
	int k = 2;
	int arr[] = { 8, 4, 2, 3, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	for (i; i < n; i++) {
		printf("%d ", arr[(i + n - k) % n]);
	}
}