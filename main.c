#include <stdio.h>
#include <stdlib.h>

#include "hehe.h"

//Stack has a dynamic array inside
//push() → add to end of array
//pop() → remove from end of array
//peek() → look at last element
//All the growing/shrinking is handled by your existing array code
//
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
//    do {                                                            \
        if ((hda)->count <= 0) {                                    \
           pop_out = NULL;                                          \
        } else {                                                    \
           *pop_out = ((hda)->items[(hda)->count-1]);                 \
           (hda)->count--;                                           \
        }                                                            \

typedef struct {
    int* items;
    size_t head;     // index to dequeue from
    size_t tail;     // index to enqueue to
    size_t count;    // how many items
    size_t capacity;
} HeheQueue;


int main(void)
{   
    HeheDynamicArray da = {0}; 
   
    

    hehe_da_append(&da, 10);
    da_print_info(&da);

    int x;
    hehe_da_pop(&da, &x);
    printf("%d", x);

    da_print_info(&da);
#if 0
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
