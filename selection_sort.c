#include <stdio.h>
#include <stdlib.h>

// static variables
int *arr;
int arr_length;

// function prototypes
int* selection_sort(int *arr, int arr_length);
void swap(int* arr, int i, int j);

// main function
int main(void) {
	// entering data //////////////////////////////

	printf("Enter the size of the array: ");
	scanf("%d", &arr_length);
	arr = (int*)malloc(arr_length*sizeof(int));
	printf("Enter the array values: ");

	for(int i = 0; i < arr_length; i++) {
		scanf("%d", arr + i);
	}
	///////////////////////////////////////////////

	// applying the insertion sort algorithm on the array
	arr = selection_sort(arr, arr_length);

	// printing the sorted array
	for(int i = 0; i < arr_length; i++){
		printf((i == arr_length - 1) ? "%d\n" : "%d, ", arr[i]);
	}

	return 0;
}


// insertion_sort: performs the insertion sort algorithm on the array pointed to by arr
int* selection_sort(int *arr, int arr_length) {

	// the outer loop - is at the boundary of the sorted and unsorted part of the array
	// the cells with indices < i are sorted
	for(int i = 0; i < arr_length - 1; i++) {

		// assume the minimum value is at index i
		int min_value = arr[i];
		int index_min = i;

		// go over the unsorted part of the array and find the minimum value
		for(int j = i + 1; j < arr_length; j++) {
			if(arr[j] < min_value) {
				min_value = arr[j];
				index_min = j;
			}
		}
		// if minimum value was found above i
		if(index_min != i) {
			// swap
			swap(arr, i, index_min);
		}
	}
	return arr;
}

// swap: swaps the elements at indices i and j in the array pointed to ny arr
void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}