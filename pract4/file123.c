#include <stdio.h>
#include <string.h>

struct dann {
    char name[100];
    char id[15];
    char level[30];
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Используйте: другой файл\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Не могу открыть файл %s\n", argv[1]);
        return 1;
    }
    
    FILE *bin = fopen("database.dat", "wb");
    if (bin == NULL) {
        printf("Не могу создать файл\n");
        fclose(f);
        return 1;
    }

    char line[256];
    
    printf("%-25s %-10s %-10s\n", "ФИО", "ID", "Уровень");
    printf("-----------------------------------------\n");
    
    while (fgets(line, sizeof(line), f)) {
        struct dann emp;  
        
        char *name = strtok(line, ";\n");
        char *id   = strtok(NULL, ";\n");
        char *lvl  = strtok(NULL, ";\n");

        if (name && id && lvl) {
            strcpy(emp.name, name);
            strcpy(emp.id, id);
            strcpy(emp.level, lvl);
            
            printf("%-25s %-10s %-10s\n", emp.name, emp.id, emp.level);
            fwrite(&emp, sizeof(struct dann), 1, bin);
        }
    }

    fclose(f);
    fclose(bin);
    
    bin = fopen("database.dat", "rb"); 
    if (bin == NULL) {
        printf("Не открылся файл\n");
        return 1;
    }
    
    char poisk[15];
    printf("Введите id для поиска: ");
    scanf("%s", poisk);  
    
    struct dann emp;
    int found = 0;

    while (fread(&emp, sizeof(struct dann), 1, bin) == 1) {
        if (strcmp(emp.id, poisk) == 0) {  
            printf("Найден: %s, %s, %s\n", emp.name, emp.id, emp.level);
            found = 1;
            break;
        }
    }
    
    if (found == 0) {
        printf("Не нашли\n");
    }
    
    fclose(bin);
    return 0;
}