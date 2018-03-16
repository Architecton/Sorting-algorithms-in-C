#include <stdio.h>
#include <stdlib.h>

// static variables
int *arr;
int arr_length;

// function prototypes
int *bubble_sort(int *arr, int arr_length);
void swap(int *arr, int index_1, int index_2);

// main method
int main(void) {

	// parsing data ///////////////////////////////
	printf("Enter the length of the array:");
	scanf("%d", &arr_length);
	arr = (int*)malloc(arr_length*sizeof(int));
	printf("Enter the elements of the array:");
	for(int i = 0; i < arr_length; i++) {
		scanf("%d", arr + i);
	}
	///////////////////////////////////////////////

	// performing the bubble sort algorith on the array pointed to by arr
	arr = bubble_sort(arr, arr_length);

	// printing the sorted array
	for(int i = 0; i < arr_length; i++) {
		printf((i == arr_length - 1) ? "%d\n" : "%d, ", arr[i]);
	}

	return 0;
}

// bubble_sort: performs the bubble sort sorting algorithm on the array of integers pointed to by arr
int *bubble_sort(int *arr, int arr_length) {
	int swapped = 1;
	while(swapped) {
		swapped = 0;
		for(int i = 0; i < arr_length - 1; i++) {
			if(arr[i] > arr[i + 1]) {
				swap(arr, i, i + 1);
				swapped = 1;
			}
		}
	}
	return arr;
}

// swap: swaps the elements at indices index_1 and index_2 in the array of integers pointed to by arr
void swap(int *arr, int index_1, int index_2) {
	int temp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = temp;
}