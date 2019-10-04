#ifndef RESPONSE_H
#define RESPONSE_H

#include "interfaces/response_interface.h"
#include "interfaces/client_socket_interface.h"
#include "types/status_codes.h"


namespace Http {

    /**
     * The Response Class
     */
    class Response : public Interfaces::ResponseInterface {

    public:

        /**
         * Construct a response.
         */
        Response();

        /**
         * Construct a response.
         * 
         * - Initialize a stream
         * 
         * @param Http::Interfaces::ClientSocketInterface * socket
         */
        Response(Interfaces::ClientSocketInterface * socket);

        /**
         * Destruct the response.
         */
        ~Response();

        /**
         * Retrieve the body stream.
         * 
         * @return Http::Interfaces::ClientSocketInterface *
         */
        Interfaces::ClientSocketInterface * getBody() const override;

        /**
         * Retrieve the status code.
         * 
         * @return Http::StatusCode
         */
        StatusCode getStatusCode() override;

    private:

        /**
         * Store the stream interface.
         * 
         * @var Http::Interfaces::ClientSocketInterface *
         */
        Interfaces::ClientSocketInterface * m_socket;

        /**
         * Store the status code.
         * 
         * @var StatusCode
         */
        StatusCode m_statusCode;

    };

}


#endif // RESPONSE_H
