// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

// Example 1:

// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2 
// Since 2 has only one digit, return it.
// Example 2:

// Input: num = 0
// Output: 0


int addDigits(int num) 
{
    while (num >= 10) // while the number < 10. Meaning it has 2 digits
    {
        int sum = 0;

        while (num > 0) // while num is bigger than 0 because we will be divign (cutting the last digit unitl)
        {
            sum += num % 10; // we add the last digit to sum
            num /= 10; // remove last digits from num
        }

        num = sum;


    }

    return num;
}