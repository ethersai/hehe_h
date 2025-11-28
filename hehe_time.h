/*
 * This software is dual-licensed to the public domain and under the following
 * license: you are granted a perpetual, irrevocable license to copy, modify,
 * publish, and distribute this file as you see fit.
 */

#ifndef HEHe_TIME_H_
#define HEHe_TIME_H_

/*
 * "Action is the proof of earnestness. [https://www.youtube.com/watch?v=Kopr6Q3oGHw] [Fri Nov 28 21:39:57]
 *  Do what you are told diligently and faithfully, and obstacles will resolve themselves."
 */

// HEHE_LOG baked in kinda.
#include <bits/time.h>
#include <stdio.h>
#define HEHE_LOG_INFO(...)  fprintf(stdout, "[INFO]: " __VA_ARGS__)
#define HEHE_LOG_ERROR(...) fprintf(stderr, "[ERROR]: " __VA_ARGS__)
#define HEHE_LOG_WARN(...)  fprintf(stderr, "[WARNING]: " __VA_ARGS__)
// ADD LOG TO FILE.

static void hehe_log_test(void) 
{
    const char* test = "This is a test!";
    // homework: HEHE BUILD STRING.
    HEHE_LOG_INFO("%s\n", test);
    HEHE_LOG_ERROR("%s\n", test);
    HEHE_LOG_INFO("%s\n", test);
}

#include <time.h>
#include <stdint.h>

#ifndef HEHEDEF
#define HEHEDEF
#endif

HEHEDEF void hehe_timestamp_iso(char* buffer, size_t buffer_size);
HEHEDEF void hehe_timestamp_brief(char* buffer, size_t size);
HEHEDEF void hehe_time_get_ms(void);
HEHEDEF void hehe_time_get_ns(void);

#if 1 
#define HEHE_TIME_IMPLEMENTATION
#endif
#ifdef HEHE_TIME_IMPLEMENTATION
// int main() {
//     time_t now = time(NULL);
//     struct tm* t = localtime(&now);
//     strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", t);
//     printf("[INFO] Current time: %s\n", buf);
//     return 0;
// }

HEHEDEF void hehe_timestamp_iso(char* buffer, size_t size)
{
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);      
}

HEHEDEF void hehe_timestamp_brief(char* buffer, size_t size)
{
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buffer, size, "%Y%m%d_%H%M%S", t);
}

HEHEDEF uint64_t hehe_time_get_ms(void)
{
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
}

HEHEDEF uint64_t hehe_time_get_ns(void) 
{
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return (uint64_t)tp.tv_sec * 1000000000ULL + tp.tv_nsec;
}

#endif /*HEHE_TIME_IMPLEMENTATION*/

#endif /*HEHe_TIME_H_*/
/****************************************/
/* Written by ethersai - Public domain. */
/****************************************/
