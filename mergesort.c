#include<stdlib.h>
#include<stdio.h>

// static variables
int *arr;
int arr_length;

// function prototypes
void print_arr(int *arr, int left, int right);
void merge(int *arr, int left, int m, int right);
void mergesort(int *arr, int left, int right);

// main function
int main() {
    // parsing data ///////////////////////////
    scanf("%d", &arr_length);
    arr = (int*)malloc(arr_length*sizeof(int));
    for(int i = 0; i < arr_length; i++) {
        scanf("%d", arr + i);
    }
    ///////////////////////////////////////////

    // perform the mergesort algorithm on the array pointed to by arr
    mergesort(arr, 0, arr_length - 1);
    
    // print the sorted array 
    print_arr(arr, 0, arr_length - 1);

    return 0;
}

// merge: merges two subarrays of arr
// the first subarray is arr[left..m]
// the second subarray is arr[m + 1..right]
void merge(int *arr, int left, int m, int right) {
    // define indices
    int i, j, k;
    // subarray_l_length := size of the first subarray
    int subarray_l_length = m - left + 1;
    // subarray_r_length := size of the second subarray
    int subarray_r_length =  right - m;
 
    // create temp arrays with lengths subarray_l_length and subarray_r_length
    int L[subarray_l_length], R[subarray_r_length];
 
    // copy the subarrays into respective temp arrays
    for(int i = 0; i < subarray_l_length; i++) {
        L[i] = arr[left + i];
    }
    for(int i = 0; i < subarray_r_length; i++) {
        R[i] = arr[m + 1 + i];
    }
 
    // i is the starting index of the first subarray
    i = 0;
    // j is the starting index of the second subarray
    j = 0;
    // k is the starting index of the merged subarray
    k = left;

    // while neither of the subarray indices has reached the respective subarray length
    while (i < subarray_l_length && j < subarray_r_length) {
        // compare values in the temp subarrays and merge into the main array
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        // increment the index of the main array that is being merged into
        k++;
    }
 
    // copy the remainder of elements from L to the main array (if it exists)
    while (i < subarray_l_length) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // copy the remainder of elements from L to the main array (if it exists)
    while (j < subarray_r_length) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// mergesort: sorts the values in the array pointed to by arr using the mergesort algorithm
void mergesort(int *arr, int left, int right) {
    if(left < right) {
        
        // compute the middle index
        int m = left + (right - left)/2;

        // recursive call for the left and right subarrays
        mergesort(arr, left, m);
        mergesort(arr, m + 1, right);
 
        // merge the two subarrays
        merge(arr, left, m, right);
    }
}

// print_arr: prints the values in the array pointed to by arr from index left to index right
void print_arr(int *arr, int left, int right) {
    for(int i = left; i <= right; i++) {
        printf((i == right) ? "%d\n" : "%d, ", arr[i]);
    }
}