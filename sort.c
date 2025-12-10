#include <stdio.h>
# комментарий по заданию
# комментарий по заданию 2
# комментарий по заданию 3
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Флаг для оптимизации: если обмен не произошел, массив отсортирован
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Сброс флага в начале каждого прохода
        for (j = 0; j < n - 1 - i; j++) {
            // Сравниваем соседние элементы
            if (arr[j] > arr[j + 1]) {
                // Меняем местами, если они в неправильном порядке
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Устанавливаем флаг, что обмен произошел
            }
        }
        // Если во внутреннем цикле не было обменов, массив уже отсортирован
        if (swapped == 0) {
            break;
        }
    }
}

// Функция для печати массива
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Исходный массив: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Отсортированный массив: \n");
    printArray(arr, n);
    return 0;
}
