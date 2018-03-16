#include <stdio.h>
#include <stdlib.h>

// static variables
static int *arr;
static int arr_length;

// function prototypes
int* insertion_sort(int *arr, int arr_length);
void swap(int *arr, int i, int j);

// main function
int main(void) {

	// parsing data /////////////////////////////
	printf("Enter the length of the array: ");
	scanf("%d", &arr_length);
	arr = (int*)malloc(arr_length*sizeof(int));

	for(int i = 0;  i < arr_length; i++) {
		scanf("%d", arr + i);
	}
	/////////////////////////////////////////////

	// perform the insertion sort algorithm on the array of integers pointed to by arr
	arr = insertion_sort(arr, arr_length);

	// print the sorted array of integers pointed to by arr
	for(int i = 0; i < arr_length; i++) {
		printf((i == arr_length - 1) ? "%d\n" : "%d, ", arr[i]);
	}

	return 0;
}

// insertion_sort: performs the insertion sort algorithm to sort the array of integers pointed to by arr
int* insertion_sort(int *arr, int arr_length) {

	// assume the first cell is sorted
	for(int i = 1; i < arr_length; i++) {
		// set j equal to the index of the leftmost element in the unsorted part of the array
		int j = i;
		// while this element is smaller than the adjacent element in the sorted part of the array, swap
		while(j > 0 && arr[j - 1] > arr[j]) {
			swap(arr, j, j - 1);
			j--;
		}
	}
	return arr;
}

// swap: swaps the elements at indices i and j in the array pointed to by arr
void swap(int *arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}