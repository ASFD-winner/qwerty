#include <pthread.h>
#include <stdio.h>
#include <unistd.h> 

struct thread_data {
    char** strings;
    int count;
};

void* print_strings(void* arg) {
    struct thread_data* data = (struct thread_data*)arg;
    
    for (int i = 0; i < data->count; i++) {
        printf("%s\n", data->strings[i]);
        sleep(1);
    }
    
    return NULL;
}

int main() {
    pthread_t threads[4];
    struct thread_data datas[4];
    
    char* s0[] = {"Hello", "World", "from thread0"};
    datas[0].strings = s0;
    datas[0].count = 3;
    
    char* s1[] = {"One", "Two"};
    datas[1].strings = s1;
    datas[1].count = 2;
    
    char* s2[] = {"Red", "Green", "Blue"};
    datas[2].strings = s2;
    datas[2].count = 3;
    
    char* s3[] = {"Finish"};
    datas[3].strings = s3;
    datas[3].count = 1;
    
    
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, print_strings, &datas[i]);
    }
    sleep(1);
    
    for (int i = 0; i < 4; i++) {
        pthread_cancel(threads[i]);  
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}