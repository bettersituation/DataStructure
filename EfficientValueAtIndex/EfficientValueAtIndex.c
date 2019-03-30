/*
Find Element At Given Index After Given Right Rotation Applied
Time Complexity: O(n * query size)
Auxiliary Space: O(1)
*/

#include <stdio.h>

void printAt(int arr[], int index, int newindex) {
	printf("Element value is %d at index %d", arr[newindex], index);
}

int queryOp(int arr[], int query[], int index, int query_num) {
	int i = 0;
	for (i; i < query_num; i++) {
		if ((index > query[query_num - 1 - i, 0]) && (index <= query[query_num - 1 - i, 1])) {
			index--;
		}
		else if (index == query[query_num - 1 - i, 0]) {
			index = query[query_num - 1 - i, 1];
		}
	}
	return index;
}

int main(void) {
	int index = 1;
	int newindex;
	int arr[] = { 1, 2, 3, 4, 5 };
	int query[2][2] = { { 0, 2 }, { 0, 3 } };
	int query_num = 2;

	newindex = queryOp(arr, query, index, query_num);
	printAt(arr, index, newindex);
}