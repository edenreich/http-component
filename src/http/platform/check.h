#ifndef PLATFORM_CHECK_H
#define PLATFORM_CHECK_H


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #define IS_WINDOWS 1
#elif defined(__APPLE__)
    #define IS_APPLE 1
#else
    #define IS_LINUX 1
#endif


#endif