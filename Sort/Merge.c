#include<stdio.h>
#include<stdlib.h>

int* merge(int low_arr[], int high_arr[], int size_low, int size_high){
    int size_result = size_low + size_high;
    int* result = (int*)malloc(size_result * sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < size_low && j < size_high){
        if(low_arr[i]<high_arr[j]){
            result[k] = low_arr[i];
            i++;
            k++;
        }else{
            result[k] = high_arr[j];
            j++;
            k++;
        }
    }
    while(i < size_low){
        result[k] =  low_arr[i];
        i++;
        k++;
    }
    while(j < size_high){
        result[k] =  high_arr[j];
        j++;
        k++;
    }
    return result;
}

int* merge_sort(int arr[], int size){
    int mid = size/2;
    if(size == 1){
        int* result = (int*)malloc(sizeof(int));
        result[0] = arr[0];
        return result;
    }
    int* low_arr = (int*)malloc(mid * sizeof(int));
    int* high_arr = (int*)malloc((size-mid) * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        if(i < mid){
            low_arr[i] = arr[i];
        }else{
            high_arr[i-mid] = arr[i];
        }
    }
    int* l = merge_sort(low_arr, mid);
    int* h = merge_sort(high_arr, size-mid);
    int* r = merge(l, h, mid, size-mid);
    free(l);
    free(h);
    return r;
}

void printArray(int arr[], int size){
for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}

void main(){
    int a[]= {6,1,3,9,0,2};
    int size_a = sizeof(a)/sizeof(a[0]);
    int* result = merge_sort(a, size_a);
    printArray(result, size_a);
    free(result);
}
