#include <stdio.h>
#include <stdlib.h>

// static variables
static int *arr;
static int arr_length;

// function prototypes
void swap(int *arr, int index_1, int index_2);
int partition(int* arr, int left, int right, int pivot);
void quickSort(int *arr, int left, int right);

// main function
int main(void) {

   // parsing data about the array ///////////7
   scanf("%d", &arr_length);
   arr = (int*)malloc(arr_length*sizeof(int));
   for(int i = 0; i < arr_length; i++) {
      scanf("%d", arr + i);
   }
   ////////////////////////////////////////////

   // perform the quicksort algorithm on the array pointed to by arr
   quickSort(arr, 0, arr_length - 1);

   // print the resulting array
   for(int i = 0; i < arr_length; i++) {
      printf((i == arr_length - 1) ? "%d\n" : "%d, ", arr[i]);
   }
}

// swap: swaps the elements with indices index_1 and index_2 in the array pointed to by arr
void swap(int *arr, int index_1, int index_2) {
   int temp = arr[index_1];
   arr[index_1] = arr[index_2];
   arr[index_2] = temp;
}

// partition: auxilliary function that computes the next fully sorted element and returns its position
int partition(int* arr, int left, int right, int pivot) {
   // left pointer starts at base value left - 1 (necessary for the use of the incrementation operator in the following lines)
   int left_ptr = left - 1;

   // left pointer starts at base value right (necessary for the use of the decrementation operator in the following lines)
   int right_ptr = right;

   // move pointers in opposite directions until they collide or overtake eachother
   while(1) {
      while(arr[++left_ptr] < pivot) {
         // move left pointer to the first value that is larger or equal to the pivot
      }
        
      while(right_ptr > 0 && arr[--right_ptr] > pivot && right_ptr > left_ptr) {
         // move right pointer to the first value that is smaller than the pivot
      }

      // if the left pointer collided or overtook the right pointer, break loop
      if(left_ptr >= right_ptr) {
         break;
      } else {
         
         // swap the elements pointed to by left_ptr and right_ptr
         swap(arr, left_ptr, right_ptr);
      }
   }

   // when both pointers stop moving 
   // (are in the same position or left pointer and pivot are in the same position), 
   // that value is swapped with the pivot value which is pointed to by right
   swap(arr, left_ptr, right);

   // the value that is pointed to by the two pointers or by the left pointer and the pivot
   // is considered fully sorted - use it as partitioning point
   return left_ptr;
}

// quicksort: performs the quicksort algorithm on the array of integers pointed to by arr
void quickSort(int *arr, int left, int right) {

   // if right is smaller or equal to left, return
   if(right - left > 0) {
      // pick the rightmost element in the array as the pivot value
      int pivot = arr[right];

      // compute the next fully sorted element and return its index
      int partition_point = partition(arr, left, right, pivot);

      // recursive call for left partition
      quickSort(arr, left, partition_point - 1);

      // recursive call for right partition
      quickSort(arr, partition_point + 1, right);
   }
}
