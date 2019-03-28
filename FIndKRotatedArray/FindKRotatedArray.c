/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <stdio.h>

int main(void) {
	int k = 5;
	int arr[] = { 1, 3, 5, 7, 9, 11, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[(i + k) % n]);
	}
	return 0;
}