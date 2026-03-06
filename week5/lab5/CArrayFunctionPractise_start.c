// Eduardo Sarno
// feb 5 ,2026

// The purpose of this program is to provide a way for the student to practise passing
// arrays to functions and have those functions perform some relatively simple tasks.

// You will need to fill in the missing statements that invoke the functions and the
// implementations of the 6 functions. Each function can be implemented in 4 to 7 lines
// of code {not including opening and closing braces}.

// Created by: Bob Langelaan
// Date:       June 6, 2022



#include <stddef.h>
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

#define SIZE1 10

// Function prototypes

// Search array and return the max value in the array
int arr_max(const int a[], size_t n);

// Search array and return the index of the first max value in the array
size_t arr_index_of_first_max(const int a[], size_t n);

// Search array and return the index of the last max value in the array
size_t arr_index_of_last_max(const int a[], size_t n);

// Search array and return index of first occurence of value in the array
// Return -1 if value is not in the array
int arr_index_of_value_first(const int a[], size_t n, int value);

// Search array and return index of last occurence of value in the array
// Return -1 if value is not in the array
int arr_index_of_value_last(const int a[], size_t n, int value);

// Compare 2 arrays and return true (1) if they are equal and false (0) otherwise
// You can assume that the 2 arrays are the same size
int arr_compare(const int a[], const int b[], size_t n);

int main()
{
	int arr1[SIZE1] = { 10, 20, 75, 15, 35, 12, 65, 15, 75, 55};
	int arr2[SIZE1] = { 10, 20, 75, 15, 35, 12, 65, 15, 75, 55 };
	int arr3[SIZE1] = { 10, 20, 75, 15, 100, 12, 65, 15, 75, 55 };

	size_t result = 0; // used to collect result from function returning a size_t value
	int result2 = 0;  // used to collect result from function returning an int value

	// Test arr_max() function
	result2 = arr_max(arr1, SIZE1); // I am providing the first function call, you supply the rest :)
	printf("%s%d", "The max value in the array \"arr1\" is: ", result2);

	// Test arr_index_of_first_max() function
	result = arr_index_of_first_max(arr1,SIZE1);
	printf("\n\n%s%zu", "The index of the first max value in the array \"arr1\" is: ", result);

	// Test arr_index_of_last_max() function
	size_t result3;
	result3 = arr_index_of_last_max(arr1,SIZE1);
	printf("\n\n%s%zu", "The index of the last max value in the array \"arr1\" is: ", result3);

	// Test arr_index_of_value_first() function
	int result4;
	result4 = arr_index_of_value_first(arr1,SIZE1,15);
	printf("\n\n%s%d", "The index of the first occurrence of 15 in the array \"arr1\" is: ", result4);
	
	int result5;
	result5 = arr_index_of_value_first(arr1,SIZE1,100);
	printf("\n%s%d", "The index of the first occurrence of 100 in the array \"arr1\" is: ", result5);

	// Test arr_index_of_value_last() function
	int result6;
	result6 = arr_index_of_value_last(arr1,SIZE1,15);
	printf("\n\n%s%d", "The index of the last occurrence of 15 in the array \"arr1\" is: ", result6);
	
	int result7;
	result7 = arr_index_of_value_last(arr1,SIZE1,100);
	printf("\n%s%d", "The index of the last occurrence of 100 in the array \"arr1\" is: ", result7);

	// Test arr_compare() function

	if (arr_compare(arr1, arr2, SIZE1))
	{
		printf("%s", "\n\nThe arrays \"arr1\" and \"arr2\" are equal.");
	}
	else
	{
		printf("%s", "\n\nThe arrays \"arr1\" and \"arr2\" are NOT equal.");
	}

	
	if (arr_compare(arr1, arr3, SIZE1))
	{
		printf("%s", "\nThe arrays \"arr1\" and \"arr3\" are equal.");
	}
	else
	{
		printf("%s", "\nThe arrays \"arr1\" and \"arr3\" are NOT equal.");
	}

	puts("\n");

}

// Search array and return the max value in the array
int arr_max(const int a[], size_t n)
{
	int num = 0;

	//printf("n: %lu\n", n);
	// used small or equal n becaue the '/0' does not work for ints
	for(int i = 0; i < n; i++){

		//printf("a[i] %d\n", a[i]);
		//printf("num: %d\n", num);
		if (num < a[i] ){
			num = a[i];
		}

	}
	return num;
}

// Search array and return the index of the first max value in the array
size_t arr_index_of_first_max(const int a[], size_t n)
{
	int num = 0;
	int index = 0;
	for(int i = 0; i < n; i++){

		//printf("a[i] %d\n", a[i]);
		//printf("num: %d\n", num);
		if (num < a[i] ){
			num = a[i];
			index = i;
		}

	}
	//printf("%d", index);
	return index;
}

// Search array and return the index of the last max value in the array
size_t arr_index_of_last_max(const int a[], size_t n)
{
	int num = 0;
	int index = 0;
	for(int i = 0; i < n; i++){

		// the only difference from this and the previous is the = 
		// because now if they are equal we update to the last 
		// insated of keeping the first
		if (num <= a[i] ){
			num = a[i];
			index = i;
		}

	}
	//printf("%d", index);
	return index;
}

// Search array and return index of first occurence of value in the array
// Return -1 if value is not in the array
int arr_index_of_value_first(const int a[], size_t n, int value)
{
	
	for(int i = 0; i < n; i++){
		if (a[i] == value){
			return i;
		}
	}

	return -1;
}

// Search array and return index of last occurence of value in the array
// Return -1 if value is not in the array
int arr_index_of_value_last(const int a[], size_t n, int value)
{
	int index = 0;
	// with the loop we grab the index of the last accurance
	for(int i = 0; i < n; i++)
	{
		if (a[i] == value){
			index = i;
		}
	}
	if (index == 0){
		return -1;
	}
	return index;
}

// Compare 2 arrays and return true if they are equal (1) and false (0) otherwise
// You can assume that the 2 arrays are the same size
int arr_compare(const int a[], const int b[], size_t n)
{
	// here we just compare char by char if they are equal
	//continue the loop otherwise the array is not equal
	for(int i = 0; i < n; i++){
		if(a[i] == b[i])
		{
			continue;
		}
		else {
			return 0;
		}

	}
	return 1;
}



