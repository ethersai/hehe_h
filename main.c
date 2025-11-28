#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "hehe.h"

typedef struct {
    int*    items;
    size_t  count;
    size_t  capacity;
} HeheDynamicArray;

typedef struct {
    int* items;
    size_t head;     
    size_t tail;
    size_t count;
    size_t capacity;
} HeheQueue;

void da_print_info(HeheDynamicArray* da)
{
    printf("[ITEMS PTR: %p]\n", da->items);
    printf("[ITEM COUNT: %zu]\n", da->count);
    printf("[DA CAPACITY: %zu]\n", da->capacity);
}

void que_print_info(HeheQueue* qu)
{
    printf("[ITEMS PTR: %p]\n", qu->items);
    printf("[HEAD: %zu]\n", qu->head);
    printf("[TAIL: %zu]\n", qu->tail);
    printf("[COUNT: %zu]\n", qu->count);
    printf("[CAP: %zu]\n", qu->capacity);
}

// Any non-zero number to the power of 0 is 1.
#define hehe_wisebit_set(value, n) do { } while (0)
#define hehe_wisebit_toggle(value, n) do { } while (0) 
#define hehe_wisebit_clear(value, n) do { } while (0)
#define hehe_wisebit_read(value, n) do { } while (0)


int main(void)
{   
    HeheQueue que = {0};
    hehe_que_mem_init(&que, 10);

    int x = 10;
    int y = 20;
    int z = 30;
    int denque = 0;
    hehe_que_enque(&que, x);
    hehe_que_enque(&que, y); 
    hehe_que_enque(&que, z); 
    
    for (int i = 0; i < 3; i++) {
        hehe_que_deque(&que, denque);
        printf("%d\n", denque);
    }

    que_print_info(&que);
    
    int neg = 10;
    neg = ~neg ;
    printf("%d\n", neg);
    
    int array[5] = {2, 2, 4, 5, 5};

    int num = 0;
    for (int i = 0; i < 5; i++) {
        num ^= array[i];
    }
    printf("%d\n", num);
    printf("%d\n", 145 >> 4);

    putchar('\n');


    


#if 0
    HeheDynamicArray da = {0}; 
   
    hehe_da_append(&da, 10);
    da_print_info(&da);

    int x;
    hehe_da_pop(&da, &x);
    printf("%d", x);

    da_print_info(&da);
    int amount = 100;
    
    hehe_da_reserve(&da, 69);
    



    da_print_info(&da);

    for (int i = 0; i < amount; i++) {
        hehe_da_append(&da, i);
    }
    
    for (int i = 0; i < amount; i++) {
        printf("%d\n", da.items[i]);
    }
    
    da_print_info(&da);
   
    int* data = calloc(300, sizeof(int));

    hehe_da_append_many(&da, data, 300);

    int c = 0;
    for (int i = 0; i < da.count; i++) {
        printf("%d\n", da.items[i]);
        if (da.items[i] == 0) {
            c++;
        }
    }

    printf("[[[%d\n", c);
    da_print_info(&da);

    hehe_da_free(&da);
    da_print_info(&da);
#endif

    return 0;
}
