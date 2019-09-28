#ifndef COMMON_H
#define COMMON_H


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #define IS_WINDOWS 1
#elif defined(__APPLE__)
    #define IS_APPLE 1
#else
    #define IS_LINUX 1
#endif


#endif // COMMON_H