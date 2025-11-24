#include <stdio.h>
#include <stdlib.h>

#include "hehe.h"

typedef struct {
    int*    items;
    size_t  count;
    size_t  capacity;
} HeheDynamicArray;

void da_print_info(HeheDynamicArray* da)
{
    printf("[ITEMS PTR: %p]\n", da->items);
    printf("[ITEM COUNT: %zu]\n", da->count);
    printf("[DA CAPACITY: %zu]\n", da->capacity);
}

int main(void)
{   
    HeheDynamicArray da = {0}; 
    int amount = 100;

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



    return 0;
}
