// C Program for counting sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// static variables
char *arr;
static int arr_length = 10;
 
// function prototypes
char *count_sort(char *arr, int arr_length);
void print_array(char *arr, int arr_length);
 
// main function
int main() {
      // allocate memory for the array that will be sorted
    arr = (char*)malloc(arr_length*sizeof(short));
    srand(time(NULL));
    // fill the array with random numbers from [0, 9]
    // ignore preserving the distribution
    for(int i = 0; i < arr_length; i++) {
        arr[i] = rand() % 10;
    }

    // print the unsorted array
    printf("array before sorting:\n");
    print_array(arr, arr_length);

    // perform countsort algorithm on array pointed to by arr
    arr = count_sort(arr, arr_length);

    //print the sorted array
    printf("array after sorting with countsort\n");
    print_array(arr, arr_length);

    return 0;

}

// count_sort: performs the countsort algorithm on an array of single digit integers pointed to by arr
char *count_sort(char *arr, int arr_length) {
    // allocate memory to the array that will hold the sorted array
    char *sorted_arr = (char*)malloc(arr_length*sizeof(char));

    // create array with indices corresponding to numbers on [0,9]
    int count[10];
    for(int i = 0; i < 10; i++) {
        count[i] = 0;
    }
    // count each number in the array that is being sorted
    for(int i = 0; i < arr_length; i++) {
        count[arr[i]]++;
    }

    // compute the cumulative sums
    for(int i = 1; i < arr_length; i++) {
        count[i] += count[i - 1];
    }

    // build sorted array
    // go over initial array in reverse
    for(int i = arr_length - 1; i >= 0; i--) {
        // get last value in the array that is being sorted
        char value = arr[i];
        // the cumulative sum represents index + 1 of the current value
        char place = count[value];
        // put value in sorted array
        sorted_arr[place - 1] = value;
        // subtract from cumulative count
        count[value]--;
    }
    
    // free the original array and let arr point to the sorted array
    free(arr);
    arr = sorted_arr;
    return arr;
}

void print_array(char *arr, int arr_length) {
    for(int i = 0; i < arr_length; i++) {
        printf((i == arr_length - 1) ? "%d\n" : "%d ", arr[i]);
    }
}