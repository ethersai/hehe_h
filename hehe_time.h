/*
 * This software is dual-licensed to the public domain and under the following
 * license: you are granted a perpetual, irrevocable license to copy, modify,
 * publish, and distribute this file as you see fit.
 */

/*
 * USAGE:
 *   #define HEHEDEF static inline  // optional
 *   #define HEHE_TIME_IMPLEMENTATION
 *   #include "hehe_time.h"
 *
 *   char buf[64];
 *   hehe_timestamp_iso(buf, sizeof(buf));
 *   printf("Time: %s\n", buf);
 *
 *   uint64_t ms = hehe_time_get_ms();
 */

#ifndef HEHe_TIME_H_
#define HEHe_TIME_H_

// HEHE_LOG baked in kinda.
#include <stdio.h>

#define HEHE_LOG_INFO(...)  fprintf(stdout, "[INFO]: " __VA_ARGS__)
#define HEHE_LOG_ERROR(...) fprintf(stderr, "[ERROR]: " __VA_ARGS__)
#define HEHE_LOG_WARN(...)  fprintf(stderr, "[WARNING]: " __VA_ARGS__)
// ADD LOG TO FILE.

#include <time.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

// eg #define HEHEDEF static inline
#ifndef HEHEDEF
#define HEHEDEF
#endif

HEHEDEF void hehe_timestamp_iso(char* buffer, size_t buffer_size);
HEHEDEF void hehe_timestamp_brief(char* buffer, size_t size);
HEHEDEF uint64_t hehe_time_get_sec(void);
HEHEDEF uint64_t hehe_time_get_ms(void);
HEHEDEF uint64_t hehe_time_get_ns(void);

// IMPLEMENTATION PART
#ifdef HEHE_TIME_IMPLEMENTATION

#define hehe_perma_assert(exp) do { if(!(exp)) { fprintf(stderr, "[HEHe_TIME] Assertion failed: %s, file %s, line %d\n", #exp, __FILE__, __LINE__); abort() ;} } while (0)

// NOTE: Timestamps not thread safe. TODO: Implement localtime_s, localtime_r for thread safety.
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

#if defined(_WIN32) && defined(_MSC_VER)
static inline long long internal_hehe_win_get_freq(void)
{
    static long long freq = 0;
    if (!freq) {
        LARGE_INTEGER li;
        if (!QueryPerformanceFrequency(&li))
            return 0;
        freq = li.QuadPart;
    }
    return freq;
}
#endif

HEHEDEF uint64_t hehe_time_get_sec(void)
{
#if defined(_WIN32) && defined(_MSC_VER)
    long long freq = internal_hehe_win_get_freq(); 
    LARGE_INTEGER ticks;
    QueryPerformanceCounter(&ticks);        // Get current tick count
    return ticks.QuadPart / freq;
#else
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return (uint64_t)tp.tv_sec + tp.tv_nsec / 1000000000ULL;   
#endif
}

HEHEDEF uint64_t hehe_time_get_ms(void)
{

#if defined(_WIN32) && defined(_MSC_VER)
    long long freq = internal_hehe_win_get_freq(); 
    LARGE_INTEGER ticks;
    QueryPerformanceCounter(&ticks);        // Get current tick count
    return (ticks.QuadPart * 1000ULL) / freq;
#else
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return (uint64_t)tp.tv_sec * 1000ULL + tp.tv_nsec / 1000000ULL;
#endif
}

HEHEDEF uint64_t hehe_time_get_ns(void) 
{
#if defined(_WIN32) && defined(_MSC_VER)
    long long freq = internal_hehe_win_get_freq(); 
    LARGE_INTEGER ticks;
    QueryPerformanceCounter(&ticks);        // Get current tick count
    return (ticks.QuadPart * 1000000000ULL) / freq;
#else
    struct timespec tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return (uint64_t)tp.tv_sec * 1000000000ULL + tp.tv_nsec;
#endif
}
#endif /*HEHE_TIME_IMPLEMENTATION*/

#endif /*HEHe_TIME_H_*/
/*
 * "Action is the proof of earnestness.
 *  Do what you are told diligently and faithfully, and obstacles will resolve themselves."
 *  [https://www.youtube.com/watch?v=Kopr6Q3oGHw] [Fri Nov 28 21:39:57]
 */
/****************************************/
/* Written by ethersai - Public domain. */
/****************************************/
