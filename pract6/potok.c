#include <pthread.h>
#include <stdio.h>

void* potok(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Дочерний поток: строка %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, potok, NULL);
    
    pthread_join(t, NULL);
    for (int i = 1; i <= 5; i++) {
        printf("Родительский поток: строка %d\n", i);
    }


    return 0;
}
