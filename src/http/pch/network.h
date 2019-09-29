#ifndef PCH_NETOWRK_H
#define PCH_NETWORK_H

#include "../platform/check.h"


#if IS_WINDOWS
    #include <winsock2.h>
#else
    #include <stdlib.h>

    extern "C" {
        #include <sys/socket.h>
        #include <unistd.h> 
        #include <netinet/in.h>
        #include <arpa/inet.h>
    }
#endif


#endif // PCH_NETOWRK_H
