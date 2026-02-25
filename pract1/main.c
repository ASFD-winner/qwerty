#include "samolet.h"
int main() {
    srand(time(NULL));

    
    int m, treb;
    char sort;
    printf("Количество рейсов: ");
    scanf("%d", &m);
    printf("Нужна ли сортировка? Y(да)/N(нет)");
    scanf(" %c", &sort);
    if (sort=='Y'){
        printf("Введите 1 если нужна сортировка по номеру\n");
        printf("Введите 2 если нужна сортировка по времени\n");
        printf("Введите 3 если нужна сортировка по цене\n");
        scanf("%d", &treb);
    }
    
    struct Samolet reic[m];
    char countries[10][30] = {"Russia", "USA", "China", "Germany", "France", 
                          "Japan", "Brazil", "India", "Italy", "Canada"};
    
    int nomer[10];
    int time1[10];
    int price1[10]; 
    
    for(int i = 0; i < 10; i++) {
        nomer[i] = rand() % 1000 + 100; 
        time1[i] = rand() % 360 + 60;   
        price1[i] = rand() % 10000 + 5000;  
    }
    zapoln(reic, m, countries, nomer, time1, price1);
    if (sort=='N'){
        print(m, reic, 0);
    }
    if (sort=='Y'){
        struct timeval start, end;
        gettimeofday(&start, NULL);
        sortirovka(reic, treb, m);
        gettimeofday(&end, NULL);
        double time_taken = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec)/10e6);
        print(m, reic, time_taken);
    }

    

    
    return 0;
}