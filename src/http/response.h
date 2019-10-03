#ifndef RESPONSE_H
#define RESPONSE_H

#include "interfaces/response_interface.h"
#include "interfaces/socket_stream_interface.h"
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
         * @param Http::Interfaces::SocketStreamInterface * stream
         */
        Response(Interfaces::SocketStreamInterface * stream);

        /**
         * Destruct the response.
         */
        ~Response();

        /**
         * Retrieve the body stream.
         * 
         * @return Http::Interfaces::SocketStreamInterface *
         */
        Interfaces::SocketStreamInterface * getBody() const override;

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
         * @var Http::Interfaces::SocketStreamInterface *
         */
        Interfaces::SocketStreamInterface * m_stream;

        /**
         * Store the status code.
         * 
         * @var StatusCode
         */
        StatusCode m_statusCode;

    };

}


#endif // RESPONSE_H
