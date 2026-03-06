#include <stdio.h>
int hammingWeight(int n) 
{
    // start the count of the ones
    int count = 0;

    int bits_size = sizeof(n) * 8; // gettign the size in bits
    //printf("%d\n", bits_size);
    
    for (int i = 0 ; i < bits_size - 1 ; i++)
    {
        if (n& 1) // check the bit to the most right is equal 1
        {
            count++; // add if it is
        }
        n>>= 1; // move the whole value to the right to check the next bit


    }
    //printf("%d", count);
    return count;

}