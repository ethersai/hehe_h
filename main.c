#include <stdio.h>
#include <stdlib.h>
#include "hehe.h"

typedef struct {
    int*    items;
    size_t  count;
    size_t  capacity;
} HeheDynamicArray;

// #define hehe_da_append(hda, item)   \
//    do {                            \
//                                    \
//                                    \
//    } while (0)                     \

void da_print_info(HeheDynamicArray* da)
{
    printf("[ITEMS PTR: %p]\n", da->items);
    printf("[ITEM COUNT: %zu]\n", da->count);
    printf("[DA CAPACITY: %zu]\n", da->capacity);
}

int main(void)
{   
    HeheDynamicArray da = {0}; 

    da_print_info(&da);

    for (int i = 0; i < 1000; i++) {
        hehe_da_append(&da, i);
    }

    
    da_print_info(&da);
    

    return 0;
}
