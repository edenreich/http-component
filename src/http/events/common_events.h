#ifndef COMMON_EVENTS_H
#define COMMON_EVENTS_H

#include <string>
#include "../interfaces/server_interface.h"


namespace Http {

    namespace Interfaces {
        // Forward declare the needed types
        class ServerInterface;
    }

    namespace Events {

        typedef void(*MessageRecievedHandler)(::Http::Interfaces::ServerInterface const* server, const std::string & message);
    
    }
}

#endif // COMMON_EVENTS_H