#include "samolet.h"
void zapoln(struct Samolet reic[], int m, char countries[][30], int nomer[], int time1[], int price1[]) {
    for (int i = 0; i < m; i++) {
        reic[i].nover = nomer[rand() % 10];
        strcpy(reic[i].kyda, countries[rand() % 10]); 
        reic[i].time = time1[rand() % 10];
        reic[i].price = price1[rand() % 10];
    }
}
void print(int m, struct Samolet reic[], double tike) {
    printf("\n-------------- SPISOK REYSOV --------------\n");
    printf("+------+--------------+--------+-----------+\n");
    printf("|  No  |    pynkt | Vremya |   Stoimost |\n");
    printf("+------+--------------+--------+-----------+\n");
    
    for(int i = 0; i < m; i++) {
        printf("| %4d | %-12s | %4d min| %7d rub |\n", 
               reic[i].nover, 
               reic[i].kyda, 
               reic[i].time, 
               reic[i].price);
    }
    printf("+------+--------------+--------+-----------+\n");
    printf("%f",tike);
}
void sortirovka(struct Samolet reic[], int treb, int m){
    int count=1;
    while (count!=0){
        count=0;
        for(int i=0; i<m-1; i++){
            if (treb==1 && reic[i].nover>reic[i+1].nover){
                count++;
                struct Samolet per = reic[i];
                reic[i] = reic[i+1];
                reic[i+1] = per;
            }
            else if (treb==2 && reic[i].time>reic[i+1].time){
                count++;
                struct Samolet per = reic[i];
                reic[i] = reic[i+1];
                reic[i+1] = per;
            }
            else if (treb==3 && reic[i].price>reic[i+1].price){
                count++;
                struct Samolet per = reic[i];
                reic[i] = reic[i+1];
                reic[i+1] = per;
            }
        
        }
    } 

}