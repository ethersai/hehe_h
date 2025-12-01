#ifndef HEHe_SB_H_
#define HEHe_SB_H_

// [STRING BUILDER] api something along the lines of:
// // create an empty string builder
// StringBuilder *sb = sb_create();
// char *str = NULL;
//
// // append some strings
// sb_appendf(sb, "What is your name?\n -> %s\n\n", "Sir Lancelot, of Camelot");
// sb_appendf(sb, "What is your quest?\n -> %s\n\n", "To seek the Holy Grail");
// sb_appendf(sb, "What is your favorite color?\n -> %s\n\n", "Blue");
// sb_append(sb, "Right, off you go");
//
// // print
// str = sb_concat(sb);
// puts(str);
//
// // clean up
// free(str);
// sb_free(sb);

#include <stddef.h>
#include <string.h>

typedef struct {
    char* items;
    size_t count;
    size_t capacity;
} HEHeSB; 

#define hehe_sb_append(sb, str) \
    do {                        \
        strlen()                         \
    } while (0)                 


// hehe_sb_free();
// hehe_sb_append();
// hehe_sb_appendf();



#endif /*HEHe_SB_H_*/
