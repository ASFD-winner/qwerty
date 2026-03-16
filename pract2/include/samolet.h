#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
struct Samolet {
    int nover;
    char kyda[30];  
    int time;
    int price;
};
void zapoln(struct Samolet reic[], int m, char countries[][30], int nomer[], int time1[], int price1[]);
void print(int m, struct Samolet reic[], double tike);
void sortirovka(struct Samolet reic[], int treb, int m);