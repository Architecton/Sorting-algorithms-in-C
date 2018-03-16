// A C implementation of the heapsort sorting algorithm
#include <stdio.h>
#include <stdlib.h>

// static variables
static int arr_length;
static int *arr;

// function prototypes
void swap(int *arr, int index_1, int index_2);
void heapify(int *arr, int arr_length, int i);
void heapsort(int *arr, int arr_length);
void print_arr(int *arr, int arr_length);
 
// main function
int main() {

    // parsing data about the array //////////////////
    scanf("%d", &arr_length);
    arr = malloc(arr_length*sizeof(int));
    for(int i = 0; i < arr_length; i++) {
        scanf("%d", arr + i);
    }
    ///////////////////////////////////////////////////

    // performing the heap sort sorting algorithm on the array pointed to by arr
    heapsort(arr, arr_length);
 
    // printing the sorted array
    print_arr(arr, arr_length);

    return 0;
}

// print_array: prints the array pointed to by arr
void print_arr(int *arr, int arr_length) {
    for(int i = 0; i < arr_length; i++) {
        printf((i == arr_length - 1) ? "%d\n" : "%d, ", arr[i]);
    }
}

// heap_sort: performs the heap sort sorting algorithm on the array of integers pointed to by arr
void heapsort(int *arr, int arr_length) {
    // build an array representation of a max heap of the values in the array
    // start from index at arr_length/2 - 1
    for(int i = arr_length/2 - 1; i >= 0; i--) {
        heapify(arr, arr_length, i);
    }
 
    // one by one extract elements from heap
    for(int i = arr_length - 1; i >= 0; i--) {
        // Move current root of the heap to the end of the array
        // (root of the heap is at 0)
        swap(arr, 0, i);
 
        // call the max heapify algorithm on the reduced heap
        // heapify the array  of unsorted values from 0 to i (which runs from the tail to the front)
        heapify(arr, i, 0);
    }
}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int *arr, int subarr_length, int root) {
	// assume largest is root
    int largest = root;
    //computing the left child
    // left = 2*i + 1
    int left = 2*root + 1;
    // computing the right child
    // right = 2*i + 2
    int right = 2*root + 2;
    
    // formula for parent:
    // parent = (index - 1)/2;
 
    // If left child is larger than the current largest (root)
    if(left < subarr_length && arr[left] > arr[largest]) {
        largest = left;
    }
 
    // If right child of the current largest is larger than the current largest
    if(right < subarr_length && arr[right] > arr[largest]) {
        largest = right;
    }
 
    // If largest is not root
    if(largest != root) {
        // swap elements at i and largest, so that the largest element
        // is pointed to by index i
        swap(arr, root, largest);
 
        // Recursively heapify the affected sub-tree
        // (from largest to the end)
        heapify(arr, subarr_length, largest);
    }
}

// swap: swaps the elements at indices index_1, index_2 in the array pointed to by arr
void swap(int *arr, int index_1, int index_2) {
	int temp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = temp;
}