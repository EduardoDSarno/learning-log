/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* replaceElements(int* arr, int arrSize, int* returnSize) {

    int *array_result = malloc(arrSize * sizeof(int));
    *returnSize = arrSize;

    int max_right = arr[arrSize - 1];
    int current = 0;
   //printf("%d\n", arrSize);

    // right to left
    for (int i = arrSize - 1; i >= 0; i--) {

        // if element to the right
        if(i != arrSize -1){
            // you become max_right
            current = arr[i];
            array_result[i] = max_right;

           // printf("current %d\n", current);
            //printf("max_r %d\n", max_right);
            if(max_right < current){
                //printf("here\n");
                //printf("array[i] %d\n", arr[i]);
                max_right = current;
            }
            
        }
        else 
        {
            array_result[i] = -1;
        }
    }

    // for (int i = 0; i < arrSize; i++) {
    //     printf("%d", arr[i]);
    // }

    return array_result;
}
