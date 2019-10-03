#ifndef PCH_NETWORK_H
#define PCH_NETWORK_H

#include "../platform/check.h"

#include <stdlib.h>
#include <stdio.h>

#if IS_WINDOWS
    #include <windows.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
#else
    extern "C" {
        #include <sys/socket.h>
        #include <unistd.h> 
        #include <netinet/in.h>
        #include <arpa/inet.h>
    }
#endif


#endif // PCH_NETWORK_H
