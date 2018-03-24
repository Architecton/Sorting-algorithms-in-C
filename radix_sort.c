#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// static variables
int *arr;
static int arr_length = 10;
 
// function prototypes
int *countsort(int *arr, int arr_length, int dec_place);
void print_array(int *arr, int arr_length);
int get_max(int *arr, int arr_length);
int *radixsort(int *arr, int arr_length);
 
// main function
int main() {
      // allocate memory for the array that will be sorted
    arr = (int*)malloc(arr_length*sizeof(int));
    srand(time(NULL));
    // fill the array with random numbers from [0, 9]
    // ignore preserving the distribution
    for(int i = 0; i < arr_length; i++) {
        arr[i] = rand() % 100;
    }

    // print the unsorted array
    printf("array before sorting:\n");
    print_array(arr, arr_length);
    // perform countsort algorithm on array pointed to by arr
    arr = radixsort(arr, arr_length);

    //print the sorted array
    printf("array after sorting with radixsort\n");
    print_array(arr, arr_length);

    return 0;

}

// count_sort: performs the countsort algorithm on an array of single digit integers pointed to by arr
int *countsort(int *arr, int arr_length, int dec_place) {

    // allocate memory to the array that will hold the sorted array
    int *sorted_arr = (int*)malloc(arr_length*sizeof(int));

    // create array with indices corresponding to numbers on [0,9]
    // set all elements to 0
    int count[10];
    for(int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    // count each digit at the specified decimal place in the array that is being sorted
    for(int i = 0; i < arr_length; i++) {
        count[(arr[i] % (dec_place * 10))/dec_place]++;
    }

    // compute the cumulative sums
    for(int i = 1; i < arr_length; i++) {
        count[i] += count[i - 1];
    }

    // build sorted array
    // go over initial array in reverse
    for(int i = arr_length - 1; i >= 0; i--) {
        // get last value in the array that is being sorted
        int value = (arr[i] % (dec_place*10))/dec_place;
        // the cumulative sum represents index + 1 of the current value
        int place = count[value];
        // put value in sorted array
        sorted_arr[place - 1] = arr[i];
        // subtract from cumulative count
        count[value]--;
    }    

    // free the original array and let arr point to the sorted array
    free(arr);
    arr = sorted_arr;
    return arr;
}

// The main function to that sorts arr[] of size n using 
// Radix Sort
int *radixsort(int *arr, int arr_length) {
    // Find the maximum number to know number of digits
    int max = get_max(arr, arr_length);
    // Perform countsort on incrementing digit positions
    for(int dec_place = 1; max/dec_place > 0; dec_place *= 10) {
        arr = countsort(arr, arr_length, dec_place );
    }
    return arr;
}

// get_max: returns the maximum element in the array pointed to by arr
int get_max(int *arr, int arr_length) {
    int max = arr[0];
    for (int i = 1; i < arr_length; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// print_array: prints the array of integers pointed to by arr
void print_array(int *arr, int arr_length) {
    for(int i = 0; i < arr_length; i++) {
        printf((i == arr_length - 1) ? "%d\n" : "%d ", arr[i]);
    }
}