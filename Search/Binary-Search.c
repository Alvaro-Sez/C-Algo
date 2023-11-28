#include <stdio.h>

void binarySearch_iterative(int nums[], int low, int high, int target){
    while (low <= high)
    {
        int mid = low + (high - low)/2; 

        if(nums[mid] == target){
            printf("valor medio encontrado en indice: %d", mid);
            return;
        }
        if(nums[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        } 
    }
}

void binarySearch_recursive(int nums[], int low, int high, int target){
    int count = 0;
    int mid = low + (high - low)/2; 
    if(nums[mid] == target){
        printf("valor medio encontrado en indice: %d", mid);
        return;
    }
    if(nums[mid] < target){
        binarySearch_recursive(nums, low+1, high, target);
    }else{
        binarySearch_recursive(nums, low, high-1, target);
    }
    return;
}


void main() {
    /* given a sorted array */
    int arr[]  = {1, 6, 7, 10, 10, 28, 34, 53, 65, 79, 81, 99, 127, 148, 231, 301};
    int length = sizeof(arr)/sizeof(arr[0]);
    binarySearch_recursive(arr, 0, length - 1, 301);
}
