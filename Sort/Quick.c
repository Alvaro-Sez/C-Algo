#include<stdio.h>


void quick_sort(int arr[], int size){
    int i = 1;
    int j = size-1;
    int pivot = arr[0];
    while (i<=j)
    {
        if(arr[i] <= pivot){
            i++;
        }else if(arr[j] >= pivot){
            j--;
        } else {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[0];
    arr[0] = arr[j];
    arr[j] = t;

    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
}

int main()
{
    // int input[]= {3,1,8,17,33,0,5,132,96,4,80,31,68,26,3,78,9,3,4,6,645,23,11,19,90};
    int a[]= {6,2,7,1};
    int size = sizeof(a)/sizeof(a[0]);
    quick_sort(a, size);
}
