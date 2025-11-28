#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "hehe.h"
#define HEHE_TIME_IMPLEMENTATION
#include "hehe_time.h"

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

#if 0
[STRING BUILDER] api something along the lines of:
// create an empty string builder
StringBuilder *sb = sb_create();
char *str = NULL;

// append some strings
sb_appendf(sb, "What is your name?\n -> %s\n\n", "Sir Lancelot, of Camelot");
sb_appendf(sb, "What is your quest?\n -> %s\n\n", "To seek the Holy Grail");
sb_appendf(sb, "What is your favorite color?\n -> %s\n\n", "Blue");
sb_append(sb, "Right, off you go");

// print
str = sb_concat(sb);
puts(str);

// clean up
free(str);
sb_free(sb);
#endif

int main(int argc, char* argv[])
{   
    
    char buffer[64];
    hehe_timestamp_iso(buffer, sizeof(buffer)); 
    printf("%s\n", buffer);
    hehe_timestamp_brief(buffer, sizeof(buffer));
    printf("%s\n", buffer);

#if 0 
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

    unsigned int f = 0;
    
    hehe_bits_print_uint32_t(f, stdout);
    hehe_bits_toggle_nth(f, 0);
    
    hehe_bits_toggle_nth(f, 0);
    hehe_bits_toggle_nth(f, 0);
    hehe_bits_clear_nth(f, 0);
    printf("\n");
    hehe_bits_print_uint32_t(f, stdout);
#endif
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
