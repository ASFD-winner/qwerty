#include <stdio.h>
// комментарий по заданию
// комментарий по заданию 2  
// комментарий по заданию 3

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    
    printf("Исходный массив: \n");
    printArray(a, n);

    bubbleSort(a, n);

    printf("Отсортированный массив: \n");
    printArray(a, n);
    return 0;
}