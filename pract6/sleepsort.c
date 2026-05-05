#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SIZE 50 

void* sleep_sort(void* arg) {
    int number = *(int*)arg;
    usleep(number * 1000000);
    printf("%d ", number);
    fflush(stdout);
    return NULL;
}

int main() {
    int arr[SIZE];
    pthread_t threads[SIZE];
    srand(time(NULL));
    
    printf("Исходный массив:\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 20 + 1;  
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    for (int i = 0; i < SIZE; i++) {
        pthread_create(&threads[i], NULL, sleep_sort, &arr[i]);
    }
    printf("\n\nОтсортированный массив:\n");
    
    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}