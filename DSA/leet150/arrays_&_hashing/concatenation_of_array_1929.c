/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int length = numsSize * 2; // 2n length
    int *answer = malloc(length * sizeof(int));

    *returnSize = length;

    for (int i = 0; i < numsSize; i++){
        // printf("i: %d\n", i);
        // printf("answer: %d\n", nums[i]);
        answer[i] = nums[i];
        answer[i + numsSize] = nums[i];
    }

    free(answer);
    return answer;
}