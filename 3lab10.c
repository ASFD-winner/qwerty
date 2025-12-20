#include <stdio.h>
#include <stdlib.h> 

struct Line {
    double *a;  
    double *b;
    int size;  
};

void dann(struct Line *lines) {  // Указатель!
    for(int i = 0; i < lines->size; i++) {
        printf("Прямая %d: введите a и b: ", i+1);
        scanf("%lf %lf", &lines->a[i], &lines->b[i]);  // стрелка ->
    }
}

int parall(struct Line *lines) {
    int k1=0;
    for(int i = 0; i < lines->size; i++) {
        if (lines->a[i]==0){
            k1+=1;
        }
    }
    return k1;
}

int main() {
    struct Line lines;
    int k2=0;
    
    printf("Сколько прямых? ");
    scanf("%d", &lines.size);
    
    lines.a = (double*)malloc(lines.size * sizeof(double));
    lines.b = (double*)malloc(lines.size * sizeof(double));
    
    dann(&lines);  // Передаем АДРЕС!
    int k1=parall(&lines);
    printf("k1=%d\n", k1);
    printf("k2=%d\n", k2);
    
    free(lines.a);
    free(lines.b);
    
    return 0;
}