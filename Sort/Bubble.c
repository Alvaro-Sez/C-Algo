#include<stdio.h>

int* bubble_sort(int* arr, int size){
    for (int i = size-1; i >= 0 ; i--)
    {
        int swapped = 0;
        for (int j = 0; j < i; j++)
        {
            if(arr[j]>arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                swapped = 1;
            }
        }
        if(swapped == 0){
            return arr;
        }
    }
    return arr;
}

void main(){
    int a[]= {7,84,12,0,154,5,3,1,2,4,9,12,22,6,23};
    int size = sizeof(a)/sizeof(a[0]);
    // int* result = insertion_sort(a, size);
    int* result = bubble_sort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",result[i]);
    }
}