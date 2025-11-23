#ifndef HEHE_DA_H_
#define HEHE_DA_H_

#include <stdlib.h>

#ifndef HEHE_DA_INIT_CAP
#define HEHE_DA_INIT_CAP 256
#endif /* HEHE_DA_INIT_CAP */
#if HEHE_DA_INIT_CAP <= 0
#error "HEHE_DA_INIT_CAP must be positive"
#endif

#ifndef HEHE_DA_ASSERT
#include <assert.h>
#define HEHE_DA_ASSERT assert
#endif /* HEHE_DA_ASSRT */


// #define hehe_da_reserve(hda) \
//     do {                     \
//                              \
//     } while (0)              \


#define hehe_da_append(hda, item)                                                      \
    do {                                                                               \
        if ((hda)->capacity < (hda)->count + 1) {                                      \
            void* tmp = NULL;                                                          \
            if ((hda)->capacity == 0) {                                                \
                (hda)->capacity = HEHE_DA_INIT_CAP;                                    \
            } else {                                                                   \
                (hda)->capacity *= 2;                                                  \
            }                                                                          \
            tmp = realloc((hda)->items, (hda)->capacity * sizeof(*(hda)->items));      \
            HEHE_DA_ASSERT(tmp && "HEHE realloc failed!");                             \
            (hda)->items = tmp;                                                        \
        }                                                                              \
        (hda)->items[(hda)->count++] = (item);                                           \
    } while (0)                                                                        \

#define hehe_da_append_many


#ifdef HEHE_DA_IMPLEMENTATION

#endif /* HEHE_DA_IMPLEMENTATION */

#endif /* HEHE_DA_H_ */
