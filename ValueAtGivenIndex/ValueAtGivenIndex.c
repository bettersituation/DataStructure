/*
Find Element At Given Index After Given Right Rotation Applied
Time Complexity: O(n * query size)
Auxiliary Space: O(1)
*/

#include <stdio.h>

void printAt(int arr[], int index) {
	printf("Element value is %d at index %d", arr[index], index);
}

void rotate(int arr[], int start, int end) {
	int temp = arr[end];
	int i = 0;
	for (i; i < end - start; i++) {
		arr[end - i] = arr[end - i - 1];
	}
	arr[start] = temp;
}

void queryOp(int arr[], int query[], int query_num) {
	int i = 0;
	for (i; i < query_num; i++) {
		rotate(arr, query[i, 0], query[i, 1]);
	}
}

int main(void) {
	int index = 1;
	int arr[] = { 1, 2, 3, 4, 5 };
	int query[2][2] = { { 0, 2 }, { 0, 3 } };
	int query_num = 2;
	
	queryOp(arr, query, query_num);
	printAt(arr, index);
}