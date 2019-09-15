#ifndef CLIENT_H
#define CLIENT_H

#include "interfaces/client_interface.h"


namespace Http {

    /**
     * The Client Class
     */
    class Client : public Interfaces::ClientInterface {

    public:

        /**
         * Get the response by given url.
         * 
         * @param Interfaces::UrlInterface url
         * @return Interfaces::ResponseInterface
         */
        Interfaces::ResponseInterface get(Interfaces::UrlInterface & url) const override;

    private:
        //

    };

}


#endif // CLIENT_H
