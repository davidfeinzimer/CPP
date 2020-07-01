/*
 * mergesort.cpp
 * Implementation of a bitonic mergesort
 */

#include <iostream>
using namespace std;

/* printArray(input, size)
   Print the passed array.
*/
void printArray(int * input, int size) {
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}

/* merge(input, size, output, asc)
   Merge the two halves of the array input (which has size elements) into
   output. If asc is true, then the output array should be in ascending order;
   otherwise it should be descending.
*/
void merge(int* input, int size, int* output, bool output_asc) {
    // Your merge implementation goes here
    cout << endl << "merge() asc:" << output_asc << " input: "; printArray(input, size);


    // if (output_asc == true) {
    //     for (int i = 0; i < size; i++) {
    //         output[i] = input[i];
    //     }
    // } else {
    //     int j = 0;
    //     for (int i = size - 1; i > -1; i--) {
    //         output[j] = input[i];
    //         j++;
    //     }
    // }


    // if (output_asc == true) {
    //     int j = size - 1;
    //     int mid = size / 2;
    //     for (int i = 0; i < mid; i++) {
    //         output[i] = input[i];
    //         output[j] = input[j];
    //         j--;
    //     }
    // } else {
    //     int mid = size / 2;
    //     int j = mid;
    //     for (int i = 0; i < mid; i++) {
    //         output[i] = input[i];
    //         output[j] = input[j];
    //         j++;
    //     }
    // }


    // if (output_asc == true) {
    //     int x = 0;
    //     int y = size - 1;
    //     int mid = size / 2;
    //     int pos = 0;
    //     while (x < mid && y >= mid) {
    //         if (input[x] <= input[y]) {
    //             output[pos] = input[x];
    //             x++;
    //         } else {
    //             output[pos] = input[y];
    //             y--;
    //         }
    //         pos++;
    //     }
    //     if (x < mid) {
    //         while (x < mid) {
    //             output[pos] = x;
    //             pos++;
    //             x++;
    //         }
    //     } else if (y >= mid) {
    //         while (y >= mid) {
    //             output[pos] = input[y];
    //             pos++;
    //             y--;
    //         }
    //     }
    // } else {
    //     int mid = size / 2;
    //     int x = mid-1;
    //     int y = mid;
    //     int pos = 0;
    //     while (x > 0 && y < size) {
    //         if (input[x] >= input[y]) {
    //             output[pos] = input[x];
    //             x--;
    //         } else {
    //             output[pos] = input[y];
    //             y++;
    //         }
    //         pos++;
    //     }
    //     if (x > 0) {
    //         while (x > 0) {
    //             output[pos] = x;
    //             pos++;
    //             x--;
    //         }
    //     } else if (y < size) {
    //         while (y < size) {
    //             output[pos] = input[y];
    //             pos++;
    //             y++;
    //         }
    //     }
    // }


    cout << "merge() output: "; printArray(output, size);
}

/* mergesort(input, size, output, asc)
   Mergesort the input array (with size elements) into the output array. If
   asc is true, the output array should be sorted ascending, otherwise it should
   be descending.
*/
void mergesort(int *input, int size, int* output, bool output_asc) {
    // Your mergesort implementation goes here
    cout << endl << "mergesort() asc:" << output_asc << " input: "; printArray(input, size);
}

/* mergesort(input, size)
   Sorts size elements in the array pointed to by input, using the MergeSort
   algorithm. Output is returned as a newly allocated array, which the caller
   is responsible for freeing.
*/
int* mergesort(int* input, int size) {
    int* output = new int[size];
    mergesort(input, size, output, true);
    return output;
}
