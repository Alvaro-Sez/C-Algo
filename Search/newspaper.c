#include<stdio.h>
#define TRUE 1
#define FALSE 0
/* 
    https://algo.monster/problems/newspapers_split

    Input: newspapers_read_times = [7,2,5,10,8], num_coworkers = 2
    maximo tiempo en leer los periodicos: 1 worker = sum(newspapers_read_times) // 32
    minimo tiempo en leer los periodicos: 5 workers = max(newspapers_read_times) // 10
    la solucion esta entre 10 y 32.
    - si asigno un tiempo x de lectura en el rango del min-max a cada coworker, tal que:
    tiempo_de_lectura = 11
    - y ahora compruebo si con 2 workers(A y B) podria satisfacer este tiempo:
    A :7+2
    B : 5
    la comprobacion de si n workers pueden satisfacer X tiempo seria:
    - iterar el array sumando los valores, mientras el valor resultante fuese menor que X,
    solo estariamos usando un worker, en cuanto se supere X, pasamos al siguiente worker y repetimos el proceso
 */
int validate_reading_time(int news[], int size, int workers, int readingTime){
    int acc = 0;
    int busyWorkers = 0;
    for (int i = 0; i <= size-1; i++)
    {
        if((acc + news[i]) > readingTime){
            busyWorkers++;
            acc = 0;
        }
        acc += news[i];
    }
    if(acc != 0){
        busyWorkers++;
    }
    return busyWorkers <= workers ? TRUE : FALSE;
}

int sum(int arr[], int size){
    int acc=0;
    for (int i = 0; i <= size-1; i++)
    {
        acc += arr[i];
    }
    return acc;
}
int max(int arr[], int size){
    int max = 0; // deberia usar INT_MIN
    for (int i = 0; i <= size-1; i++)
    {
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int newspaper(int news[], int size, int workers){
    int high = sum(news, size);
    int low = max(news, size);
    int result = 0;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if(validate_reading_time(news, size, workers, mid)){
            result = mid;
            high = mid-1;
        }else{
            low = mid +1;
        }
    }
    return result;
}

int main(){
    // int news[]= {7,2,5,10,8}; 
    // int news[]= {2,3,5,7};
    int news[]= {15, 15, 15, 15};
    // int news[]= {1, 1, 1, 1, 1, 1};
    // int news[]= {2873, 2837, 10, 3, 12, 34, 21, 450, 12 ,4 ,39, 1, 40, 59, 2, 67, 93, 49, 837, 499, 237, 287, 459, 12309, 9249, 94878, 30};

    
    int size = sizeof(news)/sizeof(news[0]);
    int result = newspaper(news, size, 4);
    printf("found in index: %d", result);
}