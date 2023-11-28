#include<stdio.h>

int* insertion_sort(int* arr, int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j > 0; j--)
        {
            if(arr[j-1] > arr[j]){
                int t = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = t;
            }
        }
    }
    return arr;
}

#define INFINITY 1000
int* selection_sort(int* arr, int size){
    for (int i = 0; i < size - 1; i++)
    {
        int min = INFINITY;
        int min_index = -1;
        int t;
        for (int j = i; j < size ; j++)
        {
            if(arr[j]<min){
                min = arr[j];
                min_index = j;
            }
        }
        t = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = t;
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

