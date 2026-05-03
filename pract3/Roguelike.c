#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

struct room {
    struct room *next;      // вправо
    struct room *down;      // вниз
    char name[50];
    int level;
    int number;
    int resolution;
};

struct room *create_node(char name[], int level, int number, int resolution) {
    struct room *new_node = (struct room *)malloc(sizeof(struct room));
    if (new_node == NULL) return NULL;
    
    strcpy(new_node->name, name);
    new_node->level = level;
    new_node->number = number;
    new_node->resolution = resolution;
    new_node->next = NULL;
    new_node->down = NULL;
    return new_node;
}

struct room *add_to_end(struct room *head, char name[], int level, int number, int resolution) {
    struct room *new_node = create_node(name, level, number, resolution);
    if (new_node == NULL) return head;
    if (head == NULL) return new_node;
    
    struct room *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

void print_list(struct room *head, int level_num) {
    if (head == NULL) {
        printf("Уровень %d пуст!\n", level_num);
        return;
    }
    
    struct room *current = head;
    int count = 1;
    printf("\n=== Уровень %d (%s номера) ===\n", level_num, level_num == 1 ? "четные" : "нечетные");
    while (current != NULL) {
        printf("%d. %s (№%d)\n", count, current->name, current->number);
        current = current->next;
        count++;
    }
}

void free_list(struct room *head) {
    struct room *current = head;
    while (current != NULL) {
        struct room *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL));
    int n, k;
    char komnaty[10][30] = {"Прихожая", "Гостиная", "Спальня", "Кухня", "Ванная",
                            "Туалет", "Детская", "Кабинет", "Балкон", "Кладовая"};
    
    printf("Введите количество комнат на верхнем уровне: ");
    scanf("%d", &n);
    printf("Введите количество комнат на нижнем уровне: ");  
    scanf("%d", &k); 
    
    struct room *up_level = NULL;    
    struct room *down_level = NULL;  
    
    for (int i = 2; i <= n*2; i += 2) {
        up_level = add_to_end(up_level, komnaty[rand() % 10], 1, i, rand() % 10 + 1);
    }
    
    
    for (int i = 1; i <= k*2; i += 2) {
        down_level = add_to_end(down_level, komnaty[rand() % 10], 2, i, rand() % 10 + 1);
    }
    
    struct room *cur_up = up_level;
    struct room *cur_down = down_level;
    while (cur_up != NULL && cur_down != NULL) {
        cur_up->down = cur_down;
        cur_up = cur_up->next;
        cur_down = cur_down->next;
    }
    
    print_list(up_level, 1);
    print_list(down_level, 2);
    
    struct room *current = up_level;
    char cmd;
    
    printf("\n=== УПРАВЛЕНИЕ ===");
    printf(" D/6 - вправо");
    printf(" S/2 - вниз");
    printf("\nQ - выход\n");
    printf("==================\n");
    
    do {
        printf("\n--- ТЕКУЩАЯ КОМНАТА ---\n");
        printf("Название: %s\n", current->name);
        printf("Номер: %d\n", current->number);
        printf("Уровень: %d\n", current->level);
        printf("Размер: %d\n", current->resolution);
        printf("------------------------\n");
        
        printf("Команда: ");
        scanf(" %c", &cmd);
        
        if ((cmd == 'D' || cmd == '6') && current->next != NULL) {
            current = current->next;
        }
        else if ((cmd == 'S' || cmd == '2') && current->down != NULL) {
            current = current->down;
        }
        else if (cmd != 'Q' && cmd != 'q') {
            printf("❌ Нельзя переместиться!\n");
        }
        
    } while (cmd != 'Q' && cmd != 'q');
    
    free_list(up_level);
    free_list(down_level);
    
    printf("\nПрограмма завершена!\n");
    return 0;
}