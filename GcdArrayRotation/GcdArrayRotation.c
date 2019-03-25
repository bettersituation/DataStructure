/*
Time Complexity: O(nd): gcd(O(n)) + times(O(d/gcd)) * moveAt(O(n/gcd))
Auxiliary Space: O(1)
*/

#include <stdio.h>

void printArr(int arr[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int getGcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return getGcd(b, a % b);
	}
}

void moveAt(int arr[], int n, int gcd, int at) {
	int temp = arr[at];
	int i = at;
	while (1) {
		if (i >= n) {
			break;
		}
		arr[i] = arr[i + gcd];
		i += gcd;
	}
	arr[i - gcd] = temp;
}

void moveWhole(int arr[], int n, int d) {
	int gcd = getGcd(n, d);
	int times = d / gcd;
	int i = 0;
	int j;
	for (i; i < times; i++) {
		j = 0;
		for (j; j < gcd; j++) {
			moveAt(arr, n, gcd, j);
		}
	}
}

int main(void) {
	int n = 15;
	int d = 6;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	moveWhole(arr, n, d);
	printArr(arr, n);
}