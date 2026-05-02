/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    *returnSize = 2;
    int * return_array = malloc(sizeof(int) * 2);
    int my_result = 0;
    int k = 0;

    while (target != my_result) {
        
        // try with first num in array
        if (numbers[k] < target) {
            my_result += numbers[k];
            return_array[0] = k + 1;
        }

        int new_target = target - my_result;
        int low = 0;
        int high = numbersSize - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (numbers[mid] == new_target) {
                return_array[1] = mid + 1;
            }
            else if (numbers[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }

        }
        my_result = 0;
        
    }
         return return_array;
}
        
