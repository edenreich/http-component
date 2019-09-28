#ifndef COMMON_H
#define COMMON_H


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #define IS_WINDOWS
#elif defined(__APPLE__)
    #define IS_APPLE
#else
    #define IS_LINUX
#endif


#endif // COMMON_H