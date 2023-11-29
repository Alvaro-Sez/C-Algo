#include<stdio.h>
#include<stdlib.h>


int* quick_sort(int arr[], int size){
    int i = 1;
    int j = size-1;
    int pivot = arr[0];

    if(size == 1){
            int* result = (int*)malloc(sizeof(int));
            result[0] = arr[0];
            return result;
    }

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
    
    arr[0] = arr[j];
    arr[j] = pivot;
    
    int* arr_left = NULL;
    int* arr_right = NULL;
    
    if(j != 0){
        arr_left = (int*)malloc(j * sizeof(arr[0]));
    }
    if(size-(j+1) != 0){
        arr_right = (int*)malloc((size-(j+1)) * sizeof(arr[0]));
    }
    
    for (int i = 0; i < size; i++)
    {
        if(i<j){
            arr_left[i] = arr[i];
        }
        if(i>j){
            arr_right[i-(j+1)] = arr[i];
        }
    }
    
    int* result_left = NULL;
    int* result_right = NULL;
    
    if(arr_left != NULL){
        result_left = quick_sort(arr_left, j);
        free(arr_left);
    }
    if(arr_right != NULL){
        result_right = quick_sort(arr_right, size-(j+1));
        free(arr_right);
    }

    int* result = (int*)malloc(size * sizeof(arr[0]));

    for (int i = 0; i < size; i++)
    {
        if(i<j && result_left != NULL){
            result[i] = result_left[i];
        }else if(i == j){
            result[i] = pivot;
        }else if(i>j && result_right != NULL){
            result[i] = result_right[i-(j+1)];
        }
    }
    if( result_left !=NULL){
        free(result_left);
    }
    if( result_right !=NULL){
        free(result_right);
    }
    return result;
}

int main()
{
    int a[]= {3,1,8,17,33,0,5,132,96,4,80,31,68,26,3,78,9,3,4,6,645,23,11,19,90};
    // int a[]= {6,2,7,11,0,5,3,1};
    int size = sizeof(a)/sizeof(a[0]);
    int* result = quick_sort(a, size);
    for (int i = 0; i < size; i++)
    {
        printf(" %d", result[i]);
    }
}
