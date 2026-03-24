// gcc -o test test.c && ./test
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    *returnSize = 2;
    int * return_array = malloc(sizeof(int) * *returnSize);

    for (int i = 0; i < numbersSize; ++i) 
    {
    
      int second_target = 0;
      second_target = target - numbers[i];
      return_array[0] = i + 1; // result 1
      
      //printf("first num %d\n", i);

      int high = numbersSize - 1;
      int low = i + 1; // so we ignore the seen indexes

      while (low <= high) {
        int mid = low + (high - low) / 2; // to avoud overflow

        if (numbers[mid] == second_target) 
        {
          
          return_array[1] = mid + 1; // result 2
          return return_array;
          //printf(" mid %d\n", mid  + 1);
        }
        else if (numbers[mid] < second_target) {
          low = mid + 1;
        }
        else {
          high = mid - 1;
        }
          
      } 
    }
    return return_array;
}

// int main(void) {
//     int numbers[] = {2,7,11,15};
//     int target = 9;
//     int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
//     int returnSize;

//     int *result = twoSum(numbers, numbersSize, target, &returnSize);

//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     free(result);
//     return 0;
// }

int main(void){

  char  firsts[] = "";

  scanf("%s", firsts);

  printf("%s",firsts);


}