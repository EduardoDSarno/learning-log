#include <stddef.h>
#include <stdio.h>
//[1,8,6,2,5,4,8,3,7]
// 49


int maxArea(int* height, int heightSize);

int main(void){
    int something[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(something) / 4; // 4 bytes each
    printf("%d\n", size);
    printf("%d",maxArea(something, size)); 
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;

    int prev_area = 0;
    // whilte TODO
    // we comapre which (start or end) is bigger
    // whatever one is we move closer to the center
    while (left < right) {
        // h will be the smaller height
        int h = (height[left] < height[right]) ? height[left] : height[right];

        int w = right - left;

        int area = h * w;

        if(area > prev_area){
            prev_area = area;
        }

        if(height[left] < height[right]) 
        {
            left++;
        }
        else {
            right--;
        }

    }

    return prev_area;


}