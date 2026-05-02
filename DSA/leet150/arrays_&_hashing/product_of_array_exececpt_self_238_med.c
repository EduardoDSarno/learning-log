/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    int * left = calloc(numsSize, sizeof(int));
    int * right = calloc(numsSize, sizeof(int));
    int * result = calloc(numsSize, sizeof(int));

    int product_left = 1;
    int product_right = 1;

    for (int i = 0; i < numsSize; i ++){
        left[i] = product_left;
        product_left *= nums[i];
       
        right[numsSize - i - 1] = product_right;
        product_right *= nums[numsSize - i - 1];
    }

    for (int i = 0 ; i < numsSize; ++i) {
        result[i] = left[i] * right[i];
    }

    *returnSize = numsSize;
    return result;
}
