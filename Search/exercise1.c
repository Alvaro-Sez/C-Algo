//exercise from https://algo.monster/problems/binary_search_boundary
// Find the First True in a Sorted Boolean Array of the right section
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void first_true(int nums[], int low, int high){
    int foundIn = 0;
    while(low <= high){
       int mid = low + (high-low)/2;

        if(nums[mid] == TRUE){
            high = mid - 1;
            foundIn = mid;
        }
        else{
            low = mid + 1;
        }
    }
    printf("found in index:%d", foundIn);
}
//https://algo.monster/problems/binary_search_first_element_not_smaller_than_target
/* Given an array of integers sorted in increasing order and a target,
 find the index of the first element in the array that is larger than or equal to the target.
 Assume that it is guaranteed to find a satisfying number. */
void first_not_smaller(int nums[], int low, int high, int target){
    int foundIn = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] >= target){
            foundIn = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    printf("found in index:%d", foundIn);
}
/* 
Given a sorted array of integers and a target integer, find the first occurrence of the target and return its index. Return -1 if the target is not in the array.
Input:
arr = [1, 3, 3, 3, 3, 6, 10, 10, 10, 100]
target = 3 */
int first_occurrence(int nums[], int low, int high, int target){
    int result;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(nums[mid] >= target){
            result = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return nums[result]== target? result: -1;
}
/* 
Given an integer, find its square root without using the built-in square root function.
Only return the integer part (truncate the decimals).
Input: 16
Output: 4 
*/

int sqrt2(int n){
    int result = 0;
    int low = 1;
    int high = (n+1)/2;
    while(low <= high){
        int mid = low + (high - low)/2;
        if((mid*mid) == n){
            return mid;
        }
        if((mid*mid) < n){
            result = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return result;
}
/* 
A mountain array is defined as an array that

has at least 3 elements
has an element with the largest value called "peak", with index k. The array elements strictly increase from the first element to A[k], 
and then strictly decreases from A[k + 1] to the last element of the array. Thus creating a "mountain" of numbers.
That is, given A[0]<...<A[k-1]<A[k]>A[k+1]>...>A[n-1], we need to find the index k. 
Note that the peak element is neither the first nor the last element of the array.

Find the index of the peak element. Assume there is only one peak element.

Input: 0 1 2 3 2 1 0

Output: 3
 */
int peak(int arr[], int high){
    int result = 0;
    int low = 0;
    
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid-1]<arr[mid]){
            result = mid;
            low = mid +1;
        }
        else{
            high = mid-1;
        }
    }
    return result;
}
/* 
    Given a sorted array of distinct integers and a target value, return the index if the target is found.
    If not, return the index where it would be if it were inserted in order.
    Example 1:

    Input: nums = [1,3,5,6], target = 5
    Output: 2
    Example 2:

    Input: nums = [1,3,5,6], target = 2
    Output: 1
    Example 3:

    Input: nums = [1,3,5,6], target = 7
    Output: 4
*/
int searchInsert(int nums[], int numsSize, int target) {
    int low, high, mid, result;
    low = 0;
    high = numsSize-1;
    
    while(low <= high){
        mid = low + (high-low)/2;
        if(nums[mid]>=target){
            result = mid;
            high = mid -1;
        }else{
            result = mid+1;
            low = mid +1;
        }
    }
    return result;
}
/*
 Given an array nums containing n distinct numbers in the range [0, n],
 return the only number in the range that is missing from the array.
    Example 1:
    Input: nums = [3,0,1]
    Output: 2

    Example 2:
    Input: nums = [0,1]
    Output: 2

    Example 3:
    Input: nums = [9,6,4,2,3,5,7,0,1]
    Output: 8
*/

int missingNumber(int* nums, int numsSize) {
    int* arr = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i <= numsSize-1; i++) {
            arr[i] = 0;
    }
    for (int i = 0; i <= numsSize-1; i++) {
            arr[nums[i]]= 1;
    }
    for (int i = 0; i <= numsSize-1; i++) {
        if(arr[i]==0){
            return i;
        }
    }   
}

/* 
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order,
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

    Example 1:

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
    Example 2:

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
    Example 3:

    Input: nums = [], target = 0
    Output: [-1,-1] */
int* searchRange(int* nums, int numsSize, int target/* , int* returnSize */) {
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;
    int low = 0;
    int high = numsSize-1;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid] > target){
            high = mid-1;
        }
        if(nums[mid] == target){
            result[0] = mid;
            high = mid-1;
        }else if(nums[mid] < target){
            low = mid+1;
        }
    }
    low = 0;
    high = numsSize-1;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid] < target){
            low = mid+1;
        }
        if(nums[mid] == target){
            result[1] = mid;
            low = mid+1;
        }else if(nums[mid] > target){
            high = mid-1;
        }

    }
    return result;
}

int main(){
    // int arr1[]= {FALSE, FALSE,FALSE, FALSE,FALSE, FALSE,FALSE, FALSE,FALSE, FALSE, TRUE};
    // int arr3[]= {2, 3, 5, 7, 11, 13, 17, 19};
    // int arr4[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,56, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int arr[] = {1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int* result = searchRange(arr, size, 0);
    printf("found in index: %d, and %d", *result, *(result+1));
}