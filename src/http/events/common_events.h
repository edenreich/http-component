#ifndef COMMON_EVENTS_H
#define COMMON_EVENTS_H

#include "../interfaces/client_interface.h"
#include "../interfaces/response_interface.h"
#include <functional>


namespace Http {
    namespace Events {

        typedef std::function<::Http::Interfaces::ResponseInterface*(::Http::Interfaces::ClientInterface * client)> MessageRecievedHandler;
    
    }
}

#endif // COMMON_EVENTS_H