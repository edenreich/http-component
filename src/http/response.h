#ifndef RESPONSE_H
#define RESPONSE_H

#include "interfaces/response_interface.h"
#include "interfaces/message_interface.h"
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
         * - Initialize a message
         * 
         * @param Http::Interfaces::MessageInterface * message
         */
        Response(Interfaces::MessageInterface * message);

        /**
         * Destruct the response.
         */
        ~Response();

        /**
         * Retrieve the body stream.
         * 
         * @return std::stringstream
         */
        std::stringstream getBody() const override;

        /**
         * Retrieve the status code.
         * 
         * @return Http::StatusCode
         */
        StatusCode getStatusCode() override;

    private:

        /**
         * Store the message content.
         * 
         * @var Http::Interfaces::MessageInterface *
         */
        Interfaces::MessageInterface * m_message;

        /**
         * Store the status code.
         * 
         * @var StatusCode
         */
        StatusCode m_statusCode;

    };

}


#endif // RESPONSE_H
