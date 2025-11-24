#ifndef HEHE_DA_H_
#define HEHE_DA_H_

#include <stdlib.h>
#include <string.h>

#ifndef HEHE_DA_INIT_CAP
#define HEHE_DA_INIT_CAP 256
#endif /* HEHE_DA_INIT_CAP */
#if HEHE_DA_INIT_CAP <= 0
#error "HEHE_DA_INIT_CAP must be positive"
#endif

// You can override these with your own implementations before including this header.
#ifndef HEHE_DA_ASSERT
#include <assert.h>
#define HEHE_DA_ASSERT assert
#endif /* HEHE_DA_ASSRT */

#ifndef HEHE_DA_REALLOC
#define HEHE_DA_REALLOC realloc
#endif /* HEHE_DA_REALLOC */

// TODO PERMA ASSERT

#define hehe_da_grow(hda, needs)                                                \
     do {                                                                       \
         void* tmp = NULL;                                                      \
         if ((hda)->capacity == 0) {                                            \
             (hda)->capacity = HEHE_DA_INIT_CAP;                                \
         }                                                                      \
         while ((hda)->capacity < (hda)->count + needs) {                       \
             (hda)->capacity *= 2;                                              \
         }                                                                      \
         tmp = HEHE_DA_REALLOC((hda)->items, (hda)->capacity * sizeof(*(hda)->items));  \
         HEHE_DA_ASSERT(tmp && "HEHE GROW FAILED!");                            \
         (hda)->items = tmp;                                                    \
     } while (0)                                                                \

#define hehe_da_append(hda, item)                                                      \
    do {                                                                               \
        if ((hda)->capacity < (hda)->count + 1) {                                      \
            hehe_da_grow((hda), 1);                                                    \
        }                                                                              \
        (hda)->items[(hda)->count++] = (item);                                         \
    } while (0)                                                                        \

#define hehe_da_append_many(hda, item, amount)                                                 \
    do {                                                                                       \
        if ((hda)->capacity < (hda)->count + (amount)) {                                       \
            hehe_da_grow((hda), (amount));                                                     \
        }                                                                                      \
        memcpy(&((hda)->items[(hda)->count]), (item), sizeof(*(hda)->items) * (amount));      \
        (hda)->count += (amount);                                                              \
    } while (0)                                                                                \

#define hehe_da_free(hda)                                                   \
    do {                                                                    \
        if ((hda)) {                                                        \
            free((hda)->items);                                             \
            (hda)->items = NULL;                                            \
            (hda)->count = 0;                                               \
            (hda)->capacity = 0;                                            \
        }                                                                   \
    } while (0)                                                             \

#ifdef HEHE_DA_IMPLEMENTATION

#endif /* HEHE_DA_IMPLEMENTATION */

#endif /* HEHE_DA_H_ */
