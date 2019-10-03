#ifndef COMMON_H
#define COMMON_H

#include "../platform/check.h"
#include "../pch/network.h"


namespace Http {
    
    #if IS_WINDOWS
    typedef SOCKET ClientSocketId;
    typedef SOCKET ServerSocketId;
    #else
    unsigned int ClientSocketId;
    unsigned int ServerSocketId;
    #endif

}


#endif // COMMON_H