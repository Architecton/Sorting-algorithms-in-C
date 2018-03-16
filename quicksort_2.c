// quicksort - 2.version
#include <stdio.h>
#include <stdlib.h>

// static variables
int *arr;
int arr_length;

// function prototypes
void swap(int *arr, int index_1, int index_2);
void quicksort(int *arr, int left_bound, int right_bound);
void print_array(int *arr, int arr_length);

// main function
int main() {
	// parsing array data //////////////////////////
	scanf("%d", &arr_length);
	arr = (int*)malloc(arr_length*sizeof(int));
	for(int i = 0; i < arr_length; i++) {
		scanf("%d", arr + i);
	}
	////////////////////////////////////////////////

	// sort array using the quicksort algorithm
	quicksort(arr, 0, arr_length - 1);

	// print the sorted array
	print_array(arr, arr_length);
	return 0;
}

// quicksort: performs the quicksort algorithm on the array pointed to by arr with indices on [left_bound, right_bound]
void quicksort(int *arr, int left_bound, int right_bound) {
	// if left_bound exceeds right_bound (invalid array bounds), return
	if(left_bound >= right_bound) {
		return;
	}
	// set left pointer to left_bound and right pointer to right_bound
	int l = left_bound;
	int r = right_bound;
	// use the middle array value as the pivot
	int pivot = arr[(right_bound + left_bound)/2];

	// while the left pointer (l) is less or equal to the right pointer (r)
	while(l <= r) {
		// while element pointed to by l is smaller than pivot
		while(arr[l] < pivot) {
			// increment l
			l++;
		}
		// while element pointed to by r is greater than pivot
		while(arr[r] > pivot) {
			// decrement r
			r--;
		}
		// if l is smaller than r, swap elements pointed by l and r
		if(l <= r) {
			swap(arr, l, r);
			// increment l and decrement r
			l++;
			r--;
		}
	}
	// recursive call on arr[left_bound..r]
	quicksort(arr, left_bound, r);
	// recursive call on arr[l..right_bound]
	quicksort(arr, l, right_bound);
}

// swap: swaps elements at indices index_1 and index_2 in the array pointed to by arr
void swap(int *arr, int index_1, int index_2) {
	int temp =  arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = temp;
}

// print_array: prints the array of integers pointed to by arr
void print_array(int *arr, int arr_length) {
	for (int i = 0; i < arr_length; i++) {
		printf((i == arr_length - 1) ? "%d\n" : "%d, ", arr[i]);		
	}
}