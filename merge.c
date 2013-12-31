#include <stdio.h>
#include <stdlib.h>

/**********************************
 * This is a simple recursive
 * implementation of a merge
 * sort. The function merge_sort
 * splits the array into left
 * and right. It then recursivley
 * calls itself on left and right
 * until each list is lenght 1
 * (sorted). It then calls merge
 * to sort the two arrays, and 
 * works its way back up the
 * recursions.
 **********************************/

int* merge_sort(int*, int);
int* merge(int*, int, int*, int);

/***********************************
 * mallocs two arrays, each half
 * the size of the original, and 
 * packs half of the array into 
 * each of them.  Then calls 
 * itself until the list is of
 * length 1. It then calls merge.
 ***********************************/
int* merge_sort(int* array, int len) {
	int i;
	int pivot = len / 2;
	int* left;
	int* right;

	if (len <= 1)
		return(array);

	left = malloc(sizeof(int) * pivot);
	right = malloc(sizeof(int) * (len - pivot));

	/*left*/
	for (i = 0; i < pivot; i++) {
		left[i] = array[i];
	}

	/*right*/
	for (i = pivot; i < len; i++) {
		right[i - pivot] = array[i];
	}

	left = merge_sort(left, pivot);
	right = merge_sort(right, (len - pivot));

	return(merge(left, pivot, right, (len - pivot)));
	free(left);
	free(right);
}

/***************************************
 * mallocs a new array the same size as
 * the original. It then makes pointers
 * to the beginning of left, right, and
 * result. It then sorts the two arrays
 * back together into result by moving
 * pointers along the arrays, and 
 * comparing what they point to.
 ***************************************/
int* merge(int* left, int len_left, int* right, int len_right) {
	int* result;
	int* result_i;
	int* left_i;
	int* right_i;

	result = malloc(sizeof(int) * (len_left + len_right));
	result_i = result;

	left_i = left;
	right_i = right;

	while (len_left > 0 || len_right > 0) {
		/*both*/
		if (len_left > 0 && len_right > 0) {
			if (*left_i <= *right_i) {
				*result_i = *left_i;
				left_i++;
				result_i++;
				--len_left; 
			}

			else {
				*result_i = *right_i;
				right_i++;
				result_i++;
				--len_right;
			}
		}

		/*left*/
		else if (len_left > 0) {
			*result_i = *left_i;
			left_i++;
			result_i++;
			--len_left;
		}

		/*right*/
		else if (len_right > 0) {
			*result_i = *right_i;
			right_i++;
			result_i++;
			--len_right;
		}
	}

	return(result);
}
