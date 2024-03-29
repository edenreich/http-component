#ifndef PCH_NETWORK_H
#define PCH_NETWORK_H

#include "../platform/check.h"

#include <stdlib.h>
#include <stdio.h>

#if IS_WINDOWS
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <windows.h>
    #pragma comment (lib, "Ws2_32.lib")
#else
    extern "C" {
        #include <sys/socket.h>
        #include <unistd.h> 
        #include <netinet/in.h>
        #include <arpa/inet.h>
    }
#endif


#endif // PCH_NETWORK_H
