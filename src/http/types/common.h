#ifndef COMMON_H
#define COMMON_H

#include "../platform/check.h"
#include "../pch/network.h"


namespace Http {
    
    #if IS_WINDOWS
    typedef SOCKET ClientSocketId;
    typedef SOCKET ServerSocketId;
    #else
    typedef unsigned int ClientSocketId;
    typedef unsigned int ServerSocketId;
    #endif

}


#endif // COMMON_H