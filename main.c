#include <stdio.h>
#include <stdlib.h>

#define HEHE_DA_INIT_CAP 1
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
    

    return 0;
}
