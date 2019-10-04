#ifndef COMMON_H
#define COMMON_H

#include "../platform/check.h"
#include "../pch/network.h"


namespace Http {
    
    #if IS_WINDOWS
    typedef SOCKET SocketId;
    #else
    typedef unsigned int SocketId;
    #endif

}


#endif // COMMON_H